#ifndef _TIM5_H_
#define _TIM5_H_

#include "stm32f10x.h"

/************通用定时器TIM参数定义，只限TIM2、3、4、5************/
// 当使用不同的定时器的时候，对应的GPIO是不一样的，这点要注意
// 我们这里默认使用TIM3

#define            GENERAL_TIM5                   TIM5
#define            GENERAL_TIM5_APBxClock_FUN     RCC_APB1PeriphClockCmd
#define            GENERAL_TIM5_CLK               RCC_APB1Periph_TIM5
#define            GENERAL_TIM5_Period            99
#define            GENERAL_TIM5_Prescaler         14399
// TIM3 CH1
#define            GENERAL_TIM5_CH1_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH1_PORT          GPIOA
#define            GENERAL_TIM5_CH1_PIN           GPIO_Pin_0

// TIM3 CH2
#define            GENERAL_TIM5_CH2_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH2_PORT          GPIOA
#define            GENERAL_TIM5_CH2_PIN           GPIO_Pin_1

// TIM3 CH3
#define            GENERAL_TIM5_CH3_GPIO_CLK      RCC_APB2Periph_GPIOA
#define            GENERAL_TIM5_CH3_PORT          GPIOA
#define            GENERAL_TIM5_CH3_PIN           GPIO_Pin_2

// TIM3 CH4
#define            GENERAL_TIM5_CH4_GPIO_CLK      RCC_APB2Periph_GPIOB
#define            GENERAL_TIM5_CH4_PORT          GPIOA
#define            GENERAL_TIM5_CH4_PIN           GPIO_Pin_3

/**************************函数声明********************************/

void TIM5_Init(void);


#endif
