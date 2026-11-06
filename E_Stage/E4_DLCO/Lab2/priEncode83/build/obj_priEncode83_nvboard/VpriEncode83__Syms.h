// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VPRIENCODE83__SYMS_H_
#define VERILATED_VPRIENCODE83__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VpriEncode83.h"

// INCLUDE MODULE CLASSES
#include "VpriEncode83___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) VpriEncode83__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VpriEncode83* const __Vm_modelp;
    const bool __Vm_isRoot;
    std::string __Vm_topNames[2];
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    union {
        struct {
            VpriEncode83___024root         TOP;
        } vlInst;
    };

    // CONSTRUCTORS
    VpriEncode83__Syms(VerilatedContext* contextp, VpriEncode83* modelp, const char* namep, bool isRoot);
    ~VpriEncode83__Syms();

    // METHODS
    const char* name() const { return vlInst.TOP.vlNamep; }
};

#endif  // guard
