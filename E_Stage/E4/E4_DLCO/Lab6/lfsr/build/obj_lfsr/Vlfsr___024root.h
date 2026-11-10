// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vlfsr.h for the primary calling header

#ifndef VERILATED_VLFSR___024ROOT_H_
#define VERILATED_VLFSR___024ROOT_H_  // guard

#include "verilated.h"


class Vlfsr__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vlfsr___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN8(clk,0,0);
            VL_IN8(rst,0,0);
            VL_OUT8(dout,7,0);
            VL_OUT8(segout1,7,0);
            VL_OUT8(segout0,7,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*0:0*/ lfsr__DOT__feedback;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__rst__1;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VactTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vlfsr__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vlfsr___024root(Vlfsr__Syms* symsp, const char* namep);
    ~Vlfsr___024root();
    VL_UNCOPYABLE(Vlfsr___024root);
    VL_UNMOVABLE(Vlfsr___024root);

    // INTERNAL METHODS
};


#endif  // guard
