#include "main.h"

/**
 * @brief 初始化外设时钟
 * 
 */
void clk_enable()
{
    CCM_CCGR0 = 0xFFFFFFFF;
    CCM_CCGR1 = 0xFFFFFFFF;
    CCM_CCGR2 = 0xFFFFFFFF;
    CCM_CCGR3 = 0xFFFFFFFF;
    CCM_CCGR4 = 0xFFFFFFFF;
    CCM_CCGR5 = 0xFFFFFFFF;
    CCM_CCGR6 = 0xFFFFFFFF;
}

/**
 * @brief 初始化led（GPIO1_IO3）
 * 
 */
void led_init()
{
    SW_PAD_GPIO1_IO03 = 0x5;
    SW_MUX_GPIO1_IO03 = 0x10B0;
    GPIO1_GDIR = 0x8;
    GPIO1_DR = 0x0;
}

void delay_short(volatile unsigned int n)
{
    while(n--);
}

void delay(volatile unsigned int n)
{
    while(n--)
    {
        delay_short(0x7FF);
    }
}

void led_on()
{
    GPIO1_DR &= ~(1<<3);
}

void led_off()
{
    GPIO1_DR |= (1<<3);
}

int main()
{
    clk_enable();

    led_init();

    while(1)
    {
        led_on();
        delay(1000);

        led_off();
        delay(1000);
    }

    return 0;
}