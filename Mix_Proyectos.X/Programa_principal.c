/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 1 de febrero de 2021, 08:25 PM
 */

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "LCD_Libreria.h"
#include "Interrupciones.h"
#include "Timer_Libreria.h"

extern uint8_t x;

void main(void) {
    LCD_Init();
    Int_Init();
    Timer0_Init();
    while(1){
        if(x == 1){
            LCD_XY(0,0);
            LCD_Cadena("HOLA :D");
            __delay_ms(500);
            x = 2;
        }
        if(x == 2){
            LCD_XY(0,0);
            LCD_Cadena("ACTIVAMOS PWM");
        }
        if(x == 3){
            x = 0;
            LCD_Comando(0x01);
        }
        
    }
}    

