// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VsvsimTestbench.h for the primary calling header

#ifndef VERILATED_VSVSIMTESTBENCH___024ROOT_H_
#define VERILATED_VSVSIMTESTBENCH___024ROOT_H_  // guard

#include "verilated.h"


class VsvsimTestbench__Syms;

class alignas(VL_CACHE_LINE_BYTES) VsvsimTestbench___024root final {
  public:

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*0:0*/ svsimTestbench__DOT__clock;
    ::CData/*0:0*/ svsimTestbench__DOT__reset;
    ::CData/*0:0*/ svsimTestbench__DOT__dut__DOT__blkReg;
    ::CData/*0:0*/ svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN;
    ::CData/*0:0*/ __Vdpi_export_trigger;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0;
    ::IData/*31:0*/ svsimTestbench__DOT__simulationState;
    ::IData/*31:0*/ svsimTestbench__DOT__traceSupported;
    ::IData/*31:0*/ svsimTestbench__DOT__dut__DOT__cntReg;
    ::IData/*31:0*/ __Vtrigprevexpr___TOP__svsimTestbench__DOT__simulationState__0;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VicoTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VactTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VnbaTriggered;
    ::VlUnpacked<::CData/*0:0*/, 2> __VtraceActivity;

    // INTERNAL VARIABLES
    VsvsimTestbench__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VsvsimTestbench___024root(VsvsimTestbench__Syms* symsp, const char* namep);
    ~VsvsimTestbench___024root();
    VL_UNCOPYABLE(VsvsimTestbench___024root);
    VL_UNMOVABLE(VsvsimTestbench___024root);

    // INTERNAL METHODS
};


#endif  // guard
