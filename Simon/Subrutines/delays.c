/*
 * delay.c
 *
 * Created: 13/09/2018 11:40:50 a. m.
 *  Author: Patricio
 */ 

#include "Funciones_P1_E3.h"

void delays_ms(unsigned int tiempo_ms)
{
    for (unsigned int i=0;i<tiempo_ms;i++)
    {
        TCCR0 = 0X03; //Timer0, Normal Mode, prescaler 64
        TCNT0 = 0x83; //Load TCNT0 to count 1ms --> 1000us/(64*0.125us) = 125 counts
        while((TIFR&0x1)==0); //Wait for TF0 to roll over
        TCCR0 = 0;
        TIFR = 0x1; //Clear TF0
    }
}
