#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

#define MEM_BASE 0x80000000u
#define MEM_SIZE (128 * 1024 * 1024)

uint32_t PC = 0x80000000;
uint32_t R[16] = {
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000,
    0x00000000, 0x00000000, 0x00000000, 0x00000000
};
uint32_t M[MEM_SIZE / 4] = {0};

uint32_t PC_offset;
uint32_t insaddr;
uint32_t ins;

int inst_cycle(const uint32_t *dut_regs)
{
    R[0] = 0x00000000;
    PC_offset = PC - MEM_BASE;
    insaddr = PC_offset >> 2; 
    ins        = M[insaddr];  

    // printf("ref PC = 0x%08x | ref instr = 0x%08x\n", PC, ins);
    // printf("==============================================\n");

    /*
        binary |31   28|27   24|23   20|19   16|15   12|11    8|7   4|3   0|
        hex    |   7   |   6   |   5   |   4   |   3   |   2   |  1  |  0  |
    */
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
        if (rd != 0) R[rd] = R[rs1] + imm12_ext;
        PC = PC + 4;
    }
    if (is_jalr) {
        uint32_t jumpaddr = (imm12_ext + R[rs1]) & 0xfffffffe;
        if (rd != 0)  R[rd] = PC + 4;
        PC = jumpaddr;
    }
    if (is_add) {
        if (rd != 0)  R[rd] = R[rs1] + R[rs2];
        PC = PC + 4;
    }
    if (is_lui) {
        if (rd != 0)  R[rd] = (imm20 << 12);
        PC = PC + 4;
    }
    if (is_lw) {
        uint32_t loadaddr = R[rs1] + imm12_ext - MEM_BASE;
        if (rd != 0) {
            if ((R[rs1] + imm12_ext == 0x10000004u) ||
                (R[rs1] + imm12_ext == 0x20000000u) ||
                (R[rs1] + imm12_ext == 0x20000004u)) {
                R[rd] = dut_regs[rd];
            } else {
                R[rd] = M[loadaddr >> 2];
            }
        }
        PC = PC + 4;
    }
    if (is_sw) {
        uint32_t immsave = (imm7 << 5) | (imm5);
        uint32_t immsave_ext = (immsave >> 11) ? (immsave | 0xfffff000) : immsave;
        uint32_t saveaddr = R[rs1] + immsave_ext - MEM_BASE;
        if ((R[rs1] + immsave_ext) != 0x10000000) {  // 不写入UART时
            M[saveaddr >> 2] = R[rs2];  
        }
        PC = PC + 4;
    }
    if (is_lbu) {
        uint32_t loadaddr = R[rs1] + imm12_ext - MEM_BASE;
        uint32_t bytesel = loadaddr & 0x00000003;
        if (rd != 0) {
            if ((R[rs1] + imm12_ext == 0x10000004u) ||
                (R[rs1] + imm12_ext == 0x20000000u) ||
                (R[rs1] + imm12_ext == 0x20000004u)) {
                R[rd] = dut_regs[rd];
            } else {
                uint32_t loaddata = M[loadaddr >> 2] & (0x000000ff << (bytesel << 3));
                R[rd] = loaddata >> (bytesel << 3);
            }
        }
        PC = PC + 4;
    }
    if (is_sb) {
        uint32_t immsave = (imm7 << 5) | (imm5);
        uint32_t immsave_ext = (immsave >> 11) ? (immsave | 0xfffff000) : immsave;
        uint32_t saveaddr = R[rs1] + immsave_ext - MEM_BASE;
        uint32_t savedata = R[rs2] & 0x000000ff;
        uint32_t bytesel = saveaddr & 0x00000003;
        uint32_t mask = 0x000000ff << (bytesel << 3);
        uint32_t maskdata = savedata << (bytesel << 3);
        if ((R[rs1] + immsave_ext) != 0x10000000) {  // 不写入UART时
            M[saveaddr >> 2] = (M[saveaddr >> 2] & ~mask) | maskdata;
        }
        
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

void ref_inst_cycle(const uint32_t *dut_regs) {
    inst_cycle(dut_regs);
}

uint32_t* ref_get_regs()
{
    return R;
}

uint32_t ref_get_PC()
{
    return PC;
}

void ref_reset()
{
    PC = 0x80000000;
    for (int i = 0; i < 16; i++) {
        R[i] = 0;
    }
}

void ref_load_bin(const char *path) {
	FILE *fp = fopen(path, "rb");
	if (fp == NULL) {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }
	size_t bin_context = fread(M, 1, MEM_SIZE, fp);
}