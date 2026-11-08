#include <nvboard.h>
#include "VsCPU.h"

void nvboard_bind_all_pins(VsCPU* top) {
	nvboard_bind_pin( &top->rst, 1, BTNC);
	nvboard_bind_pin( &top->datain, 8, SW7, SW6, SW5, SW4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->segh0, 8, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G, DEC0P);
	nvboard_bind_pin( &top->segh1, 8, SEG1A, SEG1B, SEG1C, SEG1D, SEG1E, SEG1F, SEG1G, DEC1P);
	nvboard_bind_pin( &top->out_led, 8, LD7, LD6, LD5, LD4, LD3, LD2, LD1, LD0);
}
