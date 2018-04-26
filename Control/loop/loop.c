#include "loop.h"

static short cnt_200Hz,cnt_100Hz,cnt_50Hz,cnt_20Hz,cnt_10Hz,cnt_1Hz;
int cnt_MS5837;
static MS5837_ValueTypeDef MS5837_temp={0,0,0,0.03};

static mavlink_message_t msg;
static uint8_t buf[BUF_LENGTH];

void loop_cnt(void)
{
	cnt_200Hz++;
	cnt_100Hz++;
	cnt_50Hz++;
	cnt_20Hz++;
	cnt_10Hz++;
	cnt_1Hz++;
	cnt_MS5837++;
}	


//姿态内环控制
static void Loop_200Hz(void)
{
	Inner_Loop();
	//Usart_SendString( NEO_USARTx, "200Hz");
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
#ifdef DATASENDDEBUG
	  Usart_SendString( NEO_USARTx, "20Hz\n");
#endif
	  //发送深度传感器消息,if data has changed
	  if(MS5837_temp.depth != MS5837.depth){
		//send the data
		//mavlink_msg_sensor_data_pack(1,200,&msg,MS5837.depth,MS5837.temp,MS5837.pressure,)
		
		//update the data of deep sensor
		    MS5837_temp.depth = MS5837.depth;
		    MS5837_temp.offset = MS5837.offset;
		    MS5837_temp.pressure = MS5837.pressure;
		    MS5837_temp.temp = MS5837.temp;
		
		    mavlink_msg_ms5837_data_pack(1,MAVLINK_MSG_ID_MS5837_DATA,&msg,MS5837.depth,MS5837.temp,MS5837.pressure);
		    len = mavlink_msg_to_send_buffer(buf, &msg);
		    Usart_SendArray(NEO_USARTx,(uint8_t *)buf,len);
		

	}
	//发送JY901消息
	
}

//MS5837 Deep Sensor Data collection
static void Loop_10Hz(void)
{
	MS5837_Read_From_Part();
}

//向Nanopi发送心跳包
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
		Loop_200Hz();
		cnt_200Hz = 0;
	}
	
	if( cnt_100Hz >= 10 )
	{
		Loop_100Hz();
		cnt_100Hz = 0;
	}
	
	if( cnt_50Hz >= 20 )
	{
		Loop_50Hz();
		cnt_50Hz = 0;
	}
	
	if( cnt_20Hz >= 50 )
	{
		Loop_20Hz();
		cnt_20Hz = 0;
	}
	
	if( cnt_10Hz >= 67 )
	{
		Loop_10Hz();
		cnt_10Hz = 0;
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
	cnt_50Hz = 0;
	cnt_20Hz = 0;
	cnt_10Hz = 0;
	cnt_MS5837 = 0;
}


