// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VsCPU__pch.h"

//============================================================
// Constructors

VsCPU::VsCPU(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VsCPU{_vcontextp__, _vcname__, true} {}

VsCPU::VsCPU(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VsCPU__Syms(contextp(), this, _vcname__, _vcisRoot__)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , clk{vlSymsp->vlInst.TOP.__VprimaryPorts.clk}
    , rst{vlSymsp->vlInst.TOP.__VprimaryPorts.rst}
    , datain{vlSymsp->vlInst.TOP.__VprimaryPorts.datain}
    , out_led{vlSymsp->vlInst.TOP.__VprimaryPorts.out_led}
    , segh0{vlSymsp->vlInst.TOP.__VprimaryPorts.segh0}
    , segh1{vlSymsp->vlInst.TOP.__VprimaryPorts.segh1}
    , rootp{&(vlSymsp->vlInst.TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VsCPU::VsCPU(const char* _vcname__)
    : VsCPU(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VsCPU::~VsCPU() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VsCPU___024root___eval_debug_assertions(VsCPU___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VsCPU___024root___eval_static(VsCPU___024root* vlSelf);
VL_ATTR_COLD void VsCPU___024root___eval_initial(VsCPU___024root* vlSelf);
VL_ATTR_COLD bool VsCPU___024root___eval_stl(VsCPU___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void VsCPU___024root___eval_sample(VsCPU___024root* vlSelf);
bool VsCPU___024root___eval_ico(VsCPU___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool VsCPU___024root___eval_act(VsCPU___024root* vlSelf);
bool VsCPU___024root___eval_inact(VsCPU___024root* vlSelf);
bool VsCPU___024root___eval_nba(VsCPU___024root* vlSelf);
bool VsCPU___024root___eval_obs(VsCPU___024root* vlSelf);
bool VsCPU___024root___eval_react(VsCPU___024root* vlSelf);
void VsCPU___024root___eval_postponed(VsCPU___024root* vlSelf);
VL_ATTR_COLD void VsCPU___024root___eval_final(VsCPU___024root* vlSelf);
VL_ATTR_COLD void VsCPU___024root___eval_dump_triggers__stl(VsCPU___024root* vlSelf);
VL_ATTR_COLD void VsCPU___024root___eval_dump_triggers__ico(VsCPU___024root* vlSelf);
VL_ATTR_COLD void VsCPU___024root___eval_dump_triggers__act(VsCPU___024root* vlSelf);
VL_ATTR_COLD void VsCPU___024root___eval_dump_triggers__nba(VsCPU___024root* vlSelf);
VL_ATTR_COLD void VsCPU___024root___eval_dump_triggers__obs(VsCPU___024root* vlSelf);
VL_ATTR_COLD void VsCPU___024root___eval_dump_triggers__react(VsCPU___024root* vlSelf);

void VsCPU::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VsCPU::eval_step\n"); );
    m_evalLoop.eval();
}

void VsCPU::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    VsCPU___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void VsCPU::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void VsCPU::evalStatic() {
    VsCPU___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void VsCPU::evalInitial() {
    VsCPU___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool VsCPU::evalStl(bool firstIteration) {
    return VsCPU___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void VsCPU::evalSample() {
    VsCPU___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool VsCPU::evalIco(bool firstIteration) {
    return VsCPU___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool VsCPU::evalAct() {
    return VsCPU___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool VsCPU::evalInact() {
    return VsCPU___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool VsCPU::evalNba() {
    return VsCPU___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool VsCPU::evalObs() {
    return VsCPU___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool VsCPU::evalReact() {
    return VsCPU___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void VsCPU::evalPostponed() {
    VsCPU___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void VsCPU::evalFinal() {
    VsCPU___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VsCPU::dumpTriggersStl() {
    VsCPU___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VsCPU::dumpTriggersIco() {
    VsCPU___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VsCPU::dumpTriggersAct() {
    VsCPU___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VsCPU::dumpTriggersNba() {
    VsCPU___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VsCPU::dumpTriggersObs() {
    VsCPU___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VsCPU::dumpTriggersReact() {
    VsCPU___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool VsCPU::eventsPending() { return false; }

uint64_t VsCPU::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VsCPU::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VsCPU::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VsCPU::hierName() const { return vlSymsp->name(); }
const char* VsCPU::modelName() const { return "VsCPU"; }
unsigned VsCPU::threads() const { return 1; }
void VsCPU::prepareClone() const { contextp()->prepareClone(); }
void VsCPU::atClone() const {
    contextp()->threadPoolpOnClone();
}
