#ifndef __BSP_KEYFILTER_H
#define __BSP_KEYFILTER_H

/**
 * @brief 中断初始化
 * 
 */
void keyfilter_init(void);


/**
 * @brief 按键中断服务函数
 * 
 * @param gicciar 
 * @param param 
 */
void gpio1_16_31_irqhandler(unsigned int gicciar, void *param);

/**
 * @brief 定时器初始化
 * 
 * @param value 
 */
void filtertimer_init(unsigned int value);

/**
 * @brief 关闭EPIT1定时器
 * 
 */
void filtertimer_stop();

/**
 * @brief 开启EPIT1定时器
 * 
 */
void filtertimer_start();

/**
 * @brief 重启EPIT1定时器
 * 
 * @param value 
 */
void filtertimer_restart(unsigned int value);

/**
 * @brief EPIT1时钟中断处理函数
 * 
 * @param gicciar 
 * @param param 
 */
void filtertimer_irqhandler(unsigned int gicciar, void *param);

#endif // !__BSP_KEYFILTER_H