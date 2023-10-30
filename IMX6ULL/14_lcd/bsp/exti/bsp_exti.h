#ifndef __BSP_EXTI_H
#define __BSP_EXTI_H

#include "imx6u.h"

/**
 * @brief 外部中断初始化
 * 
 */
void exti_init();

/**
 * @brief GPIO1_18中断处理函数
 * 
 * @param gicciar 
 * @param param 
 */
void gpio1_io18_irqhandler(unsigned int gicciar, void *param);

#endif // !__BSP_EXTI_H