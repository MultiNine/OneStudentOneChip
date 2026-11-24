module topNPC (
    input             clock,
    input             reset,
    output            instr_finish,
    output     [31:0] PC,
    output     [31:0] instr,
    output reg [63:0] instr_cnt,
    output            netlist_ebreak_fetched
);
`ifndef __ICARUS__
    import "DPI-C" function void NPC_ebreak(input int a0);
    import "DPI-C" function int  pmem_read(input int raddr);
    import "DPI-C" function void pmem_write(input int waddr, input int wdata, input byte wmask);
    import "DPI-C" function void NPC_commit();
`endif

    wire [31:0] ifu_raddr;  // 来自NPC IFU的取指地址
    reg  [31:0] ifu_rdata;  // 返回给NPC的访存取指结果

    wire [31:0] lsu_addr;
    wire        lsu_wen;
    reg  [31:0] lsu_rdata;
    wire [31:0] lsu_wdata;
    wire [ 3:0] lsu_wmask;
    wire [ 1:0] lsu_size;

    wire        ifu_reqValid;
    wire        lsu_reqValid;
    reg         ifu_respValid;
    reg         lsu_respValid;

    wire        is_ebreak;
    wire [31:0] a0;

`ifdef NETLIST_SIM
    assign PC           = ifu_raddr;
    assign instr_finish = 1'b0;
    assign is_ebreak    = 1'b0;
    assign a0           = 32'b0;
`else
    assign PC           = NPC.PCout;
    assign instr_finish = NPC.instr_finish;
    assign is_ebreak    = NPC.is_ebreak;
    assign a0           = NPC.a0;
`endif
    assign netlist_ebreak_fetched = ifu_respValid && (ifu_rdata == 32'h00100073);

    // 取指
`ifdef NETLIST_SIM
    assign instr = ifu_rdata;
`else
    reg [31:0] trace_instr;
    always @(posedge clock) begin
        if (reset)
            trace_instr <= 32'h00000013;
        else if (ifu_respValid)
            trace_instr <= ifu_rdata;
    end
    assign instr = ifu_respValid ? ifu_rdata : trace_instr;
`endif
    always @(posedge clock) begin
        if (reset) begin
            ifu_rdata <= 32'h00000013;
            ifu_respValid <= 1'b0;
        end
        else begin
            if (ifu_reqValid) begin
                `ifdef __ICARUS__
                    $pmem_read(ifu_raddr, ifu_rdata);
                `else
                    ifu_rdata <= pmem_read(ifu_raddr);
                `endif
            end
            else begin
                ifu_rdata <= 32'hxxxxxxxx;
            end

            ifu_respValid <= ifu_reqValid;
        end
    end

    // 访存
    always @(posedge clock) begin
        if (reset) begin
            lsu_rdata <= 32'b0;
            lsu_respValid <= 1'b0;
        end else begin
            // load指令读取存储器中的数据
            if ((lsu_reqValid && !lsu_wen)) begin
                `ifdef __ICARUS__
                     $pmem_read(lsu_addr, lsu_rdata);
                 `else
                    lsu_rdata <= pmem_read(lsu_addr);
                `endif
            end else begin
                lsu_rdata <= 32'h0;
            end
            // store指令写入存储器
            if (lsu_reqValid && lsu_wen) begin
               `ifdef __ICARUS__
                   $pmem_write(lsu_addr, lsu_wdata, {4'b0, lsu_wmask});
                `else
                    pmem_write(lsu_addr, lsu_wdata, {4'b0, lsu_wmask});
                `endif
            end
            lsu_respValid <= lsu_reqValid;
        end
    end

    // ebreak指令
    always @(posedge clock) begin
        if (!reset && instr_finish && is_ebreak) begin
            `ifdef __ICARUS__
                if (a0 == 0) $display("HIT GOOD TRAP");
                else $display("HIT BAD TRAP");
                $finish;
            `else
                NPC_ebreak(a0);
            `endif
        end
    end

    // 判断指令提交
    always @(posedge clock) begin
        if (reset) begin
            instr_cnt <= 64'd0;
        end
        else if (instr_finish) begin
            instr_cnt <= instr_cnt + 64'd1;
            `ifndef __ICARUS__
                NPC_commit();
            `endif
        end
    end

`ifdef NETLIST_SIM
    ysyx_27000000 NPC (
`else
    ysyx_27000000 #(.RESET_PC(32'h8000_0000)) NPC (
`endif
        .clock(clock),
        .reset(reset),

        .io_ifu_rdata(ifu_rdata),
        .io_ifu_respValid(ifu_respValid),
        .io_lsu_respValid(lsu_respValid),
        .io_ifu_addr(ifu_raddr),
        .io_ifu_reqValid(ifu_reqValid),
        .io_lsu_reqValid(lsu_reqValid), 

        .io_lsu_rdata(lsu_rdata),
        .io_lsu_addr(lsu_addr),
        .io_lsu_size(lsu_size),
        .io_lsu_wdata(lsu_wdata),
        .io_lsu_wmask(lsu_wmask),
        .io_lsu_wen(lsu_wen)
    );

`ifdef NETLIST_SIM
    reg [31:0] ifu_addr_d;

    always @(posedge clock) begin
        if (reset)
            ifu_addr_d <= 32'b0;
        else if (ifu_reqValid)
            ifu_addr_d <= ifu_raddr;
    end

    always @(posedge clock) begin
        if (!reset && ifu_respValid && ifu_rdata == 32'h00100073) begin
            $display("[NETLIST] ebreak fetched at PC = 0x%08x", ifu_addr_d);
        end
    end
`endif
endmodule
