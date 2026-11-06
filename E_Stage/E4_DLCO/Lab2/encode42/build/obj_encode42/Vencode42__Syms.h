// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VENCODE42__SYMS_H_
#define VERILATED_VENCODE42__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vencode42.h"

// INCLUDE MODULE CLASSES
#include "Vencode42___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vencode42__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vencode42* const __Vm_modelp;
    const bool __Vm_isRoot;
    std::string __Vm_topNames[2];
    bool __Vm_activity = false;  ///< Used by trace routines to determine change occurred
    uint32_t __Vm_baseCode = 0;  ///< Used by trace routines when tracing multiple models
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    union {
        struct {
            Vencode42___024root            TOP;
        } vlInst;
    };

    // CONSTRUCTORS
    Vencode42__Syms(VerilatedContext* contextp, Vencode42* modelp, const char* namep, bool isRoot);
    ~Vencode42__Syms();

    // METHODS
    const char* name() const { return vlInst.TOP.vlNamep; }
};

#endif  // guard
