#include "VtopNPC.h"
#include "verilated.h"
#include "verilated_fst_c.h"
#include "svdpi.h"
#include "VtopNPC__Dpi.h"
#include "minirvEMU.h"
#include "VtopNPC___024root.h"
#include "difftest.h"
//#include <sys/time.h>

#define MAX_SIM_CYCLES 10000000000ULL

#define ENABLE_DIFFTEST 0
#define ENABLE_WAVE 0
#define PMEM_SIZE (128 * 1024 * 1024)
#define NPC_FREQ_MHZ 353

extern uint32_t pmem[];

int return_flag = 1;
unsigned long long cycle_cnt;

VerilatedContext* contextp = new VerilatedContext;
VtopNPC* top = new VtopNPC(contextp);

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
    top->clock = 0;
    top->eval();

    if (!top->reset && !NPC_finished) {
    	// printf("dut PC = 0x%08x | dut instr = 0x%08x\n", top->PC, top->instr);
    }

	#if ENABLE_WAVE
    	tfp->dump(contextp->time());
	#endif

    contextp->timeInc(1);

    top->clock = 1;
    top->eval();

    #if ENABLE_WAVE
    	tfp->dump(contextp->time());
	#endif

    contextp->timeInc(1);
}

void dut_reset(int period) {
	top->reset = 0b1;
	for (int i = 0; i < period; i++) {
		dut_single_cycle();
	}
	top->reset = 0b0;
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

	#ifdef NETLIST_SIM
    	bool ebreak_fetched = false;
	#endif
	
	cycle_cnt = 0;
	int i = 0;
	load_bin(argv[1]);
	dut_reset(2);
	#if ENABLE_DIFFTEST
		uint32_t *dut_regs = &top->rootp->topNPC__DOT__NPC__DOT__u_RegisterFile__DOT__rf[0];
   		ref_load_bin(argv[1]);
   		ref_reset();
	#endif
	
  	while (!NPC_finished  && cycle_cnt < MAX_SIM_CYCLES) {
		#if ENABLE_DIFFTEST
			uint32_t last_PC = top->PC;
			uint32_t last_instr = top->instr;
		#endif
  	  	dut_single_cycle();
		cycle_cnt++;
		if (NPC_finished) {
    	    break;
    	}

		#ifdef NETLIST_SIM
    		if (top->netlist_ebreak_fetched) {
       			printf("[NETLIST] ebreak fetched at cycle %llu\n", cycle_cnt);
        		ebreak_fetched = true;
        		break;
    		}
		#endif

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
#ifdef NETLIST_SIM
    if (!ebreak_fetched) {
        fprintf(stderr, "[NETLIST] Timeout after %llu cycles\n", cycle_cnt);
        return_flag = 1;
    } else {
        printf("[NETLIST] ebreak fetched\n");
		return_flag = 0;
    }
#else
    if (!NPC_finished && cycle_cnt >= MAX_SIM_CYCLES) {
        fprintf(stderr, "[RTL] Simulation timeout\n");
        return_flag = 1;
    }
#endif

#ifdef NETLIST_SIM
    printf("[NETLIST] Cycles executed: %llu\n", cycle_cnt);
#else
	printf("Instructions executed: %llu\n", (unsigned long long)top->instr_cnt);
	printf("Cycles executed: %llu\n", cycle_cnt);
	printf("IPC of NPC: %.5f\n", (double)top->instr_cnt / cycle_cnt);
#endif

	top->final();
	#if ENABLE_WAVE
		tfp->close();
		delete tfp;
	#endif
	delete top;
	delete contextp;

	return return_flag;
}