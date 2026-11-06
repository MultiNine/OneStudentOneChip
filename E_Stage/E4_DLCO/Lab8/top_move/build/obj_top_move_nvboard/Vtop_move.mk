# Verilated -*- Makefile -*-
# DESCRIPTION: Verilator output: Makefile for building Verilated archive or executable
#
# Execute this makefile from the object directory:
#    make -f Vtop_move.mk

default: /home/caiyaohao/OneStudentOneChip/E_Stage/E4_DLCO/Lab8/top_move/build/Vtop_move_nvboard

### Constants...
# Perl executable (from $PERL, defaults to 'perl' if not set)
PERL = perl
# Python3 executable (from $PYTHON3, defaults to 'python3' if not set)
PYTHON3 = python3
# Path to Verilator kit (from $VERILATOR_ROOT)
VERILATOR_ROOT = /usr/local/share/verilator
# SystemC include directory with systemc.h (from $SYSTEMC_INCLUDE)
SYSTEMC_INCLUDE ?=
# SystemC library directory with libsystemc.a (from $SYSTEMC_LIBDIR)
SYSTEMC_LIBDIR ?=

### Switches...
# C++ code coverage  0/1 (from --prof-c)
VM_PROFC = 0
# SystemC output mode?  0/1 (from --sc)
VM_SC = 0
# Legacy or SystemC output mode?  0/1 (from --sc)
VM_SP_OR_SC = $(VM_SC)
# Deprecated
VM_PCLI = 1
# Deprecated: SystemC architecture to find link library path (from $SYSTEMC_ARCH)
VM_SC_TARGET_ARCH = linux

### Vars...
# Module prefix (from --prefix)
VM_MODPREFIX = Vtop_move
# Design prefix (from --prefix)
VM_PREFIX = Vtop_move
# Design header include, for '#include VM_PREFIX_INCLUDE' (from --prefix)
VM_PREFIX_INCLUDE = <Vtop_move.h>
# User CFLAGS (from -CFLAGS on Verilator command line)
VM_USER_CFLAGS = \
  -MMD \
  -O3 \
  -I/usr/include/SDL2 \
  -D_REENTRANT \
  -I/home/caiyaohao/ysyx-workbench/nvboard/usr/include \
  -DTOP_NAME=Vtop_move \

# User LDLIBS (from -LDFLAGS on Verilator command line)
VM_USER_LDLIBS = \
  /home/caiyaohao/ysyx-workbench/nvboard/build/nvboard.a \
  -lSDL2 \
  -lSDL2_image \
  -lSDL2_ttf \

# User library files (from .a/.o/.so on Verilator command line)
# These are also in VM_USER_LDLIBS, and are link dependencies
VM_USER_LDLIBS_FILES = \
  /home/caiyaohao/ysyx-workbench/nvboard/build/nvboard.a \

# User .cpp files (from .cpp's on Verilator command line)
VM_USER_CLASSES = \
  auto_bind \
  nvboard_top_move \

# User .cpp directories (from .cpp's on Verilator command line)
VM_USER_DIR = \
  .. \
  ../.. \

### Default rules...
# Include list of all generated classes
include Vtop_move_classes.mk
# Include global rules
include $(VERILATOR_ROOT)/include/verilated.mk

### Executable rules... (from --exe)
VPATH += $(VM_USER_DIR)

auto_bind.o: /home/caiyaohao/OneStudentOneChip/E_Stage/E4_DLCO/Lab8/top_move/build/auto_bind.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<
nvboard_top_move.o: nvboard_top_move.cpp 
	$(OBJCACHE) $(CXX) $(CXXFLAGS) $(CPPFLAGS) $(OPT_FAST)  -c -o $@ $<

### Link rules... (from --exe)
/home/caiyaohao/OneStudentOneChip/E_Stage/E4_DLCO/Lab8/top_move/build/Vtop_move_nvboard: $(VK_USER_OBJS) $(VK_GLOBAL_OBJS) $(VM_PREFIX)__ALL.a $(VM_USER_LDLIBS_FILES)
	$(LINK) $(LDFLAGS) $(filter-out $(VM_USER_LDLIBS_FILES),$^) $(LOADLIBES) $(LDLIBS) $(LIBS) $(SC_LIBS) -o $@

# Verilated -*- Makefile -*-
