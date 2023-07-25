#include "bsp_key.h"
#include "bsp_delay.h"

void key_init()
{
    IOMUXC_SetPinMux(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0);
    IOMUXC_SetPinConfig(IOMUXC_UART1_CTS_B_GPIO1_IO18, 0xF080);

    GPIO1->GDIR &= ~(1<<18);
}

int read_key()
{
    return ((GPIO1->DR) >> 18) & (0x1);
}

int key_getvalue()
{
    int ret = 0;
    static unsigned char release = 1;

    if (release == 1 && read_key() == 0)
    {
        delay(10);
        release = 0;
        if (read_key() == 0)
        {
            ret = KEY0_VALUE;
        }
    }
    else if (read_key() == 1)
    {
        ret = KEY_NONE;
        release = 1;
    }

    return ret;
}