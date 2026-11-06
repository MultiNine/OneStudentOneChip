// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "VALU__pch.h"

VL_ATTR_COLD void VALU___024root___eval_static(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_static\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__A__0 = vlSelfRef.__VprimaryPorts.A;
    vlSelfRef.__Vtrigprevexpr___TOP__B__0 = vlSelfRef.__VprimaryPorts.B;
    vlSelfRef.__Vtrigprevexpr___TOP__aluop__0 = vlSelfRef.__VprimaryPorts.aluop;
}

VL_ATTR_COLD void VALU___024root___eval_initial(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_initial\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VALU___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
extern const ::VlWide<16>/*511:0*/ VALU__ConstPool__CONST_0;

VL_ATTR_COLD bool VALU___024root___eval_stl(VALU___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_stl\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VALU___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = VALU___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _stl_comb__TOP__0
                    ::CData/*4:0*/ __Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_ALU__DOT__u_addSub4bit__DOT__c_r;
                    __Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_ALU__DOT__u_addSub4bit__DOT__c_r = 0;
                    vlSelfRef.__VprimaryPorts.segA 
                        = (0x000000ffU & VALU__ConstPool__CONST_0
                           [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.A))]);
                    vlSelfRef.__VprimaryPorts.segB 
                        = (0x000000ffU & VALU__ConstPool__CONST_0
                           [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.B))]);
                    vlSelfRef.ALU__DOT__u_addSub4bit__DOT__bin 
                        = (0x0000000fU & ((::IData)(vlSelfRef.__VprimaryPorts.B) 
                                          ^ (- (::IData)(
                                                         (0U 
                                                          != (::IData)(vlSelfRef.__VprimaryPorts.aluop))))));
                    __Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_ALU__DOT__u_addSub4bit__DOT__c_r 
                        = (0x0000001fU & ((::IData)(vlSelfRef.__VprimaryPorts.A) 
                                          + ((0U != (::IData)(vlSelfRef.__VprimaryPorts.aluop)) 
                                             + (::IData)(vlSelfRef.ALU__DOT__u_addSub4bit__DOT__bin))));
                    vlSelfRef.__VprimaryPorts.carry 
                        = (1U & ((::IData)(__Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_ALU__DOT__u_addSub4bit__DOT__c_r) 
                                 >> 4U));
                    vlSelfRef.__VprimaryPorts.zero 
                        = (1U & (~ (0U != (0x0000000fU 
                                           & (::IData)(__Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_ALU__DOT__u_addSub4bit__DOT__c_r)))));
                    vlSelfRef.__VprimaryPorts.overflow 
                        = (((1U & ((::IData)(vlSelfRef.__VprimaryPorts.A) 
                                   >> 3U)) == (1U & 
                                               ((::IData)(vlSelfRef.ALU__DOT__u_addSub4bit__DOT__bin) 
                                                >> 3U))) 
                           & ((1U & ((::IData)(vlSelfRef.__VprimaryPorts.A) 
                                     >> 3U)) != (1U 
                                                 & ((::IData)(__Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_ALU__DOT__u_addSub4bit__DOT__c_r) 
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
                                                    ((::IData)(__Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_ALU__DOT__u_addSub4bit__DOT__c_r) 
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
                                             : (::IData)(__Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_ALU__DOT__u_addSub4bit__DOT__c_r))));
                    vlSelfRef.__VprimaryPorts.segOut 
                        = (0x000000ffU & VALU__ConstPool__CONST_0
                           [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.out))]);
                }
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void VALU___024root___eval_dump_triggers__stl(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_dump_triggers__stl\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VALU___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void VALU___024root___eval_dump_triggers__ico(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_dump_triggers__ico\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VALU___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

VL_ATTR_COLD void VALU___024root___eval_dump_triggers__act(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_dump_triggers__act\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VALU___024root___eval_dump_triggers__nba(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_dump_triggers__nba\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VALU___024root___eval_dump_triggers__obs(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_dump_triggers__obs\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VALU___024root___eval_dump_triggers__react(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_dump_triggers__react\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VALU___024root___eval_final(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___eval_final\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(VALU___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VALU___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___trigger_anySet__stl\n"); );
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

bool VALU___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VALU___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(VALU___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( A)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( B)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( aluop)\n");
    }
    if ((1U & (::IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VALU___024root___ctor_var_reset(VALU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VALU___024root___ctor_var_reset\n"); );
    VALU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__VprimaryPorts.A = 0;
    vlSelf->__VprimaryPorts.B = 0;
    vlSelf->__VprimaryPorts.aluop = 0;
    vlSelf->__VprimaryPorts.out = 0;
    vlSelf->__VprimaryPorts.carry = 0;
    vlSelf->__VprimaryPorts.overflow = 0;
    vlSelf->__VprimaryPorts.zero = 0;
    vlSelf->__VprimaryPorts.segA = 0;
    vlSelf->__VprimaryPorts.segB = 0;
    vlSelf->__VprimaryPorts.segOut = 0;
    vlSelf->ALU__DOT__u_addSub4bit__DOT__bin = 0;
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 2);
    vlSelf->__Vtrigprevexpr___TOP__A__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__B__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__aluop__0 = 0;
}
