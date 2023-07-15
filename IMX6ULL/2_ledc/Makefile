OBJS = start.o main.o
# CC = arm-linux-gnueabihf-gcc

ledc.bin: $(OBJS)
	arm-linux-gnueabihf-ld -Timx6u.lds $^ -o ledc.elf
	arm-linux-gnueabihf-objcopy -O binary -S -g ledc.elf $@
	arm-linux-gnueabihf-objdump -D -m arm ledc.elf > ledc.dis


%.o: %.c
	arm-linux-gnueabihf-gcc -Wall -nostdlib -c -O2 -o $@ $<

%.o: %.s
	arm-linux-gnueabihf-gcc -Wall -nostdlib -c -O2 -o $@ $<

clean:
	rm -rf *.o ledc.bin ledc.elf ledc.dis