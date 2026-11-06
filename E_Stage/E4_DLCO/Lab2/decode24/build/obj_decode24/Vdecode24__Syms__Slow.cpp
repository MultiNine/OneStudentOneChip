// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "Vdecode24__pch.h"


void Vdecode24__Syms__ctor(Vdecode24__Syms* vlSymsp, const char* namep) {
    // Setup top module instance
    VL_INPLACE_CONSTRUCT(vlSymsp->vlInst.TOP, vlSymsp, namep);
    // Check resources
    Verilated::stackCheck(26);
    // Setup names of the model and of its top module instances
    vlSymsp->__Vm_topNames[0] = vlSymsp->name();
    vlSymsp->__Vm_topNames[1] = vlSymsp->__Vm_isRoot ? Verilated::catName(vlSymsp->name(), "decode24") : vlSymsp->name();
    // Setup sub module instances
    // Configure time unit / time precision
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
}

Vdecode24__Syms::Vdecode24__Syms(VerilatedContext* contextp, Vdecode24* modelp, const char* namep, bool isRoot)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_isRoot{isRoot}
    , __Vm_didInit{modelp->m_didInit}
{
    Vdecode24__Syms__ctor(this, namep);
}

void Vdecode24__Syms__dtor(Vdecode24__Syms* vlSymsp) {
    // Tear down scopes
    // Tear down sub module instances
    // Tear down top module instance
    VL_INPLACE_DESTRUCT(vlSymsp->vlInst.TOP);
}

Vdecode24__Syms::~Vdecode24__Syms() {
    Vdecode24__Syms__dtor(this);
}
