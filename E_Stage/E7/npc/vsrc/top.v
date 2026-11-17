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

    // 取指
    assign instr = ifu_rdata;
    always @(posedge clk) begin
        if (rst) begin
            ifu_rdata <= 32'h00000013;
            ifu_respValid <= 1'b0;
        end
        else begin
            if (ifu_reqValid) begin
                ifu_rdata <= pmem_read(ifu_raddr);
            end
            ifu_respValid <= ifu_reqValid;
        end
    end

    // 访存
    always @(posedge clk) begin
        // load指令读取存储器中的数据
        lsu_rdata <= (lsu_reqValid && !lsu_wen) ? pmem_read(lsu_addr) : 32'b0;
        if (lsu_reqValid && lsu_wen) begin
            // store指令写入存储器
            pmem_write(lsu_addr, lsu_wdata, {4'b0, lsu_wmask});
        end
        lsu_respValid <= lsu_reqValid;
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
