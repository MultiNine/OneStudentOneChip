#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"
#include "svdpi.h"
#include "Vtop__Dpi.h"
#include "minirvEMU.h"
#include "Vtop___024root.h"
#include "difftest.h"

#define PMEM_SIZE (128 * 1024 * 1024)
extern uint32_t pmem[];

int return_flag = 1;

VerilatedContext* contextp = new VerilatedContext;
Vtop* top = new Vtop(contextp);
VerilatedFstC* tfp = new VerilatedFstC;

static bool NPC_finished = false;
extern "C" void NPC_ebreak(int a0) {
    NPC_finished = true;
	if (a0 == 0) {
        printf("HIT GOOD TRAP\n");
		return_flag = 0;
    } else {
        printf("HIT BAD TRAP\n");
		return_flag = 1;
    }
}

void load_bin(const char* path) {
	FILE *fp = fopen(path, "rb");
	if (fp == NULL) {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }
	size_t bin_context = fread(pmem, 1, PMEM_SIZE, fp);
}

void dut_single_cycle() {
    top->clk = 0;
    top->eval();

    if (!top->rst && !NPC_finished) {
    	printf("dut PC = 0x%08x | dut instr = 0x%08x\n", top->PC, top->instr);
    }

    tfp->dump(contextp->time());
    contextp->timeInc(1);

    top->clk = 1;
    top->eval();

    tfp->dump(contextp->time());
    contextp->timeInc(1);
}

void dut_reset(int period) {
	top->rst = 0b1;
	for (int i = 0; i < period; i++) {
		dut_single_cycle();
	}
	top->rst = 0b0;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
    	fprintf(stderr, "Usage: %s <bin-file>\n", argv[0]);
    	return_flag = 1;
		return return_flag;
	}
	
	Verilated::traceEverOn(true);
	top->trace(tfp, 99);
	tfp->open("wave.fst");

	int i = 0;
	uint32_t *dut_regs = &top->rootp->top__DOT__u_RegisterFile__DOT__rf[0];
	load_bin(argv[1]);
	ref_load_bin(argv[1]);
	dut_reset(2);
	ref_reset();
	
  	while (!NPC_finished) {
  	  	top->eval();
  	  	dut_single_cycle();
		if (NPC_finished) {
    	    break;
    	}
    	if (!difftest_step(top->PC, dut_regs)) {	// 没有遇到ebreak再进行difftest
    	    return_flag = 1;
    	    break;
    	}
  	}

	top->final();
	tfp->close();
	delete tfp;
	delete top;
	delete contextp;

	return return_flag;
}