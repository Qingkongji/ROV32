#ifndef _OUTER_H_
#define _OUTER_H_

#include "PID.h"
#include "stm32f10x.h"
#include "JY901.h"
#include "inner.h"

extern struct PID pidData_yaw_angle;

void Outer_Init(void);
void Outer_Loop(void);

#endif

