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
    vlSelfRef.__Vtrigprevexpr___TOP__clrn__0 = vlSelfRef.__VprimaryPorts.clrn;
    vlSelfRef.__Vtrigprevexpr___TOP__ps2_clk__0 = vlSelfRef.__VprimaryPorts.ps2_clk;
    vlSelfRef.__Vtrigprevexpr___TOP__ps2_dat__0 = vlSelfRef.__VprimaryPorts.ps2_dat;
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
VL_ATTR_COLD void Vtop___024root___stl_comb__TOP__0(Vtop___024root* vlSelf);

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
        {
            // Inlined CFunc: _eval_body__stl
            if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
                Vtop___024root___stl_comb__TOP__0(vlSelf);
            }
        }
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

extern const ::VlWide<16>/*511:0*/ Vtop__ConstPool__CONST_0;

VL_ATTR_COLD void Vtop___024root___stl_comb__TOP__0(Vtop___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root___stl_comb__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*7:0*/ top__DOT__u_display_ascii__DOT__scancode2asciiMux__DOT__i0__DOT__out;
    top__DOT__u_display_ascii__DOT__scancode2asciiMux__DOT__i0__DOT__out = 0;
    // Body
    vlSelfRef.top__DOT__nextdata_n = (1U & (~ (::IData)(vlSelfRef.top__DOT__state)));
    vlSelfRef.top__DOT__u_scancode2ascii__DOT__key_valid 
        = (0U != ((- (::IData)(((0x46U == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                | ((0x3eU == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                   | ((0x3dU == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                      | ((0x36U == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                         | ((0x2eU 
                                             == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                            | ((0x25U 
                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                               | ((0x26U 
                                                   == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                  | ((0x1eU 
                                                      == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                     | ((0x16U 
                                                         == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                        | ((0x45U 
                                                            == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                           | ((0x1aU 
                                                               == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                              | ((0x35U 
                                                                  == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                 | ((0x22U 
                                                                     == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                    | ((0x1dU 
                                                                        == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                       | ((0x2aU 
                                                                           == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                          | ((0x3cU 
                                                                              == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                             | ((0x2cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x1bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x2dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x15U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x4dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x44U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x31U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x3aU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x4bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x42U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x3bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x43U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x33U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x34U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x2bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x24U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x23U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x21U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | ((0x1cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode)) 
                                                                                | (0x32U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))))))))))))))))))))))))))))))))))))) 
                  & ((0x39U & (- (::IData)((0x46U == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                     | ((0x38U & (- (::IData)((0x3eU 
                                               == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                        | ((0x37U & (- (::IData)((0x3dU 
                                                  == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                           | ((0x36U & (- (::IData)(
                                                    (0x36U 
                                                     == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                              | ((0x35U & (- (::IData)(
                                                       (0x2eU 
                                                        == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                 | ((0x34U & (- (::IData)(
                                                          (0x25U 
                                                           == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                    | ((0x33U & (- (::IData)(
                                                             (0x26U 
                                                              == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                       | ((0x32U & 
                                           (- (::IData)(
                                                        (0x1eU 
                                                         == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                          | ((0x31U 
                                              & (- (::IData)(
                                                             (0x16U 
                                                              == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                             | ((0x30U 
                                                 & (- (::IData)(
                                                                (0x45U 
                                                                 == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                | ((0x7aU 
                                                    & (- (::IData)(
                                                                   (0x1aU 
                                                                    == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                   | ((0x79U 
                                                       & (- (::IData)(
                                                                      (0x35U 
                                                                       == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                      | ((0x78U 
                                                          & (- (::IData)(
                                                                         (0x22U 
                                                                          == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                         | ((0x77U 
                                                             & (- (::IData)(
                                                                            (0x1dU 
                                                                             == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                            | ((0x76U 
                                                                & (- (::IData)(
                                                                               (0x2aU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                               | ((0x75U 
                                                                   & (- (::IData)(
                                                                                (0x3cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                  | ((0x74U 
                                                                      & (- (::IData)(
                                                                                (0x2cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                     | ((0x73U 
                                                                         & (- (::IData)(
                                                                                (0x1bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                        | ((0x72U 
                                                                            & (- (::IData)(
                                                                                (0x2dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                           | ((0x71U 
                                                                               & (- (::IData)(
                                                                                (0x15U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                              | ((0x70U 
                                                                                & (- (::IData)(
                                                                                (0x4dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x6fU 
                                                                                & (- (::IData)(
                                                                                (0x44U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x6eU 
                                                                                & (- (::IData)(
                                                                                (0x31U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x6dU 
                                                                                & (- (::IData)(
                                                                                (0x3aU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x6cU 
                                                                                & (- (::IData)(
                                                                                (0x4bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x6bU 
                                                                                & (- (::IData)(
                                                                                (0x42U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x6aU 
                                                                                & (- (::IData)(
                                                                                (0x3bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x69U 
                                                                                & (- (::IData)(
                                                                                (0x43U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x68U 
                                                                                & (- (::IData)(
                                                                                (0x33U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x67U 
                                                                                & (- (::IData)(
                                                                                (0x34U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x66U 
                                                                                & (- (::IData)(
                                                                                (0x2bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x65U 
                                                                                & (- (::IData)(
                                                                                (0x24U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x64U 
                                                                                & (- (::IData)(
                                                                                (0x23U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x63U 
                                                                                & (- (::IData)(
                                                                                (0x21U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | ((0x61U 
                                                                                & (- (::IData)(
                                                                                (0x1cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))) 
                                                                                | (0x62U 
                                                                                & (- (::IData)(
                                                                                (0x32U 
                                                                                == (::IData)(vlSelfRef.top__DOT__scancode))))))))))))))))))))))))))))))))))))))))));
    vlSelfRef.__VprimaryPorts.sampling = (::IData)(
                                                   (4U 
                                                    == 
                                                    (6U 
                                                     & (::IData)(vlSelfRef.top__DOT__u_ps2_keyboard__DOT__ps2_clk_sync))));
    vlSelfRef.__VprimaryPorts.seg4 = (0x000000ffU & Vtop__ConstPool__CONST_0
                                      [(0x0000000fU 
                                        & (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__count))]);
    vlSelfRef.__VprimaryPorts.seg5 = (0x000000ffU & Vtop__ConstPool__CONST_0
                                      [(0x0000000fU 
                                        & ((::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__count) 
                                           >> 4U))]);
    top__DOT__u_display_ascii__DOT__scancode2asciiMux__DOT__i0__DOT__out 
        = ((- (::IData)(((0x46U == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                         | ((0x3eU == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                            | ((0x3dU == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                               | ((0x36U == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                  | ((0x2eU == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                     | ((0x25U == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                        | ((0x26U == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                           | ((0x1eU 
                                               == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                              | ((0x16U 
                                                  == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                 | ((0x45U 
                                                     == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                    | ((0x1aU 
                                                        == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                       | ((0x35U 
                                                           == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                          | ((0x22U 
                                                              == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                             | ((0x1dU 
                                                                 == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                | ((0x2aU 
                                                                    == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                   | ((0x3cU 
                                                                       == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                      | ((0x2cU 
                                                                          == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                         | ((0x1bU 
                                                                             == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                            | ((0x2dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                               | ((0x15U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x4dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x44U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x31U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x3aU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x4bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x42U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x3bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x43U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x33U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x34U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x2bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x24U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x23U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x21U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | ((0x1cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)) 
                                                                                | (0x32U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))))))))))))))))))))))))))))))))))))) 
           & ((0x39U & (- (::IData)((0x46U == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
              | ((0x38U & (- (::IData)((0x3eU == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                 | ((0x37U & (- (::IData)((0x3dU == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                    | ((0x36U & (- (::IData)((0x36U 
                                              == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                       | ((0x35U & (- (::IData)((0x2eU 
                                                 == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                          | ((0x34U & (- (::IData)(
                                                   (0x25U 
                                                    == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                             | ((0x33U & (- (::IData)(
                                                      (0x26U 
                                                       == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                | ((0x32U & (- (::IData)(
                                                         (0x1eU 
                                                          == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                   | ((0x31U & (- (::IData)(
                                                            (0x16U 
                                                             == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                      | ((0x30U & (- (::IData)(
                                                               (0x45U 
                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                         | ((0x7aU 
                                             & (- (::IData)(
                                                            (0x1aU 
                                                             == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                            | ((0x79U 
                                                & (- (::IData)(
                                                               (0x35U 
                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                               | ((0x78U 
                                                   & (- (::IData)(
                                                                  (0x22U 
                                                                   == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                  | ((0x77U 
                                                      & (- (::IData)(
                                                                     (0x1dU 
                                                                      == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                     | ((0x76U 
                                                         & (- (::IData)(
                                                                        (0x2aU 
                                                                         == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                        | ((0x75U 
                                                            & (- (::IData)(
                                                                           (0x3cU 
                                                                            == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                           | ((0x74U 
                                                               & (- (::IData)(
                                                                              (0x2cU 
                                                                               == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                              | ((0x73U 
                                                                  & (- (::IData)(
                                                                                (0x1bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                 | ((0x72U 
                                                                     & (- (::IData)(
                                                                                (0x2dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                    | ((0x71U 
                                                                        & (- (::IData)(
                                                                                (0x15U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                       | ((0x70U 
                                                                           & (- (::IData)(
                                                                                (0x4dU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                          | ((0x6fU 
                                                                              & (- (::IData)(
                                                                                (0x44U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                             | ((0x6eU 
                                                                                & (- (::IData)(
                                                                                (0x31U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x6dU 
                                                                                & (- (::IData)(
                                                                                (0x3aU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x6cU 
                                                                                & (- (::IData)(
                                                                                (0x4bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x6bU 
                                                                                & (- (::IData)(
                                                                                (0x42U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x6aU 
                                                                                & (- (::IData)(
                                                                                (0x3bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x69U 
                                                                                & (- (::IData)(
                                                                                (0x43U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x68U 
                                                                                & (- (::IData)(
                                                                                (0x33U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x67U 
                                                                                & (- (::IData)(
                                                                                (0x34U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x66U 
                                                                                & (- (::IData)(
                                                                                (0x2bU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x65U 
                                                                                & (- (::IData)(
                                                                                (0x24U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x64U 
                                                                                & (- (::IData)(
                                                                                (0x23U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x63U 
                                                                                & (- (::IData)(
                                                                                (0x21U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | ((0x61U 
                                                                                & (- (::IData)(
                                                                                (0x1cU 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))))) 
                                                                                | (0x62U 
                                                                                & (- (::IData)(
                                                                                (0x32U 
                                                                                == (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key)))))))))))))))))))))))))))))))))))))))));
    if (vlSelfRef.top__DOT__u_key_decoder__DOT__is_pressed) {
        vlSelfRef.__VprimaryPorts.seg0_out = (0x000000ffU 
                                              & Vtop__ConstPool__CONST_0
                                              [(0x0000000fU 
                                                & (::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key))]);
        vlSelfRef.__VprimaryPorts.seg1_out = (0x000000ffU 
                                              & Vtop__ConstPool__CONST_0
                                              [(0x0000000fU 
                                                & ((::IData)(vlSelfRef.top__DOT__u_key_decoder__DOT__current_key) 
                                                   >> 4U))]);
        vlSelfRef.__VprimaryPorts.seg2_out = (0x000000ffU 
                                              & Vtop__ConstPool__CONST_0
                                              [(0x0000000fU 
                                                & (::IData)(top__DOT__u_display_ascii__DOT__scancode2asciiMux__DOT__i0__DOT__out))]);
        vlSelfRef.__VprimaryPorts.seg3_out = (0x000000ffU 
                                              & Vtop__ConstPool__CONST_0
                                              [(0x0000000fU 
                                                & ((::IData)(top__DOT__u_display_ascii__DOT__scancode2asciiMux__DOT__i0__DOT__out) 
                                                   >> 4U))]);
    } else {
        vlSelfRef.__VprimaryPorts.seg0_out = 0x000000ffU;
        vlSelfRef.__VprimaryPorts.seg1_out = 0x000000ffU;
        vlSelfRef.__VprimaryPorts.seg2_out = 0x000000ffU;
        vlSelfRef.__VprimaryPorts.seg3_out = 0x000000ffU;
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
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @( clrn)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 2U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 2 is active: @( ps2_clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 3U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 3 is active: @( ps2_dat)\n");
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
    vlSelf->__VprimaryPorts.clk = 0;
    vlSelf->__VprimaryPorts.clrn = 0;
    vlSelf->__VprimaryPorts.ps2_clk = 0;
    vlSelf->__VprimaryPorts.ps2_dat = 0;
    vlSelf->__VprimaryPorts.ready = 0;
    vlSelf->__VprimaryPorts.sampling = 0;
    vlSelf->__VprimaryPorts.overflow = 0;
    vlSelf->__VprimaryPorts.seg0_out = 0;
    vlSelf->__VprimaryPorts.seg1_out = 0;
    vlSelf->__VprimaryPorts.seg2_out = 0;
    vlSelf->__VprimaryPorts.seg3_out = 0;
    vlSelf->__VprimaryPorts.seg4 = 0;
    vlSelf->__VprimaryPorts.seg5 = 0;
    vlSelf->top__DOT__nextdata_n = 0;
    vlSelf->top__DOT__state = 0;
    vlSelf->top__DOT__scancode = 0;
    vlSelf->top__DOT__scan_valid = 0;
    vlSelf->top__DOT__u_scancode2ascii__DOT__key_valid = 0;
    vlSelf->top__DOT__u_key_decoder__DOT__count = 0;
    vlSelf->top__DOT__u_key_decoder__DOT__is_pressed = 0;
    vlSelf->top__DOT__u_key_decoder__DOT__current_key = 0;
    vlSelf->top__DOT__u_key_decoder__DOT__break_pending = 0;
    vlSelf->top__DOT__u_ps2_keyboard__DOT__buffer = 0;
    vlSelf->top__DOT__u_ps2_keyboard__DOT__fifo[0] = 0;
    VL_UNPACKED_FILL(vlSelf->top__DOT__u_ps2_keyboard__DOT__fifo.data(), sizeof(vlSelf->top__DOT__u_ps2_keyboard__DOT__fifo[0]), 8);
    vlSelf->top__DOT__u_ps2_keyboard__DOT__w_ptr = 0;
    vlSelf->top__DOT__u_ps2_keyboard__DOT__r_ptr = 0;
    vlSelf->top__DOT__u_ps2_keyboard__DOT__count = 0;
    vlSelf->top__DOT__u_ps2_keyboard__DOT__ps2_clk_sync = 0;
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 2);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__clrn__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ps2_clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__ps2_dat__0 = 0;
    vlSelf->__VactTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VactTriggered.data(), sizeof(vlSelf->__VactTriggered[0]), 1);
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    vlSelf->__VnbaTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VnbaTriggered.data(), sizeof(vlSelf->__VnbaTriggered[0]), 1);
}
