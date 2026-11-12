// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

extern "C" int pmem_read(int raddr);

void Vtop___024root____Vdpiimwrap_top__DOT__u_LSU__DOT__pmem_read_TOP(::IData/*31:0*/ raddr, ::IData/*31:0*/ &pmem_read__Vfuncrtn) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__u_LSU__DOT__pmem_read_TOP\n"); );
    // Body
    int raddr__Vcvt;
    raddr__Vcvt = raddr;
    int pmem_read__Vfuncrtn__Vcvt;
    pmem_read__Vfuncrtn__Vcvt = pmem_read(raddr__Vcvt);
    pmem_read__Vfuncrtn = (pmem_read__Vfuncrtn__Vcvt);
}

extern "C" void pmem_write(int waddr, int wdata, char wmask);

void Vtop___024root____Vdpiimwrap_top__DOT__u_LSU__DOT__pmem_write_TOP(::IData/*31:0*/ waddr, ::IData/*31:0*/ wdata, ::CData/*7:0*/ wmask) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root____Vdpiimwrap_top__DOT__u_LSU__DOT__pmem_write_TOP\n"); );
    // Body
    int waddr__Vcvt;
    waddr__Vcvt = waddr;
    int wdata__Vcvt;
    wdata__Vcvt = wdata;
    char wmask__Vcvt;
    wmask__Vcvt = wmask;
    pmem_write(waddr__Vcvt, wdata__Vcvt, wmask__Vcvt);
}

void Vtop___024root___eval_sample(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_sample\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

bool Vtop___024root___eval_ico(Vtop___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (::IData)((::IData)(firstIteration)));
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (::QData)((::IData)(
                                                            ((::IData)(vlSelfRef.__VprimaryPorts.clk) 
                                                             != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__0))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.__VprimaryPorts.clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    return (0U);
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
void Vtop___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in);

bool Vtop___024root___eval_act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_triggers_vec__act
        vlSelfRef.__VactTriggered[0U] = (::QData)((::IData)(
                                                            ((::IData)(vlSelfRef.__VprimaryPorts.clk) 
                                                             & (~ (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__clk__1)))));
        vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.__VprimaryPorts.clk;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
    }
#endif
    Vtop___024root___trigger_orInto__act_vec_vec(vlSelfRef.__VnbaTriggered, vlSelfRef.__VactTriggered);
    return (0U);
}

bool Vtop___024root___eval_inact(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_inact\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtop___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf);
void Vtop___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out);

bool Vtop___024root___eval_nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VnbaExecute;
    // Body
    __VnbaExecute = Vtop___024root___trigger_anySet__act(vlSelfRef.__VnbaTriggered);
    if (__VnbaExecute) {
        {
            // Inlined CFunc: _eval_body__nba
            if ((((1ULL & vlSelfRef.__VnbaTriggered[0U])) != 0ULL)) {
                Vtop___024root___nba_sequent__TOP__0(vlSelf);
                vlSelfRef.__VtraceActivity[1U] = 1U;
            }
        }
        Vtop___024root___trigger_clear__act(vlSelfRef.__VnbaTriggered);
    }
    return (__VnbaExecute);
}

bool Vtop___024root___eval_obs(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_obs\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool Vtop___024root___eval_react(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_react\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void Vtop___024root___eval_postponed(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_postponed\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_postponed__TOP
        if (VL_UNLIKELY((vlSelfRef.top__DOT__u_RegisterFile__DOT____Vstrobe0))) {
            VL_WRITEF_NX("R[0]  = 00000000, R[1]  = %08x, R[2]  = %08x, R[3]  = %08x\n",3
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[1U]
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[2U]
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[3U]);
            vlSelfRef.top__DOT__u_RegisterFile__DOT____Vstrobe0 = 0U;
        }
        if (VL_UNLIKELY((vlSelfRef.top__DOT__u_RegisterFile__DOT____Vstrobe1))) {
            VL_WRITEF_NX("R[4]  = %08x, R[5]  = %08x, R[6]  = %08x, R[7]  = %08x\n",4
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[4U]
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[5U]
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[6U]
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[7U]);
            vlSelfRef.top__DOT__u_RegisterFile__DOT____Vstrobe1 = 0U;
        }
        if (VL_UNLIKELY((vlSelfRef.top__DOT__u_RegisterFile__DOT____Vstrobe2))) {
            VL_WRITEF_NX("R[8]  = %08x, R[9]  = %08x, R[10] = %08x, R[11] = %08x\n",4
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[8U]
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[9U]
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[10U]
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[11U]);
            vlSelfRef.top__DOT__u_RegisterFile__DOT____Vstrobe2 = 0U;
        }
        if (VL_UNLIKELY((vlSelfRef.top__DOT__u_RegisterFile__DOT____Vstrobe3))) {
            VL_WRITEF_NX("R[12] = %08x, R[13] = %08x, R[14] = %08x, R[15] = %08x\n",4
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[12U]
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[13U]
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[14U]
                         , '#',32,vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[15U]);
            vlSelfRef.top__DOT__u_RegisterFile__DOT____Vstrobe3 = 0U;
        }
    }
}

bool Vtop___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__ico\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((2U > n));
    return (0U);
}

bool Vtop___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        if (in[n]) {
            return (1U);
        }
        n = ((::IData)(1U) + n);
    } while ((1U > n));
    return (0U);
}

extern "C" void NPC_ebreak();

void Vtop___024root___nba_sequent__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___nba_sequent__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::IData/*31:0*/ __Vdly_Val__top__DOT__u_RegisterFile__DOT__rf_1;
    __Vdly_Val__top__DOT__u_RegisterFile__DOT__rf_1 = 0;
    ::CData/*3:0*/ __Vdly_Dim0__top__DOT__u_RegisterFile__DOT__rf_2;
    __Vdly_Dim0__top__DOT__u_RegisterFile__DOT__rf_2 = 0;
    ::CData/*0:0*/ __Vdly_Set__top__DOT__u_RegisterFile__DOT__rf_3;
    __Vdly_Set__top__DOT__u_RegisterFile__DOT__rf_3 = 0;
    // Body
    if ((0x00100073U == vlSelfRef.__VprimaryPorts.instr)) {
        {
            // Inlined CFunc: __Vdpiimwrap_top__DOT__NPC_ebreak_TOP
            NPC_ebreak();
        }
    }
    __Vdly_Set__top__DOT__u_RegisterFile__DOT__rf_3 = 0U;
    vlSelfRef.top__DOT__u_RegisterFile__DOT____Vstrobe0 = 1U;
    vlSelfRef.top__DOT__u_RegisterFile__DOT____Vstrobe1 = 1U;
    vlSelfRef.top__DOT__u_RegisterFile__DOT____Vstrobe2 = 1U;
    vlSelfRef.top__DOT__u_RegisterFile__DOT____Vstrobe3 = 1U;
    if (((::IData)((0x00000013U == (0x0000707fU & vlSelfRef.__VprimaryPorts.instr))) 
         | ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_jalr) 
            | ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_add) 
               | ((0x37U == (0x0000007fU & vlSelfRef.__VprimaryPorts.instr)) 
                  | (::IData)(vlSelfRef.top__DOT__u_LSU__DOT__ren)))))) {
        __Vdly_Val__top__DOT__u_RegisterFile__DOT__rf_1 
            = ((::IData)(vlSelfRef.top__DOT__u_LSU__DOT__ren)
                ? ((::IData)(vlSelfRef.top__DOT__u_IDU__DOT__is_lw)
                    ? vlSelfRef.top__DOT__u_LSU__DOT__rdata
                    : (0x000000ffU & ((- (::IData)((::IData)(vlSelfRef.top__DOT__u_IDU__DOT__is_lbu))) 
                                      & ((2U & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)
                                          ? ((1U & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)
                                              ? (vlSelfRef.top__DOT__u_LSU__DOT__rdata 
                                                 >> 0x00000018U)
                                              : (vlSelfRef.top__DOT__u_LSU__DOT__rdata 
                                                 >> 0x00000010U))
                                          : ((1U & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)
                                              ? (vlSelfRef.top__DOT__u_LSU__DOT__rdata 
                                                 >> 8U)
                                              : vlSelfRef.top__DOT__u_LSU__DOT__rdata)))))
                : ((0x37U == (0x0000007fU & vlSelfRef.__VprimaryPorts.instr))
                    ? (0xfffff000U & vlSelfRef.__VprimaryPorts.instr)
                    : ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_jalr)
                        ? ((::IData)(4U) + vlSelfRef.top__DOT__u_IFU__DOT__PCout)
                        : vlSelfRef.top__DOT__u_EXU__DOT__memAddr)));
        __Vdly_Dim0__top__DOT__u_RegisterFile__DOT__rf_2 
            = (0x0000000fU & (vlSelfRef.__VprimaryPorts.instr 
                              >> 7U));
        __Vdly_Set__top__DOT__u_RegisterFile__DOT__rf_3 = 1U;
    }
    if (__Vdly_Set__top__DOT__u_RegisterFile__DOT__rf_3) {
        vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[__Vdly_Dim0__top__DOT__u_RegisterFile__DOT__rf_2] 
            = __Vdly_Val__top__DOT__u_RegisterFile__DOT__rf_1;
    }
    vlSelfRef.top__DOT__u_IFU__DOT__PCout = vlSelfRef.top__DOT__u_IFU__DOT__PCin;
    vlSelfRef.__VprimaryPorts.PC = vlSelfRef.top__DOT__u_IFU__DOT__PCout;
    Vtop___024root____Vdpiimwrap_top__DOT__u_LSU__DOT__pmem_read_TOP(vlSelfRef.top__DOT__u_IFU__DOT__PCout, vlSelfRef.__Vfunc_top__DOT__u_IFU__DOT__pmem_read__Vfuncout_1);
    vlSelfRef.__VprimaryPorts.instr = vlSelfRef.__Vfunc_top__DOT__u_IFU__DOT__pmem_read__Vfuncout_1;
    vlSelfRef.top__DOT__u_EXU__DOT__is_jalr = (::IData)(
                                                        (0x00000067U 
                                                         == 
                                                         (0x0000707fU 
                                                          & vlSelfRef.__VprimaryPorts.instr)));
    vlSelfRef.top__DOT__u_IDU__DOT__is_lw = (::IData)(
                                                      (0x00002003U 
                                                       == 
                                                       (0x0000707fU 
                                                        & vlSelfRef.__VprimaryPorts.instr)));
    vlSelfRef.top__DOT__u_IDU__DOT__is_lbu = (::IData)(
                                                       (0x00004003U 
                                                        == 
                                                        (0x0000707fU 
                                                         & vlSelfRef.__VprimaryPorts.instr)));
    vlSelfRef.top__DOT__u_EXU__DOT__is_add = (::IData)(
                                                       (0x00000033U 
                                                        == 
                                                        (0x0000707fU 
                                                         & vlSelfRef.__VprimaryPorts.instr)));
    vlSelfRef.top__DOT__u_EXU__DOT__rdata2 = ((0U == 
                                               (0x0000000fU 
                                                & (vlSelfRef.__VprimaryPorts.instr 
                                                   >> 0x00000014U)))
                                               ? 0U
                                               : vlSelfRef.top__DOT__u_RegisterFile__DOT__rf
                                              [(0x0000000fU 
                                                & (vlSelfRef.__VprimaryPorts.instr 
                                                   >> 0x00000014U))]);
    vlSelfRef.top__DOT__u_EXU__DOT__is_sw = (::IData)(
                                                      (0x00002023U 
                                                       == 
                                                       (0x0000707fU 
                                                        & vlSelfRef.__VprimaryPorts.instr)));
    vlSelfRef.top__DOT__u_EXU__DOT__is_sb = (::IData)(
                                                      (0x00000023U 
                                                       == 
                                                       (0x0000707fU 
                                                        & vlSelfRef.__VprimaryPorts.instr)));
    vlSelfRef.top__DOT__u_LSU__DOT__ren = ((::IData)(vlSelfRef.top__DOT__u_IDU__DOT__is_lw) 
                                           | (::IData)(vlSelfRef.top__DOT__u_IDU__DOT__is_lbu));
    vlSelfRef.top__DOT__u_LSU__DOT__wen = ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_sb) 
                                           | (::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_sw));
    vlSelfRef.top__DOT__u_EXU__DOT__memAddr = (((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_add)
                                                 ? vlSelfRef.top__DOT__u_EXU__DOT__rdata2
                                                 : 
                                                (((- (::IData)(
                                                               (vlSelfRef.__VprimaryPorts.instr 
                                                                >> 0x0000001fU))) 
                                                  << 0x0000000cU) 
                                                 | ((0x00000fe0U 
                                                     & (vlSelfRef.__VprimaryPorts.instr 
                                                        >> 0x00000014U)) 
                                                    | (0x0000001fU 
                                                       & ((::IData)(vlSelfRef.top__DOT__u_LSU__DOT__wen)
                                                           ? 
                                                          (vlSelfRef.__VprimaryPorts.instr 
                                                           >> 7U)
                                                           : 
                                                          (vlSelfRef.__VprimaryPorts.instr 
                                                           >> 0x00000014U)))))) 
                                               + ((0U 
                                                   == 
                                                   (0x0000000fU 
                                                    & (vlSelfRef.__VprimaryPorts.instr 
                                                       >> 0x0000000fU)))
                                                   ? 0U
                                                   : vlSelfRef.top__DOT__u_RegisterFile__DOT__rf
                                                  [
                                                  (0x0000000fU 
                                                   & (vlSelfRef.__VprimaryPorts.instr 
                                                      >> 0x0000000fU))]));
    vlSelfRef.top__DOT__u_IFU__DOT__PCin = ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_jalr)
                                             ? (0xfffffffeU 
                                                & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)
                                             : ((::IData)(4U) 
                                                + vlSelfRef.top__DOT__u_IFU__DOT__PCout));
    if (((::IData)(vlSelfRef.top__DOT__u_LSU__DOT__ren) 
         | (::IData)(vlSelfRef.top__DOT__u_LSU__DOT__wen))) {
        Vtop___024root____Vdpiimwrap_top__DOT__u_LSU__DOT__pmem_read_TOP(vlSelfRef.top__DOT__u_EXU__DOT__memAddr, vlSelfRef.__Vfunc_top__DOT__u_LSU__DOT__pmem_read__Vfuncout_0);
        vlSelfRef.top__DOT__u_LSU__DOT__rdata = vlSelfRef.__Vfunc_top__DOT__u_LSU__DOT__pmem_read__Vfuncout_0;
        if (vlSelfRef.top__DOT__u_LSU__DOT__wen) {
            Vtop___024root____Vdpiimwrap_top__DOT__u_LSU__DOT__pmem_write_TOP(vlSelfRef.top__DOT__u_EXU__DOT__memAddr, 
                                                                              ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_sw)
                                                                                ? vlSelfRef.top__DOT__u_EXU__DOT__rdata2
                                                                                : 
                                                                               (vlSelfRef.top__DOT__u_EXU__DOT__rdata2 
                                                                                << 
                                                                                (0x00000018U 
                                                                                & (vlSelfRef.top__DOT__u_EXU__DOT__memAddr 
                                                                                << 3U)))), 
                                                                              ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_sw)
                                                                                ? 0x0000000fU
                                                                                : 
                                                                               ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_sb)
                                                                                 ? 
                                                                                (0x000000ffU 
                                                                                & (0x08040201U 
                                                                                >> 
                                                                                (0x00000018U 
                                                                                & (vlSelfRef.top__DOT__u_EXU__DOT__memAddr 
                                                                                << 3U))))
                                                                                 : 0U)));
        }
    } else {
        vlSelfRef.top__DOT__u_LSU__DOT__rdata = 0U;
    }
}

void Vtop___024root___trigger_orInto__act_vec_vec(::VlUnpacked<::QData/*63:0*/, 1> &out, const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_orInto__act_vec_vec\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = (out[n] | in[n]);
        n = ((::IData)(1U) + n);
    } while ((0U >= n));
}

void Vtop___024root___trigger_clear__act(::VlUnpacked<::QData/*63:0*/, 1> &out) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_clear__act\n"); );
    // Locals
    ::IData/*31:0*/ n;
    // Body
    n = 0U;
    do {
        out[n] = 0ULL;
        n = ((::IData)(1U) + n);
    } while ((1U > n));
}

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_debug_assertions\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.clk 
                      & 0xfeU)))) {
        Verilated::overWidthError("clk");
    }
}
#endif  // VL_DEBUG
