## Tips



虚拟机中安装的交叉编译器版本为`gcc-linaro-4.9.4-2017.01-x86_64_arm-linux-gnueabihf`

教程中将代码的起始地址都链接到0x87800000

```bash
# 生成目标代码
$ arm-linux-gnueabihf-gcc -g -c leds.s -o led.o
# 链接成可执行文件
$ arm-linux-gnueabihf-ld -Ttext 0x87800000 led.o -o led.elf
# 转为二进制文件
$ arm-linux-gnueabihf-objcopy -O binary -S -g led.elf led.bin
# 反汇编
$ arm-linux-gnueabihf-objdump -D led.elf > led.dis
```



使用正点原子提供的烧写工具（imxdownload），将二进制文件烧写到sd卡中
