#include "loop.h"

static short cnt_200Hz,cnt_100Hz,cnt_50Hz,cnt_20Hz,cnt_15Hz,cnt_1Hz;
int8_t Lock_flag;           //0为上锁，1为解锁
int cnt_MS5837;
//static MS5837_ValueTypeDef MS5837_temp={0,0,0,0.03};

static mavlink_message_t msg;
static uint8_t buf[BUF_LENGTH];

void loop_cnt(void)
{
	cnt_200Hz++;
	cnt_100Hz++;
	cnt_50Hz++;
	cnt_20Hz++;
	cnt_15Hz++;
	cnt_1Hz++;
	cnt_MS5837++;
}	


//姿态内环控制
static void Loop_200Hz(void)
{
	Inner_Loop();
}

//更新遥控信号以及传感器存储数据
static void Loop_100Hz(void)
{
	Updata_set();
}

//姿态外环控制
static void Loop_50Hz(void)
{
#ifdef OUTTERDEBUG
  Usart_SendString( NEO_USARTx, "out loop debug\n");
#endif
	Outer_Loop();
}

//无人机数据发送以及自检
static void Loop_20Hz(void)
{
	  int len;
	
#ifdef JY901DEBUG
	  char str[100];
#endif
	
#ifdef DATASENDDEBUG
	Usart_SendString( NEO_USARTx, "20Hz\n");
#endif
	//进行无人机自检，并发送心跳包
    
	 
	  //发送深度传感器消息,if depth has changed
	  //经过测试，MS5837能够读取传感器的值并进行发送
		 len = MS5837_Send_MAVLink_Message(&msg,buf);
	
	  //发送JY901消息
	  //经过测试，JY901能够正常读取传感器的值并进行发送
#ifdef JY901DEBUG		
    sprintf(str,"pitch=%d,roll=%d,yaw=%d\n",JY901_Angle.Angle[0],JY901_Angle.Angle[1],JY901_Angle.Angle[2]);
		Usart_SendString(NEO_USARTx,str);
#endif
     len = JY901_Send_MAVLink_Message(&msg,buf);
    
		 
	
//发送JY901消息
//经过测试，JY901能够正常读取传感器的值并进行发送
#ifdef JY901DEBUG		
	sprintf(str,"roll=%f,yaw=%f,pitch=%f\n",JY901_Angle.Angle[0],JY901_Angle.Angle[1],JY901_Angle.Angle[2]);
	Usart_SendString(NEO_USARTx,str);
#endif
	len = JY901_Send_MAVLink_Message(&msg,buf);
    
}

//MS5837 Deep Sensor Data collection
static void Loop_15Hz(void)
{
	MS5837_Read_From_Part();
}

//向Nanopi发送心跳包,同时检测传感器及无人机状态
static void Loop_1Hz(void)
{
	int len = 0;
	mavlink_msg_heartbeat_pack(1,200,&msg,MAV_TYPE_SUBMARINE,MAV_AUTOPILOT_GENERIC,MAV_MODE_GUIDED_ARMED,0,MAV_STATE_ACTIVE);
	len = mavlink_msg_to_send_buffer(buf, &msg);   //这个编译器有一个问题就是，如果len只是简单幅值，那么是会认为len没有被使用
	Usart_SendArray(NEO_USARTx,(uint8_t *)buf,len);
}	

void ROV_Loop(void)
{
	if( cnt_200Hz >= 5 )
	{
		if( Lock_flag )
			Loop_200Hz();  //姿态内环控制
		cnt_200Hz = 0;
	}
	
	if( cnt_100Hz >= 10 )
	{
		Loop_100Hz(); //更新遥控信号以及传感器存储数据
		cnt_100Hz = 0;
	}
	
	if( cnt_50Hz >= 20 )
	{
		if( Lock_flag )
			Loop_50Hz();     //姿态外环控制
		cnt_50Hz = 0;
	}
	
	if( cnt_20Hz >= 50 )
	{
		Loop_20Hz();
		cnt_20Hz = 0;
	}
	
	if( cnt_15Hz >= 67 )
	{
		Loop_15Hz();
		cnt_15Hz = 0;
	}
	
	if( cnt_1Hz >= 1000)
	{
		Loop_1Hz();
		cnt_1Hz = 0;
	}
}


void cnt_init(void)
{
	cnt_200Hz = 0;
	cnt_100Hz = 0;
	cnt_50Hz = 16;
	cnt_20Hz = 0;
	cnt_15Hz = 0;
	cnt_MS5837 = 0;
	Lock_flag = 1;
}


