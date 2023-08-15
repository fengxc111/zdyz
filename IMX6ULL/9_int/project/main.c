#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exti.h"


int main()
{
    int_init();
    imx6u_clkinit();
    clk_enable();

    led_init();
    beep_init();
    key_init();
    exti_init();

    while(1)
    {
        led_on();
        delay(1000);

        led_off();
        delay(1000);
    }

    return 0;
}