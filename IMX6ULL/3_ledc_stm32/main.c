#include "imx6u.h"

/**
 * @brief 初始化外设时钟
 * 
 */
void clk_enable()
{
    CCM->CCGR0 = 0xFFFFFFFF;
    CCM->CCGR1 = 0xFFFFFFFF;
    CCM->CCGR2 = 0xFFFFFFFF;
    CCM->CCGR3 = 0xFFFFFFFF;
    CCM->CCGR4 = 0xFFFFFFFF;
    CCM->CCGR5 = 0xFFFFFFFF;
    CCM->CCGR6 = 0xFFFFFFFF;
}

/**
 * @brief 初始化led（GPIO1_IO3）
 * 
 */
void led_init()
{
    IOMUX_SW_MUX->GPIO1_IO03 = 0x5;
    IOMUX_SW_PAD->GPIO1_IO03 = 0x10B0;
    GPIO1->GDIR = 0x8;
    GPIO1->DR = 0x0;
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
    GPIO1->DR &= ~(1<<3);
}

void led_off()
{
    GPIO1->DR |= (1<<3);
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