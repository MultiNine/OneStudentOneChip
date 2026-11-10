// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VsCPU.h for the primary calling header

#ifndef VERILATED_VSCPU___024ROOT_H_
#define VERILATED_VSCPU___024ROOT_H_  // guard

#include "verilated.h"


class VsCPU__Syms;

class alignas(VL_CACHE_LINE_BYTES) VsCPU___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN8(clk,0,0);
            VL_IN8(rst,0,0);
            VL_IN8(datain,7,0);
            VL_OUT8(out_led,7,0);
            VL_OUT8(segh0,7,0);
            VL_OUT8(segh1,7,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*7:0*/ sCPU__DOT__out_seg;
    ::CData/*7:0*/ sCPU__DOT__u_insROM__DOT__ins;
    ::CData/*7:0*/ sCPU__DOT__u_PC__DOT__PCout;
    ::CData/*0:0*/ __Vdfg_Regularize_22;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    ::CData/*7:0*/ __Vtrigprevexpr___TOP__datain__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__rst__1;
    ::VlUnpacked<::CData/*7:0*/, 4> sCPU__DOT__u_GPR__DOT__gpr;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VactTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    VsCPU__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VsCPU___024root(VsCPU__Syms* symsp, const char* namep);
    ~VsCPU___024root();
    VL_UNCOPYABLE(VsCPU___024root);
    VL_UNMOVABLE(VsCPU___024root);

    // INTERNAL METHODS
};


#endif  // guard
