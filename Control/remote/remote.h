#ifndef _REMOTE_H_
#define _REMOTE_H_

#include "stm32f10x.h"
#include "inner.h"
#include "outer.h"
#include "PID.h"
#include "mavlink.h"

extern signed int remote_x;
extern signed int remote_y;
extern signed int remote_z;
extern signed int remote_yaw;

void Updata_set(void);
void Decode(const mavlink_message_t* msg, mavlink_joystick_control_t* joystick_control);

#endif

