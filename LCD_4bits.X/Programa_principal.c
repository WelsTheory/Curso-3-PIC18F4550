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

void main(void) {
    LCD_Init();
    LCD_XY(1,10);
    LCD_Caracter('q');// 'q'
    LCD_XY(0,0);
    LCD_Cadena("Pic18f45");
    __delay_ms(500);
    LCD_Comando(0x01);
    while(1){
        
    }
}    

