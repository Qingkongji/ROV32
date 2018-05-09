#ifndef _PID_H_
#define _PID_H_

#include "stm32f10x.h"

struct PID
{
	float kP;
	float kI;
	float kD;
	float dt;
	float P;
	float I;
	float D;
	float set;
	float feedback;
	float last_error;
	float error;
	float derror;
	int32_t Imax;
	int32_t outmax;
	float out;
};


int PID_ROLL(int roll);
int PID_YAW(int yaw);
int PID_PITCH(int pitch);

void PIDdataInit(struct PID* pidData,float kp,float ki,float kd,int32_t imax,int32_t outmax);
void PIDdataUpdate(struct PID* pidData);
void Reset_set(struct PID* pidData, float Newset);
void ResetI(struct PID* pidData);
void GetP(struct PID* pidData);
void GetI(struct PID* pidData);
void GetD(struct PID* pidData);
void GetPI_OUT(struct PID* pidData);
void GetPID_OUT(struct PID* pidData);

extern struct PID pidData_pitch_angle;
extern struct PID pidData_roll_angle;
extern struct PID pidData_yaw_angle;

extern struct PID pidData_pitch_w;
extern struct PID pidData_roll_w;
extern struct PID pidData_yaw_w;

extern struct PID pidData_deep;


#endif

