`timescale 1ns/1ps

module iverilog_top();
    reg clock;
    reg reset;

    wire instr_finish;
    wire [31:0] PC;
    wire [31:0] instr;
    wire [63:0] instr_cnt;
    wire        netlist_ebreak_fetched;

    string bin_path;

    localparam [63:0] MAX_SIM_CYCLES = 64'd1000000000;
    reg [63:0] cycle_cnt;

    always @(posedge clock) begin
        if (reset) begin
            cycle_cnt <= 64'd0;
        end
        else begin
            cycle_cnt <= cycle_cnt + 64'd1;
    
            if (cycle_cnt >= MAX_SIM_CYCLES - 1)
                $fatal(1, "Simulation timeout");
        end
    end

    topNPC u_topNPC (
        .clock(clock),
        .reset(reset),
        .instr_finish(instr_finish),
        .PC(PC),
        .instr(instr),
        .instr_cnt(instr_cnt),
        .netlist_ebreak_fetched(netlist_ebreak_fetched)
    );

    initial begin
        clock = 0;
        reset = 1;
        # 10 reset = 0;
    end
    always # 1 clock = ~clock;

    initial begin
        // 从仿真命令行获取bin文件路径
        if (!$value$plusargs("bin=%s", bin_path)) begin
            $display("ERROR: Please specify program bin file!");
            $finish;
        end
        $display("Loading program: %s", bin_path);
        $pmem_load(bin_path);
    end

    initial begin
        if ($test$plusargs("wave")) begin
            $dumpfile("wave.vcd");
            $dumpvars(0, iverilog_top);
        end
    end

    // SimpleBus接口的X/Z态检测
    always @(posedge clock) begin
        if (!reset) begin
            if ($isunknown(u_topNPC.ifu_reqValid)) $fatal(1, "ifu_reqValid contains X/Z");
            if ($isunknown(u_topNPC.ifu_respValid)) $fatal(1, "ifu_respValid contains X/Z");
        end
    end

    // 有效取指地址和指令数据的X/Z态检测
    always @(posedge clock) begin
        if (!reset) begin
            if (u_topNPC.ifu_reqValid === 1'b1) begin
                if ($isunknown(u_topNPC.ifu_raddr)) $fatal(1, "IFU address contains X/Z");
            end
            if (u_topNPC.ifu_respValid === 1'b1) begin
                if ($isunknown(u_topNPC.ifu_rdata)) $fatal(1, "Instruction contains X/Z");
            end
        end
    end

    // LSU控制信号的X/Z态检测
    always @(posedge clock) begin
        if (!reset) begin
            if ($isunknown(u_topNPC.lsu_reqValid)) $fatal(1, "lsu_reqValid contains X/Z");
            if ($isunknown(u_topNPC.lsu_respValid)) $fatal(1, "lsu_respValid contains X/Z");
            if (u_topNPC.lsu_reqValid === 1'b1) begin
                if ($isunknown(u_topNPC.lsu_wen)) $fatal(1, "lsu_wen contains X/Z");
                if ($isunknown(u_topNPC.lsu_addr)) $fatal(1, "LSU address contains X/Z");
                if (u_topNPC.lsu_wen === 1'b1) begin
                    if ($isunknown(u_topNPC.lsu_wmask)) $fatal(1, "LSU wmask contains X/Z");
                end
            end
        end
    end

`ifdef NETLIST_SIM
    always @(posedge clock) begin
        if (!reset && netlist_ebreak_fetched === 1'b1) begin
            $display("fetched ebreak");
            $display("Cycles executed: %0d", cycle_cnt);
            $finish;
        end
    end
`endif
endmodule