#ifndef __BSP_DELAY_H
#define __BSP_DELAY_H
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

/**
 * @brief 短延时函数
 * 
 * @param n 
 */
void delay_short(volatile unsigned int n);

/**
 * @brief 延时函数
 * 
 * @param n     单位ms
 */
void delay(volatile unsigned int n);

/**
 * @brief GPT1中断初始化
 * 
 */
void delay_init();


/**
 * @brief GPT1中断处理函数
 * 
 * @param gicciar 
 * @param param 
 */
void gpt1_irqhandler(unsigned int gicciar, void *param);

/**
 * @brief 微秒级延时
 * 
 * @param usdelay
 */
void delay_us(unsigned int usdelay);

/**
 * @brief 毫秒级延时
 * 
 * @param msdelay 
 */
void delay_ms(unsigned int msdelay);

#endif // !__BSP_DELAY_H