#include "systick.h"

static __IO u32 TimingDelay = 0;

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

/**
  * @brief   ms延时程序,10us为一个单位
  * @param  
  *		@arg nTime: Delay_ms( 1 ) 则实现的延时为 1 * 1ms = 1ms
  * @retval  无
  */
void Delay_ms(__IO u32 nTime)
{ 
	TimingDelay = nTime;	

	// 使能滴答定时器  
	SysTick->CTRL |=  SysTick_CTRL_ENABLE_Msk;

	while(TimingDelay != 0);
}

