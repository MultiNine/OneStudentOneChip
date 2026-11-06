// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop.h for the primary calling header

#ifndef VERILATED_VTOP___024ROOT_H_
#define VERILATED_VTOP___024ROOT_H_  // guard

#include "verilated.h"


class Vtop__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN8(clk,0,0);
            VL_IN8(clrn,0,0);
            VL_IN8(ps2_clk,0,0);
            VL_IN8(ps2_dat,0,0);
            VL_OUT8(ready,0,0);
            VL_OUT8(sampling,0,0);
            VL_OUT8(overflow,0,0);
            VL_OUT8(seg0_out,7,0);
            VL_OUT8(seg1_out,7,0);
            VL_OUT8(seg2_out,7,0);
            VL_OUT8(seg3_out,7,0);
            VL_OUT8(seg4,7,0);
            VL_OUT8(seg5,7,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*0:0*/ top__DOT__nextdata_n;
    ::CData/*0:0*/ top__DOT__state;
    ::CData/*7:0*/ top__DOT__scancode;
    ::CData/*0:0*/ top__DOT__scan_valid;
    ::CData/*0:0*/ top__DOT__u_scancode2ascii__DOT__key_valid;
    ::CData/*7:0*/ top__DOT__u_key_decoder__DOT__count;
    ::CData/*0:0*/ top__DOT__u_key_decoder__DOT__is_pressed;
    ::CData/*7:0*/ top__DOT__u_key_decoder__DOT__current_key;
    ::CData/*0:0*/ top__DOT__u_key_decoder__DOT__break_pending;
    ::CData/*2:0*/ top__DOT__u_ps2_keyboard__DOT__w_ptr;
    ::CData/*2:0*/ top__DOT__u_ps2_keyboard__DOT__r_ptr;
    ::CData/*3:0*/ top__DOT__u_ps2_keyboard__DOT__count;
    ::CData/*2:0*/ top__DOT__u_ps2_keyboard__DOT__ps2_clk_sync;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clrn__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__ps2_clk__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__ps2_dat__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
    ::SData/*9:0*/ top__DOT__u_ps2_keyboard__DOT__buffer;
    ::VlUnpacked<::CData/*7:0*/, 8> top__DOT__u_ps2_keyboard__DOT__fifo;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VactTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop___024root(Vtop__Syms* symsp, const char* namep);
    ~Vtop___024root();
    VL_UNCOPYABLE(Vtop___024root);
    VL_UNMOVABLE(Vtop___024root);

    // INTERNAL METHODS
};


#endif  // guard
