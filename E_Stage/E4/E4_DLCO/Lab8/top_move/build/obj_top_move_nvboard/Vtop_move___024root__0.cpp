// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_move.h for the primary calling header

#include "Vtop_move__pch.h"

void Vtop_move___024root___eval_sample(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_sample\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_move___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

bool Vtop_move___024root___eval_ico(Vtop_move___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_ico\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (::IData)((::IData)(firstIteration)));
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (::QData)((::IData)(
                                                            ((((::IData)(vlSelfRef.__VprimaryPorts.rst) 
                                                               != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0)) 
                                                              << 1U) 
                                                             | ((::IData)(vlSelfRef.__VprimaryPorts.clk) 
                                                                != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.__VprimaryPorts.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.__VprimaryPorts.rst;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_move___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_move___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
void Vtop_move___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in);

bool Vtop_move___024root___eval_act(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_act\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (::QData)((::IData)(
                                                            ((((::IData)(vlSelfRef.__VprimaryPorts.rst) 
                                                               & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__1))) 
                                                              << 1U) 
                                                             | ((::IData)(vlSelfRef.__VprimaryPorts.clk) 
                                                                & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__1))))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.__VprimaryPorts.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__rst__1 = vlSelfRef.__VprimaryPorts.rst;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_move___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop_move___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

bool Vtop_move___024root___eval_inact(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_inact\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtop_move___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
void Vtop_move___024root___nba_sequent__TOP__0(Vtop_move___024root* vlSelf);
void Vtop_move___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out);

bool Vtop_move___024root___eval_nba(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_nba\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop_move___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((((3ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                Vtop_move___024root___nba_sequent__TOP__0(vlSelf);
            }
            if ((((1ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__1
                    vlSelfRef.top_move__DOT__vga_data 
                        = ((::IData)(vlSelfRef.top_move__DOT__pic_valid)
                            ? ((0x0004ffffU >= vlSelfRef.top_move__DOT__addr_rom)
                                ? vlSelfRef.top_move__DOT__pic_rom
                               [vlSelfRef.top_move__DOT__addr_rom]
                                : 0U) : 0U);
                    vlSelfRef.__VprimaryPorts.VGA_R 
                        = (0x000000ffU & (vlSelfRef.top_move__DOT__vga_data 
                                          >> 0x00000010U));
                    vlSelfRef.__VprimaryPorts.VGA_G 
                        = (0x000000ffU & (vlSelfRef.top_move__DOT__vga_data 
                                          >> 8U));
                    vlSelfRef.__VprimaryPorts.VGA_B 
                        = (0x000000ffU & vlSelfRef.top_move__DOT__vga_data);
                }
            }
            if ((((3ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _nba_comb__TOP__0
                    vlSelfRef.top_move__DOT__pic_valid 
                        = ((::IData)(vlSelfRef.__VprimaryPorts.VGA_BLANK_N) 
                           & (((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__h_addr) 
                               >= (::IData)(vlSelfRef.top_move__DOT__x_pos)) 
                              & (((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__h_addr) 
                                  < ((::IData)(0x00000064U) 
                                     + (::IData)(vlSelfRef.top_move__DOT__x_pos))) 
                                 & (((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__v_addr) 
                                     >= (::IData)(vlSelfRef.top_move__DOT__y_pos)) 
                                    & ((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__v_addr) 
                                       < ((::IData)(0x00000064U) 
                                          + (::IData)(vlSelfRef.top_move__DOT__y_pos)))))));
                    vlSelfRef.top_move__DOT__addr_rom 
                        = (((0x0007fe00U & (((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__h_addr) 
                                             - (::IData)(vlSelfRef.top_move__DOT__x_pos)) 
                                            << 9U)) 
                            | (0x000001ffU & ((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__v_addr) 
                                              - (::IData)(vlSelfRef.top_move__DOT__y_pos)))) 
                           & (- (::IData)((::IData)(vlSelfRef.top_move__DOT__pic_valid))));
                }
            }
        }
        Vtop_move___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vtop_move___024root___eval_obs(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_obs\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtop_move___024root___eval_react(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_react\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vtop_move___024root___eval_postponed(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_postponed\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vtop_move___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___trigger_anySet__ico\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

bool Vtop_move___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___trigger_anySet__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

void Vtop_move___024root___nba_sequent__TOP__0(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___nba_sequent__TOP__0\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ top_move__DOT__u_vga_ctrl__DOT__h_valid;
    top_move__DOT__u_vga_ctrl__DOT__h_valid = 0;
    ::CData/*0:0*/ top_move__DOT__u_vga_ctrl__DOT__v_valid;
    top_move__DOT__u_vga_ctrl__DOT__v_valid = 0;
    ::SData/*9:0*/ __Vdly__top_move__DOT__x_pos_1;
    __Vdly__top_move__DOT__x_pos_1 = 0;
    ::SData/*9:0*/ __Vdly__top_move__DOT__y_pos_2;
    __Vdly__top_move__DOT__y_pos_2 = 0;
    ::CData/*0:0*/ __Vdly__top_move__DOT__x_dir_3;
    __Vdly__top_move__DOT__x_dir_3 = 0;
    ::CData/*0:0*/ __Vdly__top_move__DOT__y_dir_4;
    __Vdly__top_move__DOT__y_dir_4 = 0;
    ::SData/*9:0*/ __Vdly__top_move__DOT__u_vga_ctrl__DOT__x_cnt_5;
    __Vdly__top_move__DOT__u_vga_ctrl__DOT__x_cnt_5 = 0;
    ::SData/*9:0*/ __Vdly__top_move__DOT__u_vga_ctrl__DOT__y_cnt_6;
    __Vdly__top_move__DOT__u_vga_ctrl__DOT__y_cnt_6 = 0;
    // Body
    __Vdly__top_move__DOT__x_dir_3 = vlSelfRef.top_move__DOT__x_dir;
    __Vdly__top_move__DOT__y_dir_4 = vlSelfRef.top_move__DOT__y_dir;
    __Vdly__top_move__DOT__x_pos_1 = vlSelfRef.top_move__DOT__x_pos;
    __Vdly__top_move__DOT__y_pos_2 = vlSelfRef.top_move__DOT__y_pos;
    __Vdly__top_move__DOT__u_vga_ctrl__DOT__x_cnt_5 
        = vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt;
    __Vdly__top_move__DOT__u_vga_ctrl__DOT__y_cnt_6 
        = vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__y_cnt;
    if (vlSelfRef.__VprimaryPorts.rst) {
        __Vdly__top_move__DOT__x_dir_3 = 1U;
        __Vdly__top_move__DOT__y_dir_4 = 1U;
        __Vdly__top_move__DOT__x_pos_1 = 0U;
        __Vdly__top_move__DOT__y_pos_2 = 0U;
        __Vdly__top_move__DOT__u_vga_ctrl__DOT__x_cnt_5 = 1U;
        __Vdly__top_move__DOT__u_vga_ctrl__DOT__y_cnt_6 = 1U;
    } else {
        if (vlSelfRef.top_move__DOT__frame_tick) {
            if (vlSelfRef.top_move__DOT__x_dir) {
                if ((0x021cU == (::IData)(vlSelfRef.top_move__DOT__x_pos))) {
                    __Vdly__top_move__DOT__x_dir_3 = 0U;
                    __Vdly__top_move__DOT__x_pos_1 
                        = (0x000003ffU & ((::IData)(vlSelfRef.top_move__DOT__x_pos) 
                                          - (::IData)(1U)));
                } else {
                    __Vdly__top_move__DOT__x_pos_1 
                        = (0x000003ffU & ((::IData)(1U) 
                                          + (::IData)(vlSelfRef.top_move__DOT__x_pos)));
                }
            } else if ((0U == (::IData)(vlSelfRef.top_move__DOT__x_pos))) {
                __Vdly__top_move__DOT__x_dir_3 = 1U;
                __Vdly__top_move__DOT__x_pos_1 = (0x000003ffU 
                                                  & ((::IData)(1U) 
                                                     + (::IData)(vlSelfRef.top_move__DOT__x_pos)));
            } else {
                __Vdly__top_move__DOT__x_pos_1 = (0x000003ffU 
                                                  & ((::IData)(vlSelfRef.top_move__DOT__x_pos) 
                                                     - (::IData)(1U)));
            }
            if (vlSelfRef.top_move__DOT__y_dir) {
                if ((0x017cU == (::IData)(vlSelfRef.top_move__DOT__y_pos))) {
                    __Vdly__top_move__DOT__y_dir_4 = 0U;
                    __Vdly__top_move__DOT__y_pos_2 
                        = (0x000003ffU & ((::IData)(vlSelfRef.top_move__DOT__y_pos) 
                                          - (::IData)(1U)));
                } else {
                    __Vdly__top_move__DOT__y_pos_2 
                        = (0x000003ffU & ((::IData)(1U) 
                                          + (::IData)(vlSelfRef.top_move__DOT__y_pos)));
                }
            } else if ((0U == (::IData)(vlSelfRef.top_move__DOT__y_pos))) {
                __Vdly__top_move__DOT__y_dir_4 = 1U;
                __Vdly__top_move__DOT__y_pos_2 = (0x000003ffU 
                                                  & ((::IData)(1U) 
                                                     + (::IData)(vlSelfRef.top_move__DOT__y_pos)));
            } else {
                __Vdly__top_move__DOT__y_pos_2 = (0x000003ffU 
                                                  & ((::IData)(vlSelfRef.top_move__DOT__y_pos) 
                                                     - (::IData)(1U)));
            }
        }
        __Vdly__top_move__DOT__u_vga_ctrl__DOT__x_cnt_5 
            = ((0x0320U == (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt))
                ? 1U : (0x000003ffU & ((::IData)(1U) 
                                       + (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt))));
        if (((0x020dU == (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__y_cnt)) 
             & (0x0320U == (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt)))) {
            __Vdly__top_move__DOT__u_vga_ctrl__DOT__y_cnt_6 = 1U;
        } else if ((0x0320U == (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt))) {
            __Vdly__top_move__DOT__u_vga_ctrl__DOT__y_cnt_6 
                = (0x000003ffU & ((::IData)(1U) + (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__y_cnt)));
        }
    }
    vlSelfRef.top_move__DOT__VGA_VSYNC_d = ((~ (::IData)(vlSelfRef.__VprimaryPorts.rst)) 
                                            & (::IData)(vlSelfRef.__VprimaryPorts.VGA_VSYNC));
    vlSelfRef.top_move__DOT__x_dir = __Vdly__top_move__DOT__x_dir_3;
    vlSelfRef.top_move__DOT__x_pos = __Vdly__top_move__DOT__x_pos_1;
    vlSelfRef.top_move__DOT__y_dir = __Vdly__top_move__DOT__y_dir_4;
    vlSelfRef.top_move__DOT__y_pos = __Vdly__top_move__DOT__y_pos_2;
    vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt 
        = __Vdly__top_move__DOT__u_vga_ctrl__DOT__x_cnt_5;
    vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__y_cnt 
        = __Vdly__top_move__DOT__u_vga_ctrl__DOT__y_cnt_6;
    vlSelfRef.__VprimaryPorts.VGA_HSYNC = (0x0060U 
                                           < (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt));
    top_move__DOT__u_vga_ctrl__DOT__h_valid = ((0x0090U 
                                                < (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt)) 
                                               & (0x0310U 
                                                  >= (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt)));
    vlSelfRef.__VprimaryPorts.VGA_VSYNC = (2U < (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__y_cnt));
    top_move__DOT__u_vga_ctrl__DOT__v_valid = ((0x0023U 
                                                < (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__y_cnt)) 
                                               & (0x0203U 
                                                  >= (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__y_cnt)));
    vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__h_addr 
        = (0x000003ffU & (((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt) 
                           - (::IData)(0x0091U)) & 
                          (- (::IData)((::IData)(top_move__DOT__u_vga_ctrl__DOT__h_valid)))));
    vlSelfRef.top_move__DOT__frame_tick = ((~ (::IData)(vlSelfRef.__VprimaryPorts.VGA_VSYNC)) 
                                           & (::IData)(vlSelfRef.top_move__DOT__VGA_VSYNC_d));
    vlSelfRef.__VprimaryPorts.VGA_BLANK_N = ((::IData)(top_move__DOT__u_vga_ctrl__DOT__h_valid) 
                                             & (::IData)(top_move__DOT__u_vga_ctrl__DOT__v_valid));
    vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__v_addr 
        = (0x000003ffU & (((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__y_cnt) 
                           - (::IData)(0x0024U)) & 
                          (- (::IData)((::IData)(top_move__DOT__u_vga_ctrl__DOT__v_valid)))));
}

void Vtop_move___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((::IData)(1U) + n);
    } while ((0U >= n));
}

void Vtop_move___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___trigger_clear__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((::IData)(1U) + n);
    } while ((1U > n));
}

#ifdef VL_DEBUG
void Vtop_move___024root___eval_debug_assertions(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_debug_assertions\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.clk 
                      & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.rst 
                      & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
