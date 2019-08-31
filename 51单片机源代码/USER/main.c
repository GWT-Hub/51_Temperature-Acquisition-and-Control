#include "ESP8266.h"
#include "LCD1602.h"
#include "DS18B20.h"
#include "LED.h"

u8 Display[20]=" Temp   ";	    //LCD������ʾ
u8 receive[30];					//����WIFIģ�鷢����������

//��ŵȴ����͸�WiFiģ����¶���ֵ
u8 num[10];		                
u8 i=0,j=0;

//���ڷ����¶ȵĸ�WIFIģ���ATָ��
u8 *start="AT+CIPSTART=0,\"TCP\",\"192.168.4.2\",5000\r\n";
u8 *len="AT+CIPSEND=0,6\r\n";

//�����ж��ֻ�����Ҫ��Ƭ��ִ�еĹ���
static u8 btn1=0,btn2=0,btn3=0,btn4=0,btn5=0,btn6=0,btn7=0,btn8=0,btn9=0;

/********************************************************
***********    �� �� �� ��SendToPhone         ***********
***********    �� ��    �������¶�ֵ��WIFIģ��  *********
*********************************************************/
void SendToPhone(u8 i)
{
 	if(i==1)
	{
		u8 *dat;
		SendData(start);
		SendData(len);
		num[6]='\r';num[7]='\n';
		dat=num;
		SendData(dat);
	}
}
/********************************************************
********* �� �� �� ��DataExchange                ********
********* �� ��    ��ת���¶����ݲ������������  ********
*********************************************************/
void DataExchange(int temp) 	 	   
{
   	float tp;  
	if(temp< 0)			
  	{
		Display[8] = '-'; 
		num[0] = Display[8]; 	 
		temp=temp-1;
		temp=~temp;
		tp=temp;
		temp=tp*0.0625*100+0.5;	
  	}
 	else
  	{			
		Display[8] = '+';
		num[0] = Display[8];
		tp=temp;
		temp=tp*0.0625*100+0.5;	
	}
	Display[9] = (temp % 10000 / 1000)+0x30;   num[1] = Display[9];
	Display[10] = (temp % 1000 / 100)+0x30;    num[2] = Display[10];
	Display[11] = '.';					       num[3] = Display[11];
	Display[12] = (temp % 100 / 10)+0x30;	   num[4] = Display[12];
	Display[13] = (temp % 10)+0x30;			   num[5] = Display[13];
	Display[14] = 'C';
}

void main()
{
	ESP8266_init();		                  //WIFIģ���ʼ��	
	while(1)
	{  
	 	LcdInit();			  //LCDģ���ʼ��
		DataExchange(Ds18b20ReadTemp());  //�¶�����ת�����洢
		for(i=0;i<15;i++)				  //�������Ԫ����ʾ��LCD��
	    {
			LcdWriteData(Display[i]);
			delay1ms(5);	
     	}
		delay1ms(1000);					  //��ʱ1��

		SendToPhone(btn1);	              //��btn1=1 �����¶����ݸ�WIFIģ��
		voice(btn2);					  //��btn2=1 ��ʹ����������
		light(btn3);					  //��btn3=1 �����ȫ��LED��
		flow(btn4);	 					  //��btn4=1 ��ʵ����ˮ��ģʽ
	}
}
 void Uart() interrupt 4
{
   if(RI == 1)   
	{
    	RI = 0;     
		receive[j]=SBUF;
		if(receive[0]=='+') 	j++;
		else                    j=0;

		if(j==10)
		{
			j=0;
			switch(receive[9])
			{
				case '1':
					btn1=exchange(btn1);break;
				case '2':		  
					btn2=exchange(btn2);break;
				case '3':		    
					btn3=exchange(btn3);
					led1=1;led2=1;led3=1;led4=1;led5=1;
					break;
				case '4':		      
					btn4=exchange(btn4);
					led1=1;led2=1;led3=1;led4=1;led5=1;
					break;
				case '5':		     
					btn5=exchange(btn5);
					if(btn5==1)  led1=0;
					else         led1=1;
					break;
				case '6':		      
					btn6=exchange(btn6);
					if(btn6==1)  led2=0;
					else         led2=1;   break;
				case '7':		     
					btn7=exchange(btn7);
					if(btn7==1)  led3=0;
					else         led3=1;   break;
				case '8':		     
					btn8=exchange(btn8); 
					if(btn8==1)  led4=0;
					else         led4=1;   break;
				case '9':
					btn9=exchange(btn9);
					if(btn9==1)  led5=0;
					else         led5=1;    break;
				default:break;
			}
		}
	}	
}
