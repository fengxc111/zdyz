/*
 * 点亮开发板上的红色led灯DS0
 */
.global _start

_start:
    /* 使能外设时钟 */
    ldr r0, =0x020c4068 @CCGR0
    ldr r1, =0xffffffff
    str r1, [r0]

    ldr r0, =0x020c406C
    str r1, [r0]

    ldr r0, =0x020c4070
    str r1, [r0]

    ldr r0, =0x020c4074
    str r1, [r0]

    ldr r0, =0x020c4078
    str r1, [r0]

    ldr r0, =0x020c407C
    str r1, [r0]

    ldr r0, =0x020c4080
    str r1, [r0]

    /* 配置 GPIO_IO03 的引脚 的复用为GPIO 
     * IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 地址为 020E_0068h
     * IOMUXC_SW_MUX_CTL_PAD_GPIO1_IO03 值为 5
     */
    ldr r0, =0x020e0068
    ldr r1, =0x5
    str r1, [r0]

    /* 设置GPIO_3的属性
     * IOMUXC_SW_PAD_CTL_PAD_GPIO1_IO03 地址为 20E_02F4h
     * 值为 10b0
     */
    ldr r0, =0x020302f4
    ldr r1, =0x10b0
    str r1, [r0]

    /* 设置GPIO1_IO03为输出
     * GPIO1_GDIR 地址为 209_C004
     * bit3 为 1
     */
    ldr r0, =0x0209c004
    ldr r1, =0x8
    str r1, [r0]

    /* GPIO1_IO03输出0
     * GPIO1_DR 地址为 209_C000， 输出值
     */
    ldr r0, =0x0209c000
    ldr r1, =0
    str r1, [r0]

loop:
    b loop
