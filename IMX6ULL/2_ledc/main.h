#ifndef __MAIN_H
#define __MAIN_H

/* 定义外设时钟寄存器 */
#define CCM_CCGR0           *((volatile unsigned long*)0x020C4068)
#define CCM_CCGR1           *((volatile unsigned long*)0x020C406C)
#define CCM_CCGR2           *((volatile unsigned long*)0x020C4070)
#define CCM_CCGR3           *((volatile unsigned long*)0x020C4074)
#define CCM_CCGR4           *((volatile unsigned long*)0x020C4078)
#define CCM_CCGR5           *((volatile unsigned long*)0x020C407C)
#define CCM_CCGR6           *((volatile unsigned long*)0x020C4080)

/* IOMUX相关寄存器 */
#define SW_MUX_GPIO1_IO03   *((volatile unsigned long*)0x020E0068)
#define SW_PAD_GPIO1_IO03   *((volatile unsigned long*)0x020302F4)

/* GPIO1相关寄存器 */
#define GPIO1_DR            *((volatile unsigned long*)0x0209C000)
#define GPIO1_GDIR          *((volatile unsigned long*)0x0209C004)
#define GPIO1_PSR           *((volatile unsigned long*)0x0209C008)
#define GPIO1_ICR1          *((volatile unsigned long*)0x0209C00C)
#define GPIO1_ICR2          *((volatile unsigned long*)0x0209C010)
#define GPIO1_IMR           *((volatile unsigned long*)0x0209C014)
#define GPIO1_ISR           *((volatile unsigned long*)0x0209C018)
#define GPIO1_EDGE_SEL      *((volatile unsigned long*)0x0209C01C)

#endif // !__MAIN_H