// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Symbol table internal header
//
// Internal details; most calling programs do not need this header,
// unless using verilator public meta comments.

#ifndef VERILATED_VTOP_MOVE__SYMS_H_
#define VERILATED_VTOP_MOVE__SYMS_H_  // guard

#include "verilated.h"

// INCLUDE MODEL CLASS

#include "Vtop_move.h"

// INCLUDE MODULE CLASSES
#include "Vtop_move___024root.h"

// SYMS CLASS (contains all model state)
class alignas(VL_CACHE_LINE_BYTES) Vtop_move__Syms final : public VerilatedSyms {
  public:
    // INTERNAL STATE
    Vtop_move* const __Vm_modelp;
    const bool __Vm_isRoot;
    std::string __Vm_topNames[2];
    VlDeleter __Vm_deleter;
    bool& __Vm_didInit;

    // MODULE INSTANCE STATE
    union {
        struct {
            Vtop_move___024root            TOP;
        } vlInst;
    };

    // CONSTRUCTORS
    Vtop_move__Syms(VerilatedContext* contextp, Vtop_move* modelp, const char* namep, bool isRoot);
    ~Vtop_move__Syms();

    // METHODS
    const char* name() const { return vlInst.TOP.vlNamep; }
};

#endif  // guard
