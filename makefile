###############################################################################
# COMPILER SELECT
###############################################################################
CROSS_COMPILE=avr-gcc
MICRO_CONTROLLER=atmega328

###############################################################################
# FLAGS
###############################################################################
C_FLAGS=-Wall -g -mmcu=$(MICRO_CONTROLLER) -DF_CPU=8000000 -std=c99 -O2
LD_FLAGS=-mmcu=$(MICRO_CONTROLLER) -Wl,-Map=$(MAP_FILE)
INCLUDES=-I.

###############################################################################
# FILES
###############################################################################
ELF_FILE=wojOS.elf
MAP_FILE=wojOS.map
VPATH=drivers arch/avr kernel/
C_FILES=board.c uart.c libc_stdio.c platform.c task.c
SRC_FILES=kernel_asm.S

OBJ_FILES=$(C_FILES:%.c=%.o)
OBJ_FILES+=$(SRC_FILES:%.S=%.o)
DEP_FILES=$(C_FILES:%.c=%.d)
DEP_FILES+=$(SRC_FILES:%.S=%.d)

###############################################################################
# TARGETS
###############################################################################
$(ELF_FILE): $(OBJ_FILES)
	$(CROSS_COMPILE) -o $@ $(OBJ_FILES) $(LD_FLAGS)

%.o: %.c
	$(CROSS_COMPILE) $(C_FLAGS) $(INCLUDES) -M -o $*.d $<
	$(CROSS_COMPILE) $(C_FLAGS) $(INCLUDES) -c -o $@ $<

%.o: %.S
	$(CROSS_COMPILE) -D__ASM__ $(C_FLAGS) $(INCLUDES) -M -o $*.d $<
	$(CROSS_COMPILE) -D__ASM__ $(C_FLAGS) $(INCLUDES) -c -o $@ $<

###############################################################################
# CLEAN
###############################################################################
clean: clean_obj clean_dep
	rm -f $(ELF_FILE) $(MAP_FILE)

clean_obj:
	rm -f $(OBJ_FILES)

clean_dep:
	rm -f $(DEP_FILES)

-include $(DEP_FILES)
