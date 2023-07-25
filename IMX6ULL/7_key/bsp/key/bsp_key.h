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

void key_init();
int read_key();
int key_getvalue();

#endif // !__BSP_KEY_H