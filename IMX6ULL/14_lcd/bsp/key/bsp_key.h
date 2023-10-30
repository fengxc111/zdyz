#ifndef __BSP_KEY_H
#define __BSP_KEY_H
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "cc.h"

enum keyvalue{
    KEY_NONE = 0,
    KEY0_VALUE
};

/**
 * @brief 初始化按键
 * 
 */
void key_init();

/**
 * @brief 读取按键值
 * 
 * @return int 
 */
int read_key();

/**
 * @brief 获取按键状态，防抖
 * 
 * @return int 
 */
int key_getvalue();

#endif // !__BSP_KEY_H