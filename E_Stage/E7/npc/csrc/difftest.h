#ifndef DIFFTEST_H
#define DIFFTEST_H

#include <stdint.h>

bool difftest_step(uint32_t dut_PC, const uint32_t *dut_regs);

#endif