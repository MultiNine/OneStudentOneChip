// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VaddSub4bit.h for the primary calling header

#include "VaddSub4bit__pch.h"

void VaddSub4bit___024root___eval_sample(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_sample\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VaddSub4bit___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
bool VaddSub4bit___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

bool VaddSub4bit___024root___eval_ico(VaddSub4bit___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_ico\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
                                                            ((((::IData)(vlSelfRef.__VprimaryPorts.ctrl) 
                                                               != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__ctrl__0)) 
                                                              << 2U) 
                                                             | ((((::IData)(vlSelfRef.__VprimaryPorts.b) 
                                                                  != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__b__0)) 
                                                                 << 1U) 
                                                                | ((::IData)(vlSelfRef.__VprimaryPorts.a) 
                                                                   != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__a__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__a__0 = vlSelfRef.__VprimaryPorts.a;
        vlSelfRef.__Vtrigprevexpr___TOP__b__0 = vlSelfRef.__VprimaryPorts.b;
        vlSelfRef.__Vtrigprevexpr___TOP__ctrl__0 = vlSelfRef.__VprimaryPorts.ctrl;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VaddSub4bit___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = VaddSub4bit___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_body__ico
            if ((((6ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__0
                    vlSelfRef.addSub4bit__DOT__bin 
                        = (0x0000000fU & ((::IData)(vlSelfRef.__VprimaryPorts.b) 
                                          ^ (- (::IData)((::IData)(vlSelfRef.__VprimaryPorts.ctrl)))));
                }
            }
            if ((((7ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__1
                    vlSelfRef.addSub4bit__DOT__c_r 
                        = (0x0000001fU & ((::IData)(vlSelfRef.__VprimaryPorts.a) 
                                          + ((::IData)(vlSelfRef.__VprimaryPorts.ctrl) 
                                             + (::IData)(vlSelfRef.addSub4bit__DOT__bin))));
                    vlSelfRef.__VprimaryPorts.carry 
                        = (1U & ((::IData)(vlSelfRef.addSub4bit__DOT__c_r) 
                                 >> 4U));
                    vlSelfRef.__VprimaryPorts.overflow 
                        = (((1U & ((::IData)(vlSelfRef.__VprimaryPorts.a) 
                                   >> 3U)) == (1U & 
                                               ((::IData)(vlSelfRef.addSub4bit__DOT__bin) 
                                                >> 3U))) 
                           & ((1U & ((::IData)(vlSelfRef.__VprimaryPorts.a) 
                                     >> 3U)) != (1U 
                                                 & ((::IData)(vlSelfRef.addSub4bit__DOT__c_r) 
                                                    >> 3U))));
                    vlSelfRef.__VprimaryPorts.result 
                        = (0x0000000fU & (::IData)(vlSelfRef.addSub4bit__DOT__c_r));
                    vlSelfRef.__VprimaryPorts.zero 
                        = (1U & (~ (0U != (::IData)(vlSelfRef.__VprimaryPorts.result))));
                }
            }
        }
    }
    return (__VicoExecute);
}

bool VaddSub4bit___024root___eval_act(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_act\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VaddSub4bit___024root___eval_inact(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_inact\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VaddSub4bit___024root___eval_nba(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_nba\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VaddSub4bit___024root___eval_obs(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_obs\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VaddSub4bit___024root___eval_react(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_react\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void VaddSub4bit___024root___eval_postponed(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_postponed\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool VaddSub4bit___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___trigger_anySet__ico\n"); );
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
void VaddSub4bit___024root___eval_debug_assertions(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_debug_assertions\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.a & 0xf0U)))) {
        Verilated::overWidthError("a");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.b & 0xf0U)))) {
        Verilated::overWidthError("b");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.ctrl 
                      & 0xfeU)))) {
        Verilated::overWidthError("ctrl");
    }
}
#endif  // VL_DEBUG
