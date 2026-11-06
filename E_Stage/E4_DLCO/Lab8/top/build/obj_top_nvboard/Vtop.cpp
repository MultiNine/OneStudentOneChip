// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vtop__pch.h"

//============================================================
// Constructors

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__)
    : Vtop{_vcontextp__, _vcname__, true} {}

Vtop::Vtop(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vtop__Syms(contextp(), this, _vcname__, _vcisRoot__)}
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

Vtop::Vtop(const char* _vcname__)
    : Vtop(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vtop::~Vtop() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vtop___024root___eval_debug_assertions(Vtop___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vtop___024root___eval_static(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root___eval_initial(Vtop___024root* vlSelf);
VL_ATTR_COLD bool Vtop___024root___eval_stl(Vtop___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void Vtop___024root___eval_sample(Vtop___024root* vlSelf);
bool Vtop___024root___eval_ico(Vtop___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool Vtop___024root___eval_act(Vtop___024root* vlSelf);
bool Vtop___024root___eval_inact(Vtop___024root* vlSelf);
bool Vtop___024root___eval_nba(Vtop___024root* vlSelf);
bool Vtop___024root___eval_obs(Vtop___024root* vlSelf);
bool Vtop___024root___eval_react(Vtop___024root* vlSelf);
void Vtop___024root___eval_postponed(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root___eval_final(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__stl(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__ico(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__act(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__nba(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__obs(Vtop___024root* vlSelf);
VL_ATTR_COLD void Vtop___024root___eval_dump_triggers__react(Vtop___024root* vlSelf);

void Vtop::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vtop::eval_step\n"); );
    m_evalLoop.eval();
}

void Vtop::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vtop___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vtop::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vtop::evalStatic() {
    Vtop___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void Vtop::evalInitial() {
    Vtop___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool Vtop::evalStl(bool firstIteration) {
    return Vtop___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void Vtop::evalSample() {
    Vtop___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool Vtop::evalIco(bool firstIteration) {
    return Vtop___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool Vtop::evalAct() {
    return Vtop___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool Vtop::evalInact() {
    return Vtop___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool Vtop::evalNba() {
    return Vtop___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool Vtop::evalObs() {
    return Vtop___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool Vtop::evalReact() {
    return Vtop___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void Vtop::evalPostponed() {
    Vtop___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void Vtop::evalFinal() {
    Vtop___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtop::dumpTriggersStl() {
    Vtop___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtop::dumpTriggersIco() {
    Vtop___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtop::dumpTriggersAct() {
    Vtop___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtop::dumpTriggersNba() {
    Vtop___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtop::dumpTriggersObs() {
    Vtop___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vtop::dumpTriggersReact() {
    Vtop___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool Vtop::eventsPending() { return false; }

uint64_t Vtop::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vtop::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vtop::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vtop::hierName() const { return vlSymsp->name(); }
const char* Vtop::modelName() const { return "Vtop"; }
unsigned Vtop::threads() const { return 1; }
void Vtop::prepareClone() const { contextp()->prepareClone(); }
void Vtop::atClone() const {
    contextp()->threadPoolpOnClone();
}
