#ifndef __BSP_GPIO_H
#define __BSP_GPIO_H
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "cc.h"

/**
 * @brief 中断触发类型
 * 
 */
typedef enum _gpio_interrupt_mode
{
    kGPIO_Nointmode = 0U,
    kGPIO_IntLowLevel = 1U,
    kGPIO_IntHighLevel = 2U,
    kGPIO_IntRisingEdge = 3U,
    kGPIO_IntFallingEdge = 4U,
    kGPIO_IntRisingOrFallingEdge = 5U,
} gpio_interrupt_mode_t;

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
    gpio_interrupt_mode_t interruptMode;
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

/**
 * @brief 使能指定IO中断
 * 
 * @param base 
 * @param pin 
 */
void gpio_enableint(GPIO_Type *base, unsigned int pin);

/**
 * @brief 关闭指定IO中断
 * 
 * @param base 
 * @param pin 
 */
void gpio_disableint(GPIO_Type *base, unsigned int pin);


/**
 * @brief 清除中断标志位
 * 
 * @param base 
 * @param pin 
 */
void gpio_clearintflags(GPIO_Type *base, unsigned int pin);

/**
 * @brief GPIO中断初始化
 * 
 * @param base 
 * @param pin 
 * @param pin_int_mode 
 */
void gpio_intconfig(GPIO_Type *base, unsigned int pin, gpio_interrupt_mode_t pin_int_mode);

#endif // !__BSP_GPIO_H