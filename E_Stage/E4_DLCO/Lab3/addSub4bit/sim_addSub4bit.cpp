#include "verilated.h"
#include "verilated_fst_c.h"
#include "build/obj_addSub4bit/VaddSub4bit.h"

VerilatedContext* contextp = NULL;
VerilatedFstC* tfp = NULL;

static VaddSub4bit* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedFstC;
  top = new VaddSub4bit;
  contextp->traceEverOn(true);
  top->trace(tfp, 0);
  tfp->open("wave.fst");
}

void sim_exit(){
  step_and_dump_wave();
  tfp->close();
}

int main() {
  sim_init();

  // -8 - 1
  top->a = 0b1000;
  top->b = 0b0001; 
  top->ctrl = 0b1;
  step_and_dump_wave();

  // -8 - 1
  top->a = 0b1000;
  top->b = 0b0001; 
  top->ctrl = 0b1;
  step_and_dump_wave();

  // 0 - (-8)
  top->a = 0b0000;
  top->b = 0b1000; 
  top->ctrl = 0b1;
  step_and_dump_wave();

    // -8 - (-8)
  top->a = 0b1000;
  top->b = 0b1000; 
  top->ctrl = 0b1;
  step_and_dump_wave();

  sim_exit();
}