#include "stdio.h"
#include "difftest.h"
#include "minirvEMU.h"

int check_regs(const uint32_t* dut_regs, const uint32_t* ref_regs) {
	for (int i = 0; i < 16; i++) {
    	if (dut_regs[i] != ref_regs[i]) {
    	    printf("R[%d] different: DUT=0x%02x, REF=0x%02x\n",
    	           i, dut_regs[i], ref_regs[i]);
    	    return 1;
		}
	}
	return 0;
}

int check_PC(const uint32_t dut_PC, const uint32_t ref_PC) {
	if (dut_PC != ref_PC) {
		return 1;
	}
	return 0;
}

bool difftest_step(uint32_t dut_PC, const uint32_t *dut_regs) {
	uint32_t  current_PC = ref_get_PC();     // 当前PC，用于定位出错指令位置
    ref_inst_cycle();
    // 执行后的PC，用于比较状态
	uint32_t  ref_PC   = ref_get_PC();
  	uint32_t* ref_regs = ref_get_regs();

  	int is_diff_regs = check_regs(dut_regs, ref_regs);
	int is_diff_PC   = check_PC(dut_PC, ref_PC);
  	if (is_diff_regs) {
		printf("Error at PC: 0x%02x\n", current_PC);
    	printf("Simulation stop\n");
    	return false;
  	}
	if (is_diff_PC) {
		printf("Error at PC: 0x%02x\n", current_PC);
		printf("PC different: DUT=0x%02x, REF=0x%02x\n",
				dut_PC, ref_PC);
    	printf("Simulation stop\n");
    	return false;
	}
    return true;
}