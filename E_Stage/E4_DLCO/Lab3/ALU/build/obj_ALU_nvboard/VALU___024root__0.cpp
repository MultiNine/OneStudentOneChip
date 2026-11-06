// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "VALU__pch.h"

void VALU___024root___eval_sample(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_sample\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
bool VALU___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);
extern const ::VlWide<16>/*511:0*/ VALU__ConstPool__CONST_0;

bool VALU___024root___eval_ico(VALU___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_ico\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
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
                                                            ((((::IData)(vlSelfRef.__VprimaryPorts.aluop) 
                                                               != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__aluop__0)) 
                                                              << 2U) 
                                                             | ((((::IData)(vlSelfRef.__VprimaryPorts.B) 
                                                                  != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__B__0)) 
                                                                 << 1U) 
                                                                | ((::IData)(vlSelfRef.__VprimaryPorts.A) 
                                                                   != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__A__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__A__0 = vlSelfRef.__VprimaryPorts.A;
        vlSelfRef.__Vtrigprevexpr___TOP__B__0 = vlSelfRef.__VprimaryPorts.B;
        vlSelfRef.__Vtrigprevexpr___TOP__aluop__0 = vlSelfRef.__VprimaryPorts.aluop;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VALU___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = VALU___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_body__ico
            if ((((1ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__0
                    vlSelfRef.__VprimaryPorts.segA 
                        = (0x000000ffU & VALU__ConstPool__CONST_0
                           [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.A))]);
                }
            }
            if ((((2ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__1
                    vlSelfRef.__VprimaryPorts.segB 
                        = (0x000000ffU & VALU__ConstPool__CONST_0
                           [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.B))]);
                }
            }
            if ((((6ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__2
                    vlSelfRef.ALU__DOT__u_addSub4bit__DOT__bin 
                        = (0x0000000fU & ((::IData)(vlSelfRef.__VprimaryPorts.B) 
                                          ^ (- (::IData)(
                                                         (0U 
                                                          != (::IData)(vlSelfRef.__VprimaryPorts.aluop))))));
                }
            }
            if ((((7ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__3
                    ::CData/*4:0*/ __Vinline_0__eval_body__ico___Vinline_0__ico_comb__TOP__3_ALU__DOT__u_addSub4bit__DOT__c_r;
                    __Vinline_0__eval_body__ico___Vinline_0__ico_comb__TOP__3_ALU__DOT__u_addSub4bit__DOT__c_r = 0;
                    __Vinline_0__eval_body__ico___Vinline_0__ico_comb__TOP__3_ALU__DOT__u_addSub4bit__DOT__c_r 
                        = (0x0000001fU & ((::IData)(vlSelfRef.__VprimaryPorts.A) 
                                          + ((0U != (::IData)(vlSelfRef.__VprimaryPorts.aluop)) 
                                             + (::IData)(vlSelfRef.ALU__DOT__u_addSub4bit__DOT__bin))));
                    vlSelfRef.__VprimaryPorts.carry 
                        = (1U & ((::IData)(__Vinline_0__eval_body__ico___Vinline_0__ico_comb__TOP__3_ALU__DOT__u_addSub4bit__DOT__c_r) 
                                 >> 4U));
                    vlSelfRef.__VprimaryPorts.zero 
                        = (1U & (~ (0U != (0x0000000fU 
                                           & (::IData)(__Vinline_0__eval_body__ico___Vinline_0__ico_comb__TOP__3_ALU__DOT__u_addSub4bit__DOT__c_r)))));
                    vlSelfRef.__VprimaryPorts.overflow 
                        = (((1U & ((::IData)(vlSelfRef.__VprimaryPorts.A) 
                                   >> 3U)) == (1U & 
                                               ((::IData)(vlSelfRef.ALU__DOT__u_addSub4bit__DOT__bin) 
                                                >> 3U))) 
                           & ((1U & ((::IData)(vlSelfRef.__VprimaryPorts.A) 
                                     >> 3U)) != (1U 
                                                 & ((::IData)(__Vinline_0__eval_body__ico___Vinline_0__ico_comb__TOP__3_ALU__DOT__u_addSub4bit__DOT__c_r) 
                                                    >> 3U))));
                    vlSelfRef.__VprimaryPorts.out = 
                        (0x0000000fU & ((4U & (::IData)(vlSelfRef.__VprimaryPorts.aluop))
                                         ? ((2U & (::IData)(vlSelfRef.__VprimaryPorts.aluop))
                                             ? (1U 
                                                & ((1U 
                                                    & (::IData)(vlSelfRef.__VprimaryPorts.aluop))
                                                    ? (::IData)(vlSelfRef.__VprimaryPorts.zero)
                                                    : 
                                                   ((::IData)(vlSelfRef.__VprimaryPorts.overflow) 
                                                    ^ 
                                                    ((::IData)(__Vinline_0__eval_body__ico___Vinline_0__ico_comb__TOP__3_ALU__DOT__u_addSub4bit__DOT__c_r) 
                                                     >> 3U))))
                                             : ((1U 
                                                 & (::IData)(vlSelfRef.__VprimaryPorts.aluop))
                                                 ? 
                                                ((::IData)(vlSelfRef.__VprimaryPorts.A) 
                                                 ^ (::IData)(vlSelfRef.__VprimaryPorts.B))
                                                 : 
                                                ((::IData)(vlSelfRef.__VprimaryPorts.A) 
                                                 | (::IData)(vlSelfRef.__VprimaryPorts.B))))
                                         : ((2U & (::IData)(vlSelfRef.__VprimaryPorts.aluop))
                                             ? ((1U 
                                                 & (::IData)(vlSelfRef.__VprimaryPorts.aluop))
                                                 ? 
                                                ((::IData)(vlSelfRef.__VprimaryPorts.A) 
                                                 & (::IData)(vlSelfRef.__VprimaryPorts.B))
                                                 : 
                                                (~ (::IData)(vlSelfRef.__VprimaryPorts.A)))
                                             : (::IData)(__Vinline_0__eval_body__ico___Vinline_0__ico_comb__TOP__3_ALU__DOT__u_addSub4bit__DOT__c_r))));
                    vlSelfRef.__VprimaryPorts.segOut 
                        = (0x000000ffU & VALU__ConstPool__CONST_0
                           [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.out))]);
                }
            }
        }
    }
    return (__VicoExecute);
}

bool VALU___024root___eval_act(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_act\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VALU___024root___eval_inact(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_inact\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VALU___024root___eval_nba(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_nba\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VALU___024root___eval_obs(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_obs\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VALU___024root___eval_react(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_react\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void VALU___024root___eval_postponed(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_postponed\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool VALU___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___trigger_anySet__ico\n"); );
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
void VALU___024root___eval_debug_assertions(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_debug_assertions\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.A & 0xf0U)))) {
        Verilated::overWidthError("A");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.B & 0xf0U)))) {
        Verilated::overWidthError("B");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.aluop 
                      & 0xf8U)))) {
        Verilated::overWidthError("aluop");
    }
}
#endif  // VL_DEBUG
