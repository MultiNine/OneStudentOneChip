// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "VpriEncode42__Syms.h"


void VpriEncode42___024root__trace_chg_0_sub_0(VpriEncode42___024root* vlSelf, VerilatedFst::Buffer* bufp);

void VpriEncode42___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root__trace_chg_0\n"); );
    // Body
    VpriEncode42___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VpriEncode42___024root*>(voidSelf);
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VpriEncode42___024root__trace_chg_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

void VpriEncode42___024root__trace_chg_0_sub_0(VpriEncode42___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root__trace_chg_0_sub_0\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgCData(oldp+0,(vlSelfRef.__VprimaryPorts.x),4);
    bufp->chgBit(oldp+1,(vlSelfRef.__VprimaryPorts.en));
    bufp->chgCData(oldp+2,(vlSelfRef.__VprimaryPorts.y),2);
    bufp->chgIData(oldp+3,(vlSelfRef.priEncode42__DOT__i),32);
}

void VpriEncode42___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root__trace_cleanup\n"); );
    // Locals
    ::VlUnpacked<::CData/*0:0*/, 1> __VtraceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __VtraceActivity[__Vi0] = 0;
    }
    // Body
    VpriEncode42___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VpriEncode42___024root*>(voidSelf);
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __VtraceActivity[0U] = 0U;
}
