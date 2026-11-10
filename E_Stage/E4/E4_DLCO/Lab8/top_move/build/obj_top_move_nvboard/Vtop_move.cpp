// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop_move__pch.h"

//============================================================
// Constructors

Vtop_move::Vtop_move(VerilatedContext* _vcontextp__, const char* _vcname__)
    : Vtop_move{_vcontextp__, _vcname__, true} {}

Vtop_move::Vtop_move(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop_move__Syms(contextp(), this, _vcname__, _vcisRoot__)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , clk{vlSymsp->vlInst.TOP.__VprimaryPorts.clk}
    , rst{vlSymsp->vlInst.TOP.__VprimaryPorts.rst}
    , VGA_HSYNC{vlSymsp->vlInst.TOP.__VprimaryPorts.VGA_HSYNC}
    , VGA_VSYNC{vlSymsp->vlInst.TOP.__VprimaryPorts.VGA_VSYNC}
    , VGA_BLANK_N{vlSymsp->vlInst.TOP.__VprimaryPorts.VGA_BLANK_N}
    , VGA_R{vlSymsp->vlInst.TOP.__VprimaryPorts.VGA_R}
    , VGA_G{vlSymsp->vlInst.TOP.__VprimaryPorts.VGA_G}
    , VGA_B{vlSymsp->vlInst.TOP.__VprimaryPorts.VGA_B}
    , rootp{&(vlSymsp->vlInst.TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

Vtop_move::Vtop_move(const char* _vcname__)
    : Vtop_move(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop_move::~Vtop_move() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop_move___024root___eval_debug_assertions(Vtop_move___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop_move___024root___eval_static(Vtop_move___024root* vlSelf);
VL_ATTR_COLD void Vtop_move___024root___eval_initial(Vtop_move___024root* vlSelf);
VL_ATTR_COLD bool Vtop_move___024root___eval_stl(Vtop_move___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void Vtop_move___024root___eval_sample(Vtop_move___024root* vlSelf);
bool Vtop_move___024root___eval_ico(Vtop_move___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool Vtop_move___024root___eval_act(Vtop_move___024root* vlSelf);
bool Vtop_move___024root___eval_inact(Vtop_move___024root* vlSelf);
bool Vtop_move___024root___eval_nba(Vtop_move___024root* vlSelf);
bool Vtop_move___024root___eval_obs(Vtop_move___024root* vlSelf);
bool Vtop_move___024root___eval_react(Vtop_move___024root* vlSelf);
void Vtop_move___024root___eval_postponed(Vtop_move___024root* vlSelf);
VL_ATTR_COLD void Vtop_move___024root___eval_final(Vtop_move___024root* vlSelf);
VL_ATTR_COLD void Vtop_move___024root___eval_dump_triggers__stl(Vtop_move___024root* vlSelf);
VL_ATTR_COLD void Vtop_move___024root___eval_dump_triggers__ico(Vtop_move___024root* vlSelf);
VL_ATTR_COLD void Vtop_move___024root___eval_dump_triggers__act(Vtop_move___024root* vlSelf);
VL_ATTR_COLD void Vtop_move___024root___eval_dump_triggers__nba(Vtop_move___024root* vlSelf);
VL_ATTR_COLD void Vtop_move___024root___eval_dump_triggers__obs(Vtop_move___024root* vlSelf);
VL_ATTR_COLD void Vtop_move___024root___eval_dump_triggers__react(Vtop_move___024root* vlSelf);

void Vtop_move::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop_move::eval_step\n"); );
    m_evalLoop.eval();
}

void Vtop_move::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vtop_move___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vtop_move::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vtop_move::evalStatic() {
    Vtop_move___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void Vtop_move::evalInitial() {
    Vtop_move___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool Vtop_move::evalStl(bool firstIteration) {
    return Vtop_move___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void Vtop_move::evalSample() {
    Vtop_move___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool Vtop_move::evalIco(bool firstIteration) {
    return Vtop_move___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool Vtop_move::evalAct() {
    return Vtop_move___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool Vtop_move::evalInact() {
    return Vtop_move___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool Vtop_move::evalNba() {
    return Vtop_move___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool Vtop_move::evalObs() {
    return Vtop_move___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool Vtop_move::evalReact() {
    return Vtop_move___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void Vtop_move::evalPostponed() {
    Vtop_move___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void Vtop_move::evalFinal() {
    Vtop_move___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtop_move::dumpTriggersStl() {
    Vtop_move___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtop_move::dumpTriggersIco() {
    Vtop_move___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtop_move::dumpTriggersAct() {
    Vtop_move___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtop_move::dumpTriggersNba() {
    Vtop_move___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtop_move::dumpTriggersObs() {
    Vtop_move___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtop_move::dumpTriggersReact() {
    Vtop_move___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool Vtop_move::eventsPending() { return false; }

uint64_t Vtop_move::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtop_move::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vtop_move::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop_move::hierName() const { return vlSymsp->name(); }
const char* Vtop_move::modelName() const { return "Vtop_move"; }
unsigned Vtop_move::threads() const { return 1; }
void Vtop_move::prepareClone() const { contextp()->prepareClone(); }
void Vtop_move::atClone() const {
    contextp()->threadPoolpOnClone();
}
