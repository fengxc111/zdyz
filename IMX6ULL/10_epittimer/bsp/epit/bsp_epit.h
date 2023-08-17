#ifndef __BSP_EPIT_H
#define __BSP_EPIT_H

#include "imx6u.h"

/**
 * @brief 初始化EPIT1
 * 
 * @param frac 分频
 * @param value 时钟
 */
void epit1_init(unsigned int frac, unsigned int value);

/**
 * @brief EPIT1中断处理函数
 * 
 * @param gicciar 
 * @param param 
 */
void epit1_irqhandler(unsigned int gicciar, void *param);

#endif