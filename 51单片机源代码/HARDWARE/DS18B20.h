#include "Delay.h"
#ifndef __DS18B20_H_
#define __DS18B20_H_

sbit DSPORT=P3^7;				  //DS18B20�뵥Ƭ�������ӵ�����

void Ds18b20Init();				  //DS18B20��ʼ��
void Ds18b20Write(u8);	          //��DS18B20д������
void Ds18b20Chang();		      //��DS18B20��ʼת������
void Ds18b20ReadTempCom();		  //���Ͷ�ȡ�¶�����
u8   Ds18b20ReadByte();			  //��ȡһ�ֽڵ�����
int  Ds18b20ReadTemp();			  //��ȡһ��int���͵��¶�����
//void DataExchange(int ,u8 *,u8 *) 	
#endif
