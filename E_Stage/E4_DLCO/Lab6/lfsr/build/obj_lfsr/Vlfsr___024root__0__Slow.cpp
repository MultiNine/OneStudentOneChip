// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlfsr.h for the primary calling header

#include "Vlfsr__pch.h"

VL_ATTR_COLD void Vlfsr___024root___eval_static(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_static\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.__VprimaryPorts.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.__VprimaryPorts.rst;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.__VprimaryPorts.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__1 = vlSelfRef.__VprimaryPorts.rst;
}

VL_ATTR_COLD void Vlfsr___024root___eval_initial(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_initial\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlfsr___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vlfsr___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
extern const ::VlWide<16>/*511:0*/ Vlfsr__ConstPool__CONST_0;

VL_ATTR_COLD bool Vlfsr___024root___eval_stl(Vlfsr___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_stl\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vlfsr___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vlfsr___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _stl_comb__TOP__0
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
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vlfsr___024root___eval_dump_triggers__stl(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_dump_triggers__stl\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vlfsr___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlfsr___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vlfsr___024root___eval_dump_triggers__ico(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_dump_triggers__ico\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vlfsr___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlfsr___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vlfsr___024root___eval_dump_triggers__act(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_dump_triggers__act\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vlfsr___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vlfsr___024root___eval_dump_triggers__nba(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_dump_triggers__nba\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vlfsr___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vlfsr___024root___eval_dump_triggers__obs(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_dump_triggers__obs\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vlfsr___024root___eval_dump_triggers__react(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_dump_triggers__react\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vlfsr___024root___eval_final(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___eval_final\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlfsr___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(Vlfsr___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vlfsr___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___trigger_anySet__stl\n"); );
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

bool Vlfsr___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlfsr___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(Vlfsr___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( rst)\n");
    }
    if ((1U & (::IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vlfsr___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vlfsr___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (::IData)(Vlfsr___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vlfsr___024root___ctor_var_reset(Vlfsr___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root___ctor_var_reset\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__VprimaryPorts.clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->__VprimaryPorts.rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->__VprimaryPorts.dout = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 11474705599699299244ull);
    vlSelf->__VprimaryPorts.segout1 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 14582337549652332160ull);
    vlSelf->__VprimaryPorts.segout0 = VL_SCOPED_RAND_RESET_I(8, __VscopeHash, 755933191293489584ull);
    vlSelf->lfsr__DOT__feedback = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 5289313506094866755ull);
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 2);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = 0;
    vlSelf->__VactTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VactTriggered.data(), sizeof(vlSelf->__VactTriggered[0]), 1);
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__1 = 0;
    vlSelf->__VnbaTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VnbaTriggered.data(), sizeof(vlSelf->__VnbaTriggered[0]), 1);
}
