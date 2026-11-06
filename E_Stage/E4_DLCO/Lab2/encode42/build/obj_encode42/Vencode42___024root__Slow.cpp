// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vencode42.h for the primary calling header

#include "Vencode42__pch.h"

void Vencode42___024root___ctor_var_reset(Vencode42___024root* vlSelf);

void Vencode42___024root__ctor(Vencode42___024root* vlSelf, Vencode42__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    Vencode42___024root___ctor_var_reset(vlSelf);
}

Vencode42___024root::Vencode42___024root(Vencode42__Syms* symsp, const char* namep) {
    Vencode42___024root__ctor(this, symsp, namep);
}

void Vencode42___024root__dtor(Vencode42___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

Vencode42___024root::~Vencode42___024root() {
    Vencode42___024root__dtor(this);
}
