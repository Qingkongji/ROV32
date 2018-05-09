#include "JY901.h"
#include <string.h>

struct SAcc     JY901_Acc;    //加速度
struct SGyro 		JY901_Gyro;   //角速度
struct SAngle 	JY901_Angle;  //角度

void GetDataFromJY901(unsigned char ucData)
{
	static unsigned char ucRxBuffer[250];
	static unsigned char ucRxCnt = 0;	
	
	ucRxBuffer[ucRxCnt++]=ucData;
	
	if (ucRxBuffer[0]!=0x55) //数据头不对，则重新开始寻找0x55数据头
	{
		ucRxCnt=0;
		return;
	}
	if (ucRxCnt<11) { return;}//数据不满11个，则返回
	else
	{
		switch(ucRxBuffer[1])
		{
			case 0x51:  
				          //JY901_Acc.a[0] =()
				          break;
			
			case 0x52:	JY901_Gyro.w[0]=((short)ucRxBuffer[5]<<8|ucRxBuffer[4])/32768.0*2000;      //滚转   roll
									JY901_Gyro.w[1]=((short)ucRxBuffer[7]<<8|ucRxBuffer[6])/32768.0*2000;      //偏航   yaw
			            JY901_Gyro.w[2]=((short)ucRxBuffer[3]<<8|ucRxBuffer[2])/32768.0*2000;      //俯仰   pitch 
									break;
			case 0x53:	
			            JY901_Angle.Angle[0]=((short)ucRxBuffer[5]<<8|ucRxBuffer[4])/32768.0*180;     //滚转   roll 
									JY901_Angle.Angle[1]=((short)ucRxBuffer[7]<<8|ucRxBuffer[6])/32768.0*180;     //偏航   yaw
			            JY901_Angle.Angle[2]=((short)ucRxBuffer[3]<<8|ucRxBuffer[2])/32768.0*180;     //俯仰   pitch  
									break;
			
		}
		ucRxCnt=0;
	}
}

int JY901_Send_MAVLink_Message(mavlink_message_t* msg_p,uint8_t* buf){
    int len;
#ifdef JY901DEBUG
	  char str[100];
	  sprintf(str,"sending mavlink message\n");
		Usart_SendString(NEO_USARTx,str);
#endif
		//send the data
		//mavlink_msg_sensor_data_pack(1,200,&msg,MS5837.depth,MS5837.temp,MS5837.pressure,)
		   
		mavlink_msg_jy901_data_pack(1,MAVLINK_MSG_ID_JY901_DATA,msg_p,JY901_Angle.Angle[0],JY901_Angle.Angle[1],JY901_Angle.Angle[2],\
	                                                                0,0,0,\
	                                                                0,0,0,\
	                                                                0,0,0);              //row,yaw,pitch
	                                                                                             //velocity of row, yaw, pitch
	                                                                                             //acc of x ,y ,z
	                                                                                             //megnatic field intensity of x,y,z
		len = mavlink_msg_to_send_buffer(buf, msg_p);
		Usart_SendArray(NEO_USARTx,(uint8_t *)buf,len);
		

		
		return len;
}


