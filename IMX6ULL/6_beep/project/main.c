#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"

int main()
{
    clk_enable();

    led_init();
    beep_init(); 

    while(1)
    {
        led_on();
        beep_switch(ON);
        delay(1000);

        led_off();
        beep_switch(OFF);
        delay(1000);
    }

    return 0;
}