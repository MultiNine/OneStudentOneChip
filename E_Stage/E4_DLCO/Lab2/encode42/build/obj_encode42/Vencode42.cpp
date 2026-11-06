// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vencode42__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vencode42::Vencode42(VerilatedContext* _vcontextp__, const char* _vcname__)
    : Vencode42{_vcontextp__, _vcname__, true} {}

Vencode42::Vencode42(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vencode42__Syms(contextp(), this, _vcname__, _vcisRoot__)}
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

Vencode42::Vencode42(const char* _vcname__)
    : Vencode42(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vencode42::~Vencode42() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vencode42___024root___eval_debug_assertions(Vencode42___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vencode42___024root___eval_static(Vencode42___024root* vlSelf);
VL_ATTR_COLD void Vencode42___024root___eval_initial(Vencode42___024root* vlSelf);
VL_ATTR_COLD bool Vencode42___024root___eval_stl(Vencode42___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void Vencode42___024root___eval_sample(Vencode42___024root* vlSelf);
bool Vencode42___024root___eval_ico(Vencode42___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool Vencode42___024root___eval_act(Vencode42___024root* vlSelf);
bool Vencode42___024root___eval_inact(Vencode42___024root* vlSelf);
bool Vencode42___024root___eval_nba(Vencode42___024root* vlSelf);
bool Vencode42___024root___eval_obs(Vencode42___024root* vlSelf);
bool Vencode42___024root___eval_react(Vencode42___024root* vlSelf);
void Vencode42___024root___eval_postponed(Vencode42___024root* vlSelf);
VL_ATTR_COLD void Vencode42___024root___eval_final(Vencode42___024root* vlSelf);
VL_ATTR_COLD void Vencode42___024root___eval_dump_triggers__stl(Vencode42___024root* vlSelf);
VL_ATTR_COLD void Vencode42___024root___eval_dump_triggers__ico(Vencode42___024root* vlSelf);
VL_ATTR_COLD void Vencode42___024root___eval_dump_triggers__act(Vencode42___024root* vlSelf);
VL_ATTR_COLD void Vencode42___024root___eval_dump_triggers__nba(Vencode42___024root* vlSelf);
VL_ATTR_COLD void Vencode42___024root___eval_dump_triggers__obs(Vencode42___024root* vlSelf);
VL_ATTR_COLD void Vencode42___024root___eval_dump_triggers__react(Vencode42___024root* vlSelf);

void Vencode42::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vencode42::eval_step\n"); );
    m_evalLoop.eval();
}

void Vencode42::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vencode42___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vencode42::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vencode42::evalStatic() {
    Vencode42___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void Vencode42::evalInitial() {
    Vencode42___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool Vencode42::evalStl(bool firstIteration) {
    return Vencode42___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void Vencode42::evalSample() {
    Vencode42___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool Vencode42::evalIco(bool firstIteration) {
    return Vencode42___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool Vencode42::evalAct() {
    return Vencode42___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool Vencode42::evalInact() {
    return Vencode42___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool Vencode42::evalNba() {
    return Vencode42___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool Vencode42::evalObs() {
    return Vencode42___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool Vencode42::evalReact() {
    return Vencode42___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void Vencode42::evalPostponed() {
    Vencode42___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void Vencode42::evalFinal() {
    Vencode42___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vencode42::dumpTriggersStl() {
    Vencode42___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vencode42::dumpTriggersIco() {
    Vencode42___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vencode42::dumpTriggersAct() {
    Vencode42___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vencode42::dumpTriggersNba() {
    Vencode42___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vencode42::dumpTriggersObs() {
    Vencode42___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vencode42::dumpTriggersReact() {
    Vencode42___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool Vencode42::eventsPending() { return false; }

uint64_t Vencode42::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vencode42::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vencode42::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vencode42::hierName() const { return vlSymsp->name(); }
const char* Vencode42::modelName() const { return "Vencode42"; }
unsigned Vencode42::threads() const { return 1; }
void Vencode42::prepareClone() const { contextp()->prepareClone(); }
void Vencode42::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vencode42::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vencode42___024root__trace_decl_types(VerilatedFst* tracep);

void Vencode42___024root__trace_init_top(Vencode42___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vencode42___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vencode42___024root*>(voidSelf);
    Vencode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vencode42___024root__trace_decl_types(tracep);
    Vencode42___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vencode42___024root__trace_register(Vencode42___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vencode42::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vencode42::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->vlInst.TOP), name(), false, 3);
    Vencode42___024root__trace_register(&(vlSymsp->vlInst.TOP), stfp->spTrace());
}
