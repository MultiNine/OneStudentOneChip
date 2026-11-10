// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsvsimTestbench.h for the primary calling header

#include "VsvsimTestbench__pch.h"

extern "C" void initTestBenchScope();

void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__initTestBenchScope_TOP(const ::VerilatedScope* __Vscopep, const char* __Vfilenamep, ::IData/*31:0*/ __Vlineno) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__initTestBenchScope_TOP\n"); );
    // Body
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    initTestBenchScope();
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_clock_TOP\n"); );
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ value_clock) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_clock_TOP\n"); );
    // Body
    vlSymsp->vlInst.TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->vlInst.TOP.svsimTestbench__DOT__clock 
        = value_clock;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ &value_clock) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_clock_TOP\n"); );
    // Body
    value_clock = vlSymsp->vlInst.TOP.svsimTestbench__DOT__clock;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_reset_TOP\n"); );
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ value_reset) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_reset_TOP\n"); );
    // Body
    vlSymsp->vlInst.TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->vlInst.TOP.svsimTestbench__DOT__reset 
        = value_reset;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ &value_reset) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_reset_TOP\n"); );
    // Body
    value_reset = vlSymsp->vlInst.TOP.svsimTestbench__DOT__reset;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_led_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &value) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_led_TOP\n"); );
    // Body
    value = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_led_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ &value_io_led) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_led_TOP\n"); );
    // Body
    value_io_led = vlSymsp->vlInst.TOP.svsimTestbench__DOT__dut__DOT__blkReg;
}

extern "C" int simulation_body();

void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_body_TOP(const ::VerilatedScope* __Vscopep, const char* __Vfilenamep, ::IData/*31:0*/ __Vlineno) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_body_TOP\n"); );
    // Body
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    simulation_body();
}

extern "C" int simulation_final();

void VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_final_TOP(const ::VerilatedScope* __Vscopep, const char* __Vfilenamep, ::IData/*31:0*/ __Vlineno) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_final_TOP\n"); );
    // Body
    Verilated::dpiContext(__Vscopep, __Vfilenamep, __Vlineno);
    simulation_final();
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_initializeTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::std::string traceFilePath) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_initializeTrace_TOP\n"); );
    // Body
    vlSymsp->vlInst.TOP.__Vdpi_export_trigger = 1U;
    vlSymsp->_vm_contextp__->dumpfile(VL_CONCATN_NNN(traceFilePath, ".vcd"s));
    vlSymsp->_traceDumpOpen();
    vlSymsp->vlInst.TOP.svsimTestbench__DOT__traceSupported = 1U;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_enableTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &success) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_enableTrace_TOP\n"); );
    // Body
    success = vlSymsp->vlInst.TOP.svsimTestbench__DOT__traceSupported;
}

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_disableTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &success) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_disableTrace_TOP\n"); );
    // Body
    success = vlSymsp->vlInst.TOP.svsimTestbench__DOT__traceSupported;
}

void VsvsimTestbench___024root___eval_sample(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_sample\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

bool VsvsimTestbench___024root___eval_ico(VsvsimTestbench___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_ico\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = ((0xfffffffffffffffdULL 
                                          & vlSelfRef.__VicoTriggered[0U]) 
                                         | ((::QData)((::IData)(vlSelfRef.__Vdpi_export_trigger)) 
                                            << 1U));
        vlSelfRef.__Vdpi_export_trigger = 0U;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VsvsimTestbench___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VsvsimTestbench___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
void VsvsimTestbench___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 2> &out, const ::VlUnpacked<::QData/*63:0*/, 2> &in);
bool VsvsimTestbench___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 2> &in);
void VsvsimTestbench___024root___act_sequent__TOP__0(VsvsimTestbench___024root* vlSelf);

bool VsvsimTestbench___024root___eval_act(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_act\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VactExecute;
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[1U] = ((0xfffffffffffffffeULL 
                                          & vlSelfRef.__VactTriggered[1U]) 
                                         | (::IData)((::IData)(vlSelfRef.__Vdpi_export_trigger)));
        vlSelfRef.__Vdpi_export_trigger = 0U;
        vlSelfRef.__VactTriggered[0U] = (::QData)((::IData)(
                                                            ((((::IData)(vlSelfRef.svsimTestbench__DOT__clock) 
                                                               & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0))) 
                                                              << 1U) 
                                                             | (vlSelfRef.svsimTestbench__DOT__simulationState 
                                                                != vlSelfRef.__Vtrigprevexpr___TOP__svsimTestbench__DOT__simulationState__0))));
        vlSelfRef.__Vtrigprevexpr___TOP__svsimTestbench__DOT__simulationState__0 
            = vlSelfRef.svsimTestbench__DOT__simulationState;
        vlSelfRef.__Vtrigprevexpr___TOP__svsimTestbench__DOT__clock__0 
            = vlSelfRef.svsimTestbench__DOT__clock;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VsvsimTestbench___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    VsvsimTestbench___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    __VactExecute = VsvsimTestbench___024root___trigger_anySet__act(vlSelfRef.__VactTriggered);
    if (__VactExecute) {
        {
            // Inlined CFunc: _eval_body__act
            if ((((1ULL & vlSelfRef.__VactTriggered[0U])) != 0ULL)) {
                VsvsimTestbench___024root___act_sequent__TOP__0(vlSelf);
            }
        }
    }
    return (__VactExecute);
}

bool VsvsimTestbench___024root___eval_inact(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_inact\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void VsvsimTestbench___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 2> &out);

bool VsvsimTestbench___024root___eval_nba(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_nba\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = VsvsimTestbench___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((((2ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _nba_sequent__TOP__0
                    ::IData/*31:0*/ __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__svsimTestbench__DOT__dut__DOT__cntReg_0;
                    __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__svsimTestbench__DOT__dut__DOT__cntReg_0 = 0;
                    ::CData/*0:0*/ __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__svsimTestbench__DOT__dut__DOT__blkReg_1;
                    __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__svsimTestbench__DOT__dut__DOT__blkReg_1 = 0;
                    __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__svsimTestbench__DOT__dut__DOT__cntReg_0 
                        = vlSelfRef.svsimTestbench__DOT__dut__DOT__cntReg;
                    __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__svsimTestbench__DOT__dut__DOT__blkReg_1 
                        = vlSelfRef.svsimTestbench__DOT__dut__DOT__blkReg;
                    if (vlSelfRef.svsimTestbench__DOT__reset) {
                        __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__svsimTestbench__DOT__dut__DOT__cntReg_0 = 0U;
                        __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__svsimTestbench__DOT__dut__DOT__blkReg_1 = 0U;
                    } else {
                        vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN 
                            = (0x000061a7U == vlSelfRef.svsimTestbench__DOT__dut__DOT__cntReg);
                        __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__svsimTestbench__DOT__dut__DOT__cntReg_0 
                            = ((::IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN)
                                ? 0U : ((::IData)(1U) 
                                        + vlSelfRef.svsimTestbench__DOT__dut__DOT__cntReg));
                        __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__svsimTestbench__DOT__dut__DOT__blkReg_1 
                            = ((::IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__unnamedblk1__DOT___GEN) 
                               ^ (::IData)(vlSelfRef.svsimTestbench__DOT__dut__DOT__blkReg));
                    }
                    vlSelfRef.svsimTestbench__DOT__dut__DOT__cntReg 
                        = __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__svsimTestbench__DOT__dut__DOT__cntReg_0;
                    vlSelfRef.svsimTestbench__DOT__dut__DOT__blkReg 
                        = __Vinline_0__eval_body__nba___Vinline_0__nba_sequent__TOP__0___Vdly__svsimTestbench__DOT__dut__DOT__blkReg_1;
                }
                vlSelfRef.__VtraceActivity[1U] = 1U;
            }
        }
        VsvsimTestbench___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool VsvsimTestbench___024root___eval_obs(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_obs\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VsvsimTestbench___024root___eval_react(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_react\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void VsvsimTestbench___024root___eval_postponed(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_postponed\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool VsvsimTestbench___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___trigger_anySet__ico\n"); );
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

bool VsvsimTestbench___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___trigger_anySet__act\n"); );
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

void VsvsimTestbench___024root___act_sequent__TOP__0(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___act_sequent__TOP__0\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((1U == vlSelfRef.svsimTestbench__DOT__simulationState)) {
        VsvsimTestbench___024root____Vdpiimwrap_svsimTestbench__DOT__simulation_body_TOP(
                                                                                (vlSymsp->__Vscopep_svsimTestbench), 
                                                                                "/home/caiyaohao/OneStudentOneChip/E_Stage/E4_Chisel_Lab/lab1/build/chiselsim/HelloSpec/Hello-should-blink/workdir-verilator/../generated-sources/testbench.sv", 0x00000044U);
        vlSelfRef.svsimTestbench__DOT__simulationState = 2U;
    }
}

void VsvsimTestbench___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 2> &out, const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((::IData)(1U) + n);
    } while ((1U >= n));
}

void VsvsimTestbench___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 2> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___trigger_clear__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((::IData)(1U) + n);
    } while ((2U > n));
}

#ifdef VL_DEBUG
void VsvsimTestbench___024root___eval_debug_assertions(VsvsimTestbench___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root___eval_debug_assertions\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}
#endif  // VL_DEBUG
