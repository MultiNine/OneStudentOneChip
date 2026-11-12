#include "Vtop.h"
#include "verilated.h"
#include "verilated_fst_c.h"
#include "svdpi.h"
#include "Vtop__Dpi.h"

VerilatedContext* contextp = new VerilatedContext;
Vtop* top = new Vtop(contextp);
VerilatedFstC* tfp = new VerilatedFstC;

static bool NPC_finished = false;
extern "C" void NPC_ebreak() {
    NPC_finished = true;
}

void single_cycle() {
	top->clk = 0; top->eval();
    tfp->dump(contextp->time());
    contextp->timeInc(1);

    top->clk = 1; top->eval();
    tfp->dump(contextp->time());
    contextp->timeInc(1);
}

int main() {
	
	Verilated::traceEverOn(true);
	top->trace(tfp, 99);
	tfp->open("wave.fst");

	int i = 0;

  	while (!NPC_finished) {
  	  	top->eval();

		printf("=======================================================================\n");
		printf("PC = 0x%08x, instr = 0x%08x\n", top->PC, top->instr);
		printf("-----------------------------------------------------------------------\n");
		printf("M[12] = %08x, M[13] = %08x, M[14] = %08x, M[15] = %08x\n",
				pmem_read(0b110000), pmem_read(0b110100), pmem_read(0b111000), pmem_read(0b111100));
		printf("-----------------------------------------------------------------------\n");
		
  	  	single_cycle();
  	}

	top->final();
	tfp->close();
	delete tfp;
	delete top;
	delete contextp;

	return 0;
}