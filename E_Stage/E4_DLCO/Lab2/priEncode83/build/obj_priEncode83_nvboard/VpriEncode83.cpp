// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VpriEncode83__pch.h"

//============================================================
// Constructors

VpriEncode83::VpriEncode83(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VpriEncode83{_vcontextp__, _vcname__, true} {}

VpriEncode83::VpriEncode83(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VpriEncode83__Syms(contextp(), this, _vcname__, _vcisRoot__)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , en{vlSymsp->vlInst.TOP.__VprimaryPorts.en}
    , x{vlSymsp->vlInst.TOP.__VprimaryPorts.x}
    , validIn{vlSymsp->vlInst.TOP.__VprimaryPorts.validIn}
    , y{vlSymsp->vlInst.TOP.__VprimaryPorts.y}
    , segOut{vlSymsp->vlInst.TOP.__VprimaryPorts.segOut}
    , rootp{&(vlSymsp->vlInst.TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
}

VpriEncode83::VpriEncode83(const char* _vcname__)
    : VpriEncode83(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VpriEncode83::~VpriEncode83() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VpriEncode83___024root___eval_debug_assertions(VpriEncode83___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VpriEncode83___024root___eval_static(VpriEncode83___024root* vlSelf);
VL_ATTR_COLD void VpriEncode83___024root___eval_initial(VpriEncode83___024root* vlSelf);
VL_ATTR_COLD bool VpriEncode83___024root___eval_stl(VpriEncode83___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void VpriEncode83___024root___eval_sample(VpriEncode83___024root* vlSelf);
bool VpriEncode83___024root___eval_ico(VpriEncode83___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool VpriEncode83___024root___eval_act(VpriEncode83___024root* vlSelf);
bool VpriEncode83___024root___eval_inact(VpriEncode83___024root* vlSelf);
bool VpriEncode83___024root___eval_nba(VpriEncode83___024root* vlSelf);
bool VpriEncode83___024root___eval_obs(VpriEncode83___024root* vlSelf);
bool VpriEncode83___024root___eval_react(VpriEncode83___024root* vlSelf);
void VpriEncode83___024root___eval_postponed(VpriEncode83___024root* vlSelf);
VL_ATTR_COLD void VpriEncode83___024root___eval_final(VpriEncode83___024root* vlSelf);
VL_ATTR_COLD void VpriEncode83___024root___eval_dump_triggers__stl(VpriEncode83___024root* vlSelf);
VL_ATTR_COLD void VpriEncode83___024root___eval_dump_triggers__ico(VpriEncode83___024root* vlSelf);
VL_ATTR_COLD void VpriEncode83___024root___eval_dump_triggers__act(VpriEncode83___024root* vlSelf);
VL_ATTR_COLD void VpriEncode83___024root___eval_dump_triggers__nba(VpriEncode83___024root* vlSelf);
VL_ATTR_COLD void VpriEncode83___024root___eval_dump_triggers__obs(VpriEncode83___024root* vlSelf);
VL_ATTR_COLD void VpriEncode83___024root___eval_dump_triggers__react(VpriEncode83___024root* vlSelf);

void VpriEncode83::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VpriEncode83::eval_step\n"); );
    m_evalLoop.eval();
}

void VpriEncode83::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    VpriEncode83___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_deleter.deleteAll();
}

void VpriEncode83::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void VpriEncode83::evalStatic() {
    VpriEncode83___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void VpriEncode83::evalInitial() {
    VpriEncode83___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool VpriEncode83::evalStl(bool firstIteration) {
    return VpriEncode83___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void VpriEncode83::evalSample() {
    VpriEncode83___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool VpriEncode83::evalIco(bool firstIteration) {
    return VpriEncode83___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool VpriEncode83::evalAct() {
    return VpriEncode83___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool VpriEncode83::evalInact() {
    return VpriEncode83___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool VpriEncode83::evalNba() {
    return VpriEncode83___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool VpriEncode83::evalObs() {
    return VpriEncode83___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool VpriEncode83::evalReact() {
    return VpriEncode83___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void VpriEncode83::evalPostponed() {
    VpriEncode83___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void VpriEncode83::evalFinal() {
    VpriEncode83___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VpriEncode83::dumpTriggersStl() {
    VpriEncode83___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VpriEncode83::dumpTriggersIco() {
    VpriEncode83___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VpriEncode83::dumpTriggersAct() {
    VpriEncode83___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VpriEncode83::dumpTriggersNba() {
    VpriEncode83___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VpriEncode83::dumpTriggersObs() {
    VpriEncode83___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VpriEncode83::dumpTriggersReact() {
    VpriEncode83___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool VpriEncode83::eventsPending() { return false; }

uint64_t VpriEncode83::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VpriEncode83::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VpriEncode83::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VpriEncode83::hierName() const { return vlSymsp->name(); }
const char* VpriEncode83::modelName() const { return "VpriEncode83"; }
unsigned VpriEncode83::threads() const { return 1; }
void VpriEncode83::prepareClone() const { contextp()->prepareClone(); }
void VpriEncode83::atClone() const {
    contextp()->threadPoolpOnClone();
}
