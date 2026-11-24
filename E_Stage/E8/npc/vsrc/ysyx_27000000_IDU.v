module ysyx_27000000_IDU (
    input  [31:0] instr,
    
    output        idu_wen,
    output [ 4:0] rd,
    output [ 4:0] rs1,
    output [ 4:0] rs2,
    output        is_jalr,
    output        is_add,
    output        is_lui,
    output        is_lw,
    output        is_sw,
    output        is_lbu,
    output        is_sb,
    output        is_ebreak,
    output        is_csrrs,
    output [31:0] immOut_I,
    output [31:0] immOut_S,
    output [31:0] immOut_U,
    output [11:0] csr_addr
);
    wire [6:0] opcode;
    wire [2:0] funct3;
    assign opcode = instr[6:0];
    assign funct3 = instr[14:12];

    wire is_addi;
    assign is_addi   = (opcode == 7'b0010011) && (funct3 == 3'b000);
    assign is_jalr   = (opcode == 7'b1100111) && (funct3 == 3'b000);
    assign is_add    = (opcode == 7'b0110011) && (funct3 == 3'b000);
    assign is_lui    = (opcode == 7'b0110111);
    assign is_lw     = (opcode == 7'b0000011) && (funct3 == 3'b010);
    assign is_sw     = (opcode == 7'b0100011) && (funct3 == 3'b010);
    assign is_lbu    = (opcode == 7'b0000011) && (funct3 == 3'b100);
    assign is_sb     = (opcode == 7'b0100011) && (funct3 == 3'b000);
    assign is_ebreak = (instr == 32'b000000000001_00000_000_00000_1110011);
    assign is_csrrs  = (opcode == 7'b1110011) && (funct3 == 3'b010);

    assign rd  = instr[11: 7];
    assign rs1 = instr[19:15];
    assign rs2 = instr[24:20];
    assign idu_wen = is_addi | is_jalr | is_add | is_lui | is_lw | is_lbu | is_csrrs;

    wire [11:0] imm_I = instr[31:20];
    wire [11:0] imm_S = {instr[31:25], instr[11:7]};
    wire [19:0] imm_U = instr[31:12];
    assign immOut_I = {{20{imm_I[11]}}, imm_I};
    assign immOut_S = {{20{imm_S[11]}}, imm_S};
    assign immOut_U = {imm_U, 12'h000};
    assign csr_addr = instr[31:20];
endmodule
