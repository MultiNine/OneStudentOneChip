// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vdecode24.h for the primary calling header

#include "Vdecode24__pch.h"

void Vdecode24___024root___ctor_var_reset(Vdecode24___024root* vlSelf);

void Vdecode24___024root__ctor(Vdecode24___024root* vlSelf, Vdecode24__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    Vdecode24___024root___ctor_var_reset(vlSelf);
}

Vdecode24___024root::Vdecode24___024root(Vdecode24__Syms* symsp, const char* namep) {
    Vdecode24___024root__ctor(this, symsp, namep);
}

void Vdecode24___024root__dtor(Vdecode24___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

Vdecode24___024root::~Vdecode24___024root() {
    Vdecode24___024root__dtor(this);
}
