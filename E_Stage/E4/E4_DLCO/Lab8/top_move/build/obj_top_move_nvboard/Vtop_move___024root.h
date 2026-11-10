// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design internal header
// See Vtop_move.h for the primary calling header

#ifndef VERILATED_VTOP_MOVE___024ROOT_H_
#define VERILATED_VTOP_MOVE___024ROOT_H_  // guard

#include "verilated.h"


class Vtop_move__Syms;

class alignas(VL_CACHE_LINE_BYTES) Vtop_move___024root final {
  public:

    // TOP LEVEL PORTS
    union {
        struct {
            VL_IN8(clk,0,0);
            VL_IN8(rst,0,0);
            VL_OUT8(VGA_HSYNC,0,0);
            VL_OUT8(VGA_VSYNC,0,0);
            VL_OUT8(VGA_BLANK_N,0,0);
            VL_OUT8(VGA_R,7,0);
            VL_OUT8(VGA_G,7,0);
            VL_OUT8(VGA_B,7,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*0:0*/ top_move__DOT__x_dir;
    ::CData/*0:0*/ top_move__DOT__y_dir;
    ::CData/*0:0*/ top_move__DOT__VGA_VSYNC_d;
    ::CData/*0:0*/ top_move__DOT__frame_tick;
    ::CData/*0:0*/ top_move__DOT__pic_valid;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__rst__1;
    ::SData/*9:0*/ top_move__DOT__x_pos;
    ::SData/*9:0*/ top_move__DOT__y_pos;
    ::SData/*9:0*/ top_move__DOT__u_vga_ctrl__DOT__h_addr;
    ::SData/*9:0*/ top_move__DOT__u_vga_ctrl__DOT__v_addr;
    ::SData/*9:0*/ top_move__DOT__u_vga_ctrl__DOT__x_cnt;
    ::SData/*9:0*/ top_move__DOT__u_vga_ctrl__DOT__y_cnt;
    ::IData/*23:0*/ top_move__DOT__vga_data;
    ::IData/*18:0*/ top_move__DOT__addr_rom;
    ::VlUnpacked<::IData/*23:0*/, 327680> top_move__DOT__pic_rom;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VactTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VnbaTriggered;

    // INTERNAL VARIABLES
    Vtop_move__Syms* vlSymsp;
    const char* vlNamep;

    // CONSTRUCTORS
    Vtop_move___024root(Vtop_move__Syms* symsp, const char* namep);
    ~Vtop_move___024root();
    VL_UNCOPYABLE(Vtop_move___024root);
    VL_UNMOVABLE(Vtop_move___024root);

    // INTERNAL METHODS
};


#endif  // guard
