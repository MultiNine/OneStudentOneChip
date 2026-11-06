// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "Vlfsr__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

Vlfsr::Vlfsr(VerilatedContext* _vcontextp__, const char* _vcname__)
    : Vlfsr{_vcontextp__, _vcname__, true} {}

Vlfsr::Vlfsr(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new Vlfsr__Syms(contextp(), this, _vcname__, _vcisRoot__)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , clk{vlSymsp->vlInst.TOP.__VprimaryPorts.clk}
    , rst{vlSymsp->vlInst.TOP.__VprimaryPorts.rst}
    , dout{vlSymsp->vlInst.TOP.__VprimaryPorts.dout}
    , segout1{vlSymsp->vlInst.TOP.__VprimaryPorts.segout1}
    , segout0{vlSymsp->vlInst.TOP.__VprimaryPorts.segout0}
    , rootp{&(vlSymsp->vlInst.TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

Vlfsr::Vlfsr(const char* _vcname__)
    : Vlfsr(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

Vlfsr::~Vlfsr() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void Vlfsr___024root___eval_debug_assertions(Vlfsr___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void Vlfsr___024root___eval_static(Vlfsr___024root* vlSelf);
VL_ATTR_COLD void Vlfsr___024root___eval_initial(Vlfsr___024root* vlSelf);
VL_ATTR_COLD bool Vlfsr___024root___eval_stl(Vlfsr___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void Vlfsr___024root___eval_sample(Vlfsr___024root* vlSelf);
bool Vlfsr___024root___eval_ico(Vlfsr___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool Vlfsr___024root___eval_act(Vlfsr___024root* vlSelf);
bool Vlfsr___024root___eval_inact(Vlfsr___024root* vlSelf);
bool Vlfsr___024root___eval_nba(Vlfsr___024root* vlSelf);
bool Vlfsr___024root___eval_obs(Vlfsr___024root* vlSelf);
bool Vlfsr___024root___eval_react(Vlfsr___024root* vlSelf);
void Vlfsr___024root___eval_postponed(Vlfsr___024root* vlSelf);
VL_ATTR_COLD void Vlfsr___024root___eval_final(Vlfsr___024root* vlSelf);
VL_ATTR_COLD void Vlfsr___024root___eval_dump_triggers__stl(Vlfsr___024root* vlSelf);
VL_ATTR_COLD void Vlfsr___024root___eval_dump_triggers__ico(Vlfsr___024root* vlSelf);
VL_ATTR_COLD void Vlfsr___024root___eval_dump_triggers__act(Vlfsr___024root* vlSelf);
VL_ATTR_COLD void Vlfsr___024root___eval_dump_triggers__nba(Vlfsr___024root* vlSelf);
VL_ATTR_COLD void Vlfsr___024root___eval_dump_triggers__obs(Vlfsr___024root* vlSelf);
VL_ATTR_COLD void Vlfsr___024root___eval_dump_triggers__react(Vlfsr___024root* vlSelf);

void Vlfsr::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate Vlfsr::eval_step\n"); );
    m_evalLoop.eval();
}

void Vlfsr::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    Vlfsr___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
}

void Vlfsr::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void Vlfsr::evalStatic() {
    Vlfsr___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void Vlfsr::evalInitial() {
    Vlfsr___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool Vlfsr::evalStl(bool firstIteration) {
    return Vlfsr___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void Vlfsr::evalSample() {
    Vlfsr___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool Vlfsr::evalIco(bool firstIteration) {
    return Vlfsr___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool Vlfsr::evalAct() {
    return Vlfsr___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool Vlfsr::evalInact() {
    return Vlfsr___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool Vlfsr::evalNba() {
    return Vlfsr___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool Vlfsr::evalObs() {
    return Vlfsr___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool Vlfsr::evalReact() {
    return Vlfsr___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void Vlfsr::evalPostponed() {
    Vlfsr___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void Vlfsr::evalFinal() {
    Vlfsr___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vlfsr::dumpTriggersStl() {
    Vlfsr___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vlfsr::dumpTriggersIco() {
    Vlfsr___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vlfsr::dumpTriggersAct() {
    Vlfsr___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vlfsr::dumpTriggersNba() {
    Vlfsr___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vlfsr::dumpTriggersObs() {
    Vlfsr___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void Vlfsr::dumpTriggersReact() {
    Vlfsr___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool Vlfsr::eventsPending() { return false; }

uint64_t Vlfsr::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* Vlfsr::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void Vlfsr::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* Vlfsr::hierName() const { return vlSymsp->name(); }
const char* Vlfsr::modelName() const { return "Vlfsr"; }
unsigned Vlfsr::threads() const { return 1; }
void Vlfsr::prepareClone() const { contextp()->prepareClone(); }
void Vlfsr::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> Vlfsr::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void Vlfsr___024root__trace_decl_types(VerilatedFst* tracep);

void Vlfsr___024root__trace_init_top(Vlfsr___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    Vlfsr___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vlfsr___024root*>(voidSelf);
    Vlfsr__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    Vlfsr___024root__trace_decl_types(tracep);
    Vlfsr___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void Vlfsr___024root__trace_register(Vlfsr___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void Vlfsr::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'Vlfsr::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->vlInst.TOP), name(), false, 8);
    Vlfsr___024root__trace_register(&(vlSymsp->vlInst.TOP), stfp->spTrace());
}
