#include "Delay.h"

void delay1ms(u16 y)	 
{
	u16 x;
	for( ; y>0; y--)
	{
		for(x=110; x>0; x--);
	}
}
void Lcd1602_Delay1ms(u16 c)  
{
    u8 a,b;
	for (; c>0; c--)
	{
		 for (b=199;b>0;b--)
		 {
		  	for(a=1;a>0;a--);
		 }      
	}   	
}
void delayus(u16 i)
{
	while(i--);	
}  
