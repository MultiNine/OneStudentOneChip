// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VaddSub4bit.h for the primary calling header

#include "VaddSub4bit__pch.h"

VL_ATTR_COLD void VaddSub4bit___024root___eval_static(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_static\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__a__0 = vlSelfRef.__VprimaryPorts.a;
    vlSelfRef.__Vtrigprevexpr___TOP__b__0 = vlSelfRef.__VprimaryPorts.b;
    vlSelfRef.__Vtrigprevexpr___TOP__ctrl__0 = vlSelfRef.__VprimaryPorts.ctrl;
}

VL_ATTR_COLD void VaddSub4bit___024root___eval_initial(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_initial\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VaddSub4bit___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VaddSub4bit___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

VL_ATTR_COLD bool VaddSub4bit___024root___eval_stl(VaddSub4bit___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_stl\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VaddSub4bit___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = VaddSub4bit___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _stl_comb__TOP__0
                    vlSelfRef.addSub4bit__DOT__bin 
                        = (0x0000000fU & ((::IData)(vlSelfRef.__VprimaryPorts.b) 
                                          ^ (- (::IData)((::IData)(vlSelfRef.__VprimaryPorts.ctrl)))));
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
    return (__VstlExecute);
}

VL_ATTR_COLD void VaddSub4bit___024root___eval_dump_triggers__stl(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_dump_triggers__stl\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VaddSub4bit___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VaddSub4bit___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void VaddSub4bit___024root___eval_dump_triggers__ico(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_dump_triggers__ico\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VaddSub4bit___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

VL_ATTR_COLD void VaddSub4bit___024root___eval_dump_triggers__act(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_dump_triggers__act\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VaddSub4bit___024root___eval_dump_triggers__nba(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_dump_triggers__nba\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VaddSub4bit___024root___eval_dump_triggers__obs(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_dump_triggers__obs\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VaddSub4bit___024root___eval_dump_triggers__react(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_dump_triggers__react\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VaddSub4bit___024root___eval_final(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___eval_final\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VaddSub4bit___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(VaddSub4bit___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VaddSub4bit___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___trigger_anySet__stl\n"); );
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

bool VaddSub4bit___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VaddSub4bit___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(VaddSub4bit___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( a)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( b)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( ctrl)\n");
    }
    if ((1U & (::IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VaddSub4bit___024root___ctor_var_reset(VaddSub4bit___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root___ctor_var_reset\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__VprimaryPorts.a = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 510903276987443985ull);
    vlSelf->__VprimaryPorts.b = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16900879642891266615ull);
    vlSelf->__VprimaryPorts.ctrl = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10440442894316637683ull);
    vlSelf->__VprimaryPorts.carry = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16970673489425401941ull);
    vlSelf->__VprimaryPorts.zero = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 10977623970759875275ull);
    vlSelf->__VprimaryPorts.overflow = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16341344440165733293ull);
    vlSelf->__VprimaryPorts.result = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 16664408842984530663ull);
    vlSelf->addSub4bit__DOT__bin = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 13260341804653031315ull);
    vlSelf->addSub4bit__DOT__c_r = VL_SCOPED_RAND_RESET_I(5, __VscopeHash, 11078917549277720182ull);
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 2);
    vlSelf->__Vtrigprevexpr___TOP__a__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__b__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ctrl__0 = 0;
}
