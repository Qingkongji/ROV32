#ifndef _SYSTICK_H_
#define _SYSTICK_H_

#include "stm32f10x.h"
#include "core_cm3.h"


void Systick_Init(void);
void Delay_ms(__IO u32 nTime);


#endif

