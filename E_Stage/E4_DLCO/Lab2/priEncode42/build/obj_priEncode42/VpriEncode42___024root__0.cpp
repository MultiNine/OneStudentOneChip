// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VpriEncode42.h for the primary calling header

#include "VpriEncode42__pch.h"

void VpriEncode42___024root___eval_sample(VpriEncode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root___eval_sample\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

#ifdef VL_DEBUG
VL_ATTR_COLD void VpriEncode42___024root___dump_triggers__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &triggers, const ::std::string &tag);
#endif  // VL_DEBUG
bool VpriEncode42___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in);
extern const ::VlUnpacked<::CData/*1:0*/, 32> VpriEncode42__ConstPool__CONSARRAY_1;
extern const ::VlUnpacked<::CData/*1:0*/, 32> VpriEncode42__ConstPool__CONSARRAY_0;
extern const ::VlUnpacked<::IData/*31:0*/, 32> VpriEncode42__ConstPool__CONSARRAY_2;

bool VpriEncode42___024root___eval_ico(VpriEncode42___024root* vlSelf, ::CData/*0:0*/ firstIteration) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root___eval_ico\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Locals
    ::CData/*0:0*/ __VicoExecute;
    // Body
    vlSelfRef.__VicoTriggered[1U] = ((0xfffffffffffffffeULL 
                                      & vlSelfRef.__VicoTriggered[1U]) 
                                     | (::IData)((::IData)(firstIteration)));
    {
        // Inlined CFunc: _eval_triggers_vec__ico
        vlSelfRef.__VicoTriggered[0U] = (::QData)((::IData)(
                                                            ((((::IData)(vlSelfRef.__VprimaryPorts.en) 
                                                               != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__en__0)) 
                                                              << 1U) 
                                                             | ((::IData)(vlSelfRef.__VprimaryPorts.x) 
                                                                != (::IData)(vlSelfRef.__Vtrigprevexpr___TOP__x__0)))));
        vlSelfRef.__Vtrigprevexpr___TOP__x__0 = vlSelfRef.__VprimaryPorts.x;
        vlSelfRef.__Vtrigprevexpr___TOP__en__0 = vlSelfRef.__VprimaryPorts.en;
    }
#ifdef VL_DEBUG
    if (VL_UNLIKELY(vlSymsp->_vm_contextp__->debug())) {
        VpriEncode42___024root___dump_triggers__ico(vlSelfRef.__VicoTriggered, "ico"s);
    }
#endif
    __VicoExecute = VpriEncode42___024root___trigger_anySet__ico(vlSelfRef.__VicoTriggered);
    if (__VicoExecute) {
        {
            // Inlined CFunc: _eval_body__ico
            if ((((3ULL & vlSelfRef.__VicoTriggered[0U])) != 0ULL)) {
                {
                    // Inlined CFunc: _ico_comb__TOP__0
                    ::CData/*4:0*/ __Vinline_0__eval_body__ico___Vinline_1__ico_comb__TOP__0___Vtableidx_0;
                    __Vinline_0__eval_body__ico___Vinline_1__ico_comb__TOP__0___Vtableidx_0 = 0;
                    __Vinline_0__eval_body__ico___Vinline_1__ico_comb__TOP__0___Vtableidx_0 
                        = (((::IData)(vlSelfRef.__VprimaryPorts.x) 
                            << 1U) | (::IData)(vlSelfRef.__VprimaryPorts.en));
                    vlSelfRef.__VprimaryPorts.y = VpriEncode42__ConstPool__CONSARRAY_1
                        [__Vinline_0__eval_body__ico___Vinline_1__ico_comb__TOP__0___Vtableidx_0];
                    if ((0U != (2U & VpriEncode42__ConstPool__CONSARRAY_0
                                [__Vinline_0__eval_body__ico___Vinline_1__ico_comb__TOP__0___Vtableidx_0]))) {
                        vlSelfRef.priEncode42__DOT__i 
                            = VpriEncode42__ConstPool__CONSARRAY_2
                            [__Vinline_0__eval_body__ico___Vinline_1__ico_comb__TOP__0___Vtableidx_0];
                    }
                }
            }
        }
    }
    return (__VicoExecute);
}

bool VpriEncode42___024root___eval_act(VpriEncode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root___eval_act\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VpriEncode42___024root___eval_inact(VpriEncode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root___eval_inact\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VpriEncode42___024root___eval_nba(VpriEncode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root___eval_nba\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VpriEncode42___024root___eval_obs(VpriEncode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root___eval_obs\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

bool VpriEncode42___024root___eval_react(VpriEncode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root___eval_react\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    return (0U);
}

void VpriEncode42___024root___eval_postponed(VpriEncode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root___eval_postponed\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
}

bool VpriEncode42___024root___trigger_anySet__ico(const ::VlUnpacked<::QData/*63:0*/, 2> &in) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root___trigger_anySet__ico\n"); );
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

#ifdef VL_DEBUG
void VpriEncode42___024root___eval_debug_assertions(VpriEncode42___024root* vlSelf) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    VpriEncode42___024root___eval_debug_assertions\n"); );
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.x & 0xf0U)))) {
        Verilated::overWidthError("x");
    }
    if (VL_UNLIKELY(((vlSelfRef.__VprimaryPorts.en 
                      & 0xfeU)))) {
        Verilated::overWidthError("en");
    }
}
#endif  // VL_DEBUG
