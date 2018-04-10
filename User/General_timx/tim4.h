#ifndef _TIM4_H_
#define _TIM4_H_

#include "stm32f10x.h"

/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM4

#define            LED_TIM                   TIM4
#define            LED_TIM_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            LED_TIM_CLK               RCC_APB1Periph_TIM4
#define            LED_TIM_Period            (20000-1)
#define            LED_TIM_Prescaler         (72-1)

// TIM4 CH3
#define            LED1_TIM_CH3_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            LED1_TIM_CH3_PORT          GPIOB
#define            LED1_TIM_CH3_PIN           GPIO_Pin_8

// TIM4 CH4
#define            LED2_TIM_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            LED2_TIM_CH4_PORT          GPIOB
#define            LED2_TIM_CH4_PIN           GPIO_Pin_9

void LED_TIM4_Init(void);

#endif 
