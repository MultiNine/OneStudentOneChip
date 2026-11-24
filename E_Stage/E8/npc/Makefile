.DEFAULT_GOAL := default

MODE ?= soc

ifeq ($(MODE),soc)
TOPNAME := SimTop
else ifeq ($(MODE),npc)
TOPNAME := topNPC
else ifeq ($(MODE),netlist)
TOPNAME := topNPC
else
$(error Unsupported MODE=$(MODE), use soc or npc or netlist)
endif

INC_PATH ?=

VERILATOR := verilator

VERILATOR_CFLAGS += --build -cc --exe \
                    -j 0 --trace-fst

BUILD_DIR := ./build/$(MODE)
OBJ_DIR := $(BUILD_DIR)/obj_dir
BIN := $(BUILD_DIR)/$(TOPNAME)
IVERILOG_DIR := $(CURDIR)/sim_iverilog

VSRCS_NPC := vsrc/topNPC.v $(wildcard vsrc/ysyx_27000000*.v)
CSRCS_NPC := $(wildcard csrc/difftest.cpp \
               csrc/sim_npc.cpp csrc/Memory.cpp \
               csrc/minirvEMU.cpp)

NETLIST := vsrc/netlist/ysyx_27000000_Synthesis_sim.v

STD_CELL_DIR := ../icsprout55-pdk/IP/STD_cell/ics55_LLSC_H7C_V1p10C100
STD_CELL_MODELS := 	$(STD_CELL_DIR)/ics55_LLSC_H7CH/verilog/ics55_LLSC_H7CH.v \
					$(STD_CELL_DIR)/ics55_LLSC_H7CR/verilog/ics55_LLSC_H7CR.v \
					$(STD_CELL_DIR)/ics55_LLSC_H7CL/verilog/ics55_LLSC_H7CL.v

VSRCS_NETLIST := vsrc/topNPC.v $(NETLIST) $(STD_CELL_MODELS)
CSRCS_NETLIST := $(CSRCS_NPC)

NETLIST_FLAGS := --timescale "1ns/1ns" --no-timing \
    			 -D__VERILATOR__ -Dfunctional -DNETLIST_SIM \
				 -Wno-BLKANDNBLK -Wno-fatal

VSRCS_SOC := $(wildcard vsrc/*.v vsrc/*.sv) \
             $(shell find ../ysyxSoC/perip -type f \
               \( -name "*.v" -o -name "*.sv" \)) \
             ../ysyxSoC/ready-to-run/minirv/ElaborateTop.v
CSRCS_SOC := $(wildcard csrc/sim_soc.cpp)

ifeq ($(MODE),soc)
SOC_FLAGS := -I../ysyxSoC/perip/uart16550/rtl \
             -I../ysyxSoC/perip/spi/rtl \
             --timescale "1ns/1ns" \
             --no-timing \
             -D__VERILOG__ \
             -DPDK_BEHAV \
             -D__UART_TO_CONSOLE__
VERILATOR_CFLAGS += $(SOC_FLAGS)
MODE_FLAGS := $(SOC_FLAGS)
VERILATOR_CFLAGS += $(SOC_FLAGS)

NXDC_FILES := $(CURDIR)/constr/SimTop.nxdc
SRC_AUTO_BIND := $(abspath $(BUILD_DIR)/auto_bind.cpp)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	@mkdir -p $(dir $@)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $< $@

include $(NVBOARD_HOME)/scripts/nvboard.mk
INCFLAGS := $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS)
NVBOARD_DEP := $(NVBOARD_ARCHIVE)
EXTRA_FLAGS = \
    $(addprefix -CFLAGS , $(CXXFLAGS)) \
    $(addprefix -LDFLAGS , $(NVBOARD_ARCHIVE) $(LDFLAGS))

VSRCS := $(VSRCS_SOC)
CSRCS := $(CSRCS_SOC) $(SRC_AUTO_BIND)

else ifeq ($(MODE),netlist)

NVBOARD_DEP :=
EXTRA_FLAGS := -CFLAGS -DNETLIST_SIM
VSRCS := $(VSRCS_NETLIST)
CSRCS := $(CSRCS_NETLIST)

MODE_FLAGS := $(NETLIST_FLAGS)
VERILATOR_CFLAGS += $(NETLIST_FLAGS)

else
NVBOARD_DEP :=
EXTRA_FLAGS :=
VSRCS := $(VSRCS_NPC)
CSRCS := $(CSRCS_NPC)

endif

default: $(BIN)

build: $(BIN)

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_DEP) Makefile
	@mkdir -p $(BUILD_DIR)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
	    --top-module $(TOPNAME) \
	    $(VSRCS) $(CSRCS) \
	    $(EXTRA_FLAGS) \
	    --Mdir $(OBJ_DIR) \
	    -o $(abspath $(BIN))

all: build

lint:
	$(VERILATOR) --lint-only -Wall $(MODE_FLAGS) \
	    --top-module $(TOPNAME) $(VSRCS)

sim: $(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@$(BIN) $(IMAGE)

iverilog:
	$(MAKE) -C $(IVERILOG_DIR) MODE=$(MODE) all

clean:
	@rm -rf ./build
	$(MAKE) -C $(IVERILOG_DIR) MODE=npc clean

.PHONY: default build all lint sim iverilog clean

include ../Makefile
