// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VpriEncode83.h for the primary calling header

#ifndef VERILATED_VPRIENCODE83___024ROOT_H_
#define VERILATED_VPRIENCODE83___024ROOT_H_  // guard

#include "verilated.h"


class VpriEncode83__Syms;

class alignas(VL_CACHE_LINE_BYTES) VpriEncode83___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN8(en,0,0);
            VL_IN8(x,7,0);
            VL_OUT8(validIn,0,0);
            VL_OUT8(y,2,0);
            VL_OUT8(segOut,7,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*3:0*/ __Vdfg_Regularize_26;
    ::CData/*3:0*/ __Vdfg_Regularize_27;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__en__0;
    ::CData/*7:0*/ __Vtrigprevexpr___TOP__x__0;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;

    // INTERNAL VARIABLES
    VpriEncode83__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VpriEncode83___024root(VpriEncode83__Syms* symsp, const char* namep);
    ~VpriEncode83___024root();
    VL_UNCOPYABLE(VpriEncode83___024root);
    VL_UNMOVABLE(VpriEncode83___024root);

    // INTERNAL METHODS
};


#endif  // guard
