// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VpriEncode42.h for the primary calling header

#ifndef VERILATED_VPRIENCODE42___024ROOT_H_
#define VERILATED_VPRIENCODE42___024ROOT_H_  // guard

#include "verilated.h"


class VpriEncode42__Syms;

class alignas(VL_CACHE_LINE_BYTES) VpriEncode42___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN8(x,3,0);
            VL_IN8(en,0,0);
            VL_OUT8(y,1,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*3:0*/ __Vtrigprevexpr___TOP__x__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__en__0;
    ::IData/*31:0*/ priEncode42__DOT__i;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;

    // INTERNAL VARIABLES
    VpriEncode42__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VpriEncode42___024root(VpriEncode42__Syms* symsp, const char* namep);
    ~VpriEncode42___024root();
    VL_UNCOPYABLE(VpriEncode42___024root);
    VL_UNMOVABLE(VpriEncode42___024root);

    // INTERNAL METHODS
};


#endif  // guard
