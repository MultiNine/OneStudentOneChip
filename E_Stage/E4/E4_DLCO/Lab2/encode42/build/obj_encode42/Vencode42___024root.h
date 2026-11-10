// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vencode42.h for the primary calling header

#ifndef VERILATED_VENCODE42___024ROOT_H_
#define VERILATED_VENCODE42___024ROOT_H_  // guard

#include "verilated.h"


class Vencode42__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vencode42___024root final {
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
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;

    // INTERNAL VARIABLES
    Vencode42__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vencode42___024root(Vencode42__Syms* symsp, const char* namep);
    ~Vencode42___024root();
    VL_UNCOPYABLE(Vencode42___024root);
    VL_UNMOVABLE(Vencode42___024root);

    // INTERNAL METHODS
};


#endif  // guard
