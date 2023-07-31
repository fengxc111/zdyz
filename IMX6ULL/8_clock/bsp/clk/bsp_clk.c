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
    unsigned int reg = 0;

    if (((CCM->CCSR >> 2) & (0x1)) == 0)    // 当前时钟使用PLL1
    {
        // 切换时钟源为step_sel
        CCM->CCSR &= ~(0x1 << 8);
        CCM->CCSR |= (0x1 << 2); 
    }

    // 配置PLL1，设置其频率为1056MHz
    CCM_ANALOG->PLL_ARM &= ~(0x7F);
    CCM_ANALOG->PLL_ARM |= 0x58;
    // 使能PLL1
    CCM_ANALOG->PLL_ARM |= (0x1 << 13);
    // 设置2分频
    CCM->CACRR &= ~(0x7);
    CCM->CACRR |= 0x1;
    // 切换回PLL1
    CCM->CCSR &= ~(0x1 << 2);

    // 设置PLL2 PFD0-3
    reg = CCM_ANALOG->PFD_528;
    reg &= ~(0x3F3F3F3F);
    reg |= 0x2F17101B;
    CCM_ANALOG->PFD_528 = reg;

    // 设置PLL3 PFD0-3
    reg = CCM_ANALOG->PFD_480;
    reg &= ~(0x3F3F3F3F);
    reg |= 0x1311100C;
    CCM_ANALOG->PFD_480 = reg;

    // 设置AHB_CLK_ROOT = 132MHz
    reg = CCM->CBCMR;
    reg &= ~(0x3 << 18);
    reg |= (0x1 << 18);
    reg &= ~(0x1 << 25);
    while (CCM->CDHIPR & (1 << 5));     // 等待握手信号
    CCM->CBCMR = reg;

    reg = CCM->CBCDR;
    reg &= ~(0x7 << 10);
    reg |= (0x2 << 10);
    while (CCM->CDHIPR & (1 << 1));     // 等待握手信号
    CCM->CBCDR = reg;


    // 设置IPG_CLK_ROOT = 66MHz
    reg = CCM->CBCDR;
    reg &= ~(0x3 << 8);
    reg |= (0x1 << 8);
    CCM->CBCDR = reg;

    // 设置PERCLK_CLK_ROOT = 66MHz
    reg = CCM->CSCMR1;
    reg &= ~(0x7F);
    CCM->CSCMR1 = reg;
}