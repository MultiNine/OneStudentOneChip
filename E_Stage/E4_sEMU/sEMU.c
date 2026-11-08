#include <stdint.h>
#include <stdio.h>

uint8_t PC = 0;
uint8_t R[4];
uint8_t M[16] = {
    0x86, 0x92, 0x01, 0x90,
    0xa0, 0xb1, 0x17, 0x29,
    0xf9, 0xc3, 0x00, 0x00,
    0x00, 0x00, 0x00, 0x00
};

void inst_cycle()
{
    uint8_t ins       = M[PC];
    uint8_t opcode    = ((ins & 0b11000000) >> 6);
    uint8_t ins_add   = (opcode == 0b00) ? 0b1 : 0b0;
    uint8_t ins_io    = (opcode == 0b01) ? 0b1 : 0b0;
    uint8_t ins_li    = (opcode == 0b10) ? 0b1 : 0b0;
    uint8_t ins_bner0 = (opcode == 0b11) ? 0b1 : 0b0;
    uint8_t offset;
    printf("PC=%02x, ins=%02x, opcode=%u\n", PC, ins, opcode);

    if (ins_add) {
        uint8_t rd  = (ins & 0b00110000) >> 4;
        uint8_t rs1 = (ins & 0b00001100) >> 2;
        uint8_t rs2 = (ins & 0b00000011);
        R[rd] = R[rs1] + R[rs2];
    }
    if (ins_li) {
        uint8_t rd  = (ins & 0b00110000) >> 4;
        uint8_t imm = (ins & 0b00000011);
        uint8_t s   = (ins & 0b00001100) >> 2;
        R[rd] = imm << (s << 1);
    }
    if (ins_io) {
        // do nothing.
    }
    if (ins_bner0) {
        uint8_t rs2 = (ins & 0b00000011);
        if (R[0] != R[rs2]) {
            offset = (ins & 0b00111100) >> 2;
            uint8_t sign = (offset & 0b00001000) >> 3;
            if (sign == 0b1) offset = offset | 0b11110000;
            else offset = offset | 0b00000000;
        } else {
            offset = 0b1;
        }
    }

    printf("R[0] = %02x, R[1] = %02x, R[2] = %02x, R[3] = %02x\n==========================================\n",
            R[0], R[1], R[2], R[3]);

    uint8_t PCadd = ins_bner0 ? offset : 1;
    PC += PCadd;
} 

int main()
{
    int i = 0;
    while (i < 64) { 
        inst_cycle();
        i++;
    }

    return 0;
}