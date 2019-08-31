#include "ESP8266.h"
#include "LCD1602.h"
#include "DS18B20.h"
#include "LED.h"

u8 Display[20]=" Temp   ";	    //LCD屏的显示
u8 receive[30];					//接受WIFI模块发送来的数据

//存放等待发送给WiFi模块的温度数值
u8 num[10];		                
u8 i=0,j=0;

//用于发送温度的给WIFI模块的AT指令
u8 *start="AT+CIPSTART=0,\"TCP\",\"192.168.4.2\",5000\r\n";
u8 *len="AT+CIPSEND=0,6\r\n";

//用于判断手机端需要单片机执行的功能
static u8 btn1=0,btn2=0,btn3=0,btn4=0,btn5=0,btn6=0,btn7=0,btn8=0,btn9=0;

/********************************************************
***********    函 数 名 ：SendToPhone         ***********
***********    功 能    ：发送温度值给WIFI模块  *********
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
********* 函 数 名 ：DataExchange                ********
********* 功 能    ：转换温度数据并存放在数组中  ********
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
	ESP8266_init();		                  //WIFI模块初始化	
	while(1)
	{  
	 	LcdInit();			  //LCD模块初始化
		DataExchange(Ds18b20ReadTemp());  //温度数据转换并存储
		for(i=0;i<15;i++)				  //将数组的元素显示在LCD上
	    {
			LcdWriteData(Display[i]);
			delay1ms(5);	
     	}
		delay1ms(1000);					  //延时1秒

		SendToPhone(btn1);	              //若btn1=1 则发送温度数据给WIFI模块
		voice(btn2);					  //若btn2=1 则使蜂鸣器响起
		light(btn3);					  //若btn3=1 则点亮全部LED等
		flow(btn4);	 					  //若btn4=1 则实现流水灯模式
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
