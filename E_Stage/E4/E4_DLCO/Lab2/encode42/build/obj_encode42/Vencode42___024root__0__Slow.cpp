// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencode42.h for the primary calling header

#include "Vencode42__pch.h"

VL_ATTR_COLD void Vencode42___024root___eval_static(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_static\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__x__0 = vlSelfRef.__VprimaryPorts.x;
    vlSelfRef.__Vtrigprevexpr___TOP__en__0 = vlSelfRef.__VprimaryPorts.en;
}

VL_ATTR_COLD void Vencode42___024root___eval_initial(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_initial\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode42___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vencode42___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

VL_ATTR_COLD bool Vencode42___024root___eval_stl(Vencode42___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_stl\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vencode42___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vencode42___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
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
    return (__VstlExecute);
}

VL_ATTR_COLD void Vencode42___024root___eval_dump_triggers__stl(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_dump_triggers__stl\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vencode42___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode42___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vencode42___024root___eval_dump_triggers__ico(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_dump_triggers__ico\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vencode42___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

VL_ATTR_COLD void Vencode42___024root___eval_dump_triggers__act(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_dump_triggers__act\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vencode42___024root___eval_dump_triggers__nba(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_dump_triggers__nba\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vencode42___024root___eval_dump_triggers__obs(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_dump_triggers__obs\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vencode42___024root___eval_dump_triggers__react(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_dump_triggers__react\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vencode42___024root___eval_final(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___eval_final\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode42___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(Vencode42___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vencode42___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___trigger_anySet__stl\n"); );
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

bool Vencode42___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vencode42___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(Vencode42___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( x)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( en)\n");
    }
    if ((1U & (::IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vencode42___024root___ctor_var_reset(Vencode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vencode42___024root___ctor_var_reset\n"); );
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__VprimaryPorts.x = VL_SCOPED_RAND_RESET_I(4, __VscopeHash, 9409450202036847209ull);
    vlSelf->__VprimaryPorts.en = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7710216835639188562ull);
    vlSelf->__VprimaryPorts.y = VL_SCOPED_RAND_RESET_I(2, __VscopeHash, 11123243248953317070ull);
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 2);
    vlSelf->__Vtrigprevexpr___TOP__x__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__en__0 = 0;
}
