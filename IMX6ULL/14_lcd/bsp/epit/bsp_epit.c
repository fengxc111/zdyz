#include "bsp_epit.h"
#include "bsp_int.h"
#include "bsp_led.h"

void epit1_init(unsigned int frac, unsigned int value)
{
    frac = (frac > 4095) ? 4095 : frac;

    EPIT1->CR = 0;

    EPIT1->CR = (1 << 1) | (1 << 2) | (1 << 3) | (frac << 4) | (1 << 24);

    EPIT1->LR = value; 
    EPIT1->CMPR = 0;

    GIC_EnableIRQ(EPIT1_IRQn);
    system_register_irqhandler(EPIT1_IRQn, epit1_irqhandler, NULL);

    EPIT1->CR |= 1 << 0;
}

void epit1_irqhandler(unsigned int gicciar, void *param)
{
    static unsigned char state = 0;

    state = !state;
    if (EPIT1->SR & (1 << 0))
    {
        led_switch(LED0, state);
    }

    EPIT1->SR |= (1 << 0); 
}