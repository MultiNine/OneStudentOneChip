// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vlfsr.h for the primary calling header

#include "Vlfsr__pch.h"

void Vlfsr___024root___ctor_var_reset(Vlfsr___024root* vlSelf);

void Vlfsr___024root__ctor(Vlfsr___024root* vlSelf, Vlfsr__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    Vlfsr___024root___ctor_var_reset(vlSelf);
}

Vlfsr___024root::Vlfsr___024root(Vlfsr__Syms* symsp, const char* namep) {
    Vlfsr___024root__ctor(this, symsp, namep);
}

void Vlfsr___024root__dtor(Vlfsr___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

Vlfsr___024root::~Vlfsr___024root() {
    Vlfsr___024root__dtor(this);
}
