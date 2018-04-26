#include "remote.h"

float remote_pitch_angle;
float remote_roll_angle;
float remote_yaw_angle;

float remote_pitch_w;
float remote_roll_w;
float remote_yaw_w;

float remote_h;

float remote_x;
float remote_y;
float remote_z;
float remote_yaw;

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

