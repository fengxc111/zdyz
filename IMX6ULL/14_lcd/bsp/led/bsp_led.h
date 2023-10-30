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

/**
 * @brief 使能led
 * 
 */
void led_on();

/**
 * @brief 关闭led
 * 
 */
void led_off();

/**
 * @brief 切换led状态
 * 
 * @param led       led号
 * @param status    led状态，ON/OFF
 */
void led_switch(int led, int status);


#endif // !__BSP_LED_H