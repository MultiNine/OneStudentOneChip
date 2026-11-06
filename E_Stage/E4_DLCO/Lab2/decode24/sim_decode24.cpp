#include "verilated.h"
#include "verilated_fst_c.h"
#include "build/obj_decode24/Vdecode24.h"

VerilatedContext* contextp = NULL;
VerilatedFstC* tfp = NULL;

static Vdecode24* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedFstC;
  top = new Vdecode24;
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

  top->en = 0b0;  top->x = 0b00;  step_and_dump_wave();
                  top->x = 0b01;  step_and_dump_wave();
                  top->x = 0b10;  step_and_dump_wave();
                  top->x = 0b11;  step_and_dump_wave();
  top->en = 0b1;  top->x = 0b00;  step_and_dump_wave();
                  top->x = 0b01;  step_and_dump_wave();
                  top->x = 0b10;  step_and_dump_wave();
                  top->x = 0b11;  step_and_dump_wave();
  sim_exit();
}