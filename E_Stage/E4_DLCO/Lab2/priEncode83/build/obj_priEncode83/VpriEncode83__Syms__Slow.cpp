// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VpriEncode83__pch.h"


void VpriEncode83__Syms__ctor(VpriEncode83__Syms* vlSymsp, const char* namep) {
    // Setup top module instance
    VL_INPLACE_CONSTRUCT(vlSymsp->vlInst.TOP, vlSymsp, namep);
    // Check resources
    Verilated::stackCheck(26);
    // Setup names of the model and of its top module instances
    vlSymsp->__Vm_topNames[0] = vlSymsp->name();
    vlSymsp->__Vm_topNames[1] = vlSymsp->__Vm_isRoot ? Verilated::catName(vlSymsp->name(), "priEncode83") : vlSymsp->name();
    // Setup sub module instances
    // Configure time unit / time precision
    vlSymsp->_vm_contextp__->timeunit(-12);
    vlSymsp->_vm_contextp__->timeprecision(-12);
    // Setup each module's pointers to their submodules
}

VpriEncode83__Syms::VpriEncode83__Syms(VerilatedContext* contextp, VpriEncode83* modelp, const char* namep, bool isRoot)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_isRoot{isRoot}
    , __Vm_didInit{modelp->m_didInit}
{
    VpriEncode83__Syms__ctor(this, namep);
}

void VpriEncode83__Syms__dtor(VpriEncode83__Syms* vlSymsp) {
    // Tear down scopes
    // Tear down sub module instances
    // Tear down top module instance
    VL_INPLACE_DESTRUCT(vlSymsp->vlInst.TOP);
}

VpriEncode83__Syms::~VpriEncode83__Syms() {
    VpriEncode83__Syms__dtor(this);
}
