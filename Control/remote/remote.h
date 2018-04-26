#ifndef _REMOTE_H_
#define _REMOTE_H_

#include "stm32f10x.h"
#include "inner.h"
#include "outer.h"
#include "PID.h"
#include "mavlink.h"

extern float remote_x;
extern float remote_y;
extern float remote_z;
extern float remote_yaw;

void Updata_set(void);
void Decode(const mavlink_message_t* msg);

#endif

