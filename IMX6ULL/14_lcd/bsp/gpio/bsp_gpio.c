#include "bsp_gpio.h"

void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config)
{
    // if (NULL == base || NULL == config)
    // {
    //     printf("[%s]-%d: invalid param\n", __func__, __LINE__);
    //     return;
    // }

    if (config->direction == kGPIO_DigitalInput)
    {
        base->GDIR &= ~(1 << pin);
    }
    else
    {
        base->GDIR |= (1 <<  pin);
        gpio_pinwrite(base, pin, config->outputLogic);
    }

    gpio_intconfig(base, pin, config->interruptMode);
}

void gpio_pinwrite(GPIO_Type *base, int pin, int value)
{
    if (value == 0)
    {
        base->DR &= ~(1 << pin);
    }
    else
    {
        base->DR |= (1 << pin);
    }
}

int gpio_pinread(GPIO_Type *base, int pin)
{
    return (base->DR >> pin) & 0x1;
}

void gpio_enableint(GPIO_Type *base, unsigned int pin)
{
    base->IMR |= (1 << pin);
}

void gpio_disableint(GPIO_Type *base, unsigned int pin)
{
    base->IMR &= ~(1 << pin);
}

void gpio_clearintflags(GPIO_Type *base, unsigned int pin)
{
    base->ISR |= (1 << pin);
}

void gpio_intconfig(GPIO_Type *base, unsigned int pin, gpio_interrupt_mode_t pin_int_mode)
{
    volatile uint32_t *icr;
    uint32_t icrShift;

    icrShift = pin;
    base->EDGE_SEL &= ~(1 << pin);

    if (pin < 16)
    {
        icr = &(base->ICR1);
    }
    else
    {
        icr = &(base->ICR2);
        icrShift -= 16; 
    }

    switch (pin_int_mode)
    {
    case kGPIO_IntLowLevel:
        *icr &= ~(3 << (2 * icrShift));
        break;
    case kGPIO_IntHighLevel:
        *icr &= ~(3 << (2 * icrShift));
        *icr |= (1 << (2*icrShift));
        break;
    case kGPIO_IntRisingEdge:
        *icr &= ~(3 << (2 * icrShift));
        *icr |= (2 << (2*icrShift));
        break;
    case kGPIO_IntFallingEdge:
        *icr &= ~(3 << (2 * icrShift));
        *icr |= (3 << (2*icrShift));
        break;
    case kGPIO_IntRisingOrFallingEdge:
        base->EDGE_SEL |= (1 << pin);
        break;

    default:
        break;
    }
}