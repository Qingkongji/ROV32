#ifndef _INNER_H_
#define _INNER_H_

#include "stm32f10x.h"
#include "tim3.h"
#include "tim8.h"
#include "PID.h"
#include "ms5837.h"
#include "JY901.h"
#include "remote.h"

void MOTOR_UR(signed int v,unsigned int direction);
void MOTOR_UL(signed int v,unsigned int direction);
void MOTOR_DL(signed int v,unsigned int direction);
void MOTOR_DR(signed int v,unsigned int direction);
void MOTOR_1(signed int v,unsigned int direction);
void MOTOR_2(signed int v,unsigned int direction);
void MOTOR_3(signed int v,unsigned int direction);
void Inner_Init(void);
void Inner_Loop(void);

#endif

