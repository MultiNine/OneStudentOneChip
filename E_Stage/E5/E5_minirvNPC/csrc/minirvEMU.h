#ifndef minirvEMU_H
#define minirvEMU_H

#include <stdint.h>

void      ref_reset();
void      ref_inst_cycle();
uint32_t* ref_get_regs();
uint32_t  ref_get_PC();
void      ref_load_bin(const char *path);

#endif