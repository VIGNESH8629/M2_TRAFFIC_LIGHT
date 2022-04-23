/*
 */

#include <avr/io.h>
#include<util/delay.h>
#include "uart.h"

int main(void)
{
  char data;
 unsigned int ch[]={0x90,0x80,0xF8,0x82,0x92,0x99,0xB0,0xA4,0xF9,0xC0};
 unsigned int i;
 DDRB|= (1<<PB1)|(1<<PB2)|(1<<PB3);
 DDRD|= (1<<PD5)|(1<<PD6)|(1<<PD7);
 DDRC|= (1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3)|(1<<PC4)|(1<<PC5)|(1<<PC6);
 USARTInit(103);

    while(1)
        {
        data=USARTReadChar();
        if(data=='A'){
             for(i=0;i<10;i++){
                PORTC=ch[i];
                _delay_ms(1000);
        }
            PORTB |=(1<<PB1);
		    PORTB &=~(1<<PB2);
		    PORTB &=~(1<<PB3);
		    PORTD |= (1<<PD5);
		    PORTD &=~(1<<PD6);
		    PORTD &=~(1<<PD7);
        for(i=6;i<10;i++)
		{
			PORTC=ch[i];
			_delay_ms(1000);
		}

           PORTB &=~(1<<PB1);
           PORTB |=(1<<PB2);
		   PORTB &=~(1<<PB3);
		   PORTD &=~(1<<PD5);
		   PORTD |=(1<<PD6);
		   PORTD &=~(1<<PD7);
       for(i=0;i<10;i++)
		{
			PORTC=ch[i];
			_delay_ms(1000);
		}

		   PORTB &=~(1<<PB1);
		   PORTB &=~(1<<PB2);
           PORTB |=(1<<PB3);
           PORTD &=~(1<<PD5);
		   PORTD &=~(1<<PD6);
		   PORTD |=(1<<PD7);
        }
    }


    return 0;
}
