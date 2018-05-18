#ifndef _BEEP_H_
#define _BEEP_H_

#include "stm32f10x.h"

/* 定义蜂鸣器连接的GPIO端口 */
#define BEEP_GPIO_PORT    	GPIOC			              /* GPIO端口 */
#define BEEP_GPIO_CLK 	    RCC_APB2Periph_GPIOC		/* GPIO端口时钟 */
#define BEEP_GPIO_PIN		  	GPIO_Pin_1			        /* 连接到蜂鸣器的GPIO */

void BEEP_GPIO_Config(void);

#endif

