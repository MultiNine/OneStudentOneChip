// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table implementation internals

#include "VsvsimTestbench__pch.h"

void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &value);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_led_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &value);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &value);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ &value_clock);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_led_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ &value_io_led);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ &value_reset);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_clock_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ value_clock);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_reset_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ value_reset);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_disableTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &success);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_enableTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &success);
void VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_initializeTrace_TOP(VsvsimTestbench__Syms* __restrict vlSymsp, ::std::string traceFilePath);

extern const VlScopeTableEntry VsvsimTestbench__Syms__VpiScopeTable[];


// VPI VARIABLE/SCOPE TABLES
#if defined(__GNUC__)
# pragma GCC diagnostic push
# pragma GCC diagnostic ignored "-Winvalid-offsetof"
#endif
extern const VlScopeTableEntry VsvsimTestbench__Syms__VpiScopeTable[] = {
    {offsetof(VsvsimTestbench__Syms, __Vscopep_svsimTestbench), "", "svsimTestbench", "<null>", 1, -9, VerilatedScope::SCOPE_OTHER},
};
#if defined(__GNUC__)
# pragma GCC diagnostic pop
#endif

void VsvsimTestbench__Syms__ctor(VsvsimTestbench__Syms* vlSymsp, const char* namep) {
    // Setup top module instance
    VL_INPLACE_CONSTRUCT(vlSymsp->vlInst.TOP, vlSymsp, namep);
    // Check resources
    Verilated::stackCheck(37);
    // Setup names of the model and of its top module instances
    vlSymsp->__Vm_topNames[0] = vlSymsp->name();
    vlSymsp->__Vm_topNames[1] = vlSymsp->__Vm_isRoot ? Verilated::catName(vlSymsp->name(), "svsimTestbench") : vlSymsp->name();
    // Setup sub module instances
    // Configure time unit / time precision
    vlSymsp->_vm_contextp__->timeunit(-9);
    vlSymsp->_vm_contextp__->timeprecision(-10);
    // Setup each module's pointers to their submodules
    // Setup scopes
    VerilatedScope::scopesConstructFromTable(VsvsimTestbench__Syms__VpiScopeTable, 1, vlSymsp, vlSymsp->__Vm_topNames);
    // Setup export functions - final: 0
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(0, "getBitWidthImpl_clock", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_clock_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(0, "getBitWidthImpl_io_led", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_led_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(0, "getBitWidthImpl_reset", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_reset_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(0, "getBitsImpl_clock", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_clock_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(0, "getBitsImpl_io_led", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_led_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(0, "getBitsImpl_reset", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_reset_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(0, "setBitsImpl_clock", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_clock_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(0, "setBitsImpl_reset", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_reset_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(0, "simulation_disableTrace", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_disableTrace_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(0, "simulation_enableTrace", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_enableTrace_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(0, "simulation_initializeTrace", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_initializeTrace_TOP));
    // Setup export functions - final: 1
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(1, "getBitWidthImpl_clock", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_clock_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(1, "getBitWidthImpl_io_led", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_io_led_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(1, "getBitWidthImpl_reset", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitWidthImpl_reset_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(1, "getBitsImpl_clock", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_clock_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(1, "getBitsImpl_io_led", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_io_led_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(1, "getBitsImpl_reset", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__getBitsImpl_reset_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(1, "setBitsImpl_clock", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_clock_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(1, "setBitsImpl_reset", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__setBitsImpl_reset_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(1, "simulation_disableTrace", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_disableTrace_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(1, "simulation_enableTrace", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_enableTrace_TOP));
    vlSymsp->__Vscopep_svsimTestbench->exportInsert(1, "simulation_initializeTrace", (void*)(&VsvsimTestbench___024root____Vdpiexp_svsimTestbench__DOT__simulation_initializeTrace_TOP));
}

VsvsimTestbench__Syms::VsvsimTestbench__Syms(VerilatedContext* contextp, VsvsimTestbench* modelp, const char* namep, bool isRoot)
    : VerilatedSyms{contextp}
    // Setup internal state of the Syms class
    , __Vm_modelp{modelp}
    , __Vm_isRoot{isRoot}
    , __Vm_didInit{modelp->m_didInit}
{
    VsvsimTestbench__Syms__ctor(this, namep);
}

void VsvsimTestbench__Syms__dtor(VsvsimTestbench__Syms* vlSymsp) {
    if (vlSymsp->__Vm_dumping) vlSymsp->_traceDumpClose();
    // Tear down scopes
    VL_DO_CLEAR(delete vlSymsp->__Vscopep_svsimTestbench, vlSymsp->__Vscopep_svsimTestbench = nullptr);
    // Tear down sub module instances
    // Tear down top module instance
    VL_INPLACE_DESTRUCT(vlSymsp->vlInst.TOP);
}

VsvsimTestbench__Syms::~VsvsimTestbench__Syms() {
    VsvsimTestbench__Syms__dtor(this);
}

void VsvsimTestbench__Syms::_traceDump() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumperp->dump(VL_TIME_Q());
}

void VsvsimTestbench__Syms::_traceDumpOpen() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    if (VL_UNLIKELY(!__Vm_dumperp)) {
        __Vm_dumperp = new VerilatedVcdC();
        __Vm_modelp->trace(__Vm_dumperp, 0, 0);
        const std::string dumpfile = _vm_contextp__->dumpfileCheck();
        __Vm_dumperp->open(dumpfile.c_str());
        __Vm_dumping = true;
    }
}

void VsvsimTestbench__Syms::_traceDumpClose() {
    const VerilatedLockGuard lock{__Vm_dumperMutex};
    __Vm_dumping = false;
    VL_DO_CLEAR(delete __Vm_dumperp, __Vm_dumperp = nullptr);
}
