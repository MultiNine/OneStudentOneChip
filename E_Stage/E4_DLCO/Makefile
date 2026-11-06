.DEFAULT_GOAL := sim

# Project configuration
TOP ?= $(notdir $(CURDIR))
INC_PATH ?=

VSRCS ?= $(wildcard *.v *.sv)
CSRCS_SIM ?= sim_$(TOP).cpp
CSRCS_NVB ?= nvboard_$(TOP).cpp

BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj_$(TOP)
OBJ_DIR_NVB := $(BUILD_DIR)/obj_$(TOP)_nvboard

BIN := $(BUILD_DIR)/V$(TOP)
BIN_NVB := $(BUILD_DIR)/V$(TOP)_nvboard

# Verilog Testbench configuration
TB_TOP := tb_$(TOP)
TB_SRC := $(TB_TOP).v
OBJ_DIR_TB := $(BUILD_DIR)/obj_$(TB_TOP)
BIN_TB := $(OBJ_DIR_TB)/V$(TB_TOP)
RTL_SRCS := $(filter-out tb_%.v tb_%.sv,$(VSRCS))

VERILATOR := verilator
TRACE ?= fst

VERILATOR_CFLAGS += -MMD --build -cc -O3 \
                    --x-assign fast --x-initial fast --noassert

# NXDC constraint
NXDC_FILES := $(CURDIR)/constr/$(TOP).nxdc
SRC_AUTO_BIND := $(abspath $(BUILD_DIR)/auto_bind.cpp)

$(SRC_AUTO_BIND): $(NXDC_FILES)
	@mkdir -p $(dir $@)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $< $@

# NVBoard configuration
include $(NVBOARD_HOME)/scripts/nvboard.mk
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME=V$(TOP)

# Normal simulation
build: $(BIN)

$(BIN): $(RTL_SRCS) $(CSRCS_SIM)
	@mkdir -p $(BUILD_DIR)
	$(VERILATOR) --cc --exe --build -j 0 -Wall \
		--trace-$(TRACE) \
		--top-module $(TOP) \
		--Mdir $(OBJ_DIR) \
		-o $(abspath $@) \
		$(RTL_SRCS) $(CSRCS_SIM)

# NVBoard simulation
$(BIN_NVB): $(RTL_SRCS) $(CSRCS_NVB) $(SRC_AUTO_BIND) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR_NVB)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOP) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) \
		$(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR_NVB) \
		--exe -o $(abspath $@)

$(BIN_TB): $(RTL_SRCS) $(TB_SRC)
	@mkdir -p $(OBJ_DIR_TB)
	$(VERILATOR) --binary --timing -j 0 \
		--trace-fst \
		--top-module $(TB_TOP) \
		--Mdir $(OBJ_DIR_TB) \
		$(RTL_SRCS) $(TB_SRC)

sim: $(BIN)
	./$(BIN)

sim_tb: $(BIN_TB)
	./$(BIN_TB)

wave: sim
	gtkwave wave.$(TRACE)

run: $(BIN_NVB)
	./$(BIN_NVB)

lint:
	$(VERILATOR) --lint-only -Wall \
		--top-module $(TOP) $(VERILATOR_FLAGS) $(RTL_SRCS)

clean:
	rm -rf $(BUILD_DIR) wave.vcd wave.fst

.PHONY: build sim sim_tb wave run lint clean
