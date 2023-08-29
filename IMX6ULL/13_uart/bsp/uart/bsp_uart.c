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
#if 0
    UART1->UFCR &= ~(0x7 << 7);
    UART1->UFCR = (0x5 << 7);
    UART1->UBIR = 0x47;
    UART1->UBMR = 0xC34;
#else
    uart_setbaudrate(UART1, 115200, 80000000);
#endif

    uart_enable(UART1);
}

void uart_setbaudrate(UART_Type *base, unsigned int baudrate, unsigned int srcclock_hz)
{
    uint32_t numerator = 0u;		//分子
    uint32_t denominator = 0U;		//分母
    uint32_t divisor = 0U;
    uint32_t refFreqDiv = 0U;
    uint32_t divider = 1U;
    uint64_t baudDiff = 0U;
    uint64_t tempNumerator = 0U;
    uint32_t tempDenominator = 0u;

    /* get the approximately maximum divisor */
    numerator = srcclock_hz;
    denominator = baudrate << 4;
    divisor = 1;

    while (denominator != 0)
    {
        divisor = denominator;
        denominator = numerator % denominator;
        numerator = divisor;
    }

    numerator = srcclock_hz / divisor;
    denominator = (baudrate << 4) / divisor;

    /* numerator ranges from 1 ~ 7 * 64k */
    /* denominator ranges from 1 ~ 64k */
    if ((numerator > (UART_UBIR_INC_MASK * 7)) || (denominator > UART_UBIR_INC_MASK))
    {
        uint32_t m = (numerator - 1) / (UART_UBIR_INC_MASK * 7) + 1;
        uint32_t n = (denominator - 1) / UART_UBIR_INC_MASK + 1;
        uint32_t max = m > n ? m : n;
        numerator /= max;
        denominator /= max;
        if (0 == numerator)
        {
            numerator = 1;
        }
        if (0 == denominator)
        {
            denominator = 1;
        }
    }
    divider = (numerator - 1) / UART_UBIR_INC_MASK + 1;

    switch (divider)
    {
        case 1:
            refFreqDiv = 0x05;
            break;
        case 2:
            refFreqDiv = 0x04;
            break;
        case 3:
            refFreqDiv = 0x03;
            break;
        case 4:
            refFreqDiv = 0x02;
            break;
        case 5:
            refFreqDiv = 0x01;
            break;
        case 6:
            refFreqDiv = 0x00;
            break;
        case 7:
            refFreqDiv = 0x06;
            break;
        default:
            refFreqDiv = 0x05;
            break;
    }
    /* Compare the difference between baudRate_Bps and calculated baud rate.
     * Baud Rate = Ref Freq / (16 * (UBMR + 1)/(UBIR+1)).
     * baudDiff = (srcClock_Hz/divider)/( 16 * ((numerator / divider)/ denominator).
     */
    tempNumerator = srcclock_hz;
    tempDenominator = (numerator << 4);
    divisor = 1;
    /* get the approximately maximum divisor */
    while (tempDenominator != 0)
    {
        divisor = tempDenominator;
        tempDenominator = tempNumerator % tempDenominator;
        tempNumerator = divisor;
    }
    tempNumerator = srcclock_hz / divisor;
    tempDenominator = (numerator << 4) / divisor;
    baudDiff = (tempNumerator * denominator) / tempDenominator;
    baudDiff = (baudDiff >= baudrate) ? (baudDiff - baudrate) : (baudrate - baudDiff);

    if (baudDiff < (baudrate / 100) * 3)
    {
        base->UFCR &= ~UART_UFCR_RFDIV_MASK;
        base->UFCR |= UART_UFCR_RFDIV(refFreqDiv);
        base->UBIR = UART_UBIR_INC(denominator - 1); //要先写UBIR寄存器，然后在写UBMR寄存器，3592页 
        base->UBMR = UART_UBMR_MOD(numerator / divider - 1);
    }
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

// 防止编译报错
void raise(int sig_nr)
{

}