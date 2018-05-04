#ifndef _LOOP_H_
#define _LOOP_H_

#include "ms5837.h"
#include "usart1.h"
#include "inner.h"
#include "outer.h"
#include "debug.h"
#include "mavlink.h"
#include "remote.h"

#define BUF_LENGTH 2048

extern int cnt_MS5837;
extern int8_t Lock_flag;

void loop_cnt(void);
void ROV_Loop(void);
void cnt_init(void);

#endif

