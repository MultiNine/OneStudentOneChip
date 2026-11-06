// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See Vtop_move.h for the primary calling header

#include "Vtop_move__pch.h"

void Vtop_move___024root___ctor_var_reset(Vtop_move___024root* vlSelf);

void Vtop_move___024root__ctor(Vtop_move___024root* vlSelf, Vtop_move__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    Vtop_move___024root___ctor_var_reset(vlSelf);
}

Vtop_move___024root::Vtop_move___024root(Vtop_move__Syms* symsp, const char* namep) {
    Vtop_move___024root__ctor(this, symsp, namep);
}

void Vtop_move___024root__dtor(Vtop_move___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

Vtop_move___024root::~Vtop_move___024root() {
    Vtop_move___024root__dtor(this);
}
