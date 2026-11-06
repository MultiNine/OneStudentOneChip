// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VALU.h for the primary calling header

#include "VALU__pch.h"

void VALU___024root___ctor_var_reset(VALU___024root* vlSelf);

void VALU___024root__ctor(VALU___024root* vlSelf, VALU__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    VALU___024root___ctor_var_reset(vlSelf);
}

VALU___024root::VALU___024root(VALU__Syms* symsp, const char* namep) {
    VALU___024root__ctor(this, symsp, namep);
}

void VALU___024root__dtor(VALU___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

VALU___024root::~VALU___024root() {
    VALU___024root__dtor(this);
}
