module NPC #(
    parameter PC_WIDTH    = 32,
    parameter INSTR_WIDTH = 32,
    parameter ADDR_WIDTH  = 4,
    parameter DATA_WIDTH  = 32
)(
    input                       clk,
    input                       rst,

    // Instruction memory
    output [PC_WIDTH - 1:0]     PC,
    input  [INSTR_WIDTH - 1:0]  instr,        

    // Data memory
    output [DATA_WIDTH - 1:0]  memAddr,      
    input  [DATA_WIDTH - 1:0]  dataFromMem,  
    output                     mem_ren,
    output                     mem_wen,
    output [DATA_WIDTH - 1:0]  mem_wdata,
    output [7:0]               mem_wmask,
    // Simulation status
    output                     is_ebreak,    
    output [DATA_WIDTH - 1:0]  a0
);

    wire [PC_WIDTH - 1:0] PCin;
    wire [PC_WIDTH - 1:0] PCout;
    assign PC = PCout;

    // 复位期间向IDU提供NOP
    wire [INSTR_WIDTH - 1:0] instr_decode;
    assign instr_decode = rst ? 32'h00000013 : instr;

    wire                    wen;
    wire [ADDR_WIDTH - 1:0] waddr;
    wire [DATA_WIDTH - 1:0] wdata;
    wire [ADDR_WIDTH - 1:0] raddr1;
    wire [ADDR_WIDTH - 1:0] raddr2;
    wire [DATA_WIDTH - 1:0] rdata1;
    wire [DATA_WIDTH - 1:0] rdata2;

    wire is_addi, is_jalr, is_add, is_lui,
         is_lw,   is_sw,   is_lbu, is_sb;
    wire [31:0] imm_I, imm_S, imm_U;
    wire [DATA_WIDTH - 1:0] jumpAddr;
    wire [DATA_WIDTH - 1:0] exu_wdata;
    wire [DATA_WIDTH - 1:0] lsu_rdata;

    IFU #(
        .PC_WIDTH(PC_WIDTH)
    ) u_IFU (
        .clk(clk),
        .rst(rst),
        .PCin(PCin),
        .PCout(PCout)
    );

    IDU #(
        .INSTR_WIDTH(INSTR_WIDTH),
        .ADDR_WIDTH(ADDR_WIDTH)
    ) u_IDU (
        .instr(instr_decode),
        .wen(wen),
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
        .wen(wen),
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
        .memAddr(memAddr)
    );

    WBU #(
        .PC_WIDTH(PC_WIDTH),
        .DATA_WIDTH(DATA_WIDTH)
    ) u_WBU (
        .PC(PCout),
        .jumpAddr(jumpAddr),
        .exu_wdata(exu_wdata),
        .lsu_rdata(lsu_rdata),
        .is_jalr(is_jalr),
        .is_lw(is_lw),
        .is_lbu(is_lbu),
        .nextPC(PCin),
        .rf_wdata(wdata)
    );

    LSU #(
        .DATA_WIDTH(DATA_WIDTH)
    ) u_LSU (
        .is_lw(is_lw),
        .is_sw(is_sw),
        .is_lbu(is_lbu),
        .is_sb(is_sb),
        .memAddr(memAddr),
        .rdata2(rdata2),
        .dataFromMem(dataFromMem),
        .ren(mem_ren),
        .wen(mem_wen),
        .wdata(mem_wdata),
        .wmask(mem_wmask),
        .lsu_data(lsu_rdata)
    );

endmodule