#include "remote.h"

float remote_pitch_angle;
float remote_roll_angle;
float remote_yaw_angle;

float remote_pitch_w;
float remote_roll_w;
float remote_yaw_w;

float remote_x;
float remote_y;
float remote_z;
float remote_yaw;

mavlink_joystick_control_t joystick_control;
mavlink_heartbeat_t heartbeat;

void remote_init(void)
{
	remote_x = 0;
	remote_y = 0;
	remote_z = 0;
	remote_yaw = 0;
	remote_pitch_angle = 0;
	remote_roll_angle = 0;
	remote_yaw_angle = 0;
	remote_pitch_w = 0;
	remote_roll_w = 0;
	remote_yaw_w = 0;
}
	
void Updata_set(void)
{
	Reset_set(&pidData_deep, remote_z);
	Reset_set(&pidData_yaw_angle, remote_yaw);
}

void Decode(const mavlink_message_t* msg)
{
	switch (msg->msgid)
	{
		case MAVLINK_MSG_ID_HEARTBEAT:
		{
			mavlink_msg_heartbeat_decode(msg, &heartbeat);
			break;
		}
		case MAVLINK_MSG_ID_JOYSTICK_CONTROL:
		{
			mavlink_msg_joystick_control_decode(msg, &joystick_control);
			remote_x = joystick_control.x_acc;
			remote_y = joystick_control.y_acc;
			remote_z = joystick_control.z_acc;
			remote_yaw = joystick_control.yaw_acc;
			break;
		}
		default:break;
	}
}

