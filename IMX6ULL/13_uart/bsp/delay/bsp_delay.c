#include "bsp_delay.h"
#include "bsp_int.h"
#include "bsp_led.h"

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

void delay_us(unsigned int usdelay)
{
    unsigned long oldcnt, newcnt;
    unsigned long tcntvalue = 0;

    oldcnt = GPT1->CNT;
    while (1)
    {
        newcnt = GPT1->CNT;
        if (newcnt != oldcnt)
        {
            if (newcnt > oldcnt)
                tcntvalue += newcnt - oldcnt;
            else
                tcntvalue += newcnt + 0xFFFFFFFF - oldcnt;

            oldcnt = newcnt;
            if (tcntvalue >= usdelay)
                break;
        }
    }
}

void delay_ms(unsigned int msdelay)
{
    // delay_us(1000 * msdelay);
    int i;
    for (i = 0; i < msdelay; i++)
    {
        delay_us(1000);
    }
}


void delay_init()
{
    GPT1->CR = 0;

    GPT1->CR = 1 << 15;

    while ((GPT1->CR >> 15) & 0x1 ) ;

    // 设置时钟源未ipg_clk=66M, restart模式
    GPT1->CR |= (1 << 1) | (1 << 6);

    // 设置分频66, 66000000/66=1MHz
    GPT1->PR = 65;

    GPT1->OCR[0] = 0xffffffff;
#if 0
    // 设置中断周期为500ms
    GPT1->OCR[0] = 1000000 / 2;

    // 使能比较1中断
    GPT1->IR |= 1 << 0;

    // 使能GPT1中断
    GIC_EnableIRQ(GPT1_IRQn);

    system_register_irqhandler(GPT1_IRQn, gpt1_irqhandler, NULL);
#endif

    // 使能GPT1
    GPT1->CR |= 0x1;
}

void gpt1_irqhandler(unsigned int gicciar, void *param)
{
    static unsigned char state = 0;

    if (GPT1->SR & 0x1)
    {
        state = !state;
        led_switch(LED0, state);
    }

    GPT1->SR |= 0x1;
}