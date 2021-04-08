/*
 * rutinasLed.c
 *
 * Created: 14/09/2018 12:42:50 a. m.
 *  Author: Patricio
 */
#include "Funciones_P1_E3.h"

void rutina_LED_juego(unsigned char n,unsigned char lista[nivel_max])
{
    for (int h=0;h<=n;h++) //Enciende la secuencia guardada hasta ese nivel
    {
        LEDs = ~lista[h]; //Escribe el valor del elemento
        delays_ms(delay_500); //Espera 500ms con el led prendido
        LEDs_OFF;
        delays_ms(delay_500); //Espera 500ms con el led apagado
    }
}

void rutina_LED_ganador()
{
    for (int h=0;h<5;h++) //Rutina de ganador
    {
        LEDs = 0xAA;
        delays_ms(delay_200); //Espera 1s con el led prendido
        LEDs = 0x55;
        delays_ms(delay_200); //Espera 1s con el led prendido
    }
}

void rutina_LED_perdedor()
{
    for (int h=0;h<4;h++) //Rutina de perdedor
    {
        LEDs_OFF;
        delays_ms(delay_150); //Espera 1s con el led prendido
        LEDs_ON;
        delays_ms(delay_150); //Espera 1s con el led prendido
    }
}

void rutina_LED_cambio()
{
    for (int h=0;h<4;h++) //Rutina de perdedor
    {
        LEDs_ON;
        delays_ms(delay_150); //Espera 1s con el led prendido
        LEDs_OFF;
    }
}
