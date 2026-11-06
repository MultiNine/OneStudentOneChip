// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencode42.h for the primary calling header

#include "Vencode42__pch.h"

void Vencode42___024root___eval_sample(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_sample\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode42___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
bool Vencode42___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

bool Vencode42___024root___eval_ico(Vencode42___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_ico\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VicoExecute;
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (::IData)((::IData)(firstIteration)));
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (::QData)((::IData)(
                                                            ((((::IData)(vlSelfRef.__VprimaryPorts.en) 
                                                               != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__en__0)) 
                                                              << 1U) 
                                                             | ((::IData)(vlSelfRef.__VprimaryPorts.x) 
                                                                != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__x__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__x__0 = vlSelfRef.__VprimaryPorts.x;
        vlSelfRef.__Vtrigprevexpr___TOP__en__0 = vlSelfRef.__VprimaryPorts.en;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vencode42___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = Vencode42___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_body__ico
            if ((((3ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__0
                    vlSelfRef.__VprimaryPorts.y = ((::IData)(vlSelfRef.__VprimaryPorts.en)
                                                    ? 
                                                   (3U 
                                                    & (0x00030210U 
                                                       >> 
                                                       ((::IData)(vlSelfRef.__VprimaryPorts.x) 
                                                        << 1U)))
                                                    : 0U);
                }
            }
        }
    }
    return (__VicoExecute);
}

bool Vencode42___024root___eval_act(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_act\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vencode42___024root___eval_inact(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_inact\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vencode42___024root___eval_nba(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_nba\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vencode42___024root___eval_obs(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_obs\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vencode42___024root___eval_react(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_react\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vencode42___024root___eval_postponed(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_postponed\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool Vencode42___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___trigger_anySet__ico\n"); );
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

#ifdef VL_DEBUG
void Vencode42___024root___eval_debug_assertions(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_debug_assertions\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.x & 0xf0U)))) {
        Verilated::overWidthError("x");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.en 
                      & 0xfeU)))) {
        Verilated::overWidthError("en");
    }
}
#endif  // VL_DEBUG
