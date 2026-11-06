// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

void Vtop___024root___eval_sample(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_sample\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_ico(Vtop___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (::IData)((::IData)(firstIteration)));
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (::QData)((::IData)(
                                                            (((((::IData)(vlSelfRef.__VprimaryPorts.ps2_dat) 
                                                                != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__ps2_dat__0)) 
                                                               << 3U) 
                                                              | (((::IData)(vlSelfRef.__VprimaryPorts.ps2_clk) 
                                                                  != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__ps2_clk__0)) 
                                                                 << 2U)) 
                                                             | ((((::IData)(vlSelfRef.__VprimaryPorts.clrn) 
                                                                  != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clrn__0)) 
                                                                 << 1U) 
                                                                | ((::IData)(vlSelfRef.__VprimaryPorts.clk) 
                                                                   != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.__VprimaryPorts.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__clrn__0 = vlSelfRef.__VprimaryPorts.clrn;
        vlSelfRef.__Vtrigprevexpr___TOP__ps2_clk__0 
            = vlSelfRef.__VprimaryPorts.ps2_clk;
        vlSelfRef.__Vtrigprevexpr___TOP__ps2_dat__0 
            = vlSelfRef.__VprimaryPorts.ps2_dat;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
void Vtop___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in);

bool Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (::QData)((::IData)(
                                                            ((::IData)(vlSelfRef.__VprimaryPorts.clk) 
                                                             & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__1)))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.__VprimaryPorts.clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

bool Vtop___024root___eval_inact(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_inact\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtop___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out);

bool Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((((1ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                Vtop___024root___nba_sequent__TOP__0(vlSelf);
            }
        }
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vtop___024root___eval_obs(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_obs\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtop___024root___eval_react(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_react\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vtop___024root___eval_postponed(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_postponed\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vtop___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
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

bool Vtop___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
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

extern const ::VlWide<16>/*511:0*/ Vtop__ConstPool__CONST_0;

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*7:0*/ top__DOT__u_display_ascii__DOT__scancode2asciiMux__DOT__i0__DOT__out;
    top__DOT__u_display_ascii__DOT__scancode2asciiMux__DOT__i0__DOT__out = 0;
    ::CData/*0:0*/ __Vdly__top__DOT__u_key_decoder__DOT__break_pending_3;
    __Vdly__top__DOT__u_key_decoder__DOT__break_pending_3 = 0;
    ::CData/*0:0*/ __Vdly__top__DOT__u_key_decoder__DOT__is_pressed_4;
    __Vdly__top__DOT__u_key_decoder__DOT__is_pressed_4 = 0;
    ::CData/*2:0*/ __Vdly__top__DOT__u_ps2_keyboard__DOT__r_ptr_8;
    __Vdly__top__DOT__u_ps2_keyboard__DOT__r_ptr_8 = 0;
    ::CData/*0:0*/ __Vdly__ready_9;
    __Vdly__ready_9 = 0;
    ::CData/*2:0*/ __Vdly__top__DOT__u_ps2_keyboard__DOT__w_ptr_10;
    __Vdly__top__DOT__u_ps2_keyboard__DOT__w_ptr_10 = 0;
    ::CData/*3:0*/ __Vdly__top__DOT__u_ps2_keyboard__DOT__count_12;
    __Vdly__top__DOT__u_ps2_keyboard__DOT__count_12 = 0;
    ::CData/*7:0*/ __Vdly_Val__top__DOT__u_ps2_keyboard__DOT__fifo_14;
    __Vdly_Val__top__DOT__u_ps2_keyboard__DOT__fifo_14 = 0;
    ::CData/*2:0*/ __Vdly_Dim0__top__DOT__u_ps2_keyboard__DOT__fifo_15;
    __Vdly_Dim0__top__DOT__u_ps2_keyboard__DOT__fifo_15 = 0;
    ::CData/*0:0*/ __Vdly_Set__top__DOT__u_ps2_keyboard__DOT__fifo_16;
    __Vdly_Set__top__DOT__u_ps2_keyboard__DOT__fifo_16 = 0;
    // Body
    __Vdly__top__DOT__u_ps2_keyboard__DOT__count_12 
        = vlSelfRef.top__DOT__u_ps2_keyboard__DOT__count;
    __Vdly__top__DOT__u_ps2_keyboard__DOT__r_ptr_8 
        = vlSelfRef.top__DOT__u_ps2_keyboard__DOT__r_ptr;
    __Vdly__top__DOT__u_ps2_keyboard__DOT__w_ptr_10 
        = vlSelfRef.top__DOT__u_ps2_keyboard__DOT__w_ptr;
    __Vdly_Set__top__DOT__u_ps2_keyboard__DOT__fifo_16 = 0U;
    __Vdly__ready_9 = vlSelfRef.__VprimaryPorts.ready;
    __Vdly__top__DOT__u_key_decoder__DOT__break_pending_3 
        = vlSelfRef.top__DOT__u_key_decoder__DOT__break_pending;
    __Vdly__top__DOT__u_key_decoder__DOT__is_pressed_4 
        = vlSelfRef.top__DOT__u_key_decoder__DOT__is_pressed;
    vlSelfRef.top__DOT__u_ps2_keyboard__DOT__ps2_clk_sync 
        = ((6U & ((::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__ps2_clk_sync) 
                  << 1U)) | (::IData)(vlSelfRef.__VprimaryPorts.ps2_clk));
    if (vlSelfRef.__VprimaryPorts.clrn) {
        if (vlSelfRef.__VprimaryPorts.ready) {
            if (vlSelfRef.top__DOT__state) {
                __Vdly__top__DOT__u_ps2_keyboard__DOT__r_ptr_8 
                    = (7U & ((::IData)(1U) + (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__r_ptr)));
                if (((::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__w_ptr) 
                     == (7U & ((::IData)(1U) + (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__r_ptr))))) {
                    __Vdly__ready_9 = 0U;
                }
            }
        }
        if (vlSelfRef.__VprimaryPorts.sampling) {
            if ((0x0aU == (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__count))) {
                __Vdly__top__DOT__u_ps2_keyboard__DOT__count_12 = 0U;
                if ((((~ (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__buffer)) 
                      & (::IData)(vlSelfRef.__VprimaryPorts.ps2_dat)) 
                     & VL_REDXOR_32((0x000001ffU & 
                                     ((::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__buffer) 
                                      >> 1U))))) {
                    __Vdly__top__DOT__u_ps2_keyboard__DOT__w_ptr_10 
                        = (7U & ((::IData)(1U) + (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__w_ptr)));
                    vlSelfRef.__VprimaryPorts.overflow 
                        = ((::IData)(vlSelfRef.__VprimaryPorts.overflow) 
                           | ((::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__r_ptr) 
                              == (7U & ((::IData)(1U) 
                                        + (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__w_ptr)))));
                    __Vdly_Val__top__DOT__u_ps2_keyboard__DOT__fifo_14 
                        = (0x000000ffU & ((::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__buffer) 
                                          >> 1U));
                    __Vdly_Dim0__top__DOT__u_ps2_keyboard__DOT__fifo_15 
                        = vlSelfRef.top__DOT__u_ps2_keyboard__DOT__w_ptr;
                    __Vdly_Set__top__DOT__u_ps2_keyboard__DOT__fifo_16 = 1U;
                    __Vdly__ready_9 = 1U;
                }
            } else {
                __Vdly__top__DOT__u_ps2_keyboard__DOT__count_12 
                    = (0x0000000fU & ((::IData)(1U) 
                                      + (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__count)));
            }
            if ((0x0aU != (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__count))) {
                if ((9U >= (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__count))) {
                    vlSelfRef.top__DOT__u_ps2_keyboard__DOT__buffer 
                        = (((~ ((::IData)(1U) << (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__count))) 
                            & (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__buffer)) 
                           | (0x03ffU & ((::IData)(vlSelfRef.__VprimaryPorts.ps2_dat) 
                                         << (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__count))));
                }
            }
        }
        if (vlSelfRef.top__DOT__scan_valid) {
            if ((0xf0U == (::IData)(vlSelfRef.top__DOT__scancode))) {
                __Vdly__top__DOT__u_key_decoder__DOT__break_pending_3 = 1U;
            } else if (vlSelfRef.top__DOT__u_key_decoder__DOT__break_pending) {
                __Vdly__top__DOT__u_key_decoder__DOT__break_pending_3 = 0U;
            }
            if ((0xf0U != (::IData)(vlSelfRef.top__DOT__scancode))) {
                if (vlSelfRef.top__DOT__u_key_decoder__DOT__break_pending) {
                    if (((::IData)(vlSelfRef.top__DOT__scancode) 
                         == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))) {
                        __Vdly__top__DOT__u_key_decoder__DOT__is_pressed_4 = 0U;
                    }
                } else if (((~ (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__is_pressed)) 
                            & (::IData)(vlSelfRef.top__DOT__u_scancode2ascii__DOT__key_valid))) {
                    __Vdly__top__DOT__u_key_decoder__DOT__is_pressed_4 = 1U;
                }
                if ((1U & (~ (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__break_pending)))) {
                    if (((~ (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__is_pressed)) 
                         & (::IData)(vlSelfRef.top__DOT__u_scancode2ascii__DOT__key_valid))) {
                        vlSelfRef.top__DOT__u_key_decoder__DOT__count 
                            = (0x000000ffU & ((::IData)(1U) 
                                              + (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__count)));
                        vlSelfRef.top__DOT__u_key_decoder__DOT__current_key 
                            = vlSelfRef.top__DOT__scancode;
                    }
                }
            }
        }
        vlSelfRef.top__DOT__scan_valid = 0U;
        if (((~ (::IData)(vlSelfRef.top__DOT__state)) 
             & (::IData)(vlSelfRef.__VprimaryPorts.ready))) {
            vlSelfRef.top__DOT__scan_valid = 1U;
            vlSelfRef.top__DOT__scancode = vlSelfRef.top__DOT__u_ps2_keyboard__DOT__fifo
                [vlSelfRef.top__DOT__u_ps2_keyboard__DOT__r_ptr];
        }
    } else {
        __Vdly__top__DOT__u_ps2_keyboard__DOT__count_12 = 0U;
        __Vdly__top__DOT__u_ps2_keyboard__DOT__r_ptr_8 = 0U;
        __Vdly__top__DOT__u_ps2_keyboard__DOT__w_ptr_10 = 0U;
        vlSelfRef.__VprimaryPorts.overflow = 0U;
        __Vdly__ready_9 = 0U;
        __Vdly__top__DOT__u_key_decoder__DOT__break_pending_3 = 0U;
        vlSelfRef.top__DOT__u_key_decoder__DOT__count = 0U;
        __Vdly__top__DOT__u_key_decoder__DOT__is_pressed_4 = 0U;
        vlSelfRef.top__DOT__u_key_decoder__DOT__current_key = 0U;
        vlSelfRef.top__DOT__scan_valid = 0U;
        vlSelfRef.top__DOT__scancode = 0U;
    }
    vlSelfRef.top__DOT__u_ps2_keyboard__DOT__w_ptr 
        = __Vdly__top__DOT__u_ps2_keyboard__DOT__w_ptr_10;
    vlSelfRef.__VprimaryPorts.seg4 = (0x000000ffU & Vtop__ConstPool__CONST_0
                                      [(0x0000000fU 
                                        & (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__count))]);
    vlSelfRef.__VprimaryPorts.seg5 = (0x000000ffU & Vtop__ConstPool__CONST_0
                                      [(0x0000000fU 
                                        & ((::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__count) 
                                           >> 4U))]);
    vlSelfRef.__VprimaryPorts.sampling = (::IData)(
                                                   (4U 
                                                    == 
                                                    (6U 
                                                     & (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__ps2_clk_sync))));
    vlSelfRef.top__DOT__u_ps2_keyboard__DOT__count 
        = __Vdly__top__DOT__u_ps2_keyboard__DOT__count_12;
    vlSelfRef.top__DOT__u_key_decoder__DOT__break_pending 
        = __Vdly__top__DOT__u_key_decoder__DOT__break_pending_3;
    vlSelfRef.top__DOT__u_key_decoder__DOT__is_pressed 
        = __Vdly__top__DOT__u_key_decoder__DOT__is_pressed_4;
    top__DOT__u_display_ascii__DOT__scancode2asciiMux__DOT__i0__DOT__out 
        = ((- (::IData)(((0x46U == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                         | ((0x3eU == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                            | ((0x3dU == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                               | ((0x36U == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                  | ((0x2eU == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                     | ((0x25U == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                        | ((0x26U == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                           | ((0x1eU 
                                               == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                              | ((0x16U 
                                                  == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                 | ((0x45U 
                                                     == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                    | ((0x1aU 
                                                        == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                       | ((0x35U 
                                                           == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                          | ((0x22U 
                                                              == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                             | ((0x1dU 
                                                                 == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                | ((0x2aU 
                                                                    == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                   | ((0x3cU 
                                                                       == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                      | ((0x2cU 
                                                                          == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                         | ((0x1bU 
                                                                             == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                            | ((0x2dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                               | ((0x15U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x4dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x44U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x31U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x3aU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x4bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x42U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x3bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x43U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x33U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x34U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x2bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x24U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x23U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x21U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x1cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | (0x32U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))))))))))))))))))))))))))))))))))))) 
           & ((0x39U & (- (::IData)((0x46U == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
              | ((0x38U & (- (::IData)((0x3eU == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                 | ((0x37U & (- (::IData)((0x3dU == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                    | ((0x36U & (- (::IData)((0x36U 
                                              == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                       | ((0x35U & (- (::IData)((0x2eU 
                                                 == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                          | ((0x34U & (- (::IData)(
                                                   (0x25U 
                                                    == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                             | ((0x33U & (- (::IData)(
                                                      (0x26U 
                                                       == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                | ((0x32U & (- (::IData)(
                                                         (0x1eU 
                                                          == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                   | ((0x31U & (- (::IData)(
                                                            (0x16U 
                                                             == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                      | ((0x30U & (- (::IData)(
                                                               (0x45U 
                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                         | ((0x7aU 
                                             & (- (::IData)(
                                                            (0x1aU 
                                                             == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                            | ((0x79U 
                                                & (- (::IData)(
                                                               (0x35U 
                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                               | ((0x78U 
                                                   & (- (::IData)(
                                                                  (0x22U 
                                                                   == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                  | ((0x77U 
                                                      & (- (::IData)(
                                                                     (0x1dU 
                                                                      == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                     | ((0x76U 
                                                         & (- (::IData)(
                                                                        (0x2aU 
                                                                         == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                        | ((0x75U 
                                                            & (- (::IData)(
                                                                           (0x3cU 
                                                                            == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                           | ((0x74U 
                                                               & (- (::IData)(
                                                                              (0x2cU 
                                                                               == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                              | ((0x73U 
                                                                  & (- (::IData)(
                                                                                (0x1bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                 | ((0x72U 
                                                                     & (- (::IData)(
                                                                                (0x2dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                    | ((0x71U 
                                                                        & (- (::IData)(
                                                                                (0x15U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                       | ((0x70U 
                                                                           & (- (::IData)(
                                                                                (0x4dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                          | ((0x6fU 
                                                                              & (- (::IData)(
                                                                                (0x44U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                             | ((0x6eU 
                                                                                & (- (::IData)(
                                                                                (0x31U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x6dU 
                                                                                & (- (::IData)(
                                                                                (0x3aU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x6cU 
                                                                                & (- (::IData)(
                                                                                (0x4bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x6bU 
                                                                                & (- (::IData)(
                                                                                (0x42U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x6aU 
                                                                                & (- (::IData)(
                                                                                (0x3bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x69U 
                                                                                & (- (::IData)(
                                                                                (0x43U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x68U 
                                                                                & (- (::IData)(
                                                                                (0x33U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x67U 
                                                                                & (- (::IData)(
                                                                                (0x34U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x66U 
                                                                                & (- (::IData)(
                                                                                (0x2bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x65U 
                                                                                & (- (::IData)(
                                                                                (0x24U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x64U 
                                                                                & (- (::IData)(
                                                                                (0x23U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x63U 
                                                                                & (- (::IData)(
                                                                                (0x21U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x61U 
                                                                                & (- (::IData)(
                                                                                (0x1cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | (0x62U 
                                                                                & (- (::IData)(
                                                                                (0x32U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)))))))))))))))))))))))))))))))))))))))));
    if (vlSelfRef.top__DOT__u_key_decoder__DOT__is_pressed) {
        vlSelfRef.__VprimaryPorts.seg0_out = (0x000000ffU 
                                              & Vtop__ConstPool__CONST_0
                                              [(0x0000000fU 
                                                & (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))]);
        vlSelfRef.__VprimaryPorts.seg1_out = (0x000000ffU 
                                              & Vtop__ConstPool__CONST_0
                                              [(0x0000000fU 
                                                & ((::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key) 
                                                   >> 4U))]);
        vlSelfRef.__VprimaryPorts.seg2_out = (0x000000ffU 
                                              & Vtop__ConstPool__CONST_0
                                              [(0x0000000fU 
                                                & (::IData)(top__DOT__u_display_ascii__DOT__scancode2asciiMux__DOT__i0__DOT__out))]);
        vlSelfRef.__VprimaryPorts.seg3_out = (0x000000ffU 
                                              & Vtop__ConstPool__CONST_0
                                              [(0x0000000fU 
                                                & ((::IData)(top__DOT__u_display_ascii__DOT__scancode2asciiMux__DOT__i0__DOT__out) 
                                                   >> 4U))]);
    } else {
        vlSelfRef.__VprimaryPorts.seg0_out = 0x000000ffU;
        vlSelfRef.__VprimaryPorts.seg1_out = 0x000000ffU;
        vlSelfRef.__VprimaryPorts.seg2_out = 0x000000ffU;
        vlSelfRef.__VprimaryPorts.seg3_out = 0x000000ffU;
    }
    if (__Vdly_Set__top__DOT__u_ps2_keyboard__DOT__fifo_16) {
        vlSelfRef.top__DOT__u_ps2_keyboard__DOT__fifo[__Vdly_Dim0__top__DOT__u_ps2_keyboard__DOT__fifo_15] 
            = __Vdly_Val__top__DOT__u_ps2_keyboard__DOT__fifo_14;
    }
    vlSelfRef.top__DOT__u_ps2_keyboard__DOT__r_ptr 
        = __Vdly__top__DOT__u_ps2_keyboard__DOT__r_ptr_8;
    vlSelfRef.top__DOT__u_scancode2ascii__DOT__key_valid 
        = (0U != ((- (::IData)(((0x46U == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                | ((0x3eU == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                   | ((0x3dU == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                      | ((0x36U == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                         | ((0x2eU 
                                             == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                            | ((0x25U 
                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                               | ((0x26U 
                                                   == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                  | ((0x1eU 
                                                      == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                     | ((0x16U 
                                                         == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                        | ((0x45U 
                                                            == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                           | ((0x1aU 
                                                               == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                              | ((0x35U 
                                                                  == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                 | ((0x22U 
                                                                     == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                    | ((0x1dU 
                                                                        == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                       | ((0x2aU 
                                                                           == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                          | ((0x3cU 
                                                                              == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                             | ((0x2cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x1bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x2dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x15U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x4dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x44U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x31U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x3aU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x4bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x42U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x3bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x43U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x33U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x34U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x2bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x24U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x23U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x21U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x1cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | (0x32U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))))))))))))))))))))))))))))))))))))) 
                  & ((0x39U & (- (::IData)((0x46U == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                     | ((0x38U & (- (::IData)((0x3eU 
                                               == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                        | ((0x37U & (- (::IData)((0x3dU 
                                                  == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                           | ((0x36U & (- (::IData)(
                                                    (0x36U 
                                                     == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                              | ((0x35U & (- (::IData)(
                                                       (0x2eU 
                                                        == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                 | ((0x34U & (- (::IData)(
                                                          (0x25U 
                                                           == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                    | ((0x33U & (- (::IData)(
                                                             (0x26U 
                                                              == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                       | ((0x32U & 
                                           (- (::IData)(
                                                        (0x1eU 
                                                         == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                          | ((0x31U 
                                              & (- (::IData)(
                                                             (0x16U 
                                                              == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                             | ((0x30U 
                                                 & (- (::IData)(
                                                                (0x45U 
                                                                 == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                | ((0x7aU 
                                                    & (- (::IData)(
                                                                   (0x1aU 
                                                                    == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                   | ((0x79U 
                                                       & (- (::IData)(
                                                                      (0x35U 
                                                                       == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                      | ((0x78U 
                                                          & (- (::IData)(
                                                                         (0x22U 
                                                                          == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                         | ((0x77U 
                                                             & (- (::IData)(
                                                                            (0x1dU 
                                                                             == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                            | ((0x76U 
                                                                & (- (::IData)(
                                                                               (0x2aU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                               | ((0x75U 
                                                                   & (- (::IData)(
                                                                                (0x3cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                  | ((0x74U 
                                                                      & (- (::IData)(
                                                                                (0x2cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                     | ((0x73U 
                                                                         & (- (::IData)(
                                                                                (0x1bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                        | ((0x72U 
                                                                            & (- (::IData)(
                                                                                (0x2dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                           | ((0x71U 
                                                                               & (- (::IData)(
                                                                                (0x15U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                              | ((0x70U 
                                                                                & (- (::IData)(
                                                                                (0x4dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x6fU 
                                                                                & (- (::IData)(
                                                                                (0x44U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x6eU 
                                                                                & (- (::IData)(
                                                                                (0x31U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x6dU 
                                                                                & (- (::IData)(
                                                                                (0x3aU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x6cU 
                                                                                & (- (::IData)(
                                                                                (0x4bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x6bU 
                                                                                & (- (::IData)(
                                                                                (0x42U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x6aU 
                                                                                & (- (::IData)(
                                                                                (0x3bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x69U 
                                                                                & (- (::IData)(
                                                                                (0x43U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x68U 
                                                                                & (- (::IData)(
                                                                                (0x33U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x67U 
                                                                                & (- (::IData)(
                                                                                (0x34U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x66U 
                                                                                & (- (::IData)(
                                                                                (0x2bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x65U 
                                                                                & (- (::IData)(
                                                                                (0x24U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x64U 
                                                                                & (- (::IData)(
                                                                                (0x23U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x63U 
                                                                                & (- (::IData)(
                                                                                (0x21U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x61U 
                                                                                & (- (::IData)(
                                                                                (0x1cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | (0x62U 
                                                                                & (- (::IData)(
                                                                                (0x32U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))))))))))))))))))))))))))))))))))))))));
    vlSelfRef.top__DOT__state = ((::IData)(vlSelfRef.__VprimaryPorts.clrn) 
                                 && ((::IData)(vlSelfRef.top__DOT__nextdata_n) 
                                     & (::IData)(vlSelfRef.__VprimaryPorts.ready)));
    vlSelfRef.__VprimaryPorts.ready = __Vdly__ready_9;
    vlSelfRef.top__DOT__nextdata_n = (1U & (~ (::IData)(vlSelfRef.top__DOT__state)));
}

void Vtop___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((::IData)(1U) + n);
    } while ((0U >= n));
}

void Vtop___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
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
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.clk 
                      & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.clrn 
                      & 0xfeU)))) {
        Verilated::overWidthError("clrn");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.ps2_clk 
                      & 0xfeU)))) {
        Verilated::overWidthError("ps2_clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.ps2_dat 
                      & 0xfeU)))) {
        Verilated::overWidthError("ps2_dat");
    }
}
#endif  // VL_DEBUG
