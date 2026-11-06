// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_vcd_c.h"
#include "VsvsimTestbench__Syms.h"


void VsvsimTestbench___024root__trace_chg_0_sub_0(VsvsimTestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp);

void VsvsimTestbench___024root__trace_chg_0(void* voidSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root__trace_chg_0\n"); );
    // Body
    VsvsimTestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VsvsimTestbench___024root*>(voidSelf);
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VsvsimTestbench___024root__trace_chg_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

void VsvsimTestbench___024root__trace_chg_0_sub_0(VsvsimTestbench___024root* vlSelf, VerilatedVcd::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root__trace_chg_0_sub_0\n"); );
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY((vlSelfRef.__VtraceActivity[1U]))) {
        bufp->chgBit(oldp+0,(vlSelfRef.svsimTestbench__DOT__dut__DOT__blkReg));
        bufp->chgBit(oldp+1,(vlSelfRef.svsimTestbench__DOT__dut__DOT__blkReg));
        bufp->chgIData(oldp+2,(vlSelfRef.svsimTestbench__DOT__dut__DOT__cntReg),32);
    }
    bufp->chgBit(oldp+3,(vlSelfRef.svsimTestbench__DOT__clock));
    bufp->chgBit(oldp+4,(vlSelfRef.svsimTestbench__DOT__reset));
    bufp->chgIData(oldp+5,(vlSelfRef.svsimTestbench__DOT__simulationState),32);
    bufp->chgIData(oldp+6,(vlSelfRef.svsimTestbench__DOT__traceSupported),32);
    bufp->chgBit(oldp+7,(vlSelfRef.svsimTestbench__DOT__clock));
    bufp->chgBit(oldp+8,(vlSelfRef.svsimTestbench__DOT__reset));
}

void VsvsimTestbench___024root__trace_cleanup(void* voidSelf, VerilatedVcd* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VsvsimTestbench___024root__trace_cleanup\n"); );
    // Body
    VsvsimTestbench___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VsvsimTestbench___024root*>(voidSelf);
    VsvsimTestbench__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->vlInst.TOP.__VtraceActivity[0U] = 0U;
    vlSymsp->vlInst.TOP.__VtraceActivity[1U] = 0U;
}
