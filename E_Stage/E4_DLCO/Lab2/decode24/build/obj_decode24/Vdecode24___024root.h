// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vdecode24.h for the primary calling header

#ifndef VERILATED_VDECODE24___024ROOT_H_
#define VERILATED_VDECODE24___024ROOT_H_  // guard

#include "verilated.h"


class Vdecode24__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vdecode24___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN8(x,1,0);
            VL_IN8(en,0,0);
            VL_OUT8(y,3,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*1:0*/ __Vtrigprevexpr___TOP__x__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__en__0;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;

    // INTERNAL VARIABLES
    Vdecode24__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vdecode24___024root(Vdecode24__Syms* symsp, const char* namep);
    ~Vdecode24___024root();
    VL_UNCOPYABLE(Vdecode24___024root);
    VL_UNMOVABLE(Vdecode24___024root);

    // INTERNAL METHODS
};


#endif  // guard
