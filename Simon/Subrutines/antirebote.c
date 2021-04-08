/*
 * antirebote.c
 *
 * Created: 14/09/2018 11:09:38 a. m.
 *  Author: Patricio
 */ 
#include "Funciones_P1_E3.h"

void anti_rebote_pin(volatile unsigned char *puerto, unsigned char pin_num, unsigned char time_delay)
{
    delays_ms(time_delay);
    while((*puerto|~(1<<pin_num))==~(1<<pin_num));
    delays_ms(time_delay);
}
