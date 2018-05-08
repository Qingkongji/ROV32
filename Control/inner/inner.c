#include "inner.h"

struct PID pidData_pitch_w;
struct PID pidData_roll_w;
struct PID pidData_yaw_w;

struct PID pidData_deep;

float out_pitch_w;
float out_roll_w;
float out_yaw_w;
float out_deep;

//正桨为1，反桨为0
unsigned int direction_ur = 0,direction_ul = 1,direction_dr = 1,direction_dl = 0;
unsigned int direction_1 = 0,direction_2 = 1,direction_3 = 1;

void MOTOR_UR(signed int v,unsigned int direction)    //TIM3_CH1    UP-RIGHT
{
	if(v > 500)
		v = 500;
	if(v < -500)
		v = -500;
	if(direction)
		TIM_SetCompare1(GENERAL_TIM, 1500+v);
	else
		TIM_SetCompare1(GENERAL_TIM, 1500-v);
}

void MOTOR_UL(signed int v,unsigned int direction)    //TIM3_CH2    UP-LEFT
{
	if(v > 500)
		v = 500;
	if(v < -500)
		v = -500;
	if(direction)
		TIM_SetCompare2(GENERAL_TIM, 1500+v);
	else
		TIM_SetCompare2(GENERAL_TIM, 1500-v);
}

void MOTOR_DL(signed int v,unsigned int direction)    //TIM3_CH3    DOWN-LEFT
{
	if(v > 500)
		v = 500;
	if(v < -500)
		v = -500;
	if(direction)
		TIM_SetCompare3(GENERAL_TIM, 1500+v);
	else
		TIM_SetCompare3(GENERAL_TIM, 1500-v);
}

void MOTOR_DR(signed int v,unsigned int direction)    //TIM3_CH4    DOWN-RIGHT
{
	if(v > 500)
		v = 500;
	if(v < -500)
		v = -500;
	if(direction)
		TIM_SetCompare4(GENERAL_TIM, 1500+v);
	else
		TIM_SetCompare4(GENERAL_TIM, 1500-v);
}

void MOTOR_1(signed int v,unsigned int direction)    //TIM8_CH1
{
	if(v > 500)
		v = 500;
	if(v < -500)
		v = -500;
	if(direction)
		TIM_SetCompare1(ADVANCE_TIM, 1500+v);
	else
		TIM_SetCompare1(ADVANCE_TIM, 1500-v);
}

void MOTOR_2(signed int v,unsigned int direction)    //TIM8_CH2
{
	if(v > 500)
		v = 500;
	if(v < -500)
		v = -500;
	if(direction)
		TIM_SetCompare2(ADVANCE_TIM, 1500+v);
	else
		TIM_SetCompare2(ADVANCE_TIM, 1500-v);
}

void MOTOR_3(signed int v,unsigned int direction)    //TIM8_CH3
{
	if(v > 500)
		v = 500;
	if(v < -500)
		v = -500;
	if(direction)
		TIM_SetCompare3(ADVANCE_TIM, 1500+v);
	else
		TIM_SetCompare3(ADVANCE_TIM, 1500-v);
}

void Inner_Init(void)
{
	PIDdataInit(&pidData_deep,200,4,5,5000,10000);//后五个为PID参数，一个积分限幅，一个输出限幅，最终PID输出与电机PWM比例为100：1
	
	PIDdataInit(&pidData_pitch_w,20,10,5,5000,10000);//后五个为PID参数，一个积分限幅，一个输出限幅，最终PID输出与电机PWM比例为100：1
	PIDdataInit(&pidData_roll_w,20,10,5,5000,10000);//后五个为PID参数，一个积分限幅，一个输出限幅，最终PID输出与电机PWM比例为100：1
	PIDdataInit(&pidData_yaw_w,50,10,0,5000,10000);//后五个为PID参数，一个积分限幅，一个输出限幅，最终PID输出与电机PWM比例为100：1
}

void Inner_Loop(void)
{
	//获得传感器数据，角速度单位为度每秒
	pidData_roll_w.feedback = JY901_Gyro.w[0];
	pidData_yaw_w.feedback = JY901_Gyro.w[1];
	pidData_pitch_w.feedback = JY901_Gyro.w[2];
	pidData_deep.feedback = MS5837_depth();
	//处理角速度防止处于临界值 角速度范围为0-3999°/s	
	if( pidData_roll_w.feedback >= ( pidData_roll_w.set+2000 ) )
		pidData_roll_w.feedback -= 4000;
	if( pidData_yaw_w.feedback >= ( pidData_yaw_w.set+2000 ) )
		pidData_yaw_w.feedback -= 4000;
	if( pidData_pitch_w.feedback >= ( pidData_pitch_w.set+2000 ) )
		pidData_pitch_w.feedback -= 4000;
	//更新PID数据
	PIDdataUpdate(&pidData_pitch_w);
	PIDdataUpdate(&pidData_roll_w);
	PIDdataUpdate(&pidData_yaw_w);
	PIDdataUpdate(&pidData_deep);
	//计算PID
	GetPID_OUT(&pidData_pitch_w);
	GetPID_OUT(&pidData_roll_w);
	GetPID_OUT(&pidData_yaw_w);
	GetPID_OUT(&pidData_deep);

	out_pitch_w = pidData_pitch_w.out/100;
	out_roll_w = pidData_roll_w.out/100;
	out_yaw_w = pidData_yaw_w.out/100;
	out_deep = pidData_deep.out/50;
	
	//电机输出
	MOTOR_UL((int)(remote_x+remote_y+1*out_yaw_w),direction_ur);
	MOTOR_UR((int)(remote_x-remote_y),direction_ul);
	MOTOR_DL((int)(remote_x-remote_y),direction_dl);
	MOTOR_DR((int)(remote_x+remote_y-1*out_yaw_w),direction_dr);
	MOTOR_1((int)(remote_z+out_deep + 1*out_roll_w + 1*out_pitch_w),direction_1);
	MOTOR_2((int)(remote_z+out_deep - 1*out_roll_w + 1*out_pitch_w),direction_2);
	MOTOR_3((int)(remote_z+out_deep - 2*out_pitch_w),direction_3);
		
}



