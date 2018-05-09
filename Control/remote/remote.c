#include "remote.h"

float remote_pitch_angle;
float remote_roll_angle;
float remote_yaw_angle;

float remote_pitch_w;
float remote_roll_w;
float remote_yaw_w;

mavlink_joystick_control_t joystick_control;
mavlink_heartbeat_t heartbeat;

<<<<<<< HEAD
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
	
=======
signed int remote_x;       //signed + -
signed int remote_y;
signed int remote_z;
signed int remote_yaw;

>>>>>>> HaskiDuan-master
void Updata_set(void)
{
	Reset_set(&pidData_deep, remote_z);
	Reset_set(&pidData_yaw_angle, remote_yaw);
}

void Decode(const mavlink_message_t* msg)
{
<<<<<<< HEAD
	switch (msg->msgid)
	{
		case MAVLINK_MSG_ID_HEARTBEAT:                   //心跳包
		{
			mavlink_msg_heartbeat_decode(msg, &heartbeat);
			break;
		}
		case MAVLINK_MSG_ID_JOYSTICK_CONTROL:            //摇杆指令消息
		{
			mavlink_msg_joystick_control_decode(msg, &joystick_control);
			remote_x = joystick_control.x_acc;
			remote_y = joystick_control.y_acc;
			remote_z = joystick_control.z_acc;
			remote_yaw = joystick_control.yaw_acc;
			break;
		}
		//上锁与解锁的MAVLINK消息
		default:break;
=======

#ifdef DECODERDEBUG
	char str[100];
#endif
	
	if(msg->msgid == MAVLINK_MSG_ID_JOYSTICK_CONTROL){
	  mavlink_msg_joystick_control_decode(msg, &joystick_control);
	  remote_x = joystick_control.x_acc;
	  remote_y = joystick_control.y_acc;
	  remote_z = joystick_control.z_acc;
	  remote_yaw = joystick_control.yaw_acc;
#ifdef DECODERDEBUG
		sprintf(str,"remote_x=%d,remote_y=%d,remote_z=%d,remote_yaw = %d\n",remote_x,remote_y,remote_z,remote_yaw);
		Usart_SendString(NEO_USARTx,str);
#endif
>>>>>>> HaskiDuan-master
	}
}

