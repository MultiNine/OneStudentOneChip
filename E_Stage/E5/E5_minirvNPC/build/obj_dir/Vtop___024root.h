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
            VL_IN8(rst,0,0);
            VL_OUT(PC,31,0);
            VL_OUT(instr,31,0);
        } __VprimaryPorts;
    };

    // TRIVIALLY CONSTRUCTIBLE STATE
    ::CData/*0:0*/ top__DOT__u_LSU__DOT__ren;
    ::CData/*0:0*/ top__DOT__u_LSU__DOT__wen;
    ::CData/*0:0*/ top__DOT__u_EXU__DOT__is_jalr;
    ::CData/*0:0*/ top__DOT__u_EXU__DOT__is_add;
    ::CData/*0:0*/ top__DOT__u_EXU__DOT__is_sw;
    ::CData/*0:0*/ top__DOT__u_EXU__DOT__is_sb;
    ::CData/*0:0*/ top__DOT__u_IDU__DOT__is_lw;
    ::CData/*0:0*/ top__DOT__u_IDU__DOT__is_lbu;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__rst__0;
    ::CData/*0:0*/ __Vtrigprevexpr___TOP__clk__1;
    ::IData/*31:0*/ top__DOT__u_LSU__DOT__rdata;
    ::IData/*31:0*/ top__DOT__u_EXU__DOT__rdata2;
    ::IData/*31:0*/ top__DOT__u_EXU__DOT__memAddr;
    ::IData/*31:0*/ top__DOT__u_IFU__DOT____VlemCond_1;
    ::IData/*31:0*/ top__DOT__u_IFU__DOT____VlemCall_0__pmem_read;
    ::IData/*31:0*/ top__DOT__u_IFU__DOT__PCin;
    ::IData/*31:0*/ top__DOT__u_IFU__DOT__PCout;
    ::IData/*31:0*/ __Vfunc_top__DOT__u_LSU__DOT__pmem_read__Vfuncout_0;
    ::VlUnpacked<::IData/*31:0*/, 16> top__DOT__u_RegisterFile__DOT__rf;
    ::VlUnpacked<::QData/*63:0*/, 1> __VstlTriggered;
    ::VlUnpacked<::QData/*63:0*/, 2> __VicoTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VactTriggered;
    ::VlUnpacked<::QData/*63:0*/, 1> __VnbaTriggered;
    ::VlUnpacked<::CData/*0:0*/, 3> __VtraceActivity;

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
