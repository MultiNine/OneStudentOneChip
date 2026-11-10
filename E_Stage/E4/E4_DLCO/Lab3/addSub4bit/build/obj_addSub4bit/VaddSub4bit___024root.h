// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See VaddSub4bit.h for the primary calling header

#ifndef VERILATED_VADDSUB4BIT___024ROOT_H_
#define VERILATED_VADDSUB4BIT___024ROOT_H_  // guard

#include "verilated.h"


class VaddSub4bit__Syms;

class alignas(VL_CACHE_LINE_BYTES) VaddSub4bit___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN8(a,3,0);
            VL_IN8(b,3,0);
            VL_IN8(ctrl,0,0);
            VL_OUT8(carry,0,0);
            VL_OUT8(zero,0,0);
            VL_OUT8(overflow,0,0);
            VL_OUT8(result,3,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*3:0*/ addSub4bit__DOT__bin;
    ::CData/*4:0*/ addSub4bit__DOT__c_r;
    ::CData/*3:0*/ __Vtrigprevexpr___TOP__a__0;
    ::CData/*3:0*/ __Vtrigprevexpr___TOP__b__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__ctrl__0;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;

    // INTERNAL VARIABLES
    VaddSub4bit__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    VaddSub4bit___024root(VaddSub4bit__Syms* symsp, const char* namep);
    ~VaddSub4bit___024root();
    VL_UNCOPYABLE(VaddSub4bit___024root);
    VL_UNMOVABLE(VaddSub4bit___024root);

    // INTERNAL METHODS
};


#endif  // guard
