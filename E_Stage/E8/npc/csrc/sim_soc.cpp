#include "VSimTop.h"
#include "verilated.h"
#include "VSimTop___024root.h"
#include "verilated_fst_c.h"
#include <nvboard.h>

#define ENABLE_NVBOARD 1
#define ENABLE_WAVE 1

#define CLOCK_RATIO 1	// cpuClock是clock的1倍频
unsigned long long soc_halfCycle_cnt = 0;
bool soc_level = false;	// SoC时钟电平

#define FLASH_SIZE (16 * 1024 * 1024)
uint32_t flash[FLASH_SIZE / 4];

VerilatedContext* contextp = new VerilatedContext;
VSimTop* top = new VSimTop(contextp);

#if ENABLE_WAVE
	VerilatedFstC* tfp = new VerilatedFstC;
#endif

static bool NPC_finished = false;
int return_flag = 1;
unsigned long long cycle_cnt;
unsigned long long instr_cnt;

extern "C" void flash_read(int32_t addr, int32_t *data) {
    *data = flash[addr >> 2];
}

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

#if ENABLE_NVBOARD
	void nvboard_bind_all_pins(VSimTop* top);
#endif

void load_bin(const char* path) {
	FILE *fp = fopen(path, "rb");
	if (fp == NULL) {
        perror("fopen failed");
        exit(EXIT_FAILURE);
    }
    size_t bin_context = fread(flash, 1, FLASH_SIZE, fp);
}

void drive_half_cycle(bool cpu_level) {
    top->cpuClock = cpu_level;
    top->clock = soc_level;
    top->eval();

#if ENABLE_WAVE
    if (!top->reset && cycle_cnt < 10000) {
        tfp->dump(contextp->time());
    }
#endif

    contextp->timeInc(1);

    soc_halfCycle_cnt++;

    if (soc_halfCycle_cnt == CLOCK_RATIO) {
        soc_halfCycle_cnt = 0;
        soc_level = !soc_level;
    }
}

void single_cycle() {
    drive_half_cycle(0);

    bool commit = top->rootp->SimTop__DOT__asic__DOT__soc__DOT__cpu__DOT__core0__DOT__instr_finish;
    bool ebreak = top->rootp->SimTop__DOT__asic__DOT__soc__DOT__cpu__DOT__core0__DOT__is_ebreak;
    uint32_t a0 = top->rootp->SimTop__DOT__asic__DOT__soc__DOT__cpu__DOT__core0__DOT__a0;

    drive_half_cycle(1);

    if (commit) {
        instr_cnt++;

        if (ebreak) {
            NPC_ebreak(a0);
        }
    }
}

void reset(int period) {
	top->reset = 0b1;
	for (int i = 0; i < period; i++) {
		single_cycle();
	}
	top->reset = 0b0;
}

int main(int argc, char *argv[]) {
	if (argc != 2) {
    	fprintf(stderr, "Usage: %s <bin-file>\n", argv[0]);
		return 1;
	}
	load_bin(argv[1]);

	#if ENABLE_WAVE
    	Verilated::traceEverOn(true);
		top->trace(tfp, 99);
		tfp->open("wave.fst");
	#endif

	#if ENABLE_NVBOARD
		nvboard_bind_all_pins(top);
		nvboard_init();
	#endif

    reset(200 * CLOCK_RATIO);
  	while (!NPC_finished) {
		#if ENABLE_NVBOARD
			nvboard_update();
		#endif
  	  	single_cycle(); 
		cycle_cnt++;
    }

	printf("Instructions executed: %llu\n", instr_cnt);
	printf("Cycles executed: %llu\n", cycle_cnt);
	printf("IPC of NPC: %.6f\n", (double)instr_cnt / cycle_cnt);

	top->final();
	#if ENABLE_WAVE
		tfp->close();
		delete tfp;
	#endif
	delete top;
	delete contextp;
	return return_flag;
}