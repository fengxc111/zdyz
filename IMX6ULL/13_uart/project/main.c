#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exti.h"
#include "bsp_epit.h"
#include "bsp_keyfilter.h"
#include "bsp_uart.h"
#include "stdio.h"

int main()
{
    unsigned char a;
    int x, y;

    int_init();
    imx6u_clkinit();
    delay_init();
    clk_enable();
    uart_init();

    led_init();
    beep_init();
    key_init();

    unsigned char state = OFF;
    while(1)
    {
#if 0
        puts("请输入1个字符: ");
        a = getc();
        putc(a);
        puts("\r\n");
        
        puts("You input char: ");
        putc(a);
        puts("\r\n");
        state = !state;
#endif
        printf("请输入两个整数， 使用空格隔开：");
        scanf("%d %d", &x, &y);
        printf("\r\n数据%d + %d = %d\r\n", x, y, x+y);
        printf("%d的十六进制为 %#x\r\n", x+y, x+y);
        printf("\r\n");

        led_switch(LED0, state);
    }

    return 0;
}