#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"


int main()
{
    clk_enable();

    led_init();
    beep_init();
    key_init();

    while(1)
    {
        if (key_getvalue() == KEY0_VALUE)
        {
            led_switch(LED0, ON);
            beep_switch(ON);
        }
        else
        {
            led_switch(LED0, OFF);
            beep_switch(OFF);
        }
        delay(100);
    }

    return 0;
}