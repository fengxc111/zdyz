CROSS_COMPILE ?= arm-linux-gnueabihf-
TARGET ?= lcd

CC := $(CROSS_COMPILE)gcc
LD := ${CROSS_COMPILE}ld
OBJCOPY := $(CROSS_COMPILE)objcopy
OBJDUMP := $(CROSS_COMPILE)objdump

LIBPATH := -lgcc -L /usr/local/arm/gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf/lib/gcc/arm-linux-gnueabihf/4.9.4/

INCLUDIR := imx6u \
			bsp/clk \
			bsp/led \
			bsp/delay \
			bsp/beep \
			bsp/key \
			bsp/gpio \
			bsp/int \
			bsp/exti \
			bsp/epit \
			bsp/keyfilter \
			bsp/uart \
			stdio/include \
			bsp/lcd

SRCDIR := project \
		bsp/clk \
		bsp/led \
		bsp/delay \
		bsp/beep \
		bsp/key \
		bsp/gpio \
		bsp/int \
		bsp/exti \
		bsp/epit \
		bsp/keyfilter \
		bsp/uart \
		stdio/lib \
		bsp/lcd

INCLUDE := $(patsubst %, -I%, $(INCLUDIR)) 

SFILES := $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.s))
CFILES := $(foreach dir, $(SRCDIR), $(wildcard $(dir)/*.c))

SFILENODIR := $(notdir $(SFILES))
CFILENODIR := $(notdir $(CFILES))

SOBJS := $(patsubst %.s, obj/%.o, $(SFILENODIR))
COBJS := $(patsubst %.c, obj/%.o, $(CFILENODIR))

OBJS := $(SOBJS) $(COBJS)

VPATH := $(SRCDIR)

.PHONY: clean

$(TARGET).bin: $(OBJS)
	$(LD) -Timx6u.lds -o $(TARGET).elf $^ $(LIBPATH)
	$(OBJCOPY) -O binary -S $(TARGET).elf $@
	$(OBJDUMP) -D -m arm $(TARGET).elf > $(TARGET).dis

$(SOBJS): obj/%.o: %.s
	$(CC) -Wall -nostdlib -fno-builtin -c -O2 $(INCLUDE) -o $@ $^

$(COBJS): obj/%.o: %.c
	$(CC) -Wall -nostdlib -fno-builtin -Wa,-mimplicit-it=thumb -c -O2 $(INCLUDE) -o $@ $^

clean:
	rm -rf $(TARGET).elf $(TARGET).bin $(TARGET).dis $(OBJS)
	
print:
	@echo INCLUDE = $(INCLUDE)
	@echo SFILES = $(SFILES)
	@echo CFILES = $(CFILES)
	@echo SFILENODIR = $(SFILENODIR)
	@echo CFILENODIR = $(CFILENODIR)
	@echo SOBJS = $(SOBJS)
	@echo COBJS = $(COBJS)