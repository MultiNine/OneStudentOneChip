// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Model implementation (design independent parts)

#include "VpriEncode42__pch.h"
#include "verilated_fst_c.h"

//============================================================
// Constructors

VpriEncode42::VpriEncode42(VerilatedContext* _vcontextp__, const char* _vcname__)
    : VpriEncode42{_vcontextp__, _vcname__, true} {}

VpriEncode42::VpriEncode42(VerilatedContext* _vcontextp__, const char* _vcname__, bool _vcisRoot__)
    : VerilatedModel{*_vcontextp__}
    , vlSymsp{new VpriEncode42__Syms(contextp(), this, _vcname__, _vcisRoot__)}
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

VpriEncode42::VpriEncode42(const char* _vcname__)
    : VpriEncode42(Verilated::threadContextp(), _vcname__)
{
}

//============================================================
// Destructor

VpriEncode42::~VpriEncode42() {
    delete vlSymsp;
}

//============================================================
// Evaluation function

#ifdef VL_DEBUG
void VpriEncode42___024root___eval_debug_assertions(VpriEncode42___024root* vlSelf);
#endif  // VL_DEBUG
VL_ATTR_COLD void VpriEncode42___024root___eval_static(VpriEncode42___024root* vlSelf);
VL_ATTR_COLD void VpriEncode42___024root___eval_initial(VpriEncode42___024root* vlSelf);
VL_ATTR_COLD bool VpriEncode42___024root___eval_stl(VpriEncode42___024root* vlSelf, ::CData/*0:0*/ firstIteration);
void VpriEncode42___024root___eval_sample(VpriEncode42___024root* vlSelf);
bool VpriEncode42___024root___eval_ico(VpriEncode42___024root* vlSelf, ::CData/*0:0*/ firstIteration);
bool VpriEncode42___024root___eval_act(VpriEncode42___024root* vlSelf);
bool VpriEncode42___024root___eval_inact(VpriEncode42___024root* vlSelf);
bool VpriEncode42___024root___eval_nba(VpriEncode42___024root* vlSelf);
bool VpriEncode42___024root___eval_obs(VpriEncode42___024root* vlSelf);
bool VpriEncode42___024root___eval_react(VpriEncode42___024root* vlSelf);
void VpriEncode42___024root___eval_postponed(VpriEncode42___024root* vlSelf);
VL_ATTR_COLD void VpriEncode42___024root___eval_final(VpriEncode42___024root* vlSelf);
VL_ATTR_COLD void VpriEncode42___024root___eval_dump_triggers__stl(VpriEncode42___024root* vlSelf);
VL_ATTR_COLD void VpriEncode42___024root___eval_dump_triggers__ico(VpriEncode42___024root* vlSelf);
VL_ATTR_COLD void VpriEncode42___024root___eval_dump_triggers__act(VpriEncode42___024root* vlSelf);
VL_ATTR_COLD void VpriEncode42___024root___eval_dump_triggers__nba(VpriEncode42___024root* vlSelf);
VL_ATTR_COLD void VpriEncode42___024root___eval_dump_triggers__obs(VpriEncode42___024root* vlSelf);
VL_ATTR_COLD void VpriEncode42___024root___eval_dump_triggers__react(VpriEncode42___024root* vlSelf);

void VpriEncode42::eval_step() {
    VL_DEBUG_IF(VL_DBG_MSGF("+++++TOP Evaluate VpriEncode42::eval_step\n"); );
    m_evalLoop.eval();
}

void VpriEncode42::evalBegin() {
#ifdef VL_DEBUG
    // Debug assertions
    VpriEncode42___024root___eval_debug_assertions(&(vlSymsp->vlInst.TOP));
#endif  // VL_DEBUG
    vlSymsp->__Vm_activity = true;
    vlSymsp->__Vm_deleter.deleteAll();
}

void VpriEncode42::evalEnd() {
    // Evaluate cleanup
    Verilated::endOfEval(vlSymsp->__Vm_evalMsgQp);
}

void VpriEncode42::evalStatic() {
    VpriEncode42___024root___eval_static(&(vlSymsp->vlInst.TOP));
}

void VpriEncode42::evalInitial() {
    VpriEncode42___024root___eval_initial(&(vlSymsp->vlInst.TOP));
}

bool VpriEncode42::evalStl(bool firstIteration) {
    return VpriEncode42___024root___eval_stl(&(vlSymsp->vlInst.TOP), firstIteration);
}

void VpriEncode42::evalSample() {
    VpriEncode42___024root___eval_sample(&(vlSymsp->vlInst.TOP));
}

bool VpriEncode42::evalIco(bool firstIteration) {
    return VpriEncode42___024root___eval_ico(&(vlSymsp->vlInst.TOP), firstIteration);
}

bool VpriEncode42::evalAct() {
    return VpriEncode42___024root___eval_act(&(vlSymsp->vlInst.TOP));
}

bool VpriEncode42::evalInact() {
    return VpriEncode42___024root___eval_inact(&(vlSymsp->vlInst.TOP));
}

bool VpriEncode42::evalNba() {
    return VpriEncode42___024root___eval_nba(&(vlSymsp->vlInst.TOP));
}

bool VpriEncode42::evalObs() {
    return VpriEncode42___024root___eval_obs(&(vlSymsp->vlInst.TOP));
}

bool VpriEncode42::evalReact() {
    return VpriEncode42___024root___eval_react(&(vlSymsp->vlInst.TOP));
}

void VpriEncode42::evalPostponed() {
    VpriEncode42___024root___eval_postponed(&(vlSymsp->vlInst.TOP));
}

void VpriEncode42::evalFinal() {
    VpriEncode42___024root___eval_final(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VpriEncode42::dumpTriggersStl() {
    VpriEncode42___024root___eval_dump_triggers__stl(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VpriEncode42::dumpTriggersIco() {
    VpriEncode42___024root___eval_dump_triggers__ico(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VpriEncode42::dumpTriggersAct() {
    VpriEncode42___024root___eval_dump_triggers__act(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VpriEncode42::dumpTriggersNba() {
    VpriEncode42___024root___eval_dump_triggers__nba(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VpriEncode42::dumpTriggersObs() {
    VpriEncode42___024root___eval_dump_triggers__obs(&(vlSymsp->vlInst.TOP));
}

VL_ATTR_COLD void VpriEncode42::dumpTriggersReact() {
    VpriEncode42___024root___eval_dump_triggers__react(&(vlSymsp->vlInst.TOP));
}

//============================================================
// Events and timing
bool VpriEncode42::eventsPending() { return false; }

uint64_t VpriEncode42::nextTimeSlot() {
    VL_FATAL_MT(__FILE__, __LINE__, "", "No delays in the design");
    return 0;
}

//============================================================
// Utilities

const char* VpriEncode42::name() const {
    return vlSymsp->name();
}

//============================================================
// Invoke final blocks

VL_ATTR_COLD void VpriEncode42::final() {
    contextp()->executingFinal(true);
    evalFinal();
    contextp()->executingFinal(false);
}

//============================================================
// Implementations of abstract methods from VerilatedModel

const char* VpriEncode42::hierName() const { return vlSymsp->name(); }
const char* VpriEncode42::modelName() const { return "VpriEncode42"; }
unsigned VpriEncode42::threads() const { return 1; }
void VpriEncode42::prepareClone() const { contextp()->prepareClone(); }
void VpriEncode42::atClone() const {
    contextp()->threadPoolpOnClone();
}
std::unique_ptr<VerilatedTraceConfig> VpriEncode42::traceConfig() const {
    return std::unique_ptr<VerilatedTraceConfig>{new VerilatedTraceConfig{false}};
};

//============================================================
// Trace configuration

void VpriEncode42___024root__trace_decl_types(VerilatedFst* tracep);

void VpriEncode42___024root__trace_init_top(VpriEncode42___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD static void trace_init(void* voidSelf, VerilatedFst* tracep, uint32_t code) {
    // Callback from tracep->open()
    VpriEncode42___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<VpriEncode42___024root*>(voidSelf);
    VpriEncode42__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    if (!vlSymsp->_vm_contextp__->calcUnusedSigs()) {
        VL_FATAL_MT(__FILE__, __LINE__, __FILE__,
            "Turning on wave traces requires Verilated::traceEverOn(true) call before time 0.");
    }
    vlSymsp->__Vm_baseCode = code;
    tracep->pushPrefix(vlSymsp->name(), VerilatedTracePrefixType::SCOPE_MODULE);
    VpriEncode42___024root__trace_decl_types(tracep);
    VpriEncode42___024root__trace_init_top(vlSelf, tracep);
    tracep->popPrefix();
}

VL_ATTR_COLD void VpriEncode42___024root__trace_register(VpriEncode42___024root* vlSelf, VerilatedFst* tracep);

VL_ATTR_COLD void VpriEncode42::traceBaseModel(VerilatedTraceBaseC* tfp, int levels, int options) {
    (void)levels; (void)options;
    VerilatedFstC* const stfp = dynamic_cast<VerilatedFstC*>(tfp);
    if (VL_UNLIKELY(!stfp)) {
        vl_fatal(__FILE__, __LINE__, __FILE__,"'VpriEncode42::trace()' called on non-VerilatedFstC object;"
            " use --trace-fst with VerilatedFst object, and --trace-vcd with VerilatedVcd object");
    }
    stfp->spTrace()->addModel(this);
    stfp->spTrace()->addInitCb(&trace_init, &(vlSymsp->vlInst.TOP), name(), false, 4);
    VpriEncode42___024root__trace_register(&(vlSymsp->vlInst.TOP), stfp->spTrace());
}
