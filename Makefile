#******************************************************************************
# Copyright (C) 2017 by Jordan Zhang
#
# Redistribution, modification or use of this software in source or binary
# forms is permitted as long as the files maintain this copyright. Users are
# permitted to modify this and use it to learn about the field of embedded
# software. Jordan Zhang is not liable for any misuse of this material.
#
#*****************************************************************************

#------------------------------------------------------------------------------
# GNU Make program that supports the host machine and MSP432(cross-platform)
#
# Use: make [TARGET] [PLATFORM-OVERRIDES]
#
# Build Targets:
#      <FILE>.i - Generates the preprocessed output of all c-program implementation files (use the –E flag).
#      <FILE>.asm - Generates assembly output of c-program implementation files and the final output executable (Use the –S flag and the objdump utility).
#      <FILE>.o - Generates the object file for all c-source files (but do not link) by specifying the object file you want to compile.
#      compile-all - Compiles all object files, but DOES NOT link
#      build - Builds and links all source files into one executable file - c1m2.out
#              Generates the memory map of the executable
#              Provides build report of code size using gcc size too
#      clean - Removes all compiled objects, preprocessed outputs, assembly outputs, executable files and build output files.
#
# Platform Overrides:
#      <Put a description of the supported Overrides here
#
#------------------------------------------------------------------------------
include sources.mk

BASE_FILENAME = c1_final
# General Flags
GENERAL_FLAGS = \
	-Wall \
	-Werror \
	-g \
	-O0 \
	-std=c99

ifeq ($(PLATFORM), MSP432)
	# Architectures specific flags for the cross-compiler
	CPU = cortex-m4
	MODE = thumb
	ARCH = armv7e-m
	FLOAT_ABI = hard
	FPU = fpv4-sp-d16
	SPECS = nosys.specs

	# Platform specific flags for the cross-compiler
	LINKER_FILE = -T ../msp432p401r.lds

	CC = arm-none-eabi-gcc
	CFLAGS = \
			$(GENERAL_FLAGS) -mcpu=$(CPU) -m$(MODE) -march=$(ARCH) \
			-mfloat-abi=$(FLOAT_ABI) -mfpu=$(FPU) --specs=$(SPECS)

	CPPFLAGS = -DMSP432 $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(BASE_FILENAME).map  $(LINKER_FILE)
	SIZE = arm-none-eabi-size
	OBJDUMP = arm-none-eabi-objdump
else
	# When running on host platform
	CC = gcc
	CFLAGS = $(GENERAL_FLAGS)
	CPPFLAGS = -DHOST -DCOURSE1 -DVERBOSE $(INCLUDES)
	LDFLAGS = -Wl,-Map=$(BASE_FILENAME).map
	SIZE = size
	OBJDUMP = objdump
endif

OBJS = $(SOURCES:.c=.o)
DEPS = $(SOURCES:.c=.d)
ASMS = $(SOURCES:.c=.asm)
PRES = $(SOURCES:.c=.i)

# Generate the preprocessed output of all c-program implementation files (use the –E flag).
%.i : %.c
	$(CC) -E $< $(CPPFLAGS) -o $@

# Generate assembly output of c-program implementation files and the final output executable (Use the –S flag and the objdump utility).
%.asm : %.c
	$(CC) -S $< $(CPPFLAGS) $(CFLAGS) -o $@

# Generate the object file for all c-source files (but do not link)
%.o : %.c
	$(CC) -c $< $(CPPFLAGS) $(CFLAGS) -o $@

# Generate the dependency files for each source file ( using the -M* options [MP, MF, MD, MM, etc])
%.d : %.c
	$(CC) -E -M $< $(CPPFLAGS) -o $@

$(BASE_FILENAME).asm : $(BASE_FILENAME).out
	$(OBJDUMP) -d $(BASE_FILENAME).out >> $@

.PHONY: compile-all
compile-all: $(OBJS)

.PHONY: build
build: $(DEPS)
build: $(BASE_FILENAME).out

$(BASE_FILENAME).out: $(OBJS)
	$(CC) $(OBJS) $(CPPFLAGS) $(CFLAGS) $(LDFLAGS) -o $@
	$(SIZE) $@

.PHONY: clean
clean:
	rm -f $(OBJS) $(DEPS) $(ARMS) $(PRES) $(BASE_FILENAME).out $(BASE_FILENAME).map
	rm -f *.i *.asm *.o *.out *.d
