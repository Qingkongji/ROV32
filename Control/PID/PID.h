#ifndef _PID_H_
#define _PID_H_

#include "stm32f10x.h"

struct PID
{
	uint16_t kP;
	uint16_t kI;
	uint16_t kD;
	uint16_t dt;
	int32_t P;
	int32_t I;
	int32_t D;
	int32_t set;
	int32_t feedback;
	int32_t last_error;
	int32_t error;
	int32_t derror;
	int32_t Imax;
	int32_t outmax;
	int32_t out;
};


int PID_ROLL(int roll);
int PID_YAW(int yaw);
int PID_PITCH(int pitch);

void PIDdataInit(struct PID* pidData,uint16_t kp,uint16_t ki,uint16_t kd,int32_t imax,int32_t outmax);
void PIDdataUpdate(struct PID* pidData);
void Reset_set(struct PID* pidData, int32_t Newset);
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

