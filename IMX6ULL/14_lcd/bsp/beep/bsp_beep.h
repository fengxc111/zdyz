#ifndef __BSP_BEEP_H
#define __BSP_BEEP_H
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "cc.h"

/**
 * @brief 初始化蜂鸣器
 * 
 */
void beep_init();

/**
 * @brief 设置蜂鸣器状态
 * 
 * @param status    ON/OFF
 */
void beep_switch(int status);

#endif // !__BSP_BEEP_H