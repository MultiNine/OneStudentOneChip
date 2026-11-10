// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vdecode24__Syms.h"


void Vdecode24___024root__trace_chg_0_sub_0(Vdecode24___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vdecode24___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode24___024root__trace_chg_0\n"); );
    // Body
    Vdecode24___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdecode24___024root*>(voidSelf);
    Vdecode24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vdecode24___024root__trace_chg_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

void Vdecode24___024root__trace_chg_0_sub_0(Vdecode24___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode24___024root__trace_chg_0_sub_0\n"); );
    Vdecode24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgCData(oldp+0,(vlSelfRef.__VprimaryPorts.x),2);
    bufp->chgBit(oldp+1,(vlSelfRef.__VprimaryPorts.en));
    bufp->chgCData(oldp+2,(vlSelfRef.__VprimaryPorts.y),4);
}

void Vdecode24___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vdecode24___024root__trace_cleanup\n"); );
    // Locals
    ::VlUnpacked<::CData/*0:0*/, 1> __VtraceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __VtraceActivity[__Vi0] = 0;
    }
    // Body
    Vdecode24___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdecode24___024root*>(voidSelf);
    Vdecode24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __VtraceActivity[0U] = 0U;
}
