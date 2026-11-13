// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop.h for the primary calling header

#include "Vtop__pch.h"

VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_static\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.__VprimaryPorts.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.__VprimaryPorts.rst;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.__VprimaryPorts.clk;
}

VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_initial\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);
VL_ATTR_COLD void Vtop___024root___eval_body__stl(Vtop___024root* vlSelf);

VL_ATTR_COLD bool Vtop___024root___eval_stl(Vtop___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        Vtop___024root___eval_body__stl(vlSelf);
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_dump_triggers__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtop___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__ico(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_dump_triggers__ico\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtop___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__act(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_dump_triggers__act\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtop___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__nba(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_dump_triggers__nba\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtop___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__obs(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_dump_triggers__obs\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__react(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_dump_triggers__react\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_final\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(Vtop___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___trigger_anySet__stl\n"); );
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

void Vtop___024root____Vdpiimwrap_top__DOT__u_LSU__DOT__pmem_read_TOP(::IData/*31:0*/ raddr, ::IData/*31:0*/ &pmem_read__Vfuncrtn);
void Vtop___024root____Vdpiimwrap_top__DOT__u_LSU__DOT__pmem_write_TOP(::IData/*31:0*/ waddr, ::IData/*31:0*/ wdata, ::CData/*7:0*/ wmask);

VL_ATTR_COLD void Vtop___024root___eval_body__stl(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___eval_body__stl\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
        {
            // Inlined CFunc: _stl_comb__TOP__0
            vlSelfRef.__VprimaryPorts.PC = vlSelfRef.top__DOT__u_IFU__DOT__PCout;
            if (vlSelfRef.__VprimaryPorts.rst) {
                vlSelfRef.top__DOT__u_IFU__DOT____VlemCond_1 = 0x00000013U;
            } else {
                Vtop___024root____Vdpiimwrap_top__DOT__u_LSU__DOT__pmem_read_TOP(vlSelfRef.top__DOT__u_IFU__DOT__PCout, vlSelfRef.top__DOT__u_IFU__DOT____VlemCall_0__pmem_read);
                vlSelfRef.top__DOT__u_IFU__DOT____VlemCond_1 
                    = vlSelfRef.top__DOT__u_IFU__DOT____VlemCall_0__pmem_read;
            }
            vlSelfRef.__VprimaryPorts.instr = vlSelfRef.top__DOT__u_IFU__DOT____VlemCond_1;
            vlSelfRef.top__DOT__u_EXU__DOT__is_jalr 
                = (::IData)((0x00000067U == (0x0000707fU 
                                             & vlSelfRef.__VprimaryPorts.instr)));
            vlSelfRef.top__DOT__u_IDU__DOT__is_lw = (::IData)(
                                                              (0x00002003U 
                                                               == 
                                                               (0x0000707fU 
                                                                & vlSelfRef.__VprimaryPorts.instr)));
            vlSelfRef.top__DOT__u_IDU__DOT__is_lbu 
                = (::IData)((0x00004003U == (0x0000707fU 
                                             & vlSelfRef.__VprimaryPorts.instr)));
            vlSelfRef.top__DOT__u_EXU__DOT__is_add 
                = (::IData)((0x00000033U == (0x0000707fU 
                                             & vlSelfRef.__VprimaryPorts.instr)));
            vlSelfRef.top__DOT__u_EXU__DOT__rdata2 
                = ((0U == (0x0000000fU & (vlSelfRef.__VprimaryPorts.instr 
                                          >> 0x00000014U)))
                    ? 0U : vlSelfRef.top__DOT__u_RegisterFile__DOT__rf
                   [(0x0000000fU & (vlSelfRef.__VprimaryPorts.instr 
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
            vlSelfRef.top__DOT__u_EXU__DOT__memAddr 
                = (((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_add)
                     ? vlSelfRef.top__DOT__u_EXU__DOT__rdata2
                     : (((- (::IData)((vlSelfRef.__VprimaryPorts.instr 
                                       >> 0x0000001fU))) 
                         << 0x0000000cU) | ((0x00000fe0U 
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
                   + ((0U == (0x0000000fU & (vlSelfRef.__VprimaryPorts.instr 
                                             >> 0x0000000fU)))
                       ? 0U : vlSelfRef.top__DOT__u_RegisterFile__DOT__rf
                      [(0x0000000fU & (vlSelfRef.__VprimaryPorts.instr 
                                       >> 0x0000000fU))]));
            vlSelfRef.top__DOT__u_IFU__DOT__PCin = 
                ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_jalr)
                  ? (0xfffffffeU & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)
                  : ((::IData)(4U) + vlSelfRef.top__DOT__u_IFU__DOT__PCout));
            if (vlSelfRef.top__DOT__u_LSU__DOT__ren) {
                Vtop___024root____Vdpiimwrap_top__DOT__u_LSU__DOT__pmem_read_TOP(vlSelfRef.top__DOT__u_EXU__DOT__memAddr, vlSelfRef.__Vfunc_top__DOT__u_LSU__DOT__pmem_read__Vfuncout_0);
                vlSelfRef.top__DOT__u_LSU__DOT__rdata 
                    = vlSelfRef.__Vfunc_top__DOT__u_LSU__DOT__pmem_read__Vfuncout_0;
            } else {
                vlSelfRef.top__DOT__u_LSU__DOT__rdata = 0U;
            }
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
        }
        {
            // Inlined CFunc: __VtraceActivitySetAll
            vlSelfRef.__VtraceActivity[0U] = 1U;
            vlSelfRef.__VtraceActivity[1U] = 1U;
            vlSelfRef.__VtraceActivity[2U] = 1U;
        }
    }
}

bool Vtop___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(Vtop___024root___trigger_anySet__ico(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @( clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( rst)\n");
    }
    if ((1U & (::IData)(triggers[1U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 64 is active: Internal 'ico' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

bool Vtop___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (::IData)(Vtop___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop___024root___ctor_var_reset(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___ctor_var_reset\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const uint64_t __VscopeHash = VL_MURMUR64_HASH(vlSelf->vlNamep);
    vlSelf->__VprimaryPorts.clk = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 16707436170211756652ull);
    vlSelf->__VprimaryPorts.rst = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 18209466448985614591ull);
    vlSelf->__VprimaryPorts.PC = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12700755172620096637ull);
    vlSelf->__VprimaryPorts.instr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 682939282188807998ull);
    vlSelf->top__DOT__u_LSU__DOT__ren = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 11294794786955845794ull);
    vlSelf->top__DOT__u_LSU__DOT__wen = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17738098967014677477ull);
    vlSelf->top__DOT__u_LSU__DOT__rdata = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 4565921014668311028ull);
    vlSelf->top__DOT__u_EXU__DOT__is_jalr = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 15676348399364774422ull);
    vlSelf->top__DOT__u_EXU__DOT__is_add = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17808281655388375931ull);
    vlSelf->top__DOT__u_EXU__DOT__is_sw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 17473784723839860306ull);
    vlSelf->top__DOT__u_EXU__DOT__is_sb = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7141171540175048063ull);
    vlSelf->top__DOT__u_EXU__DOT__rdata2 = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9922819625535570191ull);
    vlSelf->top__DOT__u_EXU__DOT__memAddr = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 12103231491841536096ull);
    vlSelf->top__DOT__u_RegisterFile__DOT__rf[0] = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9223643604258843821ull);
    VL_UNPACKED_FILL(vlSelf->top__DOT__u_RegisterFile__DOT__rf.data(), sizeof(vlSelf->top__DOT__u_RegisterFile__DOT__rf[0]), 16);
    vlSelf->top__DOT__u_IDU__DOT__is_lw = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 7633912164711967149ull);
    vlSelf->top__DOT__u_IDU__DOT__is_lbu = VL_SCOPED_RAND_RESET_I(1, __VscopeHash, 6532878087164883825ull);
    vlSelf->top__DOT__u_IFU__DOT__PCin = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 9765774356357701446ull);
    vlSelf->top__DOT__u_IFU__DOT__PCout = VL_SCOPED_RAND_RESET_I(32, __VscopeHash, 18255080032175033274ull);
    vlSelf->__Vfunc_top__DOT__u_LSU__DOT__pmem_read__Vfuncout_0 = 0;
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 2);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = 0;
    vlSelf->__VactTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VactTriggered.data(), sizeof(vlSelf->__VactTriggered[0]), 1);
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    vlSelf->__VnbaTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VnbaTriggered.data(), sizeof(vlSelf->__VnbaTriggered[0]), 1);
    vlSelf->__VtraceActivity[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VtraceActivity.data(), sizeof(vlSelf->__VtraceActivity[0]), 3);
}
