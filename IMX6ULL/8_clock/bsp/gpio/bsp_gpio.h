#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "cc.h"

/**
 * @brief GPIO方向，0输入，1输出
 * 
 */
typedef enum _gpio_pin_direction
{
    kGPIO_DigitalInput = 0U,
    kGPIO_DigitalOutput = 1U
} gpio_pin_direction_t;

/**
 * @brief GPIO引脚信息结构体
 * 
 */
typedef struct _gpio_pin_config
{
    gpio_pin_direction_t direction;
    uint8_t outputLogic;
} gpio_pin_config_t;

/**
 * @brief GPIO初始化
 * 
 * @param base      GPIO基址
 * @param pin       GPIO引脚号
 * @param config    引脚信息
 */
void gpio_init(GPIO_Type *base, int pin, gpio_pin_config_t *config);

/**
 * @brief 写GPIO口
 * 
 * @param base      GPIO基址
 * @param pin       GPIO引脚号
 * @param value     写入的值
 */
void gpio_pinwrite(GPIO_Type *base, int pin, int value);

/**
 * @brief 读GPIO口
 * 
 * @param base      GPIO基址
 * @param pin       GPIO引脚号
 * @return int      返回 GOPIO 口读到的值
 */
int gpio_pinread(GPIO_Type *base, int pin);


#endif // !__BSP_GPIO_H