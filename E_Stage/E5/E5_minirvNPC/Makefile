TOPNAME = top
INC_PATH ?=

VERILATOR = verilator
VERILATOR_CFLAGS += --build -cc --exe \
				    -j 0 --trace-fst

BUILD_DIR = ./build
OBJ_DIR = $(BUILD_DIR)/obj_dir
BIN = $(BUILD_DIR)/$(TOPNAME)

default: $(BIN)

$(shell mkdir -p $(BUILD_DIR))

VSRCS = $(wildcard vsrc/*.v)
CSRCS = $(wildcard csrc/*.cpp)


$(BIN): $(VSRCS) $(CSRCS)
	@rm -rf $(OBJ_DIR)
	$(VERILATOR) $(VERILATOR_CFLAGS) \
		--top-module $(TOPNAME) $^ \
		--Mdir $(OBJ_DIR) -o $(abspath $(BIN))

all: default

lint: $(VSRCS)
	$(VERILATOR) --lint-only -Wall \
	    --top-module $(TOPNAME) $(VSRCS)

sim:$(BIN)
	$(call git_commit, "sim RTL") # DO NOT REMOVE THIS LINE!!!
	@$(BIN)

include ../Makefile
 