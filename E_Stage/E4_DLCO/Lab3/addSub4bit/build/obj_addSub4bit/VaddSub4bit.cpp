// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VaddSub4bit__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

VaddSub4bit::VaddSub4bit(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VaddSub4bit{_vcontextp__, _vcname__, true} {}

VaddSub4bit::VaddSub4bit(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VaddSub4bit__Syms(contextp(), this, _vcname__, _vcisRoot__)}
    , m_evalLoop{*this, /*convergeLimit:*/ 10000}
    , a{vlSymsp->vlInst.TOP.__VprimaryPorts.a}
    , b{vlSymsp->vlInst.TOP.__VprimaryPorts.b}
    , ctrl{vlSymsp->vlInst.TOP.__VprimaryPorts.ctrl}
    , carry{vlSymsp->vlInst.TOP.__VprimaryPorts.carry}
    , zero{vlSymsp->vlInst.TOP.__VprimaryPorts.zero}
    , overflow{vlSymsp->vlInst.TOP.__VprimaryPorts.overflow}
    , result{vlSymsp->vlInst.TOP.__VprimaryPorts.result}
    , rootp{&(vlSymsp->vlInst.TOP)}
{
    // Register model with the context
    contextp()->addModel(this);
    contextp()->traceBaseModelCbAdd(
        [this](VerilatedTraceBaseC* tfp, int levels, int options) { traceBaseModel(tfp, levels, options); });
}

VaddSub4bit::VaddSub4bit(const char* _vcname__)
    : VaddSub4bit(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VaddSub4bit::~VaddSub4bit() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VaddSub4bit___024root___eval_debug_assertions(VaddSub4bit___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VaddSub4bit___024root___eval_static(VaddSub4bit___024root* vlSelf);
VL_ATTR_COLD void VaddSub4bit___024root___eval_initial(VaddSub4bit___024root* vlSelf);
VL_ATTR_COLD bool VaddSub4bit___024root___eval_stl(VaddSub4bit___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void VaddSub4bit___024root___eval_sample(VaddSub4bit___024root* vlSelf);
bool VaddSub4bit___024root___eval_ico(VaddSub4bit___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool VaddSub4bit___024root___eval_act(VaddSub4bit___024root* vlSelf);
bool VaddSub4bit___024root___eval_inact(VaddSub4bit___024root* vlSelf);
bool VaddSub4bit___024root___eval_nba(VaddSub4bit___024root* vlSelf);
bool VaddSub4bit___024root___eval_obs(VaddSub4bit___024root* vlSelf);
bool VaddSub4bit___024root___eval_react(VaddSub4bit___024root* vlSelf);
void VaddSub4bit___024root___eval_postponed(VaddSub4bit___024root* vlSelf);
VL_ATTR_COLD void VaddSub4bit___024root___eval_final(VaddSub4bit___024root* vlSelf);
VL_ATTR_COLD void VaddSub4bit___024root___eval_dump_triggers__stl(VaddSub4bit___024root* vlSelf);
VL_ATTR_COLD void VaddSub4bit___024root___eval_dump_triggers__ico(VaddSub4bit___024root* vlSelf);
VL_ATTR_COLD void VaddSub4bit___024root___eval_dump_triggers__act(VaddSub4bit___024root* vlSelf);
VL_ATTR_COLD void VaddSub4bit___024root___eval_dump_triggers__nba(VaddSub4bit___024root* vlSelf);
VL_ATTR_COLD void VaddSub4bit___024root___eval_dump_triggers__obs(VaddSub4bit___024root* vlSelf);
VL_ATTR_COLD void VaddSub4bit___024root___eval_dump_triggers__react(VaddSub4bit___024root* vlSelf);

void VaddSub4bit::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VaddSub4bit::eval_step\n"); );
    m_evalLoop.eval();
}

void VaddSub4bit::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    VaddSub4bit___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
}

void VaddSub4bit::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void VaddSub4bit::evalStatic() {
    VaddSub4bit___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void VaddSub4bit::evalInitial() {
    VaddSub4bit___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool VaddSub4bit::evalStl(bool firstIteration) {
    return VaddSub4bit___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void VaddSub4bit::evalSample() {
    VaddSub4bit___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool VaddSub4bit::evalIco(bool firstIteration) {
    return VaddSub4bit___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool VaddSub4bit::evalAct() {
    return VaddSub4bit___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool VaddSub4bit::evalInact() {
    return VaddSub4bit___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool VaddSub4bit::evalNba() {
    return VaddSub4bit___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool VaddSub4bit::evalObs() {
    return VaddSub4bit___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool VaddSub4bit::evalReact() {
    return VaddSub4bit___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void VaddSub4bit::evalPostponed() {
    VaddSub4bit___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void VaddSub4bit::evalFinal() {
    VaddSub4bit___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VaddSub4bit::dumpTriggersStl() {
    VaddSub4bit___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VaddSub4bit::dumpTriggersIco() {
    VaddSub4bit___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VaddSub4bit::dumpTriggersAct() {
    VaddSub4bit___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VaddSub4bit::dumpTriggersNba() {
    VaddSub4bit___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VaddSub4bit::dumpTriggersObs() {
    VaddSub4bit___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VaddSub4bit::dumpTriggersReact() {
    VaddSub4bit___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool VaddSub4bit::eventsPending() { return false; }

uint64_t VaddSub4bit::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VaddSub4bit::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VaddSub4bit::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VaddSub4bit::hierName() const { return vlSymsp->name(); }
const char* VaddSub4bit::modelName() const { return "VaddSub4bit"; }
unsigned VaddSub4bit::threads() const { return 1; }
void VaddSub4bit::prepareClone() const { contextp()->prepareClone(); }
void VaddSub4bit::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VaddSub4bit::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void VaddSub4bit___024root__trace_decl_types(VerilatedFst* tracep);

void VaddSub4bit___024root__trace_init_top(VaddSub4bit___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    VaddSub4bit___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VaddSub4bit___024root*>(voidSelf);
    VaddSub4bit__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    VaddSub4bit___024root__trace_decl_types(tracep);
    VaddSub4bit___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VaddSub4bit___024root__trace_register(VaddSub4bit___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void VaddSub4bit::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VaddSub4bit::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->vlInst.TOP), name(), false, 9);
    VaddSub4bit___024root__trace_register(&(vlSymsp->vlInst.TOP), stfp->spTrace());
}
