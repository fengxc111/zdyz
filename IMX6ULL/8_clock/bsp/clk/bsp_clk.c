#include "bsp_clk.h"

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

void imx6u_clkinit()
{
    if (((CCM->CCSR >> 2) & (0x1)) == 0)    // 当前时钟使用PLL1
    {
        CCM->CCSR &= ~(0x1 << 8);
        CCM->CCSR |= (0x1 << 2); 
    }

    CCM_ANALOG->PLL_ARM &= ~(0x7F);
    CCM_ANALOG->PLL_ARM |= 0x58;
    CCM_ANALOG->PLL_ARM |= (0x1 << 13);

    CCM->CACRR &= ~(0x7);
    CCM->CACRR |= 0x1;

    CCM->CCSR &= ~(0x1 << 2);
}