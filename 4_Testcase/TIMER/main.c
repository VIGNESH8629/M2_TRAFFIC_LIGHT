/*
 */

#include <avr/io.h>
#include<avr/interrupt.h>

unsigned volatile overflow;

int main(void)
{
     PORTB|= (1<<PB1)|(1<<PB2)|(1<<PB3);
     PORTD|= (1<<PD5)|(1<<PD6)|(1<<PD7);
     PORTC|= (1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3)|(1<<PC4)|(1<<PC5)|(1<<PC6);
     TCCR0B|=(1<< CS02);
     TIMSK0|=(1<<TOIE0);
     TCNT0=0;
     overflow=0;
     sei();

    while(1)
    {
        if(overflow>=12)
        {
           if(TCNT0>=52)
           {
               PORTB^= (1<<PB1)|(1<<PB2)|(1<<PB3);
               PORTD^= (1<<PD5)|(1<<PD6)|(1<<PD7);
               PORTC^= (1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3)|(1<<PC4)|(1<<PC5)|(1<<PC6);
               TCNT0=0;
               overflow=0;
           }

        }

    }

    return 0;
}
ISR(TIMER0_OVF_vect)
{
    overflow++;
}
