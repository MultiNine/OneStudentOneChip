module NPC #(
    parameter PC_WIDTH    = 32,
    parameter INSTR_WIDTH = 32,
    parameter ADDR_WIDTH  = 4,
    parameter DATA_WIDTH  = 32
)(
    input                      clk,
    input                      rst,

    // Instruction memory
    input  [INSTR_WIDTH - 1:0] instr,
    input                      ifu_respValid,// 存储器取指完成
    input                      lsu_respValid,// 存储器访存完成
    output [PC_WIDTH    - 1:0] PC,
    output [PC_WIDTH    - 1:0] ifu_raddr,   // IFU发出访存请求，向存储器提供的取指地址
    output                     instr_finish,// 当前指令将在本周期结束执行
    output                     ifu_reqValid,// 告知存储器可以取指
    output                     lsu_reqValid,// 告知存储器可以访存

    // Data memory
    input  [DATA_WIDTH - 1:0]  lsu_rdata,
    output [DATA_WIDTH - 1:0]  lsu_addr,      
    output [DATA_WIDTH - 1:0]  lsu_wdata,
    output [             3:0]  lsu_wmask,
    output                     lsu_wen,     // 面向top存储器的写使能

    // Simulation status
    output                     is_ebreak,    
    output [DATA_WIDTH - 1:0]  a0
);

    wire [PC_WIDTH - 1:0] PCin;
    wire [PC_WIDTH - 1:0] PCout;
    wire                  instr_valid;  // 当前取回的指令有效，开始处理
    assign PC = PCout;

    wire is_addi, is_jalr, is_add, is_lui,
         is_lw,   is_sw,   is_lbu, is_sb;
    wire [31:0] imm_I, imm_S, imm_U;
    wire [DATA_WIDTH - 1:0] jumpAddr;

    wire [ADDR_WIDTH - 1:0] waddr;
    wire [DATA_WIDTH - 1:0] wdata;
    wire [ADDR_WIDTH - 1:0] raddr1;
    wire [ADDR_WIDTH - 1:0] raddr2;
    wire [DATA_WIDTH - 1:0] rdata1;
    wire [DATA_WIDTH - 1:0] rdata2;

    wire                    idu_wen;        // 当前指令是否需要写GPR
    wire [DATA_WIDTH - 1:0] exu_wdata;
    wire [DATA_WIDTH - 1:0] lsu_loaddata;

    wire                    is_mem = is_lw | is_lbu | is_sw | is_sb;          

    IFU #(
        .PC_WIDTH(PC_WIDTH)
    ) u_IFU (
        .clk(clk),
        .rst(rst),
        .PCin(PCin),
        .is_mem(is_mem),
        .lsu_respValid(lsu_respValid),
        .ifu_respValid(ifu_respValid),

        .ifu_raddr(ifu_raddr),
        .PCout(PCout),
        .instr_valid(instr_valid),
        .instr_finish(instr_finish),
        .ifu_reqValid(ifu_reqValid)
    );

    IDU #(
        .INSTR_WIDTH(INSTR_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) u_IDU (
        .instr(instr),

        .idu_wen(idu_wen),
        .rd(waddr),
        .rs1(raddr1),
        .rs2(raddr2),
        .is_addi(is_addi),
        .is_jalr(is_jalr),
        .is_add(is_add),
        .is_lui(is_lui),
        .is_lw(is_lw),
        .is_sw(is_sw),
        .is_lbu(is_lbu),
        .is_sb(is_sb),
        .is_ebreak(is_ebreak),
        .immOut_I(imm_I),
        .immOut_S(imm_S),
        .immOut_U(imm_U)
    );

    RegisterFile #(
        .ADDR_WIDTH(ADDR_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) u_RegisterFile (
        .clk(clk),
        .wdata(wdata),
        .waddr(waddr),
        .wen(idu_wen && instr_finish),
        .raddr1(raddr1),
        .raddr2(raddr2),

        .rdata1(rdata1),
        .rdata2(rdata2),
        .a0(a0)
    );

    EXU #(
        .DATA_WIDTH(DATA_WIDTH)
    ) u_EXU (
        .PC(PCout),
        .is_jalr(is_jalr),
        .is_add(is_add),
        .is_lui(is_lui),
        .is_sw(is_sw),
        .is_sb(is_sb),
        .rdata1(rdata1),
        .rdata2(rdata2),
        .imm_I(imm_I),
        .imm_S(imm_S),
        .imm_U(imm_U),

        .wdata(exu_wdata),
        .jumpAddr(jumpAddr),
        .memAddr(lsu_addr)
    );

    WBU #(
        .PC_WIDTH(PC_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) u_WBU (
        .PC(PCout),
        .jumpAddr(jumpAddr),
        .exu_wdata(exu_wdata),
        .lsu_rdata(lsu_loaddata),
        .is_jalr(is_jalr),
        .is_lw(is_lw),
        .is_lbu(is_lbu),
        
        .nextPC(PCin),
        .rf_wdata(wdata)
    );

    LSU #(
        .DATA_WIDTH(DATA_WIDTH)
    ) u_LSU (
        .clk(clk),
        .rst(rst),
        .is_lw(is_lw),
        .is_sw(is_sw),
        .is_lbu(is_lbu),
        .is_sb(is_sb),
        .rdata2(rdata2),
        .instr_valid(instr_valid),
        .lsu_addr(lsu_addr),
        .lsu_rdata(lsu_rdata),
        .lsu_respValid(lsu_respValid),

        .lsu_wen(lsu_wen),
        .lsu_wdata(lsu_wdata),
        .lsu_wmask(lsu_wmask),
        .lsu_loaddata(lsu_loaddata),
        .lsu_reqValid(lsu_reqValid)
    );
endmodule
