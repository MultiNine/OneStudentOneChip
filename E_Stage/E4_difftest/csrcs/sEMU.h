#ifndef sEMU_H
#define sEMU_H

#include <stdint.h>

void ref_reset();
void ref_inst_cycle();
uint8_t* ref_get_regs();
uint8_t  ref_get_PC();

#endif