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

uint16_t valor_adc = 0;
float vin = 0.0;// double
char datos[16];

extern uint8_t x;

void main(void) {
    TRISAbits.RA1 = 1;
    TRISAbits.RA0 = 1;
    LCD_Init();
    ADC_Init();
    Int_Init();
    while(1){
        if(x == 4){
            valor_adc = ADC_Read(0);// ADRES + ADREL -> 0X28 0XF0
            vin = (5.0/1023)*valor_adc;
            sprintf(datos,"Voltaje: %0.2fV",vin);// vin = 3.85 -> int 
            LCD_XY(0,0);
            LCD_Cadena(datos);// "volatje: 3.85
            __delay_ms(100);
        }
        if(x == 3){
            valor_adc = ADC_Read(1);// ADRES + ADREL -> 0X28 0XF0
            vin = (5.0/1023)*valor_adc;
            sprintf(datos,"Voltaje: %0.2fV",vin);// vin = 3.85 -> int 
            LCD_XY(0,0);
            LCD_Cadena(datos);// "volatje: 3.85
            __delay_ms(100);
        }
        if(x == 2){
            valor_adc = ADC_Read(0);// ADRES + ADREL -> 0X28 0XF0
            vin = (5.0/1023)*valor_adc;
            sprintf(datos,"Voltaje: %0.2fV",vin);// vin = 3.85 -> int 
            LCD_XY(0,0);
            LCD_Cadena(datos);// "volatje: 3.85
            __delay_ms(100);
        }
        if(x == 1){
            valor_adc = ADC_Read(1);// ADRES + ADREL -> 0X28 0XF0
            vin = (5.0/1023)*valor_adc;
            sprintf(datos,"Voltaje: %0.2fV",vin);// vin = 3.85 -> int 
            LCD_XY(0,0);
            LCD_Cadena(datos);// "volatje: 3.85
            __delay_ms(100);
        }
     
        
    }
    return;
}
