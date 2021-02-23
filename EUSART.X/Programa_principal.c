/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 16 de febrero de 2021, 07:37 PM
 */


#include <xc.h>
#include <stdio.h>
#include "Configuracion.h"
#include "EUSART_Libreria.h"
#include "Interrupciones.h"
#include "LCD_Libreria.h"
#include "ADC_Libreria.h"

char valor = 0;
extern char datos[16];
extern uint8_t x;
uint16_t valor_adc = 0;
float vin = 0.0;// double
char datos_adc[16];

void main(void) {
    TRISD = 0x00;
    EUSART_Init(31);// 9600
    Int_Init();
    LCD_Init();
    ADC_Init();
    LCD_Cadena("Bienvenido :D");
    __delay_ms(1000);
    while(1){//'1'
//        if(x>= 0 & x<17){
//            LCD_Comando(0x01);
//            LCD_XY(0,0);
//            LCD_Cadena(datos);
//            x = 0;
//        }
        valor_adc = ADC_Read(0);// ADRES + ADREL -> 0X28 0XF0
        vin = (5.0/1023)*valor_adc;
        sprintf(datos_adc,"Voltaje: %0.2fV \n",vin);// vin = 3.85 -> int 
        EUSART_Cadena(datos_adc);// "volatje: 3.85
//        switch(valor){
//            case '1':
//                LATDbits.LATD0 = 1;
//                break;
//            case '0':
//                LATDbits.LATD0 = 0;
//                break;
//        }
        __delay_ms(500);
    }
    return;
}
