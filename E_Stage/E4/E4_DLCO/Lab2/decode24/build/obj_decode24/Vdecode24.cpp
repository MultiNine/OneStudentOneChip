// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vdecode24__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vdecode24::Vdecode24(VerilatedContext* _vcontextp__, const char* _vcname__)
    : Vdecode24{_vcontextp__, _vcname__, true} {}

Vdecode24::Vdecode24(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vdecode24__Syms(contextp(), this, _vcname__, _vcisRoot__)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , x{vlSymsp->vlInst.TOP.__VprimaryPorts.x}
    , en{vlSymsp->vlInst.TOP.__VprimaryPorts.en}
    , y{vlSymsp->vlInst.TOP.__VprimaryPorts.y}
    , rootp{&(vlSymsp->vlInst.TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vdecode24::Vdecode24(const char* _vcname__)
    : Vdecode24(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vdecode24::~Vdecode24() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vdecode24___024root___eval_debug_assertions(Vdecode24___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vdecode24___024root___eval_static(Vdecode24___024root* vlSelf);
VL_ATTR_COLD void Vdecode24___024root___eval_initial(Vdecode24___024root* vlSelf);
VL_ATTR_COLD bool Vdecode24___024root___eval_stl(Vdecode24___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void Vdecode24___024root___eval_sample(Vdecode24___024root* vlSelf);
bool Vdecode24___024root___eval_ico(Vdecode24___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool Vdecode24___024root___eval_act(Vdecode24___024root* vlSelf);
bool Vdecode24___024root___eval_inact(Vdecode24___024root* vlSelf);
bool Vdecode24___024root___eval_nba(Vdecode24___024root* vlSelf);
bool Vdecode24___024root___eval_obs(Vdecode24___024root* vlSelf);
bool Vdecode24___024root___eval_react(Vdecode24___024root* vlSelf);
void Vdecode24___024root___eval_postponed(Vdecode24___024root* vlSelf);
VL_ATTR_COLD void Vdecode24___024root___eval_final(Vdecode24___024root* vlSelf);
VL_ATTR_COLD void Vdecode24___024root___eval_dump_triggers__stl(Vdecode24___024root* vlSelf);
VL_ATTR_COLD void Vdecode24___024root___eval_dump_triggers__ico(Vdecode24___024root* vlSelf);
VL_ATTR_COLD void Vdecode24___024root___eval_dump_triggers__act(Vdecode24___024root* vlSelf);
VL_ATTR_COLD void Vdecode24___024root___eval_dump_triggers__nba(Vdecode24___024root* vlSelf);
VL_ATTR_COLD void Vdecode24___024root___eval_dump_triggers__obs(Vdecode24___024root* vlSelf);
VL_ATTR_COLD void Vdecode24___024root___eval_dump_triggers__react(Vdecode24___024root* vlSelf);

void Vdecode24::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vdecode24::eval_step\n"); );
    m_evalLoop.eval();
}

void Vdecode24::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vdecode24___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vdecode24::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vdecode24::evalStatic() {
    Vdecode24___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void Vdecode24::evalInitial() {
    Vdecode24___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool Vdecode24::evalStl(bool firstIteration) {
    return Vdecode24___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void Vdecode24::evalSample() {
    Vdecode24___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool Vdecode24::evalIco(bool firstIteration) {
    return Vdecode24___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool Vdecode24::evalAct() {
    return Vdecode24___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool Vdecode24::evalInact() {
    return Vdecode24___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool Vdecode24::evalNba() {
    return Vdecode24___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool Vdecode24::evalObs() {
    return Vdecode24___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool Vdecode24::evalReact() {
    return Vdecode24___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void Vdecode24::evalPostponed() {
    Vdecode24___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void Vdecode24::evalFinal() {
    Vdecode24___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vdecode24::dumpTriggersStl() {
    Vdecode24___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vdecode24::dumpTriggersIco() {
    Vdecode24___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vdecode24::dumpTriggersAct() {
    Vdecode24___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vdecode24::dumpTriggersNba() {
    Vdecode24___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vdecode24::dumpTriggersObs() {
    Vdecode24___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vdecode24::dumpTriggersReact() {
    Vdecode24___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool Vdecode24::eventsPending() { return false; }

uint64_t Vdecode24::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vdecode24::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vdecode24::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vdecode24::hierName() const { return vlSymsp->name(); }
const char* Vdecode24::modelName() const { return "Vdecode24"; }
unsigned Vdecode24::threads() const { return 1; }
void Vdecode24::prepareClone() const { contextp()->prepareClone(); }
void Vdecode24::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vdecode24::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vdecode24___024root__trace_decl_types(VerilatedFst* tracep);

void Vdecode24___024root__trace_init_top(Vdecode24___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vdecode24___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vdecode24___024root*>(voidSelf);
    Vdecode24__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vdecode24___024root__trace_decl_types(tracep);
    Vdecode24___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vdecode24___024root__trace_register(Vdecode24___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vdecode24::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vdecode24::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->vlInst.TOP), name(), false, 3);
    Vdecode24___024root__trace_register(&(vlSymsp->vlInst.TOP), stfp->spTrace());
}
