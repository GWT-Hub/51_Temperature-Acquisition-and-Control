#include "Delay.h"
#ifndef __LCD1602_H_
#define __LCD1602_H_


#define LCD1602_DATAPINS P0
sbit LCD1602_E=P2^7;			 //LCD1602使能引脚
sbit LCD1602_RW=P2^5;			 //LCD1602读写选择端引脚
sbit LCD1602_RS=P2^6;			 //LCD1602数据命令选择端引脚


void Lcd1602_Delay1ms(u16 );     //延时函数
void LcdWriteCom(u8 );	         //向LCD1602写入8位命令
void LcdWriteData(u8 );	         //向LCD1602写入8位数	
void LcdInit();					 //LCD1602初始化	  

#endif
