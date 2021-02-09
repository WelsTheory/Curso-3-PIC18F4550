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

extern uint8_t sec, sec_d,min,min_d,hor,hor_d;

void main(void) {
    TRISD = 0x00;
    LCD_Init();
    Timer1_Init();
    Int_Init();
    while(1){
        LCD_XY(0,0);
        LCD_Caracter(hor_d+'0');
        LCD_Caracter(hor+'0');// sec = 4 -> 0x04 + 0x30 = 0x34
        LCD_Caracter(':');
        LCD_Caracter(min_d+'0');
        LCD_Caracter(min+'0');// sec = 4 -> 0x04 + 0x30 = 0x34
        LCD_Caracter(':');
        LCD_Caracter(sec_d+'0');
        LCD_Caracter(sec+'0');// sec = 4 -> 0x04 + 0x30 = 0x34
        __delay_ms(500);
    }
}    

