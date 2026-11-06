// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VpriEncode83.h for the primary calling header

#include "VpriEncode83__pch.h"

void VpriEncode83___024root___ctor_var_reset(VpriEncode83___024root* vlSelf);

void VpriEncode83___024root__ctor(VpriEncode83___024root* vlSelf, VpriEncode83__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    VpriEncode83___024root___ctor_var_reset(vlSelf);
}

VpriEncode83___024root::VpriEncode83___024root(VpriEncode83__Syms* symsp, const char* namep) {
    VpriEncode83___024root__ctor(this, symsp, namep);
}

void VpriEncode83___024root__dtor(VpriEncode83___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

VpriEncode83___024root::~VpriEncode83___024root() {
    VpriEncode83___024root__dtor(this);
}
