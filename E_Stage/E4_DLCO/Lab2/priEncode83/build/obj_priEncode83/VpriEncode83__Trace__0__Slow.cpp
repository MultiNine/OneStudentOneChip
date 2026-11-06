// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "VpriEncode83__Syms.h"


VL_ATTR_COLD void VpriEncode83___024root__trace_init_sub__TOP__0(VpriEncode83___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root__trace_init_sub__TOP__0\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$rootio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"validIn",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"segOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "priEncode83", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+0,0,"en",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"x",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"validIn",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+3,0,"y",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+4,0,"segOut",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"segData",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_seg", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+6,0,"b",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+5,0,"h",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void VpriEncode83___024root__trace_init_top(VpriEncode83___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root__trace_init_top\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VpriEncode83___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void VpriEncode83___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void VpriEncode83___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VpriEncode83___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void VpriEncode83___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void VpriEncode83___024root__trace_register(VpriEncode83___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root__trace_register\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&VpriEncode83___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&VpriEncode83___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&VpriEncode83___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&VpriEncode83___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void VpriEncode83___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root__trace_const_0\n"); );
    // Body
    VpriEncode83___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VpriEncode83___024root*>(voidSelf);
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
}

VL_ATTR_COLD void VpriEncode83___024root__trace_full_0_sub_0(VpriEncode83___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void VpriEncode83___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root__trace_full_0\n"); );
    // Body
    VpriEncode83___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VpriEncode83___024root*>(voidSelf);
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    VpriEncode83___024root__trace_full_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

extern const ::VlWide<16>/*511:0*/ VpriEncode83__ConstPool__CONST_2;

VL_ATTR_COLD void VpriEncode83___024root__trace_full_0_sub_0(VpriEncode83___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode83___024root__trace_full_0_sub_0\n"); );
    VpriEncode83__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullBit(oldp+0,(vlSelfRef.__VprimaryPorts.en));
    bufp->fullCData(oldp+1,(vlSelfRef.__VprimaryPorts.x),8);
    bufp->fullBit(oldp+2,(vlSelfRef.__VprimaryPorts.validIn));
    bufp->fullCData(oldp+3,(vlSelfRef.__VprimaryPorts.y),3);
    bufp->fullCData(oldp+4,(vlSelfRef.__VprimaryPorts.segOut),8);
    bufp->fullCData(oldp+5,((0x000000ffU & VpriEncode83__ConstPool__CONST_2
                             [(0x07ffffffU & (::IData)(vlSelfRef.__VprimaryPorts.y))])),8);
    bufp->fullCData(oldp+6,(vlSelfRef.__VprimaryPorts.y),4);
}
