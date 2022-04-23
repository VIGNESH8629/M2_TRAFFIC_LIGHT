/*
 */

#include <avr/io.h>
#include<util/delay.h>

int main(void)
{
    TCCR0A|=(1<<COM0A0)| (1<<COM0A0)|(1<<WGM00)|(1<<WGM00);
    TCCR1A|=(1<<COM1A1)|(1<<WGM11)|(1<<WGM10);
    TCCR1B|=(1<<WGM12)|(1<<CS11)|(1<<CS10);
    TCCR0B|=(1<<CS01)|(1<<CS00);

    DDRB|= (1<<PB1)|(1<<PB2)|(1<<PB3);
    DDRD|= (1<<PD5)|(1<<PD6)|(1<<PD7);
    DDRC|= (1<<PC0)|(1<<PC1)|(1<<PC2)|(1<<PC3)|(1<<PC4)|(1<<PC5)|(1<<PC6);


    while(1)
    {
       OCR0A=10;
       _delay_ms(200);
       OCR0A=50;
       _delay_ms(200);
       OCR0A=100;
       _delay_ms(200);
       OCR0A=150;
       _delay_ms(200);
       OCR0A=200;
       _delay_ms(200);
       OCR0A=250;
       _delay_ms(200);


    }

    return 0;
}
