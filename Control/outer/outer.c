#include "outer.h"

struct PID pidData_pitch_angle;
struct PID pidData_roll_angle;
struct PID pidData_yaw_angle;

float out_pitch_angle;
float out_roll_angle;
float out_yaw_angle;

//static int cnt = 0;
//static char str[100];

void Outer_Init(void)
{
	PIDdataInit(&pidData_pitch_angle,20,10,5,5000,10000);      //kp ki kd imax outmax
	PIDdataInit(&pidData_roll_angle,20,20,5,5000,10000);
	PIDdataInit(&pidData_yaw_angle,50,50,0,5000,10000);
}

void Outer_Loop(void)
{
	//获取传感器数据,单位为度
	pidData_roll_angle.feedback = JY901_Angle.Angle[0];
	pidData_yaw_angle.feedback = JY901_Angle.Angle[1];
	pidData_pitch_angle.feedback = JY901_Angle.Angle[2];
	//处理角度以防止临界值即0与359度之间
	if(pidData_pitch_angle.feedback >= 180)
		pidData_pitch_angle.feedback -= 360.0;
	if(pidData_roll_angle.feedback >= 180)
		pidData_roll_angle.feedback -= 360.0;
	if(pidData_yaw_angle.feedback >= (180+remote_yaw))
		pidData_yaw_angle.feedback -= 360.0;
		
//	if( cnt++>50 )
//	{
//		sprintf(str,"yaw=%.1f,roll=%.1f,pitch=%.1f\n",pidData_yaw_angle.feedback,pidData_roll_angle.feedback,pidData_pitch_angle.feedback);
//		Usart_SendString(NEO_USARTx,str);
//		cnt = 0;
//	}
	
	//更新PID数据
	PIDdataUpdate(&pidData_pitch_angle);
	PIDdataUpdate(&pidData_roll_angle);
	PIDdataUpdate(&pidData_yaw_angle);
	//计算PID
	GetPID_OUT(&pidData_pitch_angle);
	GetPID_OUT(&pidData_roll_angle);
	GetPID_OUT(&pidData_yaw_angle);
	//外环PID输出
	out_pitch_angle=pidData_pitch_angle.out/100;
	out_roll_angle=pidData_roll_angle.out/100;
	out_yaw_angle=pidData_yaw_angle.out/100;
	
	Reset_set(&pidData_pitch_w, out_pitch_angle);
	Reset_set(&pidData_roll_w, out_roll_angle);
	Reset_set(&pidData_yaw_w, out_yaw_angle);
}

