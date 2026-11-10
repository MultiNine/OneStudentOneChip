// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VsCPU.h for the primary calling header

#include "VsCPU__pch.h"

void VsCPU___024root___ctor_var_reset(VsCPU___024root* vlSelf);

void VsCPU___024root__ctor(VsCPU___024root* vlSelf, VsCPU__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    VsCPU___024root___ctor_var_reset(vlSelf);
}

VsCPU___024root::VsCPU___024root(VsCPU__Syms* symsp, const char* namep) {
    VsCPU___024root__ctor(this, symsp, namep);
}

void VsCPU___024root__dtor(VsCPU___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

VsCPU___024root::~VsCPU___024root() {
    VsCPU___024root__dtor(this);
}
