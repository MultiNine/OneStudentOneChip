#include "verilated.h"
#include "verilated_fst_c.h"
#include "build/obj_priEncode83/VpriEncode83.h"

VerilatedContext* contextp = NULL;
VerilatedFstC* tfp = NULL;

static VpriEncode83* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedFstC;
  top = new VpriEncode83;
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

  top->en=0b0;
  for (int i = 0b0; i <= 0b11111111; i = i + 0b1) {
    top->x = i;
    step_and_dump_wave();
  }

  top->en=0b1;
  for (int i = 0b0; i <= 0b11111111; i = i + 0b1) {
    top->x = i;
    step_and_dump_wave();
  } 

  sim_exit();
}