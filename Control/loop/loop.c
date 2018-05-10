#include "loop.h"

static short cnt_Inner,cnt_Remote,cnt_Outer,cnt_Databack,cnt_Ms5837,cnt_Heartbeat;
int8_t Lock_flag;           //0为上锁，1为解锁
int cnt_MS5837;
//static MS5837_ValueTypeDef MS5837_temp={0,0,0,0.03};

static mavlink_message_t msg;
static uint8_t buf[BUF_LENGTH];

void loop_cnt(void)
{
	cnt_Inner++;
	cnt_Remote++;
	cnt_Outer++;
	cnt_Databack++;
	cnt_Ms5837++;
	cnt_Heartbeat++;
	cnt_MS5837++;
}	


//姿态内环控制
static void Loop_Inner(void)
{
	Inner_Loop();
}

//更新遥控信号以及传感器存储数据
static void Loop_Remote(void)
{
	Updata_set();
}

//姿态外环控制
static void Loop_Outer(void)
{
#ifdef OUTTERDEBUG
  Usart_SendString( NEO_USARTx, "out loop debug\n");
#endif
	Outer_Loop();
}

//无人机数据发送以及自检
static void Loop_Databack(void)
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
static void Loop_Ms5837(void)
{
	MS5837_Read_From_Part();
}

//向Nanopi发送心跳包,同时检测传感器及无人机状态
static void Loop_Heartbeat(void)
{
	int len = 0;
	mavlink_msg_heartbeat_pack(1,200,&msg,MAV_TYPE_SUBMARINE,MAV_AUTOPILOT_GENERIC,MAV_MODE_GUIDED_ARMED,0,MAV_STATE_ACTIVE);
	len = mavlink_msg_to_send_buffer(buf, &msg);   //这个编译器有一个问题就是，如果len只是简单幅值，那么是会认为len没有被使用
	Usart_SendArray(NEO_USARTx,(uint8_t *)buf,len);
}	

void ROV_Loop(void)
{
	if( cnt_Inner >= 20 )
	{
		if( Lock_flag )
			Loop_Inner();  //姿态内环控制 50Hz
		cnt_Inner = 0;
	}
	
	if( cnt_Remote >= 10 )
	{
		Loop_Remote(); //更新遥控信号以及传感器存储数据 100Hz
		cnt_Remote = 0;
	}
	
	if( cnt_Outer >= 100 )
	{
		if( Lock_flag )
			Loop_Outer();     //姿态外环控制 10Hz
		cnt_Outer = 0;
	}
	
	if( cnt_Databack >= 50 )
	{
		Loop_Databack();    //数据回传20Hz
		cnt_Databack = 0;
	}
	
	if( cnt_Ms5837 >= 67 )
	{
		Loop_Ms5837();      //MS5837读取 15Hz
		cnt_Ms5837 = 0;
	}
	
	if( cnt_Heartbeat >= 1000)
	{
		Loop_Heartbeat();   //心跳包 1Hz
		cnt_Heartbeat = 0;
	}
}


void cnt_init(void)
{
	cnt_Inner = 0;
	cnt_Remote = 0;
	cnt_Outer = 81;
	cnt_Databack = 0;
	cnt_Ms5837 = 0;
	cnt_Heartbeat = 0;
	cnt_MS5837 = 0;
	Lock_flag = 1;
}


