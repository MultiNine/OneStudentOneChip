// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VSCPU__SYMS_H_
#define VERILATED_VSCPU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VsCPU.h"

// INCLUDE MODULE CLASSES
#include "VsCPU___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) VsCPU__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VsCPU* const __Vm_modelp;
    const bool __Vm_isRoot;
    std::string __Vm_topNames[2];
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    union {
        struct {
            VsCPU___024root                TOP;
        } vlInst;
    };

    // CONSTRUCTORS
    VsCPU__Syms(VerilatedContext* contextp, VsCPU* modelp, const char* namep, bool isRoot);
    ~VsCPU__Syms();

    // METHODS
    const char* name() const { return vlInst.TOP.vlNamep; }
};

#endif  // guard
