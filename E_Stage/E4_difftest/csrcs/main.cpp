#include "verilated.h"
#include "VsCPU.h"
#include "VsCPU___024root.h"
#include "sEMU.h"

VerilatedContext* contextp = NULL;
static VsCPU* top;

void step_and_eval() {
  	top->eval();
  	contextp->timeInc(1);
}

void dut_single_cycle() {
    top->clk = 0; step_and_eval();
    top->clk = 1; step_and_eval();
}

void dut_reset(int n) {
    top->rst = 1;
    while (n-- > 0) {
        dut_single_cycle();
    }
    top->rst = 0;
    step_and_eval();
}

void sim_init() {
  	contextp = new VerilatedContext;
  	top = new VsCPU;
}

int check_regs(const uint8_t* dut_regs, const uint8_t* ref_regs) {
	for (int i = 0; i < 4; i++) {
    	if (dut_regs[i] != ref_regs[i]) {
    	    printf("R[%d] different: DUT=0x%02x, REF=0x%02x\n",
    	           i, dut_regs[i], ref_regs[i]);
    	    return 1;
		}
	}
	return 0;
}

int check_PC(const uint8_t dut_PC, const uint8_t ref_PC) {
	if (dut_PC != ref_PC) {
		return 1;
	}
	return 0;
}

int main() 
{
	sim_init();
	dut_reset(10);
	ref_reset();

	int i = 0;
	uint8_t *dut_regs = &top->rootp->sCPU__DOT__u_GPR__DOT__gpr[0];
  	while (i < 64) {
		uint8_t current_PC = ref_get_PC();	// 当前PC，用于定位出错指令位置
		i++;
  		dut_single_cycle();
  		ref_inst_cycle();

		// 执行后的PC，用于比较状态
		uint8_t  dut_PC = top->rootp->sCPU__DOT__u_PC__DOT__PCout;
		uint8_t  ref_PC = ref_get_PC(); 
  		uint8_t* ref_regs = ref_get_regs();
  		int is_diff_regs = check_regs(dut_regs, ref_regs);
		int is_diff_PC = check_PC(dut_PC, ref_PC);

  		if (is_diff_regs) {
			printf("Error at PC: 0x%02x\n", current_PC);
    		printf("Simulation stop\n");
    		break;
  		}
		if (is_diff_PC) {
			printf("Error at PC: 0x%02x\n", current_PC);
			printf("PC different: DUT=0x%02x, REF=0x%02x\n",
					dut_PC, ref_PC);
    		printf("Simulation stop\n");
    		break;
		}
	}

	uint8_t* ref_regs = ref_get_regs();
	printf("Difftest PASS!\n");
	for (int i = 0; i < 4; i++) {
    	printf("DUT R[%d] = 0x%02x | REF R[%d] = 0x%02x\n",
			   i, dut_regs[i], i, ref_regs[i]);
	}

	return 0;
}