// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VpriEncode42.h for the primary calling header

#include "VpriEncode42__pch.h"

void VpriEncode42___024root___ctor_var_reset(VpriEncode42___024root* vlSelf);

void VpriEncode42___024root__ctor(VpriEncode42___024root* vlSelf, VpriEncode42__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    VpriEncode42___024root___ctor_var_reset(vlSelf);
}

VpriEncode42___024root::VpriEncode42___024root(VpriEncode42__Syms* symsp, const char* namep) {
    VpriEncode42___024root__ctor(this, symsp, namep);
}

void VpriEncode42___024root__dtor(VpriEncode42___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

VpriEncode42___024root::~VpriEncode42___024root() {
    VpriEncode42___024root__dtor(this);
}
