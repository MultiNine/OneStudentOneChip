// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VALU.h for the primary calling header

#ifndef VERILATED_VALU___024ROOT_H_
#define VERILATED_VALU___024ROOT_H_  // guard

#include "verilated.h"


class VALU__Syms;

class alignas(VL_CACHE_LINE_BYTES) VALU___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN8(A,3,0);
            VL_IN8(B,3,0);
            VL_IN8(aluop,2,0);
            VL_OUT8(out,3,0);
            VL_OUT8(carry,0,0);
            VL_OUT8(overflow,0,0);
            VL_OUT8(zero,0,0);
            VL_OUT8(segA,7,0);
            VL_OUT8(segB,7,0);
            VL_OUT8(segOut,7,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*3:0*/ ALU__DOT__u_addSub4bit__DOT__bin;
    ::CData/*3:0*/ __Vtrigprevexpr___TOP__A__0;
    ::CData/*3:0*/ __Vtrigprevexpr___TOP__B__0;
    ::CData/*2:0*/ __Vtrigprevexpr___TOP__aluop__0;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;

    // INTERNAL VARIABLES
    VALU__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VALU___024root(VALU__Syms* symsp, const char* namep);
    ~VALU___024root();
    VL_UNCOPYABLE(VALU___024root);
    VL_UNMOVABLE(VALU___024root);

    // INTERNAL METHODS
};


#endif  // guard
