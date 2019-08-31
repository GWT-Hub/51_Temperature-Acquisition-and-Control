#include "Delay.h"
#ifndef __DS18B20_H_
#define __DS18B20_H_

sbit DSPORT=P3^7;				  //DS18B20与单片机的连接的引脚

void Ds18b20Init();				  //DS18B20初始化
void Ds18b20Write(u8);	          //向DS18B20写入命令
void Ds18b20Chang();		      //让DS18B20开始转化数据
void Ds18b20ReadTempCom();		  //发送读取温度命令
u8   Ds18b20ReadByte();			  //读取一字节的数据
int  Ds18b20ReadTemp();			  //读取一个int类型的温度数据
//void DataExchange(int ,u8 *,u8 *) 	
#endif
