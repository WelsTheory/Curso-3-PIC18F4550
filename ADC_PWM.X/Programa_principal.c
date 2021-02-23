/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 15 de febrero de 2021, 07:41 PM
 */


#include <xc.h>
#include <stdint.h>
#include <stdio.h>
#include "Interrupciones.h"
#include "ADC_Libreria.h"
#include "Configuracion.h"
#include "LCD_Libreria.h"
#include "PWM.h"

uint16_t valor_adc = 0;
float vin = 0.0;// double
char datos[16];

extern uint8_t x;

void main(void) {
    TRISAbits.RA1 = 1;
    TRISAbits.RA0 = 1;
    //LCD_Init();
    ADC_Init();
    PWM_Init();
    //Int_Init();
    while(1){
        //PWM = CCPR1L + 2 BITS -> CCPR1H 
        //ADC = ADRESH + ADRESL
        valor_adc = ADC_Read(0);// ADRES + ADREL -> 16 bits
        if(valor_adc == 312){
            valor_adc = 311;
        }
        if(valor_adc == 0){
            valor_adc = 1;
        }
        CCPR1L = (valor_adc>>8);//(valor_adc<<8); //0B 0000000 00101110
        CCP1CONbits.DC1B = ((valor_adc>>6)); // 00000011
        __delay_ms(20);
    }
    return;
}
