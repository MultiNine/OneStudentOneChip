#include <stdint.h>
#include <stdio.h>

uint32_t PC = 0;
uint32_t R[16] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000
};
uint32_t M[16] = {
    0x03c00513, 0x00052583, 0x09000613, 0x00c501a3,
    0x0ab00613, 0x00c50123, 0x0cd00613, 0x00c500a3,
    0x0ef00613, 0x00c50023, 0x00052683, 0x00100073,
    0x00000000, 0x00000000, 0x00000000, 0x12345678 
};

int inst_cycle()
{
    R[0] = 0x00000000;
    uint32_t insaddr = PC >> 2;

    /*
        binary |31   28|27   24|23   20|19   16|15   12|11    8|7   4|3   0|
        hex    |   7   |   6   |   5   |   4   |   3   |   2   |  1  |  0  |
    */
    uint32_t ins        = M[insaddr];
    uint32_t opcode     = (ins & 0x0000007f) >> 0;  // 0000_0000_0000_0000_0000_0000_0111_1111
    uint32_t funct3     = (ins & 0x00007000) >> 12; // 0000_0000_0000_0000_0111_0000_0000_0000
    uint32_t rs1        = (ins & 0x000f8000) >> 15; // 0000_0000_0000_1111_1000_0000_0000_0000
    uint32_t rs2        = (ins & 0x01f00000) >> 20; // 0000_0001_1111_0000_0000_0000_0000_0000
    uint32_t rd         = (ins & 0x00000f80) >> 7;  // 0000_0000_0000_0000_0000_1111_1000_0000
    uint32_t imm12      = (ins & 0xfff00000) >> 20; // 1111_1111_1111_0000_0000_0000_0000_0000 
    uint32_t imm12_ext  = (imm12 >> 11) ? (imm12 | 0xfffff000) : imm12;
    uint32_t imm20      = (ins & 0xfffff000) >> 12; // 1111_1111_1111_1111_1111_0000_0000_0000
    uint32_t imm7       = (ins & 0xfe000000) >> 25; // 1111_1110_0000_0000_0000_0000_0000_0000
    uint32_t imm5       = (ins & 0x00000f80) >> 7;  // 0000_0000_0000_0000_0000_1111_1000_0000

    printf("PC = %08x, instr = %08x\n", PC, ins);

    uint32_t is_addi   = (opcode == 0b0010011) && (funct3 == 0b000);
    uint32_t is_jalr   = (opcode == 0b1100111) && (funct3 == 0b000);
    uint32_t is_add    = (opcode == 0b0110011) && (funct3 == 0b000);
    uint32_t is_lui    = (opcode == 0b0110111);
    uint32_t is_lw     = (opcode == 0b0000011) && (funct3 == 0b010);
    uint32_t is_lbu    = (opcode == 0b0000011) && (funct3 == 0b100);
    uint32_t is_sw     = (opcode == 0b0100011) && (funct3 == 0b010);
    uint32_t is_sb     = (opcode == 0b0100011) && (funct3 == 0b000);
    uint32_t is_ebreak = (ins == 0x00100073);

    if (is_addi) {
        R[rd] = R[rs1] + imm12_ext;
        PC = PC + 4;
    }
    if (is_jalr) {
        uint32_t jumpaddr = (imm12_ext + R[rs1]) & 0xfffffffe;
        R[rd] = PC + 4;
        PC = jumpaddr;
    }
    if (is_add) {
        R[rd] = R[rs1] + R[rs2];
        PC = PC + 4;
    }
    if (is_lui) {
        R[rd] = (imm20 << 12);
        PC = PC + 4;
    }
    if (is_lw) {
        uint32_t loadaddr = R[rs1] + imm12_ext;
        R[rd] = M[loadaddr >> 2];
        PC = PC + 4;
    }
    if (is_sw) {
        uint32_t immsave = (imm7 << 5) | (imm5);
        uint32_t immsave_ext = (immsave >> 11) ? (immsave | 0xfffff000) : immsave;
        uint32_t saveaddr = R[rs1] + immsave_ext;
        M[saveaddr >> 2] = R[rs2];
        PC = PC + 4;
    }
    if (is_lbu) {
        uint32_t loadaddr = R[rs1] + imm12_ext;
        uint32_t bytesel = loadaddr & 0x00000003;
        uint32_t loaddata = M[loadaddr >> 2] & (0x000000ff << (bytesel << 3));
        R[rd] = loaddata >> (bytesel << 3);
        PC = PC + 4;
    }
    if (is_sb) {
        uint32_t immsave = (imm7 << 5) | (imm5);
        uint32_t immsave_ext = (immsave >> 11) ? (immsave | 0xfffff000) : immsave;
        uint32_t saveaddr = R[rs1] + immsave_ext;
        uint32_t savedata = R[rs2] & 0x000000ff;
        uint32_t bytesel = saveaddr & 0x00000003;
        uint32_t mask = 0x000000ff << (bytesel << 3);
        uint32_t maskdata = savedata << (bytesel << 3);
        M[saveaddr >> 2] = (M[saveaddr >> 2] & ~mask) | maskdata;
        PC = PC + 4;
    }
    if (is_ebreak) {
        R[0] = 0x00000000;

        printf("-----------------------------------------------------------------------\n");
        printf("Receive ebreak, terminate program.\n");
        printf("R[0]  = %08x, R[1]  = %08x, R[2]  = %08x, R[3]  = %08x\n", 
            R[0], R[1], R[2], R[3]);
        printf("R[4]  = %08x, R[5]  = %08x, R[6]  = %08x, R[7]  = %08x\n", 
                R[4], R[5], R[6], R[7]);
        printf("R[8]  = %08x, R[9]  = %08x, R[10] = %08x, R[11] = %08x\n", 
                R[8], R[9], R[10], R[11]);
        printf("R[12] = %08x, R[13] = %08x, R[14] = %08x, R[15] = %08x\n", 
                R[12], R[13], R[14], R[15]);
        printf("-----------------------------------------------------------------------\n");
        printf("M[12] = %08x, M[13] = %08x, M[14] = %08x, M[15] = %08x\n", 
                M[12], M[13], M[14], M[15]);
        printf("=======================================================================\n");
        
        return 0;
    }
    return 1;
}

int main()
{
    while (inst_cycle()) { 

    }

    return 0;
}