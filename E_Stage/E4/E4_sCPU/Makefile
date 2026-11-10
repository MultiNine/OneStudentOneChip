.DEFAULT_GOAL := build
INC_PATH ?=
TOP ?= sCPU

VSRCS := $(wildcard vsrcs/*.v)
CSRCS := $(wildcard csrcs/*.cpp)

BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj_$(TOP)
BIN := $(BUILD_DIR)/V$(TOP)

VERILATOR := verilator
TRACE ?= fst

VERILATOR_CFLAGS += -MMD --build -cc -O3 \
                    --x-assign fast --x-initial fast --noassert

NXDC_FILES := $(CURDIR)/constr/$(TOP).nxdc
SRC_AUTO_BIND := $(abspath $(BUILD_DIR)/auto_bind.cpp)
CSRCS += $(SRC_AUTO_BIND)
$(SRC_AUTO_BIND): $(NXDC_FILES)
	@mkdir -p $(dir $@)
	python3 $(NVBOARD_HOME)/scripts/auto_pin_bind.py $< $@

# NVBoard configuration
include $(NVBOARD_HOME)/scripts/nvboard.mk
INCFLAGS = $(addprefix -I, $(INC_PATH))
CXXFLAGS += $(INCFLAGS) -DTOP_NAME=V$(TOP)

build: $(BIN)

$(BIN): $(VSRCS) $(CSRCS) $(NVBOARD_ARCHIVE)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOP) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) \
		$(addprefix -LDFLAGS , $(LDFLAGS)) \
		--Mdir $(OBJ_DIR) \
		--exe -o $(abspath $@)

lint:
	$(VERILATOR) --lint-only -Wall \
	--top-module $(TOP) $(VERILATOR_FLAGS) $(VSRCS)

run: $(BIN)
	./$(BIN)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: build run lint clean
