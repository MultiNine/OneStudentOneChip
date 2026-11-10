// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "VpriEncode42__Syms.h"


VL_ATTR_COLD void VpriEncode42___024root__trace_init_sub__TOP__0(VpriEncode42___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root__trace_init_sub__TOP__0\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$rootio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "priEncode42", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+1,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+2,0,"y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 1,0);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"i",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::INTEGER, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void VpriEncode42___024root__trace_init_top(VpriEncode42___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root__trace_init_top\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VpriEncode42___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VpriEncode42___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void VpriEncode42___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VpriEncode42___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VpriEncode42___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void VpriEncode42___024root__trace_register(VpriEncode42___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root__trace_register\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VpriEncode42___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VpriEncode42___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VpriEncode42___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VpriEncode42___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VpriEncode42___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root__trace_const_0\n"); );
    // Body
    VpriEncode42___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VpriEncode42___024root*>(voidSelf);
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VpriEncode42___024root__trace_full_0_sub_0(VpriEncode42___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VpriEncode42___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root__trace_full_0\n"); );
    // Body
    VpriEncode42___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VpriEncode42___024root*>(voidSelf);
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VpriEncode42___024root__trace_full_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

VL_ATTR_COLD void VpriEncode42___024root__trace_full_0_sub_0(VpriEncode42___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root__trace_full_0_sub_0\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+0,(vlSelfRef.__VprimaryPorts.x),4);
    bufp->fullBit(oldp+1,(vlSelfRef.__VprimaryPorts.en));
    bufp->fullCData(oldp+2,(vlSelfRef.__VprimaryPorts.y),2);
    bufp->fullIData(oldp+3,(vlSelfRef.priEncode42__DOT__i),32);
}
