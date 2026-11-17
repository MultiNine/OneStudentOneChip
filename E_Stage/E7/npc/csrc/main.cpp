#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"
#include "svdpi.h"
#include "Vtop__Dpi.h"
#include "minirvEMU.h"
#include "Vtop___024root.h"
#include "difftest.h"
//#include <sys/time.h>

#define ENABLE_DIFFTEST 0
#define ENABLE_WAVE 0
#define PMEM_SIZE (128 * 1024 * 1024)
#define NPC_FREQ_MHZ 416

extern uint32_t pmem[];

int return_flag = 1;
unsigned long long cycle_cnt;

VerilatedContext* contextp = new VerilatedContext;
Vtop* top = new Vtop(contextp);

#if ENABLE_WAVE
	VerilatedFstC* tfp = new VerilatedFstC;
#endif

unsigned long long get_time() {
  	return (cycle_cnt / NPC_FREQ_MHZ);
}

static bool NPC_finished  = false;
static bool NPC_committed = false;
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
extern "C" void NPC_commit() {
    NPC_committed = true;
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
	NPC_committed = false;
    top->clk = 0;
    top->eval();

    if (!top->rst && !NPC_finished) {
    	// printf("dut PC = 0x%08x | dut instr = 0x%08x\n", top->PC, top->instr);
    }

	#if ENABLE_WAVE
    	tfp->dump(contextp->time());
	#endif

    contextp->timeInc(1);

    top->clk = 1;
    top->eval();

    #if ENABLE_WAVE
    	tfp->dump(contextp->time());
	#endif

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

	#if ENABLE_WAVE
    	Verilated::traceEverOn(true);
		top->trace(tfp, 99);
		tfp->open("wave.fst");
	#endif
	
	cycle_cnt = 0;
	int i = 0;
	load_bin(argv[1]);
	dut_reset(2);
	#if ENABLE_DIFFTEST
		uint32_t *dut_regs = &top->rootp->top__DOT__u_NPC__DOT__u_RegisterFile__DOT__rf[0];
   		ref_load_bin(argv[1]);
   		ref_reset();
	#endif
	
  	while (!NPC_finished) {
		#if ENABLE_DIFFTEST
			uint32_t last_PC = top->PC;
			uint32_t last_instr = top->instr;
		#endif
  	  	dut_single_cycle();
		cycle_cnt++;
		if (NPC_finished) {
    	    break;
    	}
		#if ENABLE_DIFFTEST
			// 没有遇到ebreak且NPC执行一条指令后再进行difftest
			if (NPC_committed) {
				printf("[DiffTest] cycle: %llu, instr NO.%llu\n", 
						cycle_cnt, (unsigned long long)top->instr_cnt);
				printf("[DiffTest] PC = 0x%08x, instr = 0x%08x\n", last_PC, last_instr);
				printf("===============================================\n");
				if (!difftest_step(top->PC, dut_regs)) {	
    				return_flag = 1;
    		    	break;
    			}
			}
		#endif
  	}

	printf("Instructions executed: %llu\n", (unsigned long long)top->instr_cnt);
	printf("Cycles executed: %llu\n", cycle_cnt);
	printf("IPC of NPC: %.5f\n", (double)top->instr_cnt / cycle_cnt);

	top->final();
	#if ENABLE_WAVE
		tfp->close();
		delete tfp;
	#endif
	delete top;
	delete contextp;

	return return_flag;
}