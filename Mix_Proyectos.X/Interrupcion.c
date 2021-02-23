
#include <xc.h>
#include <stdint.h>
#include "Interrupciones.h"
#include "LCD_Libreria.h"

uint8_t x = 0;
uint8_t i = 0;

void Int_Init(void){
    TRISBbits.RB0 = 1;// Entrada
//    TRISBbits.RB1 = 1;// Entrada
    INTCONbits.INT0IE = 1; //Habilitando Int0
//    INTCON3bits.INT1E = 1; //Habilitando Int1
    INTCONbits.INT0IF = 0; //Limpiar Flag INT0
//    INTCON3bits.INT1F = 0; //Flag limpiar INT1
    INTCON2bits.INTEDG0 = 0; // Descendente
//    INTCON2bits.INTEDG1 = 0; // 
    RCONbits.IPEN = 1; //Habilitar Prioridades
//    INTCON3bits.INT1P = 0;//Prioridad baja
    INTCONbits.GIEL = 1; //Int Periféricos
    INTCONbits.GIEH = 1; //Int Globales
}

//Vector de interrupcion
void __interrupt(high_priority) INT0_ISR(void){
    if(x == 2){
        x = 3;
        T0CONbits.TMR0ON = 0;
        LATDbits.LATD0 = 0;
    }
    if(x == 0){
        T0CONbits.TMR0ON = 1;
        x = 1;
    }
    INTCONbits.INT0IF = 0;
}

void __interrupt(low_priority) TMR0_ISR(void){    
    TMR0L = 60;
    if(i == 10){
        LATDbits.LATD0 = ~LATDbits.LATD0;
        i =0;
    }
    i++;
    INTCONbits.TMR0IF = 0;
}