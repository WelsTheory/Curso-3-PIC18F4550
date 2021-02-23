
#include <xc.h>
#include "Configuracion.h"
#include "ADC_Libreria.h"

void ADC_Init(void){
    ADCON1bits.PCFG = 0b1101; // AN0 y AN1
    ADCON1bits.VCFG = 0b00; // Vss y VDD
    ADCON0bits.CHS = 0b0000;
    // TAD == 0.8uS
    ADCON2bits.ADCS = 0b101; // 16Tosc = 16 * (1/20MHz) = 0.8us
    // Tiempo Adquisición = 2.45us
    ADCON2bits.ACQT = 0b010; //4*TAD = 4 * 0.8 = 3.2us  
    // Tiempo Adq + Tcnv = 3.2us + 8.8us = 12us
    ADCON2bits.ADFM = 1;
    ADCON0bits.ADON = 1;// ADC ON
}

uint16_t ADC_Read(char ch){
    if(ch >= 13){
        ch = 0;
    }
    ADCON0bits.CHS = ch;
    ADCON0bits.GO_NOT_DONE = 1;// Realiza la conversión
    while(ADCON0bits.GO_NOT_DONE);// Todavia no convierte
    return ADRES;
}