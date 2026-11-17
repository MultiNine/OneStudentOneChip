module top #(PC_WIDTH = 32,
             INSTR_WIDTH = 32,
             ADDR_WIDTH  = 4, 
             DATA_WIDTH = 32
             ) (
    input                          clk,
    input                          rst,
    output                         instr_finish,
    output     [PC_WIDTH    - 1:0] PC,
    output     [INSTR_WIDTH - 1:0] instr,
    output reg [             63:0] instr_cnt
);
    import "DPI-C" function void NPC_ebreak(input int a0);
    import "DPI-C" function int  pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
    import "DPI-C" function void NPC_commit();

    wire [DATA_WIDTH - 1:0] ifu_raddr;  // 来自NPC IFU的取指地址
    reg  [DATA_WIDTH - 1:0] ifu_rdata;  // 返回给NPC的访存取指结果

    wire [DATA_WIDTH - 1:0] lsu_addr;
    wire                    lsu_wen;
    reg  [DATA_WIDTH - 1:0] lsu_rdata;
    wire [DATA_WIDTH - 1:0] lsu_wdata;
    wire [             3:0] lsu_wmask;

    wire                    ifu_reqValid;
    wire                    lsu_reqValid;
    reg                     ifu_respValid;
    reg                     lsu_respValid;

    wire                    is_ebreak;
    wire [DATA_WIDTH - 1:0] a0;

    // Delay Control
    reg                    ifu_busy;
    reg [             4:0] ifu_delay_cnt;
    reg [DATA_WIDTH - 1:0] ifu_raddr_buf;
    reg                    lsu_busy;
    reg [             4:0] lsu_delay_cnt;
    reg [DATA_WIDTH - 1:0] lsu_addr_buf;
    reg [DATA_WIDTH - 1:0] lsu_wdata_buf;
    reg [             3:0] lsu_wmask_buf;
    reg                    lsu_wen_buf;

    wire ifu_req_accept = ifu_reqValid && !ifu_busy;
    wire lsu_req_accept = lsu_reqValid && !lsu_busy;
    wire mem_req_accept = ifu_req_accept || lsu_req_accept;
    reg [             7:0] lfsr;
    wire feedback;
    assign feedback = lfsr[4] ^ lfsr[3] ^ lfsr[2] ^ lfsr[0];
    always@(posedge clk) begin
        if(rst) begin
            lfsr <= 8'b0000_0001;
        end
        else if (mem_req_accept) begin
            lfsr <= {feedback, lfsr[7:1]};
        end
    end
    // 取LFSR输出低5位，实现随机延迟1~32周期
    wire [5:0] mem_delay = {1'b0, lfsr[4:0]} + 6'd1;

    // 取指
    assign instr = ifu_rdata;
    always @(posedge clk) begin
        if (rst) begin
            ifu_rdata     <= 32'h00000013;
            ifu_respValid <= 1'b0;
            ifu_busy      <= 1'b0;
            ifu_delay_cnt <= 5'd0;
            ifu_raddr_buf <= 32'd0;
        end
        else begin
            ifu_respValid <= 1'b0;
            if (!ifu_busy) begin
                if (ifu_reqValid) begin
                    if (mem_delay == 6'd1) begin   // 保持原来的响应时序
                        ifu_rdata     <= pmem_read(ifu_raddr);
                        ifu_respValid <= 1'b1;
                    end
                    else begin
                        ifu_busy      <= 1'b1;
                        ifu_delay_cnt <= mem_delay[4:0] - 5'd1;
                        ifu_raddr_buf <= ifu_raddr;
                    end
                end
            end
            else begin
                if (ifu_delay_cnt > 5'd1) begin
                    ifu_delay_cnt <= ifu_delay_cnt - 5'd1;
                end
                else if (ifu_delay_cnt == 5'd1) begin
                    ifu_rdata     <= pmem_read(ifu_raddr_buf);
                    ifu_respValid <= 1'b1;
                    ifu_busy      <= 1'b0;
                    ifu_delay_cnt <= 5'd0;
                end
            end
        end
    end
   
    // 访存
    always @(posedge clk) begin
        if (rst) begin
            lsu_rdata     <= 32'h0;
            lsu_respValid <= 1'b0;
            lsu_busy      <= 1'b0;
            lsu_delay_cnt <= 5'd0;
            lsu_addr_buf  <= 32'd0;
            lsu_wdata_buf <= 32'd0;
            lsu_wmask_buf <= 4'b0000;
            lsu_wen_buf   <= 1'b0;
        end
        else begin
            lsu_respValid <= 1'b0;
            if (!lsu_busy) begin
                if (lsu_reqValid) begin
                    if (mem_delay == 6'd1) begin
                        if (!lsu_wen) begin                     // 保持原来的响应时序
                            lsu_rdata <= pmem_read(lsu_addr);   // Load
                        end
                        else begin
                            pmem_write(lsu_addr, lsu_wdata, {4'b0, lsu_wmask}); // Store
                            lsu_rdata <= 32'b0;
                        end
                        lsu_respValid <= 1'b1;
                    end
                    else begin
                        lsu_busy      <= 1'b1;
                        lsu_delay_cnt <= mem_delay[4:0] - 5'd1;
                        lsu_addr_buf  <= lsu_addr;
                        lsu_wdata_buf <= lsu_wdata;
                        lsu_wmask_buf <= lsu_wmask;
                        lsu_wen_buf   <= lsu_wen;
                    end
                end
            end
            else begin
                if (lsu_delay_cnt > 5'd1) begin
                    lsu_delay_cnt <= lsu_delay_cnt - 5'd1;
                end
                else if (lsu_delay_cnt == 5'd1) begin
                    if (!lsu_wen_buf) begin
                        lsu_rdata <= pmem_read(lsu_addr_buf);   // Load
                    end
                    else begin
                        pmem_write(lsu_addr_buf, lsu_wdata_buf, {4'b0, lsu_wmask_buf}); // Store
                        lsu_rdata <= 32'b0;
                    end
                    lsu_respValid <= 1'b1;
                    lsu_busy      <= 1'b0;
                    lsu_delay_cnt <= 5'd0;
                end
            end
        end
    end

    // ebreak指令
    always @(posedge clk) begin
        if (!rst && instr_finish && is_ebreak) begin
            NPC_ebreak(a0);
        end
    end

    // 判断指令提交
    always @(posedge clk) begin
        if (rst) begin
            instr_cnt <= 64'd0;
        end
        else if (instr_finish) begin
            instr_cnt <= instr_cnt + 64'd1;
            NPC_commit();
        end
    end

    NPC #(
    .PC_WIDTH(PC_WIDTH),
    .INSTR_WIDTH(INSTR_WIDTH),
    .ADDR_WIDTH(ADDR_WIDTH),
    .DATA_WIDTH(DATA_WIDTH)
    ) u_NPC (
        .clk(clk),
        .rst(rst),

        .instr(instr),
        .ifu_respValid(ifu_respValid),
        .lsu_respValid(lsu_respValid),
        .PC(PC),
        .ifu_raddr(ifu_raddr),
        .instr_finish(instr_finish),
        .ifu_reqValid(ifu_reqValid),
        .lsu_reqValid(lsu_reqValid),

        .lsu_rdata(lsu_rdata),
        .lsu_addr(lsu_addr),
        .lsu_wdata(lsu_wdata),
        .lsu_wmask(lsu_wmask),
        .lsu_wen(lsu_wen),

        .is_ebreak(is_ebreak),
        .a0(a0)
    );
endmodule