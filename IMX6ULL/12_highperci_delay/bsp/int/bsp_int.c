#include "bsp_int.h"

static unsigned int irqNesting;

static sys_irq_handle_t irqTable[NUMBER_OF_INT_VECTORS];

void system_irqtable_init()
{
    unsigned int i = 0;
    irqNesting = 0;

    for (i = 0; i < NUMBER_OF_INT_VECTORS; i++)
    {
        // irqTable[i].irqHandler = default_irqhandler;
        // irqTable[i].userParam = NULL;
        system_register_irqhandler(i, default_irqhandler, NULL);
    }
}

void system_register_irqhandler(IRQn_Type irq, system_irq_handler_t handler, void *userParam)
{
    irqTable[irq].irqHandler = handler;
    irqTable[irq].userParam = userParam;
}

void int_init()
{
    GIC_Init();

    /* 中断向量偏移设置 */
    __set_VBAR(0x87800000);
}

void default_irqhandler(unsigned int gicciar, void *userParam)
{
    while (1){}
}

void system_irqhandler(unsigned int gicciar)
{
    uint32_t intNum = gicciar & 0x3FF;

    if (intNum >= NUMBER_OF_INT_VECTORS)
    {
        return;
    }

    irqNesting++;

    irqTable[intNum].irqHandler(intNum, irqTable[intNum].userParam);
    
    irqNesting--;
}