// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "VpriEncode83__Syms.h"


void VpriEncode83___024root__trace_chg_0_sub_0(VpriEncode83___024root* vlSelf, VerilatedFst::Buffer* bufp);

void VpriEncode83___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root__trace_chg_0\n"); );
    // Body
    VpriEncode83___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VpriEncode83___024root*>(voidSelf);
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    VpriEncode83___024root__trace_chg_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

extern const ::VlWide<16>/*511:0*/ VpriEncode83__ConstPool__CONST_2;

void VpriEncode83___024root__trace_chg_0_sub_0(VpriEncode83___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root__trace_chg_0_sub_0\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgBit(oldp+0,(vlSelfRef.__VprimaryPorts.en));
    bufp->chgCData(oldp+1,(vlSelfRef.__VprimaryPorts.x),8);
    bufp->chgBit(oldp+2,(vlSelfRef.__VprimaryPorts.validIn));
    bufp->chgCData(oldp+3,(vlSelfRef.__VprimaryPorts.y),3);
    bufp->chgCData(oldp+4,(vlSelfRef.__VprimaryPorts.segOut),8);
    bufp->chgCData(oldp+5,((0x000000ffU & VpriEncode83__ConstPool__CONST_2
                            [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.y))])),8);
    bufp->chgCData(oldp+6,(vlSelfRef.__VprimaryPorts.y),4);
}

void VpriEncode83___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root__trace_cleanup\n"); );
    // Locals
    ::VlUnpacked<::CData/*0:0*/, 1> __VtraceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __VtraceActivity[__Vi0] = 0;
    }
    // Body
    VpriEncode83___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VpriEncode83___024root*>(voidSelf);
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __VtraceActivity[0U] = 0U;
}
