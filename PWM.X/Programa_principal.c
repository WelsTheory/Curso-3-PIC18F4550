/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 1 de febrero de 2021, 08:25 PM
 */

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "PWM.h"

uint16_t duty = 0;

//max 312 = 0b100111001 -> CCPR1L 

void main(void) {
    PWM_Init();
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    while(1){
        if(PORTBbits.RB0 == 0){
            duty++;
            if(duty == 312){
                duty = 311;
            }
            CCPR1L = duty>>2; //0B00101110
            //CCP1CON = ((duty&0x03)<<4)|(CCP1CON&0x0F);
            CCP1CONbits.DC1B = (duty&0x03); // 2 bits 
            /*
             * duty = 0b11001101 AND
             *        0B00000011
             *        0B00000001
             * 
             * <<4    0b00010000
             * 
             * CCP1CON = 0b00001100 AND
             *           0B00001111
             *           0B00001100
             * 
             * 0b00010000 OR 
             * 0B00001100 
             * 0B00011100
             */
            __delay_ms(20);
        }
        if(PORTBbits.RB1 == 0){
            duty--;
            if(duty <= 0){
                duty = 1;
            }
            CCPR1L = duty>>2; //0B00101110
            //CCP1CON = ((duty&0x03)<<4)|(CCP1CON&0x0F);
            CCP1CONbits.DC1B = (duty&0x03);
            __delay_ms(20);
        }
        
    }
}    

