#include "remote.h"
//fix conflict

float remote_pitch_angle = 0.0;
float remote_roll_angle = 0.0;
float remote_yaw_init = 0.0;

float remote_pitch_w = 0.0;
float remote_roll_w = 0.0;
float remote_yaw_w = 0.0;

float remote_x = 0.0;       //signed + -
float remote_y = 0.0;
float remote_z = 0.0;
float remote_yaw = 0.0;


mavlink_joystick_control_t joystick_control = {0,0,0,0,0,0};
mavlink_heartbeat_t heartbeat = {0,0,0,0,0,0};


void remote_init(void)
{
	remote_yaw_init = JY901_Angle.Angle[1];
	if( remote_yaw_init >= 180 )
		remote_yaw_init -= 360;
	remote_yaw = remote_yaw_init;
	remote_x = 0;
	remote_y = 0;
	remote_z = 0;
	remote_pitch_angle = 0;
	remote_roll_angle = 0;
	remote_pitch_w = 0;
	remote_roll_w = 0;
	remote_yaw_w = 0;
	Reset_set(&pidData_pitch_angle, remote_pitch_angle);
	Reset_set(&pidData_roll_angle, remote_roll_angle);
	Reset_set(&pidData_yaw_angle, remote_yaw);
	Reset_set(&pidData_deep, remote_z);
}
	

void Updata_set(void)
{
	remote_x = joystick_control.x_acc/32768.0*50;
	remote_y = joystick_control.y_acc/32768.0*50;
	remote_z = joystick_control.z_acc/32768.0*50;
	remote_yaw = joystick_control.yaw_acc/32768.0*36+remote_yaw_init;
	Reset_set(&pidData_deep, remote_z);
	Reset_set(&pidData_yaw_angle, remote_yaw);
}

void Decode(const mavlink_message_t* msg)
{
//<<<<<<< HEAD
//	switch (msg->msgid)
//	{
//		case MAVLINK_MSG_ID_HEARTBEAT:                   //心跳包
//		{
//			mavlink_msg_heartbeat_decode(msg, &heartbeat);
//			break;
//		}
//		case MAVLINK_MSG_ID_JOYSTICK_CONTROL:            //摇杆指令消息
//		{
//			mavlink_msg_joystick_control_decode(msg, &joystick_control);
//			remote_x = joystick_control.x_acc;
//			remote_y = joystick_control.y_acc;
//			remote_z = joystick_control.z_acc;
//			remote_yaw = joystick_control.yaw_acc;
//			break;
//		}
//		//上锁与解锁的MAVLINK消息
//		default:break;
//=======

#ifdef DECODERDEBUG
	char str[100];
#endif
	
	if(msg->msgid == MAVLINK_MSG_ID_JOYSTICK_CONTROL){
	  mavlink_msg_joystick_control_decode(msg, &joystick_control);
#ifdef DECODERDEBUG
		sprintf(str,"remote_x=%.1f,remote_y=%.1f,remote_z=%.1f,remote_yaw = %.1f\n",remote_x,remote_y,remote_z,remote_yaw);
		Usart_SendString(NEO_USARTx,str);
#endif
	}
}

