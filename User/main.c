#include "stm32f10x.h"
#include "usart1.h"
#include "usart3.h"
#include "iic.h"
#include "ms5837.h"
#include "JY901.h"
#include "tim3.h"
#include "tim8.h"
#include "systick.h"
#include "loop.h"
#include "inner.h"
#include "outer.h"
#include "debug.h"
#include "tim4.h"

int main(void)
{	
	
	char str[100];
	
	/*初始化USART 115200 8-N-1，中断接收*/
	/*add comment*/
  USART1_Config();
	I2C_GPIOconfig();
	JY_USART3_Remap_Config();
	TIM3_Init();
	TIM8_Init();
	LED_TIM4_Init();
	Systick_Init();
	Outer_Init();
	Inner_Init();
	
#ifdef DEBUG
	sprintf(str,"This is the debug edition\n");
	Usart_SendString(NEO_USARTx,str);
#endif
		
	while(!(MS5837_CheckDevice()))
	{
		sprintf(str,"MS5837 disconnected\n");
		Usart_SendString(NEO_USARTx,str);
	}
	
	sprintf(str,"MS5837 connected\n");
	Usart_SendString(NEO_USARTx,str);

	MS5837_Init();
	cnt_init();
	
			
  while(1)
	{	
		ROV_Loop();
	}	
}

