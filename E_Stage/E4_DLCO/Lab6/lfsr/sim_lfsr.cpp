#include "verilated.h"
#include "verilated_fst_c.h"
#include "build/obj_lfsr/Vlfsr.h"

VerilatedContext* contextp = NULL;
VerilatedFstC* tfp = NULL;

static Vlfsr* top;

void step_and_dump_wave(){
  	top->eval();
  	contextp->timeInc(1);
  	tfp->dump(contextp->time());
}

static void single_cycle() {
    top->clk = 0; step_and_dump_wave();
    top->clk = 1; step_and_dump_wave();
}

static void reset(int n) {
   	top->rst = 1;
	step_and_dump_wave();

   	while (n -- > 0) single_cycle();
   	top->rst = 0;
	step_and_dump_wave();
}

void sim_init(){
  	contextp = new VerilatedContext;
  	tfp = new VerilatedFstC;
  	top = new Vlfsr;
  	contextp->traceEverOn(true);
  	top->trace(tfp, 0);
  	tfp->open("wave.fst");
}

void sim_exit(){
  	step_and_dump_wave();
  	tfp->close();
}

int main() {
	int outval0[255] = {0};
	int outval1[255] = {0};
	bool pass = true;

  	sim_init();
	
  	reset(10);
	for(int i = 0; i < 255; i++) {
		single_cycle();
		step_and_dump_wave();
		outval0[i] = top->dout;
	}
	for(int i = 0; i < 255; i++) {
		single_cycle();
		step_and_dump_wave();
		outval1[i] = top->dout;
	}

	for(int i = 0; i < 255; i++) {
		if(outval0[i] != outval1[i]) {
   			printf("Mismatch at %d: %02x != %02x\n", i, outval0[i], outval1[i]);
			pass = false;
		}
	}
	if (pass) printf("PASS\n");

  	sim_exit();
}	