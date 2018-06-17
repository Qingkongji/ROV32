#include "inner.h"

struct PID pidData_pitch_w = { 0.0,0.0,0.0,0.02,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0.0 };
struct PID pidData_roll_w = { 0.0,0.0,0.0,0.02,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0.0 };
struct PID pidData_yaw_w = { 0.0,0.0,0.0,0.02,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0.0 };

struct PID pidData_deep = { 0.0,0.0,0.0,0.02,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0.0,0,0,0.0 };

float out_pitch_w = 0.0;
float out_roll_w = 0.0;
float out_yaw_w = 0.0;
float out_deep = 0.0;

unsigned int direction_ur = 1,direction_ul = 0,direction_dr = 1,direction_dl = 0;
unsigned int direction_1 = 1,direction_2 = 0,direction_3 = 0;

void MOTOR_UR(signed int v,unsigned int direction)    //TIM3_CH1    UP-RIGHT
{
	if(v == (TIM_GetCapture1(GENERAL_TIM) - 1500))
		return;
	if(v > 0)
		v += 20;
	if(v < 0)
		v -= 20;
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
	if(v == (TIM_GetCapture2(GENERAL_TIM) - 1500))
		return;
	if(v > 0)
		v += 20;
	if(v < 0)
		v -= 20;
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
	if(v == (TIM_GetCapture3(GENERAL_TIM) - 1500))
		return;
	if(v > 0)
		v += 20;
	if(v < 0)
		v -= 20;
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
	if(v == (TIM_GetCapture4(GENERAL_TIM) - 1500))
		return;
	if(v > 0)
		v += 20;
	if(v < 0)
		v -= 20;
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
	if(v == (TIM_GetCapture1(ADVANCE_TIM) - 1500))
		return;
	if(v > 0)
		v += 20;
	if(v < 0)
		v -= 20;
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
	if(v == (TIM_GetCapture2(ADVANCE_TIM) - 1500))
		return;
	if(v > 0)
		v += 20;
	if(v < 0)
		v -= 20;
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
	if(v == (TIM_GetCapture3(ADVANCE_TIM) - 1500))
		return;
	if(v > 0)
		v = 2*v+20;
	if(v < 0)
		v = 2*v-20;
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
	PIDdataInit(&pidData_deep,20,0,0,5000,10000);//�����ΪPID������һ�������޷���һ������޷�������PID�������PWM����Ϊ100��1
	
	PIDdataInit(&pidData_pitch_w,50,0,5,5000,10000);//�����ΪPID������һ�������޷���һ������޷�������PID�������PWM����Ϊ100��1
	PIDdataInit(&pidData_roll_w,50,0,5,5000,10000);//�����ΪPID������һ�������޷���һ������޷�������PID�������PWM����Ϊ100��1
	PIDdataInit(&pidData_yaw_w,50,0,0,5000,10000);//�����ΪPID������һ�������޷���һ������޷�������PID�������PWM����Ϊ100��1
}

void Inner_Loop(void)
{
	//��ô��������ݣ����ٶȵ�λΪ��ÿ��
	pidData_roll_w.feedback = JY901_Gyro.w[0];
	pidData_yaw_w.feedback = JY901_Gyro.w[1];
	pidData_pitch_w.feedback = JY901_Gyro.w[2];
	pidData_deep.feedback = MS5837_depth();
	//������ٶȷ�ֹ�����ٽ�ֵ ���ٶȷ�ΧΪ0-3999��/s	
	if( pidData_roll_w.feedback >= ( pidData_roll_w.set+2000 ) )
		pidData_roll_w.feedback -= 4000;
	if( pidData_yaw_w.feedback >= ( pidData_yaw_w.set+2000 ) )
		pidData_yaw_w.feedback -= 4000;
	if( pidData_pitch_w.feedback >= ( pidData_pitch_w.set+2000 ) )
		pidData_pitch_w.feedback -= 4000;
	//����PID����
	PIDdataUpdate(&pidData_pitch_w);
	PIDdataUpdate(&pidData_roll_w);
	PIDdataUpdate(&pidData_yaw_w);
	PIDdataUpdate(&pidData_deep);
	//����PID
	GetPID_OUT(&pidData_pitch_w);
	GetPID_OUT(&pidData_roll_w);
	GetPID_OUT(&pidData_yaw_w);
	GetPID_OUT(&pidData_deep);
	
	out_pitch_w = pidData_pitch_w.out/100;
//	out_roll_w = pidData_roll_w.out/5;
//	out_yaw_w = pidData_yaw_w.out/5;
//	out_deep = pidData_deep.out/20;
	
//	out_pitch_w = 0;
	out_roll_w = 0;
	out_yaw_w = 0;
	out_deep = 0;

	//������
	MOTOR_UL((int)(remote_x+remote_y+1*remote_yaw),direction_ul);
	MOTOR_UR((int)(remote_x-remote_y),direction_ur);
	MOTOR_DL((int)(remote_x-remote_y),direction_dl);
	MOTOR_DR((int)(remote_x+remote_y-1*remote_yaw),direction_dr);
	MOTOR_1((int)(remote_z - 1*out_roll_w - 1*out_pitch_w),direction_1);
	MOTOR_2((int)(remote_z + 1*out_roll_w - 1*out_pitch_w),direction_2);
	MOTOR_3((int)(remote_z + 1*out_pitch_w),direction_3);
		
}



