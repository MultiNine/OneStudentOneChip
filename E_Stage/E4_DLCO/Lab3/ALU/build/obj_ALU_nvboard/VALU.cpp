// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VALU__pch.h"

//============================================================
// Constructors

VALU::VALU(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VALU{_vcontextp__, _vcname__, true} {}

VALU::VALU(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VALU__Syms(contextp(), this, _vcname__, _vcisRoot__)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , A{vlSymsp->vlInst.TOP.__VprimaryPorts.A}
    , B{vlSymsp->vlInst.TOP.__VprimaryPorts.B}
    , aluop{vlSymsp->vlInst.TOP.__VprimaryPorts.aluop}
    , out{vlSymsp->vlInst.TOP.__VprimaryPorts.out}
    , carry{vlSymsp->vlInst.TOP.__VprimaryPorts.carry}
    , overflow{vlSymsp->vlInst.TOP.__VprimaryPorts.overflow}
    , zero{vlSymsp->vlInst.TOP.__VprimaryPorts.zero}
    , segA{vlSymsp->vlInst.TOP.__VprimaryPorts.segA}
    , segB{vlSymsp->vlInst.TOP.__VprimaryPorts.segB}
    , segOut{vlSymsp->vlInst.TOP.__VprimaryPorts.segOut}
    , rootp{&(vlSymsp->vlInst.TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VALU::VALU(const char* _vcname__)
    : VALU(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VALU::~VALU() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VALU___024root___eval_debug_assertions(VALU___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VALU___024root___eval_static(VALU___024root* vlSelf);
VL_ATTR_COLD void VALU___024root___eval_initial(VALU___024root* vlSelf);
VL_ATTR_COLD bool VALU___024root___eval_stl(VALU___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void VALU___024root___eval_sample(VALU___024root* vlSelf);
bool VALU___024root___eval_ico(VALU___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool VALU___024root___eval_act(VALU___024root* vlSelf);
bool VALU___024root___eval_inact(VALU___024root* vlSelf);
bool VALU___024root___eval_nba(VALU___024root* vlSelf);
bool VALU___024root___eval_obs(VALU___024root* vlSelf);
bool VALU___024root___eval_react(VALU___024root* vlSelf);
void VALU___024root___eval_postponed(VALU___024root* vlSelf);
VL_ATTR_COLD void VALU___024root___eval_final(VALU___024root* vlSelf);
VL_ATTR_COLD void VALU___024root___eval_dump_triggers__stl(VALU___024root* vlSelf);
VL_ATTR_COLD void VALU___024root___eval_dump_triggers__ico(VALU___024root* vlSelf);
VL_ATTR_COLD void VALU___024root___eval_dump_triggers__act(VALU___024root* vlSelf);
VL_ATTR_COLD void VALU___024root___eval_dump_triggers__nba(VALU___024root* vlSelf);
VL_ATTR_COLD void VALU___024root___eval_dump_triggers__obs(VALU___024root* vlSelf);
VL_ATTR_COLD void VALU___024root___eval_dump_triggers__react(VALU___024root* vlSelf);

void VALU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VALU::eval_step\n"); );
    m_evalLoop.eval();
}

void VALU::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    VALU___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void VALU::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void VALU::evalStatic() {
    VALU___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void VALU::evalInitial() {
    VALU___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool VALU::evalStl(bool firstIteration) {
    return VALU___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void VALU::evalSample() {
    VALU___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool VALU::evalIco(bool firstIteration) {
    return VALU___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool VALU::evalAct() {
    return VALU___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool VALU::evalInact() {
    return VALU___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool VALU::evalNba() {
    return VALU___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool VALU::evalObs() {
    return VALU___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool VALU::evalReact() {
    return VALU___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void VALU::evalPostponed() {
    VALU___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void VALU::evalFinal() {
    VALU___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VALU::dumpTriggersStl() {
    VALU___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VALU::dumpTriggersIco() {
    VALU___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VALU::dumpTriggersAct() {
    VALU___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VALU::dumpTriggersNba() {
    VALU___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VALU::dumpTriggersObs() {
    VALU___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VALU::dumpTriggersReact() {
    VALU___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool VALU::eventsPending() { return false; }

uint64_t VALU::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VALU::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VALU::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VALU::hierName() const { return vlSymsp->name(); }
const char* VALU::modelName() const { return "VALU"; }
unsigned VALU::threads() const { return 1; }
void VALU::prepareClone() const { contextp()->prepareClone(); }
void VALU::atClone() const {
    contextp()->threadPoolpOnClone();
}
