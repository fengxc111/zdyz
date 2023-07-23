#ifndef __BSP_LED_H
#define __BSP_LED_H
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "cc.h"

#define LED0        0
#define LED1        1

/**
 * @brief 初始化led（GPIO1_IO3）
 * 
 */
void led_init();
void led_on();
void led_off();
void led_switch(int led, int status);


#endif // !__BSP_LED_H