// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Implementation of DPI export functions
//
// Verilator compiles this file in when DPI functions are used.
// If you have multiple Verilated designs with the same DPI exported
// function names, you will get multiple definition link errors from here.
// This is an unfortunate result of the DPI specification.
// To solve this, either
//    1. Call VsvsimTestbench::{export_function} instead,
//       and do not even bother to compile this file
// or 2. Compile all __Dpi.cpp files in the same compiler run,
//       and #ifdefs already inserted here will sort everything out.

#include "VsvsimTestbench__Dpi.h"
#include "VsvsimTestbench.h"

#ifndef VL_DPIDECL_getBitWidthImpl_clock_
#define VL_DPIDECL_getBitWidthImpl_clock_
void getBitWidthImpl_clock(int* value) {
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:17:17
    return VsvsimTestbench::getBitWidthImpl_clock(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidthImpl_io_led_
#define VL_DPIDECL_getBitWidthImpl_io_led_
void getBitWidthImpl_io_led(int* value) {
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:51:17
    return VsvsimTestbench::getBitWidthImpl_io_led(value);
}
#endif

#ifndef VL_DPIDECL_getBitWidthImpl_reset_
#define VL_DPIDECL_getBitWidthImpl_reset_
void getBitWidthImpl_reset(int* value) {
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:34:17
    return VsvsimTestbench::getBitWidthImpl_reset(value);
}
#endif

#ifndef VL_DPIDECL_getBitsImpl_clock_
#define VL_DPIDECL_getBitsImpl_clock_
void getBitsImpl_clock(svBitVecVal* value_clock) {
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:27:17
    return VsvsimTestbench::getBitsImpl_clock(value_clock);
}
#endif

#ifndef VL_DPIDECL_getBitsImpl_io_led_
#define VL_DPIDECL_getBitsImpl_io_led_
void getBitsImpl_io_led(svBitVecVal* value_io_led) {
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:56:17
    return VsvsimTestbench::getBitsImpl_io_led(value_io_led);
}
#endif

#ifndef VL_DPIDECL_getBitsImpl_reset_
#define VL_DPIDECL_getBitsImpl_reset_
void getBitsImpl_reset(svBitVecVal* value_reset) {
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:44:17
    return VsvsimTestbench::getBitsImpl_reset(value_reset);
}
#endif

#ifndef VL_DPIDECL_setBitsImpl_clock_
#define VL_DPIDECL_setBitsImpl_clock_
void setBitsImpl_clock(const svBitVecVal* value_clock) {
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:22:17
    return VsvsimTestbench::setBitsImpl_clock(value_clock);
}
#endif

#ifndef VL_DPIDECL_setBitsImpl_reset_
#define VL_DPIDECL_setBitsImpl_reset_
void setBitsImpl_reset(const svBitVecVal* value_reset) {
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:39:17
    return VsvsimTestbench::setBitsImpl_reset(value_reset);
}
#endif

#ifndef VL_DPIDECL_simulation_disableTrace_
#define VL_DPIDECL_simulation_disableTrace_
void simulation_disableTrace(int* success) {
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:129:17
    return VsvsimTestbench::simulation_disableTrace(success);
}
#endif

#ifndef VL_DPIDECL_simulation_enableTrace_
#define VL_DPIDECL_simulation_enableTrace_
void simulation_enableTrace(int* success) {
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:114:17
    return VsvsimTestbench::simulation_enableTrace(success);
}
#endif

#ifndef VL_DPIDECL_simulation_initializeTrace_
#define VL_DPIDECL_simulation_initializeTrace_
void simulation_initializeTrace(const char* traceFilePath) {
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:90:17
    return VsvsimTestbench::simulation_initializeTrace(traceFilePath);
}
#endif

