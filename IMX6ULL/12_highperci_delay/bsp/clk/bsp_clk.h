#ifndef __BSP_CLK_H
#define __BSP_CLK_H
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"

/**
 * @brief 初始化外设时钟
 * 
 */
void clk_enable();

/**
 * @brief 初始化系统时钟
 * 
 */
void imx6u_clkinit();

#endif // !__BSP_CLK_H