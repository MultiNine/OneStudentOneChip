// Verilated -*- C++ -*-
// DESCRIPTION: Verilator output: Tracing implementation internals

#include "verilated_fst_c.h"
#include "Vtop__Syms.h"


VL_ATTR_COLD void Vtop___024root__trace_init_dtype____0(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_sub__TOP__0(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_sub__TOP__0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    const int c = vlSymsp->__Vm_baseCode;
    VL_TRACE_PUSH_PREFIX(tracep, "$rootio", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+35,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"PC",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "top", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"PC_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"INSTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+57,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+35,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"PC",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+17,0,"a0",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"PCin",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"PCout",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+37,0,"wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+39,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+40,0,"raddr1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+41,0,"raddr2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"rdata1",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"rdata2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+43,0,"is_addi",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"is_jalr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"is_add",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+44,0,"is_lui",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"is_lw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+5,0,"is_sw",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"is_lbu",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"is_sb",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+45,0,"is_ebreak",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"imm_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"imm_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+48,0,"imm_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"jumpAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"memAddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"exu_wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+10,0,"lsu_rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_PUSH_PREFIX(tracep, "u_EXU", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"PC",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"is_jalr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"is_add",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+44,0,"is_lui",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+5,0,"is_sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"is_sb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"rdata1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"rdata2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"imm_I",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"imm_S",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+48,0,"imm_U",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"jumpAddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"memAddr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"addResult",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+50,0,"addOP2",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_IDU", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"INSTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+57,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"instr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+37,0,"wen",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"rd",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+40,0,"rs1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+41,0,"rs2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+43,0,"is_addi",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"is_jalr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+3,0,"is_add",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+44,0,"is_lui",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"is_lw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+5,0,"is_sw",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"is_lbu",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"is_sb",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+45,0,"is_ebreak",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+46,0,"immOut_I",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+47,0,"immOut_S",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+48,0,"immOut_U",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+51,0,"opcode",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 6,0);
    VL_TRACE_DECL_BUS(tracep,c+52,0,"funct3",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 2,0);
    VL_TRACE_DECL_BUS(tracep,c+53,0,"imm_I",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+54,0,"imm_S",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 11,0);
    VL_TRACE_DECL_BUS(tracep,c+55,0,"imm_U",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 19,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_IFU", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"PC_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"INSTR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+35,0,"rst",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"PCin",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"PCout",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+36,0,"instr",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_LSU", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"is_lw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+5,0,"is_sw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"is_lbu",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+7,0,"is_sb",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"memAddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"rdata2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+10,0,"lsu_data",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+11,0,"ren",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+12,0,"wen",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+13,0,"wmask",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 7,0);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"waddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+14,0,"wdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+9,0,"raddr",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+15,0,"rdata",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_RegisterFile", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+57,0,"ADDR_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+34,0,"clk",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+39,0,"wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+38,0,"waddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BIT(tracep,c+37,0,"wen",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+40,0,"raddr1",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+41,0,"raddr2",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 3,0);
    VL_TRACE_DECL_BUS(tracep,c+42,0,"rdata1",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+1,0,"rdata2",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+17,0,"a0",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);

    Vtop___024root__trace_init_dtype____0(vlSelf, tracep, "rf", 0, c+18, VerilatedTraceSigDirection::NONE);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_PUSH_PREFIX(tracep, "u_WBU", VerilatedTracePrefixType::SCOPE_MODULE, 0, 0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"PC_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+56,0,"DATA_WIDTH",-1, VerilatedTraceSigDirection::NONE, VerilatedTraceSigKind::PARAMETER, VerilatedTraceSigType::BIT, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+16,0,"PC",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+8,0,"jumpAddr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+49,0,"exu_wdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+10,0,"lsu_rdata",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BIT(tracep,c+2,0,"is_jalr",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+4,0,"is_lw",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BIT(tracep,c+6,0,"is_lbu",-1, VerilatedTraceSigDirection::INPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC);
    VL_TRACE_DECL_BUS(tracep,c+0,0,"nextPC",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_DECL_BUS(tracep,c+39,0,"rf_wdata",-1, VerilatedTraceSigDirection::OUTPUT, VerilatedTraceSigKind::WIRE, VerilatedTraceSigType::LOGIC, 31,0);
    VL_TRACE_POP_PREFIX(tracep);
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____0(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction);

VL_ATTR_COLD void Vtop___024root__trace_init_dtype____0(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_dtype_sub____0(vlSelf, tracep, name, fidx, c, direction);
}

VL_ATTR_COLD void Vtop___024root__trace_init_dtype_sub____0(Vtop___024root* vlSelf, VerilatedFst* tracep, const char* name, uint32_t fidx, uint32_t c, VerilatedTraceSigDirection direction) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_dtype_sub____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    VL_TRACE_PUSH_PREFIX(tracep, name, VerilatedTracePrefixType::ARRAY_UNPACKED, 15, 0);
    for (int i = 0; i < 16; ++i) {
        VL_TRACE_DECL_BUS_ARRAY(tracep,c+0+i*1,fidx,"",-1, direction, VerilatedTraceSigKind::VAR, VerilatedTraceSigType::LOGIC, (15 - i), 31,0);
    }
    VL_TRACE_POP_PREFIX(tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_init_top(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_init_top\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    Vtop___024root__trace_init_sub__TOP__0(vlSelf, tracep);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp);
VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_chg_0(void* voidSelf, VerilatedFst::Buffer* bufp);
void Vtop___024root__trace_cleanup(void* voidSelf, VerilatedFst* /*unused*/);

VL_ATTR_COLD void Vtop___024root__trace_register(Vtop___024root* vlSelf, VerilatedFst* tracep) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_register\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    tracep->addConstCb(&Vtop___024root__trace_const_0, 0, vlSelf);
    tracep->addFullCb(&Vtop___024root__trace_full_0, 0, vlSelf);
    tracep->addChgCb(&Vtop___024root__trace_chg_0, 0, vlSelf);
    tracep->addCleanupCb(&Vtop___024root__trace_cleanup, vlSelf);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_const_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_const_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_const_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_const_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+56,(0x00000020U),32);
    bufp->fullIData(oldp+57,(4U),32);
}

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp);

VL_ATTR_COLD void Vtop___024root__trace_full_0(void* voidSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0\n"); );
    // Body
    Vtop___024root* const __restrict vlSelf VL_ATTR_UNUSED = static_cast<Vtop___024root*>(voidSelf);
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    Vtop___024root__trace_full_0_sub_0((&vlSymsp->vlInst.TOP), bufp);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const ::VlUnpacked<::IData/*31:0*/, 16>& __VdtypeVar);

VL_ATTR_COLD void Vtop___024root__trace_full_0_sub_0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_0_sub_0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode);
    bufp->fullIData(oldp+0,(((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_jalr)
                              ? (0xfffffffeU & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)
                              : ((::IData)(4U) + vlSelfRef.top__DOT__u_IFU__DOT__PCout))),32);
    bufp->fullIData(oldp+1,(vlSelfRef.top__DOT__u_EXU__DOT__rdata2),32);
    bufp->fullBit(oldp+2,(vlSelfRef.top__DOT__u_EXU__DOT__is_jalr));
    bufp->fullBit(oldp+3,(vlSelfRef.top__DOT__u_EXU__DOT__is_add));
    bufp->fullBit(oldp+4,(vlSelfRef.top__DOT__u_IDU__DOT__is_lw));
    bufp->fullBit(oldp+5,(vlSelfRef.top__DOT__u_EXU__DOT__is_sw));
    bufp->fullBit(oldp+6,(vlSelfRef.top__DOT__u_IDU__DOT__is_lbu));
    bufp->fullBit(oldp+7,(vlSelfRef.top__DOT__u_EXU__DOT__is_sb));
    bufp->fullIData(oldp+8,((0xfffffffeU & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)),32);
    bufp->fullIData(oldp+9,(vlSelfRef.top__DOT__u_EXU__DOT__memAddr),32);
    bufp->fullIData(oldp+10,(((::IData)(vlSelfRef.top__DOT__u_IDU__DOT__is_lw)
                               ? vlSelfRef.top__DOT__u_LSU__DOT__rdata
                               : (0x000000ffU & ((- (::IData)((::IData)(vlSelfRef.top__DOT__u_IDU__DOT__is_lbu))) 
                                                 & ((2U 
                                                     & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)
                                                     ? 
                                                    ((1U 
                                                      & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)
                                                      ? 
                                                     (vlSelfRef.top__DOT__u_LSU__DOT__rdata 
                                                      >> 0x00000018U)
                                                      : 
                                                     (vlSelfRef.top__DOT__u_LSU__DOT__rdata 
                                                      >> 0x00000010U))
                                                     : 
                                                    ((1U 
                                                      & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)
                                                      ? 
                                                     (vlSelfRef.top__DOT__u_LSU__DOT__rdata 
                                                      >> 8U)
                                                      : vlSelfRef.top__DOT__u_LSU__DOT__rdata)))))),32);
    bufp->fullBit(oldp+11,(vlSelfRef.top__DOT__u_LSU__DOT__ren));
    bufp->fullBit(oldp+12,(vlSelfRef.top__DOT__u_LSU__DOT__wen));
    bufp->fullCData(oldp+13,(((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_sw)
                               ? 0x0000000fU : ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_sb)
                                                 ? 
                                                (0x000000ffU 
                                                 & (0x08040201U 
                                                    >> 
                                                    (0x00000018U 
                                                     & (vlSelfRef.top__DOT__u_EXU__DOT__memAddr 
                                                        << 3U))))
                                                 : 0U))),8);
    bufp->fullIData(oldp+14,(((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_sw)
                               ? vlSelfRef.top__DOT__u_EXU__DOT__rdata2
                               : (vlSelfRef.top__DOT__u_EXU__DOT__rdata2 
                                  << (0x00000018U & 
                                      (vlSelfRef.top__DOT__u_EXU__DOT__memAddr 
                                       << 3U))))),32);
    bufp->fullIData(oldp+15,(vlSelfRef.top__DOT__u_LSU__DOT__rdata),32);
    bufp->fullIData(oldp+16,(vlSelfRef.top__DOT__u_IFU__DOT__PCout),32);
    bufp->fullIData(oldp+17,(vlSelfRef.top__DOT__u_RegisterFile__DOT__rf[10U]),32);
    Vtop___024root__trace_full_dtype____0(vlSelf, bufp, 18, vlSelfRef.top__DOT__u_RegisterFile__DOT__rf);
    bufp->fullBit(oldp+34,(vlSelfRef.__VprimaryPorts.clk));
    bufp->fullBit(oldp+35,(vlSelfRef.__VprimaryPorts.rst));
    bufp->fullIData(oldp+36,(vlSelfRef.__VprimaryPorts.instr),32);
    bufp->fullBit(oldp+37,(((::IData)((0x00000013U 
                                       == (0x0000707fU 
                                           & vlSelfRef.__VprimaryPorts.instr))) 
                            | ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_jalr) 
                               | ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_add) 
                                  | ((0x37U == (0x0000007fU 
                                                & vlSelfRef.__VprimaryPorts.instr)) 
                                     | (::IData)(vlSelfRef.top__DOT__u_LSU__DOT__ren)))))));
    bufp->fullCData(oldp+38,((0x0000000fU & (vlSelfRef.__VprimaryPorts.instr 
                                             >> 7U))),4);
    bufp->fullIData(oldp+39,(((::IData)(vlSelfRef.top__DOT__u_LSU__DOT__ren)
                               ? ((::IData)(vlSelfRef.top__DOT__u_IDU__DOT__is_lw)
                                   ? vlSelfRef.top__DOT__u_LSU__DOT__rdata
                                   : (0x000000ffU & 
                                      ((- (::IData)((::IData)(vlSelfRef.top__DOT__u_IDU__DOT__is_lbu))) 
                                       & ((2U & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)
                                           ? ((1U & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)
                                               ? (vlSelfRef.top__DOT__u_LSU__DOT__rdata 
                                                  >> 0x00000018U)
                                               : (vlSelfRef.top__DOT__u_LSU__DOT__rdata 
                                                  >> 0x00000010U))
                                           : ((1U & vlSelfRef.top__DOT__u_EXU__DOT__memAddr)
                                               ? (vlSelfRef.top__DOT__u_LSU__DOT__rdata 
                                                  >> 8U)
                                               : vlSelfRef.top__DOT__u_LSU__DOT__rdata)))))
                               : ((0x37U == (0x0000007fU 
                                             & vlSelfRef.__VprimaryPorts.instr))
                                   ? (0xfffff000U & vlSelfRef.__VprimaryPorts.instr)
                                   : ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_jalr)
                                       ? ((::IData)(4U) 
                                          + vlSelfRef.top__DOT__u_IFU__DOT__PCout)
                                       : vlSelfRef.top__DOT__u_EXU__DOT__memAddr)))),32);
    bufp->fullCData(oldp+40,((0x0000000fU & (vlSelfRef.__VprimaryPorts.instr 
                                             >> 0x0000000fU))),4);
    bufp->fullCData(oldp+41,((0x0000000fU & (vlSelfRef.__VprimaryPorts.instr 
                                             >> 0x00000014U))),4);
    bufp->fullIData(oldp+42,(((0U == (0x0000000fU & 
                                      (vlSelfRef.__VprimaryPorts.instr 
                                       >> 0x0000000fU)))
                               ? 0U : vlSelfRef.top__DOT__u_RegisterFile__DOT__rf
                              [(0x0000000fU & (vlSelfRef.__VprimaryPorts.instr 
                                               >> 0x0000000fU))])),32);
    bufp->fullBit(oldp+43,((::IData)((0x00000013U == 
                                      (0x0000707fU 
                                       & vlSelfRef.__VprimaryPorts.instr)))));
    bufp->fullBit(oldp+44,((0x37U == (0x0000007fU & vlSelfRef.__VprimaryPorts.instr))));
    bufp->fullBit(oldp+45,((0x00100073U == vlSelfRef.__VprimaryPorts.instr)));
    bufp->fullIData(oldp+46,((((- (::IData)((vlSelfRef.__VprimaryPorts.instr 
                                             >> 0x0000001fU))) 
                               << 0x0000000cU) | (vlSelfRef.__VprimaryPorts.instr 
                                                  >> 0x00000014U))),32);
    bufp->fullIData(oldp+47,((((- (::IData)((vlSelfRef.__VprimaryPorts.instr 
                                             >> 0x0000001fU))) 
                               << 0x0000000cU) | ((0x00000fe0U 
                                                   & (vlSelfRef.__VprimaryPorts.instr 
                                                      >> 0x00000014U)) 
                                                  | (0x0000001fU 
                                                     & (vlSelfRef.__VprimaryPorts.instr 
                                                        >> 7U))))),32);
    bufp->fullIData(oldp+48,((0xfffff000U & vlSelfRef.__VprimaryPorts.instr)),32);
    bufp->fullIData(oldp+49,(((0x37U == (0x0000007fU 
                                         & vlSelfRef.__VprimaryPorts.instr))
                               ? (0xfffff000U & vlSelfRef.__VprimaryPorts.instr)
                               : ((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_jalr)
                                   ? ((::IData)(4U) 
                                      + vlSelfRef.top__DOT__u_IFU__DOT__PCout)
                                   : vlSelfRef.top__DOT__u_EXU__DOT__memAddr))),32);
    bufp->fullIData(oldp+50,(((::IData)(vlSelfRef.top__DOT__u_EXU__DOT__is_add)
                               ? vlSelfRef.top__DOT__u_EXU__DOT__rdata2
                               : (((- (::IData)((vlSelfRef.__VprimaryPorts.instr 
                                                 >> 0x0000001fU))) 
                                   << 0x0000000cU) 
                                  | ((0x00000fe0U & 
                                      (vlSelfRef.__VprimaryPorts.instr 
                                       >> 0x00000014U)) 
                                     | (0x0000001fU 
                                        & ((::IData)(vlSelfRef.top__DOT__u_LSU__DOT__wen)
                                            ? (vlSelfRef.__VprimaryPorts.instr 
                                               >> 7U)
                                            : (vlSelfRef.__VprimaryPorts.instr 
                                               >> 0x00000014U))))))),32);
    bufp->fullCData(oldp+51,((0x0000007fU & vlSelfRef.__VprimaryPorts.instr)),7);
    bufp->fullCData(oldp+52,((7U & (vlSelfRef.__VprimaryPorts.instr 
                                    >> 0x0000000cU))),3);
    bufp->fullSData(oldp+53,((vlSelfRef.__VprimaryPorts.instr 
                              >> 0x00000014U)),12);
    bufp->fullSData(oldp+54,(((0x00000fe0U & (vlSelfRef.__VprimaryPorts.instr 
                                              >> 0x00000014U)) 
                              | (0x0000001fU & (vlSelfRef.__VprimaryPorts.instr 
                                                >> 7U)))),12);
    bufp->fullIData(oldp+55,((vlSelfRef.__VprimaryPorts.instr 
                              >> 0x0000000cU)),20);
}

VL_ATTR_COLD void Vtop___024root__trace_full_dtype____0(Vtop___024root* vlSelf, VerilatedFst::Buffer* bufp, uint32_t offset, const ::VlUnpacked<::IData/*31:0*/, 16>& __VdtypeVar) {
    VL_DEBUG_IF(VL_DBG_MSGF("+    Vtop___024root__trace_full_dtype____0\n"); );
    Vtop__Syms* const __restrict vlSymsp VL_ATTR_UNUSED = vlSelf->vlSymsp;
    auto& vlSelfRef = std::ref(*vlSelf).get();
    // Body
    uint32_t* const oldp VL_ATTR_UNUSED = bufp->oldp(vlSymsp->__Vm_baseCode + offset);
    bufp->fullIData(oldp+0,(__VdtypeVar[15]),32);
    bufp->fullIData(oldp+1,(__VdtypeVar[14]),32);
    bufp->fullIData(oldp+2,(__VdtypeVar[13]),32);
    bufp->fullIData(oldp+3,(__VdtypeVar[12]),32);
    bufp->fullIData(oldp+4,(__VdtypeVar[11]),32);
    bufp->fullIData(oldp+5,(__VdtypeVar[10]),32);
    bufp->fullIData(oldp+6,(__VdtypeVar[9]),32);
    bufp->fullIData(oldp+7,(__VdtypeVar[8]),32);
    bufp->fullIData(oldp+8,(__VdtypeVar[7]),32);
    bufp->fullIData(oldp+9,(__VdtypeVar[6]),32);
    bufp->fullIData(oldp+10,(__VdtypeVar[5]),32);
    bufp->fullIData(oldp+11,(__VdtypeVar[4]),32);
    bufp->fullIData(oldp+12,(__VdtypeVar[3]),32);
    bufp->fullIData(oldp+13,(__VdtypeVar[2]),32);
    bufp->fullIData(oldp+14,(__VdtypeVar[1]),32);
    bufp->fullIData(oldp+15,(__VdtypeVar[0]),32);
}
