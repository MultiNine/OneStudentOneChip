// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsCPU.h for the primary calling header

#include "VsCPU__pch.h"

void VsCPU___024root___eval_sample(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_sample\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsCPU___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

bool VsCPU___024root___eval_ico(VsCPU___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_ico\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (::IData)((::IData)(firstIteration)));
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (::QData)((::IData)(
                                                            ((((::IData)(vlSelfRef.__VprimaryPorts.datain) 
                                                               != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__datain__0)) 
                                                              << 2U) 
                                                             | ((((::IData)(vlSelfRef.__VprimaryPorts.rst) 
                                                                  != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__0)) 
                                                                 << 1U) 
                                                                | ((::IData)(vlSelfRef.__VprimaryPorts.clk) 
                                                                   != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.__VprimaryPorts.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.__VprimaryPorts.rst;
        vlSelfRef.__Vtrigprevexpr___TOP__datain__0 
            = vlSelfRef.__VprimaryPorts.datain;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VsCPU___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsCPU___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
void VsCPU___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in);

bool VsCPU___024root___eval_act(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_act\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (::QData)((::IData)(
                                                            ((((::IData)(vlSelfRef.__VprimaryPorts.rst) 
                                                               & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__rst__1))) 
                                                              << 1U) 
                                                             | ((::IData)(vlSelfRef.__VprimaryPorts.clk) 
                                                                & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__1))))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.__VprimaryPorts.clk;
        vlSelfRef.__Vtrigprevexpr___TOP__rst__1 = vlSelfRef.__VprimaryPorts.rst;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VsCPU___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    VsCPU___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

bool VsCPU___024root___eval_inact(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_inact\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VsCPU___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
void VsCPU___024root___nba_sequent__TOP__0(VsCPU___024root* vlSelf);
void VsCPU___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out);

bool VsCPU___024root___eval_nba(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_nba\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VsCPU___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((((3ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                VsCPU___024root___nba_sequent__TOP__0(vlSelf);
            }
        }
        VsCPU___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool VsCPU___024root___eval_obs(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_obs\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VsCPU___024root___eval_react(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_react\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void VsCPU___024root___eval_postponed(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_postponed\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool VsCPU___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___trigger_anySet__ico\n"); );
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

bool VsCPU___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___trigger_anySet__act\n"); );
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

extern const ::VlUnpacked<::CData/*7:0*/, 16> VsCPU__ConstPool__CONSARRAY_1;
extern const ::VlWide<16>/*511:0*/ VsCPU__ConstPool__CONST_1;
extern const ::VlWide<16>/*511:0*/ VsCPU__ConstPool__CONST_0;

void VsCPU___024root___nba_sequent__TOP__0(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___nba_sequent__TOP__0\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __Vdly_Set__sCPU__DOT__u_GPR__DOT__gpr_3;
    __Vdly_Set__sCPU__DOT__u_GPR__DOT__gpr_3 = 0;
    ::CData/*7:0*/ __Vdly_Val__sCPU__DOT__u_GPR__DOT__gpr_4;
    __Vdly_Val__sCPU__DOT__u_GPR__DOT__gpr_4 = 0;
    ::CData/*1:0*/ __Vdly_Dim0__sCPU__DOT__u_GPR__DOT__gpr_5;
    __Vdly_Dim0__sCPU__DOT__u_GPR__DOT__gpr_5 = 0;
    ::CData/*0:0*/ __Vdly_Set__sCPU__DOT__u_GPR__DOT__gpr_6;
    __Vdly_Set__sCPU__DOT__u_GPR__DOT__gpr_6 = 0;
    // Body
    __Vdly_Set__sCPU__DOT__u_GPR__DOT__gpr_3 = 0U;
    __Vdly_Set__sCPU__DOT__u_GPR__DOT__gpr_6 = 0U;
    if (vlSelfRef.__VprimaryPorts.rst) {
        vlSelfRef.sCPU__DOT__u_PC__DOT__PCout = 0U;
        __Vdly_Set__sCPU__DOT__u_GPR__DOT__gpr_3 = 1U;
        vlSelfRef.__VprimaryPorts.out_led = 0U;
        vlSelfRef.sCPU__DOT__out_seg = 0U;
    } else {
        vlSelfRef.sCPU__DOT__u_PC__DOT__PCout = (0x000000ffU 
                                                 & ((::IData)(vlSelfRef.sCPU__DOT__u_PC__DOT__PCout) 
                                                    + 
                                                    ((::IData)(
                                                               ((0xc0U 
                                                                 == 
                                                                 (0xc0U 
                                                                  & (::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins))) 
                                                                & (vlSelfRef.sCPU__DOT__u_GPR__DOT__gpr
                                                                   [
                                                                   (3U 
                                                                    & (((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                                        >> 2U) 
                                                                       & (- (::IData)(
                                                                                (3U 
                                                                                != 
                                                                                (3U 
                                                                                & ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                                                >> 6U)))))))] 
                                                                   != vlSelfRef.sCPU__DOT__u_GPR__DOT__gpr
                                                                   [
                                                                   (3U 
                                                                    & ((1U 
                                                                        == 
                                                                        (3U 
                                                                         & ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                                            >> 6U)))
                                                                        ? 
                                                                       ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                                        >> 4U)
                                                                        : (::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins)))])))
                                                      ? 
                                                     ((0x000000f0U 
                                                       & ((- (::IData)(
                                                                       (1U 
                                                                        & ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                                           >> 5U)))) 
                                                          << 4U)) 
                                                      | (0x0000000fU 
                                                         & ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                            >> 2U)))
                                                      : 1U)));
        if (((0U == (3U & ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                           >> 6U))) | ((2U == (3U & 
                                               ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                >> 6U))) 
                                       | (::IData)(vlSelfRef.__Vdfg_Regularize_22)))) {
            __Vdly_Val__sCPU__DOT__u_GPR__DOT__gpr_4 
                = (0x000000ffU & ((::IData)(vlSelfRef.__Vdfg_Regularize_22)
                                   ? (::IData)(vlSelfRef.__VprimaryPorts.datain)
                                   : ((0U == (3U & 
                                              ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                               >> 6U)))
                                       ? ((::IData)(vlSelfRef.sCPU__DOT__u_GPR__DOT__gpr
                                                    [
                                                    (3U 
                                                     & (((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                         >> 2U) 
                                                        & (- (::IData)(
                                                                       (3U 
                                                                        != 
                                                                        (3U 
                                                                         & ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                                            >> 6U)))))))]) 
                                          + (::IData)(vlSelfRef.sCPU__DOT__u_GPR__DOT__gpr
                                                      [
                                                      (3U 
                                                       & ((1U 
                                                           == 
                                                           (3U 
                                                            & ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                               >> 6U)))
                                                           ? 
                                                          ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                           >> 4U)
                                                           : (::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins)))]))
                                       : VsCPU__ConstPool__CONSARRAY_1
                                      [((0x0000000cU 
                                         & ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                            << 2U)) 
                                        | (3U & ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                 >> 2U)))])));
            __Vdly_Dim0__sCPU__DOT__u_GPR__DOT__gpr_5 
                = (3U & ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                         >> 4U));
            __Vdly_Set__sCPU__DOT__u_GPR__DOT__gpr_6 = 1U;
        }
        if ((::IData)((0x48U == (0xc9U & (::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins))))) {
            vlSelfRef.__VprimaryPorts.out_led = vlSelfRef.sCPU__DOT__u_GPR__DOT__gpr
                [(3U & ((1U == (3U & ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                      >> 6U))) ? ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                  >> 4U)
                         : (::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins)))];
        }
        if ((::IData)((0x49U == (0xc9U & (::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins))))) {
            vlSelfRef.sCPU__DOT__out_seg = vlSelfRef.sCPU__DOT__u_GPR__DOT__gpr
                [(3U & ((1U == (3U & ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                      >> 6U))) ? ((::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins) 
                                                  >> 4U)
                         : (::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins)))];
        }
    }
    if (__Vdly_Set__sCPU__DOT__u_GPR__DOT__gpr_3) {
        vlSelfRef.sCPU__DOT__u_GPR__DOT__gpr[0U] = 0U;
        vlSelfRef.sCPU__DOT__u_GPR__DOT__gpr[1U] = 0U;
        vlSelfRef.sCPU__DOT__u_GPR__DOT__gpr[2U] = 0U;
        vlSelfRef.sCPU__DOT__u_GPR__DOT__gpr[3U] = 0U;
    }
    if (__Vdly_Set__sCPU__DOT__u_GPR__DOT__gpr_6) {
        vlSelfRef.sCPU__DOT__u_GPR__DOT__gpr[__Vdly_Dim0__sCPU__DOT__u_GPR__DOT__gpr_5] 
            = __Vdly_Val__sCPU__DOT__u_GPR__DOT__gpr_4;
    }
    vlSelfRef.sCPU__DOT__u_insROM__DOT__ins = (0x000000ffU 
                                               & VsCPU__ConstPool__CONST_1
                                               [(0x0000000fU 
                                                 & (::IData)(vlSelfRef.sCPU__DOT__u_PC__DOT__PCout))]);
    vlSelfRef.__VprimaryPorts.segh0 = (0x000000ffU 
                                       & VsCPU__ConstPool__CONST_0
                                       [(0x0000000fU 
                                         & (::IData)(vlSelfRef.sCPU__DOT__out_seg))]);
    vlSelfRef.__VprimaryPorts.segh1 = (0x000000ffU 
                                       & VsCPU__ConstPool__CONST_0
                                       [(0x0000000fU 
                                         & ((::IData)(vlSelfRef.sCPU__DOT__out_seg) 
                                            >> 4U))]);
    vlSelfRef.__Vdfg_Regularize_22 = (::IData)((0x40U 
                                                == 
                                                (0xc8U 
                                                 & (::IData)(vlSelfRef.sCPU__DOT__u_insROM__DOT__ins))));
}

void VsCPU___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((::IData)(1U) + n);
    } while ((0U >= n));
}

void VsCPU___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___trigger_clear__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((::IData)(1U) + n);
    } while ((1U > n));
}

#ifdef VL_DEBUG
void VsCPU___024root___eval_debug_assertions(VsCPU___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsCPU___024root___eval_debug_assertions\n"); );
    VsCPU__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.clk 
                      & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.rst 
                      & 0xfeU)))) {
        Verilated::overWidthError("rst");
    }
}
#endif  // VL_DEBUG
