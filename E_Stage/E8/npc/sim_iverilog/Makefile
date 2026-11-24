.DEFAULT_GOAL := all

MODE ?= npc

IVERILOG     := iverilog
IVERILOG_VPI := iverilog-vpi
VVP          := vvp

ROOT := ..

VPI_SRC := $(ROOT)/csrc/vpi/Memory_vpi.c
VPI_LIB := Memory_vpi.vpi
TOP_SRC := $(ROOT)/vsrc/iverilog_top.v

RTL_SRC := $(ROOT)/vsrc/topNPC.v \
           $(wildcard $(ROOT)/vsrc/ysyx_2700000*.v)

STD_CELL_DIR := $(ROOT)/../icsprout55-pdk/IP/STD_cell/ics55_LLSC_H7C_V1p10C100
STD_CELL_MODELS :=  $(STD_CELL_DIR)/ics55_LLSC_H7CH/verilog/ics55_LLSC_H7CH.v \
    				$(STD_CELL_DIR)/ics55_LLSC_H7CR/verilog/ics55_LLSC_H7CR.v \
    				$(STD_CELL_DIR)/ics55_LLSC_H7CL/verilog/ics55_LLSC_H7CL.v
NETLIST_SRC := $(ROOT)/vsrc/topNPC.v \
               $(ROOT)/vsrc/netlist/ysyx_27000000_Synthesis_sim.v \
               $(STD_CELL_MODELS)

TOP_MODULE := iverilog_top
VVP_FILE := $(MODE).vvp

all: $(VPI_LIB) $(VVP_FILE)

$(VPI_LIB): $(VPI_SRC)
	$(IVERILOG_VPI) $(VPI_SRC)


ifeq ($(MODE),netlist)
    VSRCS := $(NETLIST_SRC)
    SIM_FLAGS := -Dfunctional -DNETLIST_SIM
else ifeq ($(MODE),npc)
    VSRCS := $(RTL_SRC)
    SIM_FLAGS :=
else
    $(error Unsupported MODE=$(MODE), use npc or netlist)
endif

$(VVP_FILE): $(VSRCS) $(TOP_SRC) Makefile
	$(IVERILOG) -g2012 $(SIM_FLAGS) \
	-s $(TOP_MODULE) -o $@ \
	$(VSRCS) $(TOP_SRC)

run: all
	@test -n "$(BIN)" || \
		(echo "ERROR: Please specify BIN=program.bin"; exit 1)
	@test -f "$(BIN)" || \
		(echo "ERROR: BIN file not found: $(BIN)"; exit 1)
	$(VVP) -M. -mMemory_vpi $(VVP_FILE) \
		+bin=$(abspath $(BIN))

clean:
	rm -f $(VPI_LIB) Memory_vpi.o \
	npc_rtl.vvp netlist.vvp npc.vvp \
	npc.vcd wave.vcd

.PHONY: all run clean