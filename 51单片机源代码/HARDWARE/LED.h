#include "intrins.h"
#include "Delay.h"
#ifndef _OTHER_H_
#define _OTHER_H_

#define led P2

sbit beep=P1^5;

sbit led1=P2^4;
sbit led2=P2^3;
sbit led3=P2^2;
sbit led4=P2^1;
sbit led5=P2^0;

void flow(u8 );
void light(u8 );
void voice(u8 );
u8 exchange(u8 );


#endif