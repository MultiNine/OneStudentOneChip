// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlfsr.h for the primary calling header

#include "Vlfsr__pch.h"

void Vlfsr___024root___eval_sample(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_sample\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlfsr___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

bool Vlfsr___024root___eval_ico(Vlfsr___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_ico\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
        Vlfsr___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlfsr___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
void Vlfsr___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in);

bool Vlfsr___024root___eval_act(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_act\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
        Vlfsr___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vlfsr___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

bool Vlfsr___024root___eval_inact(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_inact\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vlfsr___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
extern const ::VlWide<16>/*511:0*/ Vlfsr__ConstPool__CONST_0;
void Vlfsr___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out);

bool Vlfsr___024root___eval_nba(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_nba\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vlfsr___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((((3ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    vlSelfRef.__VprimaryPorts.dout 
                        = ((::IData)(vlSelfRef.__VprimaryPorts.rst)
                            ? 1U : (((::IData)(vlSelfRef.lfsr__DOT__feedback) 
                                     << 7U) | (0x0000007fU 
                                               & ((::IData)(vlSelfRef.__VprimaryPorts.dout) 
                                                  >> 1U))));
                    vlSelfRef.lfsr__DOT__feedback = 
                        (1U & VL_REDXOR_8((0x1dU & (::IData)(vlSelfRef.__VprimaryPorts.dout))));
                    vlSelfRef.__VprimaryPorts.segout1 
                        = (0x000000ffU & Vlfsr__ConstPool__CONST_0
                           [(0x0000000fU & ((::IData)(vlSelfRef.__VprimaryPorts.dout) 
                                            >> 4U))]);
                    vlSelfRef.__VprimaryPorts.segout0 
                        = (0x000000ffU & Vlfsr__ConstPool__CONST_0
                           [(0x0000000fU & (::IData)(vlSelfRef.__VprimaryPorts.dout))]);
                }
            }
        }
        Vlfsr___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vlfsr___024root___eval_obs(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_obs\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vlfsr___024root___eval_react(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_react\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vlfsr___024root___eval_postponed(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_postponed\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vlfsr___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___trigger_anySet__ico\n"); );
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

bool Vlfsr___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___trigger_anySet__act\n"); );
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

void Vlfsr___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((::IData)(1U) + n);
    } while ((0U >= n));
}

void Vlfsr___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___trigger_clear__act\n"); );
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
void Vlfsr___024root___eval_debug_assertions(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_debug_assertions\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
