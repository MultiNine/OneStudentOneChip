// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsvsimTestbench.h for the primary calling header

#include "VsvsimTestbench__pch.h"

void VsvsimTestbench___024root___ctor_var_reset(VsvsimTestbench___024root* vlSelf);

void VsvsimTestbench___024root__ctor(VsvsimTestbench___024root* vlSelf, VsvsimTestbench__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    VsvsimTestbench___024root___ctor_var_reset(vlSelf);
}

VsvsimTestbench___024root::VsvsimTestbench___024root(VsvsimTestbench__Syms* symsp, const char* namep) {
    VsvsimTestbench___024root__ctor(this, symsp, namep);
}

void VsvsimTestbench___024root__dtor(VsvsimTestbench___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

VsvsimTestbench___024root::~VsvsimTestbench___024root() {
    VsvsimTestbench___024root__dtor(this);
}
