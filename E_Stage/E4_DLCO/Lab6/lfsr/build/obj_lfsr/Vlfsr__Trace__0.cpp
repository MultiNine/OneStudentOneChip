// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vlfsr__Syms.h"


void Vlfsr___024root__trace_chg_0_sub_0(Vlfsr___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vlfsr___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root__trace_chg_0\n"); );
    // Body
    Vlfsr___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlfsr___024root*>(voidSelf);
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vlfsr___024root__trace_chg_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

void Vlfsr___024root__trace_chg_0_sub_0(Vlfsr___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root__trace_chg_0_sub_0\n"); );
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    bufp->chgBit(oldp+0,(vlSelfRef.__VprimaryPorts.clk));
    bufp->chgBit(oldp+1,(vlSelfRef.__VprimaryPorts.rst));
    bufp->chgCData(oldp+2,(vlSelfRef.__VprimaryPorts.dout),8);
    bufp->chgCData(oldp+3,(vlSelfRef.__VprimaryPorts.segout1),8);
    bufp->chgCData(oldp+4,(vlSelfRef.__VprimaryPorts.segout0),8);
    bufp->chgBit(oldp+5,((1U & VL_REDXOR_8((0x1dU & (::IData)(vlSelfRef.__VprimaryPorts.dout))))));
    bufp->chgCData(oldp+6,((0x0000000fU & (::IData)(vlSelfRef.__VprimaryPorts.dout))),4);
    bufp->chgCData(oldp+7,((0x0000000fU & ((::IData)(vlSelfRef.__VprimaryPorts.dout) 
                                           >> 4U))),4);
}

void Vlfsr___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vlfsr___024root__trace_cleanup\n"); );
    // Locals
    ::VlUnpacked<::CData/*0:0*/, 1> __VtraceActivity;
    for (int __Vi0 = 0; __Vi0 < 1; ++__Vi0) {
        __VtraceActivity[__Vi0] = 0;
    }
    // Body
    Vlfsr___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlfsr___024root*>(voidSelf);
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    __VtraceActivity[0U] = 0U;
}
