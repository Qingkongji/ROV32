#include "inner.h"

struct PID pidData_pitch_w;
struct PID pidData_roll_w;
struct PID pidData_yaw_w;

struct PID pidData_deep;

int32_t out_pitch_w;
int32_t out_roll_w;
int32_t out_yaw_w;
int32_t out_deep;

unsigned int direction_ur,direction_ul,direction_dr,direction_dl;
unsigned int direction_1,direction_2,direction_3;

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
	
	PIDdataInit(&pidData_pitch_w,1,0,0,5000,10000);//后五个为PID参数，一个积分限幅，一个输出限幅，最终PID输出与电机PWM比例为100：1
	PIDdataInit(&pidData_roll_w,20,10,5,5000,10000);//后五个为PID参数，一个积分限幅，一个输出限幅，最终PID输出与电机PWM比例为100：1
	PIDdataInit(&pidData_yaw_w,50,10,0,5000,10000);//后五个为PID参数，一个积分限幅，一个输出限幅，最终PID输出与电机PWM比例为100：1
}

void Inner_Loop(void)
{
	//获得传感器数据
	pidData_pitch_w.feedback = JY901_Gyro.w[0];
	pidData_roll_w.feedback = JY901_Gyro.w[1];
	pidData_yaw_w.feedback = JY901_Gyro.w[2];
	pidData_deep.feedback = MS5837_depth();
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
	MOTOR_UL(remote_x+remote_y+remote_yaw+1*out_yaw_w,direction_ur);
	MOTOR_UR(remote_x-remote_y-1*out_yaw_w,direction_ul);
	MOTOR_DL(remote_x-remote_y+1*out_yaw_w,direction_dl);
	MOTOR_DR(remote_x+remote_y-remote_yaw-1*out_yaw_w,direction_dr);
	MOTOR_1(remote_z+out_deep + 1*out_roll_w + 1*out_pitch_w,direction_1);
	MOTOR_2(remote_z+out_deep - 1*out_roll_w + 1*out_pitch_w,direction_2);
	MOTOR_3(remote_z+out_deep - 2*out_pitch_w,direction_3);
		
}



