// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsCPU.h for the primary calling header

#include "VsCPU__pch.h"

VL_ATTR_COLD void VsCPU___024root___eval_static(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_static\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.__VprimaryPorts.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.__VprimaryPorts.rst;
    vlSelfRef.__Vtrigprevexpr___TOP__datain__0 = vlSelfRef.__VprimaryPorts.datain;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.__VprimaryPorts.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__1 = vlSelfRef.__VprimaryPorts.rst;
}

VL_ATTR_COLD void VsCPU___024root___eval_initial(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_initial\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsCPU___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool VsCPU___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
extern const ::VlWide<16>/*511:0*/ VsCPU__ConstPool__CONST_0;
extern const ::VlWide<16>/*511:0*/ VsCPU__ConstPool__CONST_1;

VL_ATTR_COLD bool VsCPU___024root___eval_stl(VsCPU___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_stl\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VsCPU___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = VsCPU___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _stl_comb__TOP__0
                    vlSelfRef.__VprimaryPorts.segh0 
                        = (0x000000ffU & VsCPU__ConstPool__CONST_0
                           [(0x0000000fU & (::IData)(vlSelfRef.sCPU__DOT__out_seg))]);
                    vlSelfRef.__VprimaryPorts.segh1 
                        = (0x000000ffU & VsCPU__ConstPool__CONST_0
                           [(0x0000000fU & ((::IData)(vlSelfRef.sCPU__DOT__out_seg) 
                                            >> 4U))]);
                    vlSelfRef.sCPU__DOT__u_insROM__DOT__ins 
                        = (0x000000ffU & VsCPU__ConstPool__CONST_1
                           [(0x0000000fU & (::IData)(vlSelfRef.sCPU__DOT__u_PC__DOT__PCout))]);
                    vlSelfRef.__Vdfg_Regularize_22 
                        = (::IData)((0x40U == (0xc8U 
                                               & (::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins))));
                }
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void VsCPU___024root___eval_dump_triggers__stl(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_dump_triggers__stl\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VsCPU___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsCPU___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void VsCPU___024root___eval_dump_triggers__ico(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_dump_triggers__ico\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VsCPU___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsCPU___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void VsCPU___024root___eval_dump_triggers__act(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_dump_triggers__act\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VsCPU___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void VsCPU___024root___eval_dump_triggers__nba(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_dump_triggers__nba\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VsCPU___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void VsCPU___024root___eval_dump_triggers__obs(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_dump_triggers__obs\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VsCPU___024root___eval_dump_triggers__react(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_dump_triggers__react\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VsCPU___024root___eval_final(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_final\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsCPU___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(VsCPU___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VsCPU___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___trigger_anySet__stl\n"); );
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

bool VsCPU___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VsCPU___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(VsCPU___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( rst)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( datain)\n");
    }
    if ((1U & (::IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool VsCPU___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VsCPU___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (::IData)(VsCPU___024root___trigger_anySet__act(triggers))))) {
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

VL_ATTR_COLD void VsCPU___024root___ctor_var_reset(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___ctor_var_reset\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__VprimaryPorts.clk = 0;
    vlSelf->__VprimaryPorts.rst = 0;
    vlSelf->__VprimaryPorts.datain = 0;
    vlSelf->__VprimaryPorts.out_led = 0;
    vlSelf->__VprimaryPorts.segh0 = 0;
    vlSelf->__VprimaryPorts.segh1 = 0;
    vlSelf->sCPU__DOT__out_seg = 0;
    vlSelf->sCPU__DOT__u_GPR__DOT__gpr[0] = 0;
    VL_UNPACKED_FILL(vlSelf->sCPU__DOT__u_GPR__DOT__gpr.data(), sizeof(vlSelf->sCPU__DOT__u_GPR__DOT__gpr[0]), 4);
    vlSelf->sCPU__DOT__u_insROM__DOT__ins = 0;
    vlSelf->sCPU__DOT__u_PC__DOT__PCout = 0;
    vlSelf->__Vdfg_Regularize_22 = 0;
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 2);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__datain__0 = 0;
    vlSelf->__VactTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VactTriggered.data(), sizeof(vlSelf->__VactTriggered[0]), 1);
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__1 = 0;
    vlSelf->__VnbaTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VnbaTriggered.data(), sizeof(vlSelf->__VnbaTriggered[0]), 1);
}
