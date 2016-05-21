#include <avr/io.h>
#include "lcd_lib.h"
#include <util/delay.h>
#include<stdio.h>
#include<adc_lib.h>

void main(void)
{
	int x,y,flag,z,i;
	char a[15];
		ADCinit();// Initializes ADC in 10 bit mode
		LCDinit();
		LCDclr( );
		DDRD = 0xFF;
		DDRA=00;
		while (1)
		{
			z = read_adc(2);
			y = read_adc(1);
			x = read_adc(0);

			LCDGotoXY(0,0);
			sprintf(a,"Value = %d",x);
			LCDdisplay(a);
			_delay_ms(300);
			LCDclr( );
			if(x<500)
			{
				flag = 1;
				for(i=0;i<10;i++)
				{
			   _delay_ms(1000);
                PORTD = 0x05;//for1010
				_delay_ms(30);
				PORTD = 0x00;
				_delay_ms(30);
				PORTD = 0x0A;//0101
				_delay_ms(40);
				PORTD = 0x00;
				_delay_ms(30);
				}

			}


			else if(z<500&& flag==1)
			{
				for(i=0;i<5;i++)
				{
					_delay_ms(1000);
			PORTD = 0x0A;//for1010
			_delay_ms(30);
			PORTD = 0x00;
			_delay_ms(30);
			PORTD = 0x05;//0101
			_delay_ms(40);
			PORTD = 0x00;
			_delay_ms(30);
				}

			}
			else if(y<500)
			{
				for(i=0;i<5;i++)
				{
					_delay_ms(1000);
				flag = 0;
				PORTD = 0x0A;//for1010
				_delay_ms(30);
				PORTD = 0x00;
				_delay_ms(30);
				PORTD = 0x05;//0101
				_delay_ms(40);
				PORTD = 0x00;
				_delay_ms(30);
				}

			}
			else
			{
				PORTD = 0x00;
				_delay_ms(400);
			}
		}






}
