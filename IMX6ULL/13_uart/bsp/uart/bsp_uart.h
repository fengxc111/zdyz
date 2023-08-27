#ifndef __BSP_UART_H
#define __BSP_UART_H
#include "fsl_common.h"
#include "fsl_iomuxc.h"
#include "MCIMX6Y2.h"
#include "cc.h"

/**
 * @brief 初始化UART1
 * 
 */
void uart_init();


/**
 * @brief UART1的IO复用初始化
 * 
 */
void uart_io_init();

/**
 * @brief 关闭UART
 * 
 * @param base 
 */
void uart_disable(UART_Type *base);

/**
 * @brief 使能UART
 * 
 * @param base 
 */
void uart_enable(UART_Type *base);

/**
 * @brief 复位UART
 * 
 * @param base 
 */
void uart_softreset(UART_Type *base);

void putc(unsigned char c);
unsigned char getc();
void puts(char *str);

#endif // !__BSP_UART_H