// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSVSIMTESTBENCH__SYMS_H_
#define VERILATED_VSVSIMTESTBENCH__SYMS_H_  // guard

#include "verilated.h"
#include "verilated_vcd_c.h"

// INCLUDE MODEL CLASS

#include "VsvsimTestbench.h"

// INCLUDE MODULE CLASSES
#include "VsvsimTestbench___024root.h"

// DPI TYPES for DPI Export callbacks (Internal use)
using VsvsimTestbench__Vcb_getBitWidthImpl_clock_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_io_led_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitWidthImpl_reset_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &value);
using VsvsimTestbench__Vcb_getBitsImpl_clock_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ &value_clock);
using VsvsimTestbench__Vcb_getBitsImpl_io_led_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ &value_io_led);
using VsvsimTestbench__Vcb_getBitsImpl_reset_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ &value_reset);
using VsvsimTestbench__Vcb_setBitsImpl_clock_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ value_clock);
using VsvsimTestbench__Vcb_setBitsImpl_reset_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, ::CData/*0:0*/ value_reset);
using VsvsimTestbench__Vcb_simulation_disableTrace_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &success);
using VsvsimTestbench__Vcb_simulation_enableTrace_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, ::IData/*31:0*/ &success);
using VsvsimTestbench__Vcb_simulation_initializeTrace_t = void (*) (VsvsimTestbench__Syms* __restrict vlSymsp, ::std::string traceFilePath);

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) VsvsimTestbench__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VsvsimTestbench* const __Vm_modelp;
    const bool __Vm_isRoot;
    std::string __Vm_topNames[2];
    bool __Vm_dumping = false;  // Dumping is active
    VerilatedMutex __Vm_dumperMutex;  // Protect __Vm_dumperp
    VerilatedVcdC* __Vm_dumperp VL_GUARDED_BY(__Vm_dumperMutex) = nullptr;  /// Trace class for $dump*
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    union {
        struct {
            VsvsimTestbench___024root      TOP;
        } vlInst;
    };

    // SCOPE NAMES
    ::VerilatedScope* __Vscopep_svsimTestbench;

    // CONSTRUCTORS
    VsvsimTestbench__Syms(VerilatedContext* contextp, VsvsimTestbench* modelp, const char* namep, bool isRoot);
    ~VsvsimTestbench__Syms();

    // METHODS
    const char* name() const { return vlInst.TOP.vlNamep; }
    void _traceDump();
    void _traceDumpOpen();
    void _traceDumpClose();
};

#endif  // guard
