// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_move.h for the primary calling header

#include "Vtop_move__pch.h"

VL_ATTR_COLD void Vtop_move___024root___eval_static(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_static\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelfRef.__Vtrigprevexpr___TOP__clk__0 = vlSelfRef.__VprimaryPorts.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__0 = vlSelfRef.__VprimaryPorts.rst;
    vlSelfRef.__Vtrigprevexpr___TOP__clk__1 = vlSelfRef.__VprimaryPorts.clk;
    vlSelfRef.__Vtrigprevexpr___TOP__rst__1 = vlSelfRef.__VprimaryPorts.rst;
}

VL_ATTR_COLD void Vtop_move___024root___eval_initial(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_initial\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    {
        // Inlined CFunc: _eval_initial__TOP
        VL_READMEM_N(true, 24, 327680, 0, "./pic/ysyx.hex"s
                     ,  &(vlSelfRef.top_move__DOT__pic_rom)
                     , 0, ~0ULL);
    }
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_move___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
VL_ATTR_COLD bool Vtop_move___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

VL_ATTR_COLD bool Vtop_move___024root___eval_stl(Vtop_move___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_stl\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VstlExecute;
    // Body
    vlSelfRef.__VstlTriggered[0U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VstlTriggered[0U]) 
                                     | (::IData)((::IData)(firstIteration)));
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        Vtop_move___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
    }
#endif
    __VstlExecute = Vtop_move___024root___trigger_anySet__stl(vlSelfRef.__VstlTriggered);
    if (__VstlExecute) {
        {
            // Inlined CFunc: _eval_body__stl
            if ((((1ULL & vlSelfRef.__VstlTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _stl_comb__TOP__0
                    ::CData/*0:0*/ __Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_top_move__DOT__u_vga_ctrl__DOT__h_valid;
                    __Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_top_move__DOT__u_vga_ctrl__DOT__h_valid = 0;
                    ::CData/*0:0*/ __Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_top_move__DOT__u_vga_ctrl__DOT__v_valid;
                    __Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_top_move__DOT__u_vga_ctrl__DOT__v_valid = 0;
                    vlSelfRef.__VprimaryPorts.VGA_HSYNC 
                        = (0x0060U < (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt));
                    vlSelfRef.__VprimaryPorts.VGA_R 
                        = (0x000000ffU & (vlSelfRef.top_move__DOT__vga_data 
                                          >> 0x00000010U));
                    vlSelfRef.__VprimaryPorts.VGA_G 
                        = (0x000000ffU & (vlSelfRef.top_move__DOT__vga_data 
                                          >> 8U));
                    vlSelfRef.__VprimaryPorts.VGA_B 
                        = (0x000000ffU & vlSelfRef.top_move__DOT__vga_data);
                    vlSelfRef.__VprimaryPorts.VGA_VSYNC 
                        = (2U < (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__y_cnt));
                    __Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_top_move__DOT__u_vga_ctrl__DOT__h_valid 
                        = ((0x0090U < (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt)) 
                           & (0x0310U >= (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt)));
                    __Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_top_move__DOT__u_vga_ctrl__DOT__v_valid 
                        = ((0x0023U < (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__y_cnt)) 
                           & (0x0203U >= (::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__y_cnt)));
                    vlSelfRef.top_move__DOT__frame_tick 
                        = ((~ (::IData)(vlSelfRef.__VprimaryPorts.VGA_VSYNC)) 
                           & (::IData)(vlSelfRef.top_move__DOT__VGA_VSYNC_d));
                    vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__h_addr 
                        = (0x000003ffU & (((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__x_cnt) 
                                           - (::IData)(0x0091U)) 
                                          & (- (::IData)((::IData)(__Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_top_move__DOT__u_vga_ctrl__DOT__h_valid)))));
                    vlSelfRef.__VprimaryPorts.VGA_BLANK_N 
                        = ((::IData)(__Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_top_move__DOT__u_vga_ctrl__DOT__h_valid) 
                           & (::IData)(__Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_top_move__DOT__u_vga_ctrl__DOT__v_valid));
                    vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__v_addr 
                        = (0x000003ffU & (((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__y_cnt) 
                                           - (::IData)(0x0024U)) 
                                          & (- (::IData)((::IData)(__Vinline_0__eval_body__stl___Vinline_0__stl_comb__TOP__0_top_move__DOT__u_vga_ctrl__DOT__v_valid)))));
                    vlSelfRef.top_move__DOT__pic_valid 
                        = ((::IData)(vlSelfRef.__VprimaryPorts.VGA_BLANK_N) 
                           & (((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__h_addr) 
                               >= (::IData)(vlSelfRef.top_move__DOT__x_pos)) 
                              & (((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__h_addr) 
                                  < ((::IData)(0x00000064U) 
                                     + (::IData)(vlSelfRef.top_move__DOT__x_pos))) 
                                 & (((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__v_addr) 
                                     >= (::IData)(vlSelfRef.top_move__DOT__y_pos)) 
                                    & ((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__v_addr) 
                                       < ((::IData)(0x00000064U) 
                                          + (::IData)(vlSelfRef.top_move__DOT__y_pos)))))));
                    vlSelfRef.top_move__DOT__addr_rom 
                        = (((0x0007fe00U & (((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__h_addr) 
                                             - (::IData)(vlSelfRef.top_move__DOT__x_pos)) 
                                            << 9U)) 
                            | (0x000001ffU & ((::IData)(vlSelfRef.top_move__DOT__u_vga_ctrl__DOT__v_addr) 
                                              - (::IData)(vlSelfRef.top_move__DOT__y_pos)))) 
                           & (- (::IData)((::IData)(vlSelfRef.top_move__DOT__pic_valid))));
                }
            }
        }
    }
    return (__VstlExecute);
}

VL_ATTR_COLD void Vtop_move___024root___eval_dump_triggers__stl(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_dump_triggers__stl\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtop_move___024root___dump_triggers__stl(vlSelfRef.__VstlTriggered, "stl"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_move___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_move___024root___eval_dump_triggers__ico(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_dump_triggers__ico\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtop_move___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
#endif
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_move___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_move___024root___eval_dump_triggers__act(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_dump_triggers__act\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtop_move___024root___dump_triggers__act(vlSelfRef.__VactTriggered, "act"s);
#endif
}

VL_ATTR_COLD void Vtop_move___024root___eval_dump_triggers__nba(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_dump_triggers__nba\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
#ifdef VL_DEBUG
    Vtop_move___024root___dump_triggers__act(vlSelfRef.__VnbaTriggered, "nba"s);
#endif
}

VL_ATTR_COLD void Vtop_move___024root___eval_dump_triggers__obs(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_dump_triggers__obs\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop_move___024root___eval_dump_triggers__react(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_dump_triggers__react\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

VL_ATTR_COLD void Vtop_move___024root___eval_final(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___eval_final\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_move___024root___dump_triggers__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___dump_triggers__stl\n"); );
    // Body
    if ((1U & (~ (::IData)(Vtop_move___024root___trigger_anySet__stl(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: Internal 'stl' trigger - first iteration\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD bool Vtop_move___024root___trigger_anySet__stl(const ::VlUnpacked<::QData/*63:0*/, 1> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___trigger_anySet__stl\n"); );
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

bool Vtop_move___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_move___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___dump_triggers__ico\n"); );
    // Body
    if ((1U & (~ (::IData)(Vtop_move___024root___trigger_anySet__ico(triggers))))) {
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

bool Vtop_move___024root___trigger_anySet__act(const ::VlUnpacked<::QData/*63:0*/, 1> &in);

#ifdef VL_DEBUG
VL_ATTR_COLD void Vtop_move___024root___dump_triggers__act(const ::VlUnpacked<::QData/*63:0*/, 1> &triggers, const ::std::string &tag) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___dump_triggers__act\n"); );
    // Body
    if ((1U & (~ (::IData)(Vtop_move___024root___trigger_anySet__act(triggers))))) {
        VL_DBG_MSGS("         No '" + tag + "' region triggers active\n");
    }
    if ((1U & (::IData)(triggers[0U]))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 0 is active: @(posedge clk)\n");
    }
    if ((1U & (::IData)((triggers[0U] >> 1U)))) {
        VL_DBG_MSGS("         '" + tag + "' region trigger index 1 is active: @(posedge rst)\n");
    }
}
#endif  // VL_DEBUG

VL_ATTR_COLD void Vtop_move___024root___ctor_var_reset(Vtop_move___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop_move___024root___ctor_var_reset\n"); );
    Vtop_move__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    vlSelf->__VprimaryPorts.clk = 0;
    vlSelf->__VprimaryPorts.rst = 0;
    vlSelf->__VprimaryPorts.VGA_HSYNC = 0;
    vlSelf->__VprimaryPorts.VGA_VSYNC = 0;
    vlSelf->__VprimaryPorts.VGA_BLANK_N = 0;
    vlSelf->__VprimaryPorts.VGA_R = 0;
    vlSelf->__VprimaryPorts.VGA_G = 0;
    vlSelf->__VprimaryPorts.VGA_B = 0;
    vlSelf->top_move__DOT__vga_data = 0;
    vlSelf->top_move__DOT__x_pos = 0;
    vlSelf->top_move__DOT__y_pos = 0;
    vlSelf->top_move__DOT__x_dir = 0;
    vlSelf->top_move__DOT__y_dir = 0;
    vlSelf->top_move__DOT__VGA_VSYNC_d = 0;
    vlSelf->top_move__DOT__frame_tick = 0;
    vlSelf->top_move__DOT__pic_valid = 0;
    vlSelf->top_move__DOT__pic_rom[0] = 0;
    VL_UNPACKED_FILL(vlSelf->top_move__DOT__pic_rom.data(), sizeof(vlSelf->top_move__DOT__pic_rom[0]), 327680);
    vlSelf->top_move__DOT__addr_rom = 0;
    vlSelf->top_move__DOT__u_vga_ctrl__DOT__h_addr = 0;
    vlSelf->top_move__DOT__u_vga_ctrl__DOT__v_addr = 0;
    vlSelf->top_move__DOT__u_vga_ctrl__DOT__x_cnt = 0;
    vlSelf->top_move__DOT__u_vga_ctrl__DOT__y_cnt = 0;
    vlSelf->__VstlTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VstlTriggered.data(), sizeof(vlSelf->__VstlTriggered[0]), 1);
    vlSelf->__VicoTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VicoTriggered.data(), sizeof(vlSelf->__VicoTriggered[0]), 2);
    vlSelf->__Vtrigprevexpr___TOP__clk__0 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__0 = 0;
    vlSelf->__VactTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VactTriggered.data(), sizeof(vlSelf->__VactTriggered[0]), 1);
    vlSelf->__Vtrigprevexpr___TOP__clk__1 = 0;
    vlSelf->__Vtrigprevexpr___TOP__rst__1 = 0;
    vlSelf->__VnbaTriggered[0] = 0;
    VL_UNPACKED_FILL(vlSelf->__VnbaTriggered.data(), sizeof(vlSelf->__VnbaTriggered[0]), 1);
}
