#include "bsp_uart.h"
#include "bsp_gpio.h"


void uart_init()
{
    // 初始化UART1的IO复用
    uart_io_init();

    // 初始化UART1
    uart_disable(UART1);
    uart_softreset(UART1);
    
    UART1->UCR1 = 0x0;
    UART1->UCR1 &= ~(0x1 << 14);
    // 数据位 奇偶校验位 停止位
    // UART1->UCR2 = 0x0;
    UART1->UCR2 |= (0x4026);        // 0100 0000 0010 0110

    UART1->UCR3 |= (0x1 << 2);      // 0000 0000 0000 0100
    
    // 设置波特率为 115200, 计算方法见13_uart/info.md
#if 1
    UART1->UFCR &= ~(0x7 << 7);
    UART1->UFCR = (0x5 << 7);
    UART1->UBIR = 0x47;
    UART1->UBMR = 0xC34;
#else
	UART1->UFCR = 5<<7; //ref freq等于ipg_clk/1=80Mhz
	UART1->UBIR = 71;
	UART1->UBMR = 3124;
#endif

    uart_enable(UART1);
}

void uart_disable(UART_Type *base)
{
    base->UCR1 &= ~(0x1);
}

void uart_enable(UART_Type *base)
{
    base->UCR1 |= (0x1);
}

void uart_softreset(UART_Type *base)
{
    base->UCR2 &= ~(0x1);
    while(0 == (base->UCR2 & 0x1));
}

void uart_io_init()
{
    // 设置管脚复用， 复用为UART的TX和RX
    IOMUXC_SetPinMux(IOMUXC_UART1_TX_DATA_UART1_TX, 0);
    IOMUXC_SetPinMux(IOMUXC_UART1_RX_DATA_UART1_RX, 0);

    IOMUXC_SetPinConfig(IOMUXC_UART1_TX_DATA_UART1_TX, 0x10B0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_RX_DATA_UART1_RX, 0x10B0);
}

void putc(unsigned char c)
{
    // while(0 == (UART1->USR2 & (0x1 << 3)));
    while (((UART1->USR2 >> 3) & 0x1) == 0);

    UART1->UTXD = c;
}

unsigned char getc()
{
    // while(0 == (UART1->USR2 & (0x1 << 3)));
    while ((UART1->USR2  & 0x1) == 0);

    return UART1->URXD;
}

void puts(char *str)
{
    char *p = str;

    while (*p)
        putc(*p++);
}

// void gets()
// {

// }