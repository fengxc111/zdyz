#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exti.h"
#include "bsp_epit.h"
#include "bsp_keyfilter.h"


int main()
{
    int_init();
    imx6u_clkinit();
    clk_enable();

    led_init();
    beep_init();
    key_init();
    keyfilter_init();

    unsigned char state = OFF;

    while(1)
    {
        state = !state;
        led_switch(LED0, state);
        delay(500);
    }

    return 0;
}