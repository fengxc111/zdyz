OBJS := start.o main.o
CC := arm-linux-gnueabihf-gcc
LD := arm-linux-gnueabihf-ld
OBJCOPY := arm-linux-gnueabihf-objcopy
OBJDUMP := arm-linux-gnueabihf-objdump

ledc.bin: $(OBJS)
	$(LD) -Timx6u.lds $^ -o ledc.elf
	$(OBJCOPY) -O binary -S -g ledc.elf $@
	$(OBJDUMP) -D -m arm ledc.elf > ledc.dis


%.o: %.c
	$(CC) -Wall -nostdlib -c -O2 -o $@ $<

%.o: %.s
	$(CC) -Wall -nostdlib -c -O2 -o $@ $<

clean:
	rm -rf *.o ledc.bin ledc.elf ledc.dis