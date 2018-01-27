#include "systick.h"


void Systick_Init(void)
{
	/* SystemCoreClock / 1000    1ms中断一次
	 * SystemCoreClock / 100000	 10us中断一次
	 * SystemCoreClock / 1000000 1us中断一次
	 * static __INLINE uint32_t SysTick_Config(uint32_t ticks)在core_cm3.h中定义，用来配置重转载寄存器的值，
	 * 其中也含有中断优先级配置。
	*/
	if(SysTick_Config(SystemCoreClock/1000))
	{
		while(1);
	}
}

