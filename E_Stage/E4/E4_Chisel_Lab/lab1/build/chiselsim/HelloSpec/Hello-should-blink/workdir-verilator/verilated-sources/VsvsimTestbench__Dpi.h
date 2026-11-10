// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Prototypes for DPI import and export functions.
//
// Verilator includes this file in all generated .cpp files that use DPI functions.
// Manually include this file where DPI .c import functions are declared to ensure
// the C functions match the expectations of the DPI imports.

#ifndef VERILATED_VSVSIMTESTBENCH__DPI_H_
#define VERILATED_VSVSIMTESTBENCH__DPI_H_  // guard

#include "svdpi.h"

#ifdef __cplusplus
extern "C" {
#endif


    // DPI EXPORTS
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:17:17
    extern void getBitWidthImpl_clock(int* value);
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:51:17
    extern void getBitWidthImpl_io_led(int* value);
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:34:17
    extern void getBitWidthImpl_reset(int* value);
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:27:17
    extern void getBitsImpl_clock(svBitVecVal* value_clock);
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:56:17
    extern void getBitsImpl_io_led(svBitVecVal* value_io_led);
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:44:17
    extern void getBitsImpl_reset(svBitVecVal* value_reset);
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:22:17
    extern void setBitsImpl_clock(const svBitVecVal* value_clock);
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:39:17
    extern void setBitsImpl_reset(const svBitVecVal* value_reset);
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:129:17
    extern void simulation_disableTrace(int* success);
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:114:17
    extern void simulation_enableTrace(int* success);
    // DPI export at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:90:17
    extern void simulation_initializeTrace(const char* traceFilePath);

    // DPI IMPORTS
    // DPI import at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:12:40
    extern void initTestBenchScope();
    // DPI import at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:84:32
    extern void run_simulation(int timesteps, int* done);
    // DPI import at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:62:31
    extern int simulation_body();
    // DPI import at /home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv:72:31
    extern int simulation_final();

#ifdef __cplusplus
}
#endif

#endif  // guard
