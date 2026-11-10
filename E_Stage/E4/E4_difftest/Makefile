.DEFAULT_GOAL := sim
INC_PATH ?=
TOP ?= sCPU

VSRCS := $(wildcard vsrcs/*.v)
CSRCS := $(wildcard csrcs/*.cpp)

BUILD_DIR := build
OBJ_DIR := $(BUILD_DIR)/obj_$(TOP)
BIN := $(BUILD_DIR)/V$(TOP)

VERILATOR := verilator

VERILATOR_CFLAGS += -MMD --build -cc -O3 \
                    --x-assign fast --x-initial fast --noassert


build: $(BIN)

$(BIN): $(VSRCS) $(CSRCS)
	@rm -rf $(OBJ_DIR)
	@mkdir -p $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOP) $^ \
		$(addprefix -CFLAGS , $(CXXFLAGS)) \
		--Mdir $(OBJ_DIR) \
		--exe -o $(abspath $@)

lint:
	$(VERILATOR) --lint-only -Wall \
	--top-module $(TOP) $(VERILATOR_FLAGS) $(VSRCS)

sim: $(BIN)
	./$(BIN)

clean:
	rm -rf $(BUILD_DIR)

.PHONY: build sim lint clean
