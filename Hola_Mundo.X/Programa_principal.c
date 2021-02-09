/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 1 de febrero de 2021, 08:25 PM
 */

#include <xc.h>
#include "Configuracion.h"

void main(void) {
    //TRISD = 0;//0x00//0b00000000;
    TRISDbits.RD0 = 0; //Configurarlo Salida
    TRISDbits.RD1 = 0;
    TRISDbits.RD2 = 0;
    TRISB = 0xFF; //1111 1111
    LATDbits.LATD0 = 1; //Escribir 0 logico -> Enable
    while(1){
        if(PORTBbits.RB0 == 0){
            LATDbits.LATD1 = 1;
            LATDbits.LATD2 = 0;
        }
        else if(PORTBbits.RB1 == 0){
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 1;
        }
        else{
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 0;
        }
        /*
        else{
            LATDbits.LATD1 = 0;
            LATDbits.LATD2 = 1;
        }
        
        */
    }    
    return;
}
