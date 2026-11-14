// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (VL_UNLIKELY(!vlSymsp->__Vm_activity)) return;
    Vtop___024root__trace_chg_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const ::VlUnpacked<::IData/*31:0*/, 16>& __VdtypeVar);

void Vtop___024root__trace_chg_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + 0);
    if (VL_UNLIKELY(((vlSelfRef.__VtraceActivity[1U] 
                      | vlSelfRef.__VtraceActivity[2U])))) {
        bufp->chgIData(oldp+0,(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr),32);
        bufp->chgBit(oldp+1,(vlSelfRef.top__DOT__u_NPC__DOT__u_LSU__DOT__ren));
        bufp->chgBit(oldp+2,(vlSelfRef.top__DOT__u_NPC__DOT__u_LSU__DOT__wen));
        bufp->chgIData(oldp+3,(vlSelfRef.top__DOT__mem_rdata),32);
        bufp->chgIData(oldp+4,(((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_sw)
                                 ? vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__rdata2
                                 : (vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__rdata2 
                                    << (0x00000018U 
                                        & (vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr 
                                           << 3U))))),32);
        bufp->chgCData(oldp+5,(((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_sw)
                                 ? 0x0000000fU : ((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_sb)
                                                   ? 
                                                  (0x000000ffU 
                                                   & (0x08040201U 
                                                      >> 
                                                      (0x00000018U 
                                                       & (vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr 
                                                          << 3U))))
                                                   : 0U))),8);
        bufp->chgBit(oldp+6,((0x00100073U == vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr)));
        bufp->chgIData(oldp+7,(((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_jalr)
                                 ? (0xfffffffeU & vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr)
                                 : ((::IData)(4U) + vlSelfRef.top__DOT__u_NPC__DOT__u_IFU__DOT__PCout))),32);
        bufp->chgIData(oldp+8,(vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr),32);
        bufp->chgBit(oldp+9,(((::IData)((0x00000013U 
                                         == (0x0000707fU 
                                             & vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr))) 
                              | ((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_jalr) 
                                 | ((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_add) 
                                    | ((0x37U == (0x0000007fU 
                                                  & vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr)) 
                                       | (::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_LSU__DOT__ren)))))));
        bufp->chgCData(oldp+10,((0x0000000fU & (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                                >> 7U))),4);
        bufp->chgIData(oldp+11,(((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_LSU__DOT__ren)
                                  ? ((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__is_lw)
                                      ? vlSelfRef.top__DOT__mem_rdata
                                      : (0x000000ffU 
                                         & ((- (::IData)((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__is_lbu))) 
                                            & ((2U 
                                                & vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr)
                                                ? (
                                                   (1U 
                                                    & vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr)
                                                    ? 
                                                   (vlSelfRef.top__DOT__mem_rdata 
                                                    >> 0x00000018U)
                                                    : 
                                                   (vlSelfRef.top__DOT__mem_rdata 
                                                    >> 0x00000010U))
                                                : (
                                                   (1U 
                                                    & vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr)
                                                    ? 
                                                   (vlSelfRef.top__DOT__mem_rdata 
                                                    >> 8U)
                                                    : vlSelfRef.top__DOT__mem_rdata)))))
                                  : ((0x37U == (0x0000007fU 
                                                & vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr))
                                      ? (0xfffff000U 
                                         & vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr)
                                      : ((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_jalr)
                                          ? ((::IData)(4U) 
                                             + vlSelfRef.top__DOT__u_NPC__DOT__u_IFU__DOT__PCout)
                                          : vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr)))),32);
        bufp->chgCData(oldp+12,((0x0000000fU & (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                                >> 0x0000000fU))),4);
        bufp->chgCData(oldp+13,((0x0000000fU & (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                                >> 0x00000014U))),4);
        bufp->chgIData(oldp+14,(((0U == (0x0000000fU 
                                         & (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                            >> 0x0000000fU)))
                                  ? 0U : vlSelfRef.top__DOT__u_NPC__DOT__u_RegisterFile__DOT__rf
                                 [(0x0000000fU & (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                                  >> 0x0000000fU))])),32);
        bufp->chgIData(oldp+15,(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__rdata2),32);
        bufp->chgBit(oldp+16,((::IData)((0x00000013U 
                                         == (0x0000707fU 
                                             & vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr)))));
        bufp->chgBit(oldp+17,(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_jalr));
        bufp->chgBit(oldp+18,(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_add));
        bufp->chgBit(oldp+19,((0x37U == (0x0000007fU 
                                         & vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr))));
        bufp->chgBit(oldp+20,(vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__is_lw));
        bufp->chgBit(oldp+21,(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_sw));
        bufp->chgBit(oldp+22,(vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__is_lbu));
        bufp->chgBit(oldp+23,(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_sb));
        bufp->chgIData(oldp+24,((((- (::IData)((vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                                >> 0x0000001fU))) 
                                  << 0x0000000cU) | 
                                 (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                  >> 0x00000014U))),32);
        bufp->chgIData(oldp+25,((((- (::IData)((vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                                >> 0x0000001fU))) 
                                  << 0x0000000cU) | 
                                 ((0x00000fe0U & (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                                  >> 0x00000014U)) 
                                  | (0x0000001fU & 
                                     (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                      >> 7U))))),32);
        bufp->chgIData(oldp+26,((0xfffff000U & vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr)),32);
        bufp->chgIData(oldp+27,((0xfffffffeU & vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr)),32);
        bufp->chgIData(oldp+28,(((0x37U == (0x0000007fU 
                                            & vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr))
                                  ? (0xfffff000U & vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr)
                                  : ((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_jalr)
                                      ? ((::IData)(4U) 
                                         + vlSelfRef.top__DOT__u_NPC__DOT__u_IFU__DOT__PCout)
                                      : vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr))),32);
        bufp->chgIData(oldp+29,(((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__is_lw)
                                  ? vlSelfRef.top__DOT__mem_rdata
                                  : (0x000000ffU & 
                                     ((- (::IData)((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__is_lbu))) 
                                      & ((2U & vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr)
                                          ? ((1U & vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr)
                                              ? (vlSelfRef.top__DOT__mem_rdata 
                                                 >> 0x00000018U)
                                              : (vlSelfRef.top__DOT__mem_rdata 
                                                 >> 0x00000010U))
                                          : ((1U & vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__memAddr)
                                              ? (vlSelfRef.top__DOT__mem_rdata 
                                                 >> 8U)
                                              : vlSelfRef.top__DOT__mem_rdata)))))),32);
        bufp->chgIData(oldp+30,(((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__is_add)
                                  ? vlSelfRef.top__DOT__u_NPC__DOT__u_EXU__DOT__rdata2
                                  : (((- (::IData)(
                                                   (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                                    >> 0x0000001fU))) 
                                      << 0x0000000cU) 
                                     | ((0x00000fe0U 
                                         & (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                            >> 0x00000014U)) 
                                        | (0x0000001fU 
                                           & ((::IData)(vlSelfRef.top__DOT__u_NPC__DOT__u_LSU__DOT__wen)
                                               ? (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                                  >> 7U)
                                               : (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                                  >> 0x00000014U))))))),32);
        bufp->chgCData(oldp+31,((0x0000007fU & vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr)),7);
        bufp->chgCData(oldp+32,((7U & (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                       >> 0x0000000cU))),3);
        bufp->chgSData(oldp+33,((vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                 >> 0x00000014U)),12);
        bufp->chgSData(oldp+34,(((0x00000fe0U & (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                                 >> 0x00000014U)) 
                                 | (0x0000001fU & (vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                                   >> 7U)))),12);
        bufp->chgIData(oldp+35,((vlSelfRef.top__DOT__u_NPC__DOT__u_IDU__DOT__instr 
                                 >> 0x0000000cU)),20);
    }
    if (VL_UNLIKELY((vlSelfRef.__VtraceActivity[2U]))) {
        bufp->chgIData(oldp+36,(vlSelfRef.top__DOT__u_NPC__DOT__u_IFU__DOT__PCout),32);
        bufp->chgIData(oldp+37,(vlSelfRef.top__DOT__u_NPC__DOT__u_RegisterFile__DOT__rf[10U]),32);
        Vtop___024root__trace_chg_dtype____0(vlSelf, bufp, 38, vlSelfRef.top__DOT__u_NPC__DOT__u_RegisterFile__DOT__rf);
    }
    bufp->chgBit(oldp+54,(vlSelfRef.__VprimaryPorts.clk));
    bufp->chgBit(oldp+55,(vlSelfRef.__VprimaryPorts.rst));
    bufp->chgIData(oldp+56,(vlSelfRef.__VprimaryPorts.instr),32);
}

void Vtop___024root__trace_chg_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const ::VlUnpacked<::IData/*31:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_chg_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode +  offset);
    bufp->chgIData(oldp+0,(__VdtypeVar[15]),32);
    bufp->chgIData(oldp+1,(__VdtypeVar[14]),32);
    bufp->chgIData(oldp+2,(__VdtypeVar[13]),32);
    bufp->chgIData(oldp+3,(__VdtypeVar[12]),32);
    bufp->chgIData(oldp+4,(__VdtypeVar[11]),32);
    bufp->chgIData(oldp+5,(__VdtypeVar[10]),32);
    bufp->chgIData(oldp+6,(__VdtypeVar[9]),32);
    bufp->chgIData(oldp+7,(__VdtypeVar[8]),32);
    bufp->chgIData(oldp+8,(__VdtypeVar[7]),32);
    bufp->chgIData(oldp+9,(__VdtypeVar[6]),32);
    bufp->chgIData(oldp+10,(__VdtypeVar[5]),32);
    bufp->chgIData(oldp+11,(__VdtypeVar[4]),32);
    bufp->chgIData(oldp+12,(__VdtypeVar[3]),32);
    bufp->chgIData(oldp+13,(__VdtypeVar[2]),32);
    bufp->chgIData(oldp+14,(__VdtypeVar[1]),32);
    bufp->chgIData(oldp+15,(__VdtypeVar[0]),32);
}

void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_cleanup\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    vlSymsp->__Vm_activity = false;
    vlSymsp->vlInst.TOP.__VtraceActivity[0U] = 0U;
    vlSymsp->vlInst.TOP.__VtraceActivity[1U] = 0U;
    vlSymsp->vlInst.TOP.__VtraceActivity[2U] = 0U;
}
