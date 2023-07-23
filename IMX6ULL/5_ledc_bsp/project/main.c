#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"


int main()
{
    clk_enable();

    led_init();

    while(1)
    {
        led_on();
        delay(1000);

        led_off();
        delay(300);
    }

    return 0;
}