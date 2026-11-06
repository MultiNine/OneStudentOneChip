#include <nvboard.h>
#include "VALU.h"

void nvboard_bind_all_pins(VALU* top) {
	nvboard_bind_pin( &top->A, 4, SW7, SW6, SW5, SW4);
	nvboard_bind_pin( &top->B, 4, SW3, SW2, SW1, SW0);
	nvboard_bind_pin( &top->aluop, 3, SW10, SW9, SW8);
	nvboard_bind_pin( &top->out, 4, LD3, LD2, LD1, LD0);
	nvboard_bind_pin( &top->carry, 1, LD4);
	nvboard_bind_pin( &top->overflow, 1, LD5);
	nvboard_bind_pin( &top->zero, 1, LD6);
	nvboard_bind_pin( &top->segA, 8, SEG2A, SEG2B, SEG2C, SEG2D, SEG2E, SEG2F, SEG2G, DEC2P);
	nvboard_bind_pin( &top->segB, 8, SEG1A, SEG1B, SEG1C, SEG1D, SEG1E, SEG1F, SEG1G, DEC1P);
	nvboard_bind_pin( &top->segOut, 8, SEG0A, SEG0B, SEG0C, SEG0D, SEG0E, SEG0F, SEG0G, DEC0P);
}
