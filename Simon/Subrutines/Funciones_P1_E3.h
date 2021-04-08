/*
 * Funciones_P1_E3.h
 *
 * Created: 13/09/2018 11:41:24 a. m.
 *  Author: Patricio
 */

#ifndef FUNCIONES_P1_E3_H_
#define FUNCIONES_P1_E3_H_
#define F_CPU 8000000UL

#include <math.h>
#include <util/delay.h>
#include <avr/io.h>
#include <stdlib.h>
#include <time.h>

#define nivel_max 3 //Numero de niveles en el juego

#define LEDs PORTC	
#define LEDs_ON LEDs=0;	
#define LEDs_OFF LEDs=0xFF;

#define BTNs_PORT PORTA
#define BTNs_PIN PINA	
#define push_0 0	
#define push_1 1	
#define push_2 2	
#define push_3 3	
#define push_4 4	
#define push_5 5	
#define push_6 6	
#define push_7 7

#define delay_150 150
#define delay_200 200
#define delay_1s 1000
#define delay_30 30
#define delay_500 500
#define delay_300 300

void delays_ms(unsigned int tiempo_ms);
unsigned char generate_random();
void rutina_LED_juego(unsigned char n, unsigned char lista[nivel_max]);
void rutina_LED_ganador();
void rutina_LED_perdedor();
void rutina_LED_cambio();
void anti_rebote_pin(volatile unsigned char *puerto, unsigned char pin_num, unsigned char time_delay);

#endif /* FUNCIONES_P1_E3_H_ */
