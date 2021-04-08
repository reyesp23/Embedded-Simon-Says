/*
 * Proyecto1_E3.c
 *
 * Created: 13/09/2018 11:38:44 a. m.
 * Author : Patricio
 */

#include "Subrutinas/Funciones_P1_E3.h" 

unsigned char nivel=0,status_flag=1,mov_flag,valor_mov,m=0;
unsigned char secuencia[nivel_max];

int main(void) {
    /*INICIALIZACIONES*/
    /*Puertos de salida */
    DDRC=0xFF;	//Puerto B de salida
    LEDs_ON; //LEDs inician encendidos
    /*Puertos de entrada */
    DDRA=0;	//Puerto A de entrada
    BTNs_PORT=0xFF;	//Resistencias de pull-up activas
    
    while (1) {
        LEDs_ON; //LEDs encendidos, el sistema esta listo
        while(((BTNs_PIN|~(1<<push_7))==~(1<<push_7)) == 0); //Se presiona el boton 7 de INICIO
        anti_rebote_pin(&BTNs_PIN,push_7,delay_30); //Rutina antirebote
        LEDs_OFF; //Se apagan los LEDs
        nivel=0; //Juego nuevo, empieza desde nivel 0
        status_flag=1; //El status comienza en 1
        delays_ms(delay_500); //Espera 500ms para comenzar el juego
        
        /*COMIENZA JUEGO*/
        while (nivel<nivel_max && status_flag == 1) {  //Se juega mientras nivel sea menor al max y el status en 1
            /*TURNO DE LA MAQUINA */
            secuencia[nivel] = generate_random(); //Genera un nuevo valor random y lo guarda
            rutina_LED_juego(nivel,secuencia); //Muestra la secuencia LED de ese nivel
            rutina_LED_cambio(); //Rutina LED de cambio de turno
            /*TURNO DEL USUARIO */
            m=0; //Cuenta movimientos del usuario, inicia en 0
            while(m<=nivel && status_flag==1) { //Lee y verifica los movimientos del usuario
                mov_flag=1; //Bandera: esperando un nuevo movimiento del usuario
                while(mov_flag==1) { //Solo corre mientras este esperando un movimiento
                    if ((BTNs_PIN|~(1<<push_0))==~(1<<push_0)) { //Lee push 0
                        anti_rebote_pin(&BTNs_PIN,push_0,delay_30); //Rutina antirebote
                        valor_mov=1; //Guarda el valor del boton presionado
                        mov_flag=0;//Termina el movimiento del usuario
                    }
                    else if ((BTNs_PIN|~(1<<push_1))==~(1<<push_1)) { //Lee push 1
                        anti_rebote_pin(&BTNs_PIN,push_1,30); //Rutina antirebote
                        valor_mov=2; //Guarda el valor del boton presionado
                        mov_flag=0; //Termina el movimiento del usuario
                    }
                    else if ((BTNs_PIN|~(1<<push_2))==~(1<<push_2)) { //Lee push 2
                        anti_rebote_pin(&BTNs_PIN,push_2,delay_30); //Rutina antirebote
                        valor_mov=4; //Guarda el valor del boton presionado
                        mov_flag=0;//Termina el movimiento del usuario
                    }
                    else if ((BTNs_PIN|~(1<<push_3))==~(1<<push_3)) { //Lee push 3
                        anti_rebote_pin(&BTNs_PIN,push_3,delay_30); //Rutina antirebote
                        valor_mov=8; //Guarda el valor del boton presionado
                        mov_flag=0;//Termina el movimiento del usuario
                    }
                    else if ((BTNs_PIN|~(1<<push_4))==~(1<<push_4)) { //Lee push 4
                        anti_rebote_pin(&BTNs_PIN,push_4,delay_30); //Rutina antirebote
                        valor_mov=16; //Guarda el valor del boton presionado
                        mov_flag=0;//Termina el movimiento del usuario
                    }
                    else if ((BTNs_PIN|~(1<<push_5))==~(1<<push_5)) { //Lee push 5
                        anti_rebote_pin(&BTNs_PIN,push_5,delay_30); //Rutina antirebote
                        valor_mov=32; //Guarda el valor del boton presionado
                        mov_flag=0;//Termina el movimiento del usuario
                    }
                    else if ((BTNs_PIN|~(1<<push_6))==~(1<<push_6)) { //Lee push 6
                        anti_rebote_pin(&BTNs_PIN,push_6,delay_30); //Rutina antirebote
                        valor_mov=64; //Guarda el valor del boton presionado
                        mov_flag=0;//Termina el movimiento del usuario
                    }
                    else if ((BTNs_PIN|~(1<<push_7))==~(1<<push_7)) { //Lee push 7
                        anti_rebote_pin(&BTNs_PIN,push_7,delay_30); //Rutina antirebote
                        valor_mov=128; //Guarda el valor del boton presionado
                        mov_flag=0;//Termina el movimiento del usuario
                    }
                } //Termina movimiento del usuario
                /*Verificacion del movimiento del usuario*/
                if (valor_mov == secuencia[m]) {
                    m++; ////El valor coincide, se admite un siguiente movimiento.
                }
                else {
                    status_flag=0; //El valor no coincide, GAME OVER.
                }
            } /*TERMINA TURNO DEL USUARIO*/
            if (status_flag ==1) { //Si el usuario no ha perdido, aumenta el nivel
                nivel++; //Aumenta en 1 el nivel del juego
                delays_ms(delay_300); //Espera 300ms con el led prendido
            }
        } //TERMINA JUEGO
        /*SECUENCIAS FINALES*/
        if (status_flag==1) { //El usuario gano
            rutina_LED_ganador();
        }
        if (status_flag==0) { //El usuario perdio
            rutina_LED_perdedor();
        }
        /*REGRESA AL INICIO*/
    }
}
