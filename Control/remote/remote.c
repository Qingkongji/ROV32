#include "remote.h"

int32_t remote_pitch_angle;
int32_t remote_roll_angle;
int32_t remote_yaw_angle;

int32_t remote_pitch_w;
int32_t remote_roll_w;
int32_t remote_yaw_w;

int32_t remote_h;

signed int remote_x;
signed int remote_y;
signed int remote_z;
signed int remote_yaw;

void Updata_set(void)
{
	Reset_set(&pidData_deep, remote_h);
	Reset_set(&pidData_yaw_angle, remote_yaw);
}

void Decode(const mavlink_message_t* msg, mavlink_joystick_control_t* joystick_control)
{
	mavlink_msg_joystick_control_decode(msg, joystick_control);
	remote_x = joystick_control->x_acc;
	remote_y = joystick_control->y_acc;
	remote_z = joystick_control->z_acc;
	remote_h = joystick_control->yaw_acc;
}

