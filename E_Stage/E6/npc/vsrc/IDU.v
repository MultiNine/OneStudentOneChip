module IDU #(INSTR_WIDTH = 32, 
             ADDR_WIDTH = 5) (
    input  [INSTR_WIDTH - 1:0] instr,
    output                     wen,
    output [ADDR_WIDTH - 1:0]  rd,
    output [ADDR_WIDTH - 1:0]  rs1,
    output [ADDR_WIDTH - 1:0]  rs2,
    output                     is_addi,
    output                     is_jalr,
    output                     is_add,
    output                     is_lui,
    output                     is_lw,
    output                     is_sw,
    output                     is_lbu,
    output                     is_sb,
    output                     is_ebreak,
    output [31:0]              immOut_I,
    output [31:0]              immOut_S,
    output [31:0]              immOut_U
);

    wire [6:0] opcode;
    wire [2:0] funct3;
    assign opcode = instr[6:0];
    assign funct3 = instr[14:12];

    assign is_addi   = (opcode == 7'b0010011) && (funct3 == 3'b000);
    assign is_jalr   = (opcode == 7'b1100111) && (funct3 == 3'b000);
    assign is_add    = (opcode == 7'b0110011) && (funct3 == 3'b000);
    assign is_lui    = (opcode == 7'b0110111);
    assign is_lw     =  (opcode == 7'b0000011) && (funct3 == 3'b010);
    assign is_sw     =  (opcode == 7'b0100011) && (funct3 == 3'b010);
    assign is_lbu    =  (opcode == 7'b0000011) && (funct3 == 3'b100);
    assign is_sb     =  (opcode == 7'b0100011) && (funct3 == 3'b000);
    assign is_ebreak =  (instr == 32'b000000000001_00000_000_00000_1110011);

    assign rd  = instr[10:7];
    assign rs1 = instr[18:15];
    assign rs2 = instr[23:20];
    assign wen = is_addi | is_jalr | is_add | is_lui | is_lw | is_lbu;

    wire [11:0] imm_I = instr[31:20];
    wire [11:0] imm_S = {instr[31:25], instr[11:7]};
    wire [19:0] imm_U = instr[31:12];
    assign immOut_I = {{20{imm_I[11]}}, imm_I};
    assign immOut_S = {{20{imm_S[11]}}, imm_S};
    assign immOut_U = {imm_U, 12'h000};
    
endmodule
