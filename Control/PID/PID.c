#include "PID.h"

float P_ROLL=0.5;
float I_ROLL=0.15;
float D_ROLL=0.0;

float P_PITCH=1;
float I_PITCH=0.15;
float D_PITCH=0.0;

float P_YAW=1;
float I_YAW=0.15;
float D_YAW=0.0;

/* 约束条件，用于抗饱和 */
int32_t constrain_int32(int32_t amt, int32_t low, int32_t high) 
{
	return ((amt)<(low)?(low):((amt)>(high)?(high):(amt)));
}

/* 设置PID参数 */
void PIDdataInit(struct PID* pidData,uint16_t kp,uint16_t ki,uint16_t kd,int32_t imax,int32_t outmax)
{
	pidData->Imax=imax;
	pidData->outmax=outmax;
	pidData->kP=kp;
	pidData->kI=ki;
	pidData->kD=kd;
	pidData->P=0;
	pidData->I=0;
	pidData->D=0;
	pidData->error=0;
	pidData->last_error=0;
	pidData->derror=0;
	pidData->set=0;
	pidData->out=0;
}

/* 更新PID三个模块内容，注意ki、kd中是处理了采样时间的，不是单纯的kd */
void PIDdataUpdate(struct PID* pidData)
{
	pidData->error = pidData->set - pidData->feedback;
	pidData->derror = pidData->error - pidData->last_error;
	pidData->last_error = pidData->error;
	
	pidData->P = pidData->kP * pidData->error;
	
	pidData->I += pidData->kI * pidData->error;
	pidData->I = constrain_int32(pidData->I, -pidData->Imax, +pidData->Imax);	  //抗积分饱和
	
	pidData->D = pidData->kD * pidData->derror;
	
}

void ResetI(struct PID* pidData)
{
	pidData->I = 0;
}

void GetP(struct PID* pidData)
{
	pidData->P = pidData->kP * pidData->error;
}

void GetI(struct PID* pidData)
{
	pidData->I += pidData->kI * pidData->error;
	pidData->I = constrain_int32(pidData->I, -pidData->Imax, +pidData->Imax);	
}
void GetD(struct PID* pidData)
{
	pidData->D = pidData->kD * pidData->derror;
}

void GetPI_OUT(struct PID* pidData)
{
	pidData->out = pidData->P + pidData->I;
	pidData->out = constrain_int32(pidData->out, -pidData->outmax, +pidData->outmax);	
}

void GetPID_OUT(struct PID* pidData)
{
	pidData->out = pidData->P + pidData->I + pidData->D;
	pidData->out = constrain_int32(pidData->out, -pidData->outmax, +pidData->outmax);	
}


int PID_ROLL(int roll)
{
	static float lastError=0;
	static float Ierror=0;
	float Derror=0;
	float error=0;
	int out=0;
	
	error=0-roll;
	Derror=error-lastError;
	lastError=error;
	Ierror+=error;
	if(Ierror>40)  Ierror=40;
	if(Ierror<-40) Ierror=-40;
	
	out=(int)(P_ROLL*error+I_ROLL*error+D_ROLL*Derror);

	if(out>80)out=80;
	if(out<-80)out=-80;
	return out;
}

int PID_PITCH(int pitch)
{
	static float lastError=0;
	static float Ierror=0;
	float Derror=0;
	float error=0;
	int out=0;
	
	error=0-pitch;
	Derror=error-lastError;
	lastError=error;
	Ierror+=error;
	if(Ierror>40)  Ierror=40;
	if(Ierror<-40) Ierror=-40;
	
	out=(int)(P_PITCH*error+I_PITCH*error+D_PITCH*Derror);

	if(out>60)out=60;
	if(out<-60)out=-60;
	return out;
}

int PID_YAW(int yaw)
{
	static float lastError=0;
	static float Ierror=0;
	float Derror=0;
	float error=0;
	int out=0;
	
//	error=ROV_CMD.yawSpeed.value-yaw;
	error=0-yaw;
	Derror=error-lastError;
	lastError=error;
	Ierror+=error;
	if(Ierror>100)  Ierror=100;
	if(Ierror<-100) Ierror=-100;
	
	out=(int)(P_YAW*error+I_YAW*error+D_YAW*Derror);

	if(out>100)out=100;
	if(out<-100)out=-100;
	return out;
}

