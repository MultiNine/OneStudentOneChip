#include "verilated.h"
#include "verilated_fst_c.h"
#include "build/obj_priEncode42/VpriEncode42.h"

VerilatedContext* contextp = NULL;
VerilatedFstC* tfp = NULL;

static VpriEncode42* top;

void step_and_dump_wave(){
  top->eval();
  contextp->timeInc(1);
  tfp->dump(contextp->time());
}
void sim_init(){
  contextp = new VerilatedContext;
  tfp = new VerilatedFstC;
  top = new VpriEncode42;
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

  top->en=0b0; top->x =0b0000; step_and_dump_wave();
               top->x =0b0001; step_and_dump_wave();
               top->x =0b0010; step_and_dump_wave();
               top->x =0b0011; step_and_dump_wave();
               top->x =0b0100; step_and_dump_wave();
               top->x =0b0101; step_and_dump_wave();
               top->x =0b0110; step_and_dump_wave();
               top->x =0b0111; step_and_dump_wave();
               top->x =0b1000; step_and_dump_wave();
               top->x =0b1001; step_and_dump_wave();
               top->x =0b1010; step_and_dump_wave();
               top->x =0b1011; step_and_dump_wave();
               top->x =0b1100; step_and_dump_wave();
               top->x =0b1101; step_and_dump_wave();
               top->x =0b1110; step_and_dump_wave();
               top->x =0b1111; step_and_dump_wave();
  top->en=0b1; top->x =0b0000; step_and_dump_wave();
               top->x =0b0001; step_and_dump_wave();
               top->x =0b0010; step_and_dump_wave();               
               top->x =0b0011; step_and_dump_wave();               
               top->x =0b0100; step_and_dump_wave();                              
               top->x =0b0101; step_and_dump_wave();            
               top->x =0b0110; step_and_dump_wave();
               top->x =0b0111; step_and_dump_wave();
               top->x =0b1000; step_and_dump_wave();
               top->x =0b1001; step_and_dump_wave();
               top->x =0b1010; step_and_dump_wave();
               top->x =0b1011; step_and_dump_wave();
               top->x =0b1100; step_and_dump_wave();
               top->x =0b1101; step_and_dump_wave();
               top->x =0b1110; step_and_dump_wave();
               top->x =0b1111; step_and_dump_wave();

  sim_exit();
}