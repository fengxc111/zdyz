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

#endif // !__BSP_DELAY_H