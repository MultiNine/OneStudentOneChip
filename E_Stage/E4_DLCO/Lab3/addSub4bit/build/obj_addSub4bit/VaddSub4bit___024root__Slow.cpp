// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Design implementation internals
// See VaddSub4bit.h for the primary calling header

#include "VaddSub4bit__pch.h"

void VaddSub4bit___024root___ctor_var_reset(VaddSub4bit___024root* vlSelf);

void VaddSub4bit___024root__ctor(VaddSub4bit___024root* vlSelf, VaddSub4bit__Syms* symsp, const char* namep) {
    vlSelf->vlSymsp = symsp;
    vlSelf->vlNamep = strdup(namep);
    // Construct members
    // Reset structure values
    VaddSub4bit___024root___ctor_var_reset(vlSelf);
}

VaddSub4bit___024root::VaddSub4bit___024root(VaddSub4bit__Syms* symsp, const char* namep) {
    VaddSub4bit___024root__ctor(this, symsp, namep);
}

void VaddSub4bit___024root__dtor(VaddSub4bit___024root* vlSelf) {
    // Destroy members
    VL_DO_DANGLING(std::free(const_cast<char*>(vlSelf->vlNamep)), vlSelf->vlNamep);
}

VaddSub4bit___024root::~VaddSub4bit___024root() {
    VaddSub4bit___024root__dtor(this);
}
