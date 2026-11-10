// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "VaddSub4bit__Syms.h"


VL_ATTR_COLD void VaddSub4bit___024root__trace_init_sub__TOP__0(VaddSub4bit___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root__trace_init_sub__TOP__0\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$rootio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"ctrl",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"carry",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"zero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+5,0,"overflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "addSub4bit", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"a",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"ctrl",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"carry",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"zero",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+5,0,"overflow",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"result",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+7,0,"bin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"c_r",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 4,0);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void VaddSub4bit___024root__trace_init_top(VaddSub4bit___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root__trace_init_top\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VaddSub4bit___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VaddSub4bit___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void VaddSub4bit___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VaddSub4bit___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VaddSub4bit___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void VaddSub4bit___024root__trace_register(VaddSub4bit___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root__trace_register\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VaddSub4bit___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VaddSub4bit___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VaddSub4bit___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VaddSub4bit___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VaddSub4bit___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root__trace_const_0\n"); );
    // Body
    VaddSub4bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VaddSub4bit___024root*>(voidSelf);
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VaddSub4bit___024root__trace_full_0_sub_0(VaddSub4bit___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VaddSub4bit___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root__trace_full_0\n"); );
    // Body
    VaddSub4bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VaddSub4bit___024root*>(voidSelf);
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VaddSub4bit___024root__trace_full_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

VL_ATTR_COLD void VaddSub4bit___024root__trace_full_0_sub_0(VaddSub4bit___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VaddSub4bit___024root__trace_full_0_sub_0\n"); );
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullCData(oldp+0,(vlSelfRef.__VprimaryPorts.a),4);
    bufp->fullCData(oldp+1,(vlSelfRef.__VprimaryPorts.b),4);
    bufp->fullBit(oldp+2,(vlSelfRef.__VprimaryPorts.ctrl));
    bufp->fullBit(oldp+3,(vlSelfRef.__VprimaryPorts.carry));
    bufp->fullBit(oldp+4,(vlSelfRef.__VprimaryPorts.zero));
    bufp->fullBit(oldp+5,(vlSelfRef.__VprimaryPorts.overflow));
    bufp->fullCData(oldp+6,(vlSelfRef.__VprimaryPorts.result),4);
    bufp->fullCData(oldp+7,(vlSelfRef.addSub4bit__DOT__bin),4);
    bufp->fullCData(oldp+8,(vlSelfRef.addSub4bit__DOT__c_r),5);
}
