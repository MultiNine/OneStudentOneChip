// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsvsimTestbench.h for the primary calling header

#include "VsvsimTestbench__pch.h"

VL_ATTR_COLD void VsvsimTestbench___024root___eval_static(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_static\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_static__TOP
        vlSelfRef.svsimTestbench__DOT__clock = 0U;
        vlSelfRef.svsimTestbench__DOT__reset = 0U;
        vlSelfRef.svsimTestbench__DOT__simulationState = 0U;
        vlSelfRef.svsimTestbench__DOT__traceSupported = 0U;
    }
    vlSelfRef.__Vtrigprevexpr___TOP__svsimTestbench__DOT__simulationState__0 = 0U;
    vlSelfRef.__Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0 
        = vlSelfRef.svsimTestbench__DOT__clock;
}

VL_ATTR_COLD void VsvsimTestbench___024root___eval_initial__TOP(VsvsimTestbench___024root* vlSelf);

VL_ATTR_COLD void VsvsimTestbench___024root___eval_initial(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_initial\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VsvsimTestbench___024root___eval_initial__TOP(vlSelf);
    {
        // Inlined CFunc: __VtraceActivitySetAll
        vlSelfRef.__VtraceActivity[0U] = 1U;
        vlSelfRef.__VtraceActivity[1U] = 1U;
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD bool VsvsimTestbench___024root___eval_stl(VsvsimTestbench___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_stl\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VsvsimTestbench___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    return (0U);
}

VL_ATTR_COLD void VsvsimTestbench___024root___eval_dump_triggers__stl(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_dump_triggers__stl\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VsvsimTestbench___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void VsvsimTestbench___024root___eval_dump_triggers__ico(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_dump_triggers__ico\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VsvsimTestbench___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void VsvsimTestbench___024root___eval_dump_triggers__act(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_dump_triggers__act\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VsvsimTestbench___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void VsvsimTestbench___024root___eval_dump_triggers__nba(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_dump_triggers__nba\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    VsvsimTestbench___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void VsvsimTestbench___024root___eval_dump_triggers__obs(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_dump_triggers__obs\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VsvsimTestbench___024root___eval_dump_triggers__react(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_dump_triggers__react\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void VsvsimTestbench___024root___eval_final__TOP(VsvsimTestbench___024root* vlSelf);

VL_ATTR_COLD void VsvsimTestbench___024root___eval_final(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_final\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VsvsimTestbench___024root___eval_final__TOP(vlSelf);
}

void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__initTestBenchScope_TOP(const ::VerilatedScope* __Vscopep, const char* __Vfilenamep, ::IData/*31:0*/ __Vlineno);

VL_ATTR_COLD void VsvsimTestbench___024root___eval_initial__TOP(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_initial__TOP\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::IData/*31:0*/ svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM__BRA__0__KET__;
    svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM__BRA__0__KET__ = 0;
    ::IData/*31:0*/ svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM__BRA__1__KET__;
    svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM__BRA__1__KET__ = 0;
    // Body
    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__initTestBenchScope_TOP(
                                                                                (vlSymsp->__Vscopep_svsimTestbench), 
                                                                                "/home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv", 0x0000000eU);
    vlSelfRef.svsimTestbench__DOT__simulationState = 1U;
    svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM__BRA__0__KET__ 
        = VL_RANDOM_I();
    svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM__BRA__1__KET__ 
        = VL_RANDOM_I();
    vlSelfRef.svsimTestbench__DOT__dut__DOT__cntReg 
        = svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM__BRA__0__KET__;
    vlSelfRef.svsimTestbench__DOT__dut__DOT__blkReg 
        = (1U & svsimTestbench__DOT__dut__DOT__unnamedblk2__DOT___RANDOM__BRA__1__KET__);
}

void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_final_TOP(const ::VerilatedScope* __Vscopep, const char* __Vfilenamep, ::IData/*31:0*/ __Vlineno);

VL_ATTR_COLD void VsvsimTestbench___024root___eval_final__TOP(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_final__TOP\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_final_TOP(
                                                                                (vlSymsp->__Vscopep_svsimTestbench), 
                                                                                "/home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv", 0x0000004aU);
}

VL_ATTR_COLD bool VsvsimTestbench___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(VsvsimTestbench___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool VsvsimTestbench___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___trigger_anySet__stl\n"); );
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

bool VsvsimTestbench___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(VsvsimTestbench___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'ico' trigger - first iteration\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: Internal 'ico' trigger - DPI export trigger\n");
    }
}
#endif  // VL_DEBUG

bool VsvsimTestbench___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (::IData)(VsvsimTestbench___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( svsimTestbench.simulationState)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge svsimTestbench.clock)\n");
    }
    if ((1U & (::IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'act' trigger - DPI export trigger\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void VsvsimTestbench___024root___ctor_var_reset(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___ctor_var_reset\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->svsimTestbench__DOT__dut__DOT__cntReg = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 3732806442966273987ull);
    vlSelf->svsimTestbench__DOT__dut__DOT__blkReg = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15894904787333962195ull);
    vlSelf->__Vdpi_export_trigger = 0;
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 1);
    vlSelf->__VactTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VactTriggered.data(), sizeof(vlSelf->__VactTriggered[0]), 2);
    vlSelf->__Vtrigprevexpr___TOP__svsimTestbench__DOT__simulationState__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0 = 0;
    vlSelf->__VnbaTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VnbaTriggered.data(), sizeof(vlSelf->__VnbaTriggered[0]), 2);
    vlSelf->__VtraceActivity[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VtraceActivity.data(), sizeof(vlSelf->__VtraceActivity[0]), 2);
}
