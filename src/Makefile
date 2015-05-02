PROJECT = blink

# Project options
CPU = -mthumb -mcpu=cortex-m0plus -MD
FPU = #-mfloat-abi=soft
LINKSCRIPT = lpc8xx.ld

# Executables
TOOLCHAIN = arm-none-eabi
CC = $(TOOLCHAIN)-gcc
LD = $(TOOLCHAIN)-ld
SIZE = $(TOOLCHAIN)-size
OBJCOPY = $(TOOLCHAIN)-objcopy

# Project files
SOURCES = $(wildcard *.c)
OBJECTS = $(SOURCES:.c=.o)

# Flags
CFLAGS += -Os --specs=nano.specs -ffunction-sections -fdata-sections -fno-builtin
CFLAGS += $(CPU) $(FPU) $(INC)

all: $(PROJECT).bin $(PROJECT).hex

clean:
	@echo "Cleaning *.o, *.d $(PROJECT).afx $(PROJECT).hex and $(PROJECT).bin"
	@rm -f *.o *.d $(PROJECT).axf $(PROJECT).hex $(PROJECT).bin

%.o: %.c Makefile
	-@echo " - Compiling $@"
	@$(CC) $(CFLAGS) -c -o $@ $<

$(PROJECT).axf: $(OBJECTS) $(LINKSCRIPT)
	-@echo " - Linking $@"
	@$(LD) -o $@ $(LDFLAGS) -T $(LINKSCRIPT) $(OBJECTS)

size: $(PROJECT).axf
	-@echo ""
	@$(SIZE) $<
	-@echo ""

$(PROJECT).hex: $(PROJECT).axf
	-@echo " - Generating $@"
	@$(OBJCOPY) --strip-unneeded -O ihex $< $@

$(PROJECT).bin: $(PROJECT).axf
	-@echo " - Generating $@"
	@$(OBJCOPY) --strip-unneeded -O binary $< $@

