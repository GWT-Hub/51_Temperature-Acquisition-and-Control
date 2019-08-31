#include "Delay.h"
#ifndef __LCD1602_H_
#define __LCD1602_H_


#define LCD1602_DATAPINS P0
sbit LCD1602_E=P2^7;			 //LCD1602ʹ������
sbit LCD1602_RW=P2^5;			 //LCD1602��дѡ�������
sbit LCD1602_RS=P2^6;			 //LCD1602��������ѡ�������


void Lcd1602_Delay1ms(u16 );     //��ʱ����
void LcdWriteCom(u8 );	         //��LCD1602д��8λ����
void LcdWriteData(u8 );	         //��LCD1602д��8λ��	
void LcdInit();					 //LCD1602��ʼ��	  

#endif
