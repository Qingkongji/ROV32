#ifndef _LOOP_H_
#define _LOOP_H_

#include "ms5837.h"
#include "usart1.h"
#include "inner.h"
#include "outer.h"

extern int cnt_MS5837;

void loop_cnt(void);
void ROV_Loop(void);
void cnt_init(void);

#endif

