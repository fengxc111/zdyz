#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"


int main()
{
    imx6u_clkinit();
    clk_enable();

    led_init();
    beep_init();
    // key_init();

    while(1)
    {
        led_on();
        beep_switch(ON);
        delay(1000);

        beep_switch(OFF);
        led_off();
        delay(300);
    }

    return 0;
}