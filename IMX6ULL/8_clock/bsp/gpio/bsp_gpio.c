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