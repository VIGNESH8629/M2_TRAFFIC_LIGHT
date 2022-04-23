/*
 */

#include <avr/io.h>
#include<util/delay.h>
#include <avr/interrupt.h>

static volatile int Echo = 0;
static volatile int i = 0;

int main(void)
{
 unsigned int ch[]={0x90,0x80,0xF8,0x82,0x92,0x99,0xB0,0xA4,0xF9,0xC0};
 unsigned int i;
 int16_t count_a = 0;

 DDRB|= (1<<PB1)|(1<<PB2)|(1<<PB3);
 DDRD|= (1<<PD5)|(1<<PD6)|(1<<PD7)|(1<<PD1)|(1<<PD2);
 DDRC|= (1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3)|(1<<PC4)|(1<<PC5)|(1<<PC6);

  _delay_ms(50);

EICRA|= (1<<ISC00);
EIMSK|= (1<<INT0);

  sei();

  while(1)
    {
       for(i=0;i<10;i++)
       {
                PORTC=ch[i];
                _delay_ms(1000);
        }
            PORTB |=(1<<PB1); //GREEN is ON
		    PORTB &=~(1<<PB2);
		    PORTB &=~(1<<PB3);
		    PORTD |= (1<<PD5);//RED IS ON
		    PORTD &=~(1<<PD6);
		    PORTD &=~(1<<PD7);
		    PORTD |= (1<<PIND1);
            _delay_us(15);

            PORTD &= ~(1<<PIND1);
           count_a = Echo/58;

        for(i=6;i<10;i++)
		{
			PORTC=ch[i]; //7 SEVEN SEGMENT DISPLAY
			_delay_ms(1000);
		}

           PORTB &=~(1<<PB1);
           PORTB |=(1<<PB2);//YELLOW IS ON
		   PORTB &=~(1<<PB3);
		   PORTD &=~(1<<PD5);
		   PORTD |=(1<<PD6);//YELLOW IS ON
		   PORTD &=~(1<<PD7);
		   PORTD |= (1<<PIND1);
            _delay_us(15);

          PORTD &= ~(1<<PIND1);
           count_a = Echo/58;
       for(i=0;i<10;i++)
		{
			PORTC=ch[i];
			_delay_ms(1000);
		}

		   PORTB &=~(1<<PB1);
		   PORTB &=~(1<<PB2);
           PORTB |=(1<<PB3);//RED IS ON
           PORTD &=~(1<<PD5);
		   PORTD &=~(1<<PD6);
		   PORTD |=(1<<PD7);//GREEN IS ON
		   PORTD |= (1<<PIND1); //SENSOR
           _delay_us(15);

           PORTD &= ~(1<<PIND1);
           count_a = Echo/58;

}

    return 0;
}
ISR(INT0_vect)
{
  if(i == 0)
  {
    TCCR1B |= (1<<CS10);
    i = 1;
  }
  else
  {
    TCCR1B = 0;
    Echo = TCNT1L;
    TCNT1L = 0;
    i = 0;
  }
}

