// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VpriEncode83.h for the primary calling header

#include "VpriEncode83__pch.h"

VL_ATTR_COLD void VpriEncode83___024root___eval_static(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_static\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__en__0 = vlSelfRef.__VprimaryPorts.en;
    vlSelfRef.__Vtrigprevexpr___TOP__x__0 = vlSelfRef.__VprimaryPorts.x;
}

VL_ATTR_COLD void VpriEncode83___024root___eval_initial(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_initial\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VpriEncode83___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VpriEncode83___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
extern const ::VlWide<256>/*8191:0*/ VpriEncode83__ConstPool__CONST_1;
extern const ::VlWide<256>/*8191:0*/ VpriEncode83__ConstPool__CONST_0;
extern const ::VlWide<16>/*511:0*/ VpriEncode83__ConstPool__CONST_2;

VL_ATTR_COLD bool VpriEncode83___024root___eval_stl(VpriEncode83___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_stl\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VpriEncode83___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = VpriEncode83___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _stl_comb__TOP__0
                    vlSelfRef.__Vdfg_Regularize_19 
                        = (0x0000000fU & VpriEncode83__ConstPool__CONST_1
                           [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.x))]);
                    vlSelfRef.__Vdfg_Regularize_20 
                        = (0x0000000fU & VpriEncode83__ConstPool__CONST_0
                           [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.x))]);
                    if (vlSelfRef.__VprimaryPorts.en) {
                        vlSelfRef.__VprimaryPorts.y 
                            = (7U & ((::IData)(vlSelfRef.__Vdfg_Regularize_20) 
                                     >> 1U));
                        vlSelfRef.__VprimaryPorts.validIn 
                            = (1U & (::IData)(vlSelfRef.__Vdfg_Regularize_20));
                    } else {
                        vlSelfRef.__VprimaryPorts.y 
                            = (7U & ((::IData)(vlSelfRef.__Vdfg_Regularize_19) 
                                     >> 1U));
                        vlSelfRef.__VprimaryPorts.validIn 
                            = (1U & (::IData)(vlSelfRef.__Vdfg_Regularize_19));
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
    return (__VstlExecute);
}

VL_ATTR_COLD void VpriEncode83___024root___eval_dump_triggers__stl(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_dump_triggers__stl\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VpriEncode83___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VpriEncode83___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void VpriEncode83___024root___eval_dump_triggers__ico(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_dump_triggers__ico\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VpriEncode83___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

VL_ATTR_COLD void VpriEncode83___024root___eval_dump_triggers__act(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_dump_triggers__act\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VpriEncode83___024root___eval_dump_triggers__nba(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_dump_triggers__nba\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VpriEncode83___024root___eval_dump_triggers__obs(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_dump_triggers__obs\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VpriEncode83___024root___eval_dump_triggers__react(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_dump_triggers__react\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VpriEncode83___024root___eval_final(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___eval_final\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VpriEncode83___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(VpriEncode83___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VpriEncode83___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___trigger_anySet__stl\n"); );
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

bool VpriEncode83___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VpriEncode83___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(VpriEncode83___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( en)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( x)\n");
    }
    if ((1U & (::IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VpriEncode83___024root___ctor_var_reset(VpriEncode83___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root___ctor_var_reset\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__VprimaryPorts.en = 0;
    vlSelf->__VprimaryPorts.x = 0;
    vlSelf->__VprimaryPorts.validIn = 0;
    vlSelf->__VprimaryPorts.y = 0;
    vlSelf->__VprimaryPorts.segOut = 0;
    vlSelf->__Vdfg_Regularize_19 = 0;
    vlSelf->__Vdfg_Regularize_20 = 0;
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 2);
    vlSelf->__Vtrigprevexpr___TOP__en__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__x__0 = 0;
}
