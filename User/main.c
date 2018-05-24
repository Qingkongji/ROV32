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
#include "mavlink.h"
#include "tim4.h"
#include "beep.h"

int main(void)
{	
	
	char str[100] = {'0'};
	
	/*初始化USART 115200 8-N-1，中断接收*/
	/*接口初始化*/
  USART1_Config();             //nanopi接口
	I2C_GPIOconfig();            //MS5837接口
	JY_USART3_Remap_Config();    //JY901接口
	TIM3_Init();                 //四路PWM接口-电机
	TIM8_Init();                 //四路PWM接口-电机
	LED_TIM4_Init();             //两路灯光PWM接口
	Systick_Init();              //滴答定时器
	BEEP_GPIO_Config();          //蜂鸣器接口初始化并拉低
	
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

	MS5837_Init();               //MS5837初始化，完成校准工作
	
	I2C_delay_ms(10000);
	
	/*控制初始化*/
	Outer_Init();                //外环PID参数初始化
	Inner_Init();                //内环PID参数初始化
	remote_init();               //指令初始化赋值
	
	cnt_init();                  //循环内计数初始化
			
  while(1)
	{	
		ROV_Loop();
	}	
}

