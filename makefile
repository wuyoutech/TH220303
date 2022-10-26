prefix = arm-none-eabi

build_dir = build
src_dir = src

# project name & config 
target = rspll
debug = 1
opt = -Og

# sources 
asm_sources +=
c_sources += src/main.c
c_sources += src/peripheral/src/rf_ctrl.c

# defines
defs += -DUSE_STDPERIPH_DRIVER
defs += -DGD32F405

# includes 
includes += -Isrc
includes += -Isrc/peripheral/inc

# include platform support file
include src/platform/makefile