// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "VaddSub4bit__Syms.h"


void VaddSub4bit___024root__trace_chg_0_sub_0(VaddSub4bit___024root* vlSelf, VerilatedFst::Buffer* bufp);

void VaddSub4bit___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root__trace_chg_0\n"); );
    // Body
    VaddSub4bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VaddSub4bit___024root*>(voidSelf);
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VaddSub4bit___024root__trace_chg_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

void VaddSub4bit___024root__trace_chg_0_sub_0(VaddSub4bit___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root__trace_chg_0_sub_0\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgCData(oldp+0,(vlSelfRef.__VprimaryPorts.a),4);
    bufp->chgCData(oldp+1,(vlSelfRef.__VprimaryPorts.b),4);
    bufp->chgBit(oldp+2,(vlSelfRef.__VprimaryPorts.ctrl));
    bufp->chgBit(oldp+3,(vlSelfRef.__VprimaryPorts.carry));
    bufp->chgBit(oldp+4,(vlSelfRef.__VprimaryPorts.zero));
    bufp->chgBit(oldp+5,(vlSelfRef.__VprimaryPorts.overflow));
    bufp->chgCData(oldp+6,(vlSelfRef.__VprimaryPorts.result),4);
    bufp->chgCData(oldp+7,(vlSelfRef.addSub4bit__DOT__bin),4);
    bufp->chgCData(oldp+8,(vlSelfRef.addSub4bit__DOT__c_r),5);
}

void VaddSub4bit___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root__trace_cleanup\n"); );
    // Locals
    ::VlUnpacked<::CData/*0:0*/, 1> __VtraceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __VtraceActivity[__Vi0] = 0;
    }
    // Body
    VaddSub4bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VaddSub4bit___024root*>(voidSelf);
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __VtraceActivity[0U] = 0U;
}
