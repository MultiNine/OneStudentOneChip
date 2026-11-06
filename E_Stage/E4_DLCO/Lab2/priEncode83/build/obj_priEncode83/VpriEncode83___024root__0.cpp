// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VpriEncode83.h for the primary calling header

#include "VpriEncode83__pch.h"

void VpriEncode83___024root___eval_sample(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_sample\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VpriEncode83___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
bool VpriEncode83___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);
extern const ::VlWide<256>/*8191:0*/ VpriEncode83__ConstPool__CONST_1;
extern const ::VlWide<256>/*8191:0*/ VpriEncode83__ConstPool__CONST_0;
extern const ::VlWide<16>/*511:0*/ VpriEncode83__ConstPool__CONST_2;

bool VpriEncode83___024root___eval_ico(VpriEncode83___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_ico\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
                                                            ((((::IData)(vlSelfRef.__VprimaryPorts.x) 
                                                               != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__x__0)) 
                                                              << 1U) 
                                                             | ((::IData)(vlSelfRef.__VprimaryPorts.en) 
                                                                != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__en__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__en__0 = vlSelfRef.__VprimaryPorts.en;
        vlSelfRef.__Vtrigprevexpr___TOP__x__0 = vlSelfRef.__VprimaryPorts.x;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VpriEncode83___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = VpriEncode83___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_body__ico
            if ((((2ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__0
                    vlSelfRef.__Vdfg_Regularize_26 
                        = (0x0000000fU & VpriEncode83__ConstPool__CONST_1
                           [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.x))]);
                    vlSelfRef.__Vdfg_Regularize_27 
                        = (0x0000000fU & VpriEncode83__ConstPool__CONST_0
                           [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.x))]);
                }
            }
            if ((((3ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__1
                    if (vlSelfRef.__VprimaryPorts.en) {
                        vlSelfRef.__VprimaryPorts.y 
                            = (7U & ((::IData)(vlSelfRef.__Vdfg_Regularize_27) 
                                     >> 1U));
                        vlSelfRef.__VprimaryPorts.validIn 
                            = (1U & (::IData)(vlSelfRef.__Vdfg_Regularize_27));
                    } else {
                        vlSelfRef.__VprimaryPorts.y 
                            = (7U & ((::IData)(vlSelfRef.__Vdfg_Regularize_26) 
                                     >> 1U));
                        vlSelfRef.__VprimaryPorts.validIn 
                            = (1U & (::IData)(vlSelfRef.__Vdfg_Regularize_26));
                    }
                    vlSelfRef.__VprimaryPorts.segOut 
                        = (((::IData)(vlSelfRef.__VprimaryPorts.en) 
                            & (::IData)(vlSelfRef.__VprimaryPorts.validIn))
                            ? (0x000000ffU & VpriEncode83__ConstPool__CONST_2
                               [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.y))])
                            : 0x000000ffU);
                }
            }
        }
    }
    return (__VicoExecute);
}

bool VpriEncode83___024root___eval_act(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_act\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VpriEncode83___024root___eval_inact(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_inact\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VpriEncode83___024root___eval_nba(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_nba\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VpriEncode83___024root___eval_obs(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_obs\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VpriEncode83___024root___eval_react(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_react\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void VpriEncode83___024root___eval_postponed(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_postponed\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool VpriEncode83___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___trigger_anySet__ico\n"); );
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
void VpriEncode83___024root___eval_debug_assertions(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_debug_assertions\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.en 
                      & 0xfeU)))) {
        Verilated::overWidthError("en");
    }
}
#endif  // VL_DEBUG
