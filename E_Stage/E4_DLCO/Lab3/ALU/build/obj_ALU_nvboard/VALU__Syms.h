// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VALU__SYMS_H_
#define VERILATED_VALU__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "VALU.h"

// INCLUDE MODULE CLASSES
#include "VALU___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) VALU__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    VALU* const __Vm_modelp;
    const bool __Vm_isRoot;
    std::string __Vm_topNames[2];
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    union {
        struct {
            VALU___024root                 TOP;
        } vlInst;
    };

    // CONSTRUCTORS
    VALU__Syms(VerilatedContext* contextp, VALU* modelp, const char* namep, bool isRoot);
    ~VALU__Syms();

    // METHODS
    const char* name() const { return vlInst.TOP.vlNamep; }
};

#endif  // guard
