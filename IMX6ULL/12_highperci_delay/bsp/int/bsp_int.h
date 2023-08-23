#ifndef __BSP_INT_H
#define __BSP_INT_H

#include "imx6u.h"

/**
 * @brief 中断处理函数
 * 
 */
typedef void (*system_irq_handler_t)(unsigned int gicciar, void *param);

/**
 * @brief 中断处理函数结构体
 * 
 */
typedef struct _sys_irq_handle
{
    system_irq_handler_t irqHandler;
    void *userParam;
} sys_irq_handle_t;

/**
 * @brief 初始化中断函数表
 * 
 */
void system_irqtable_init();

/**
 * @brief 初始化中断
 * 
 */
void int_init();

/**
 * @brief 默认中断处理函数
 * 
 * @param gicciar 
 * @param userParam 
 */
void default_irqhandler(unsigned int gicciar, void *userParam);

/**
 * @brief 注册中断处理函数
 * 
 * @param irq       中断号
 * @param handler   中断处理函数
 * @param userParam 参数
 */
void system_register_irqhandler(IRQn_Type irq, system_irq_handler_t handler, void *userParam);

/**
 * @brief 具体的中断处理函数
 * 
 * @param gicciar 
 */
void system_irqhandler(unsigned int gicciar);


#endif // !__BSP_INT_H