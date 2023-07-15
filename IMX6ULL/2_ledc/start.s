.global _start

_start:
    /* 设置处理器进入SVC模式 */
    mrs r0, cpsr
    bic r0, r0, #0x1f
    orr r0, r0, #0x13
    msr cpsr, r0

    /* 设置sp指针 */
    ldr sp, =0x80200000
    b main      @跳转到c语言的main函数
