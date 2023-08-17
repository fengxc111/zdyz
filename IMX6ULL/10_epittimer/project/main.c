#include "main.h"
#include "bsp_clk.h"
#include "bsp_delay.h"
#include "bsp_led.h"
#include "bsp_beep.h"
#include "bsp_key.h"
#include "bsp_int.h"
#include "bsp_exti.h"
#include "bsp_epit.h"


int main()
{
    int_init();
    imx6u_clkinit();
    clk_enable();

    led_init();
    beep_init();
    key_init();
    epit1_init(0, 66000000 / 2);

    while(1)
    {
        delay(500);
    }

    return 0;
}