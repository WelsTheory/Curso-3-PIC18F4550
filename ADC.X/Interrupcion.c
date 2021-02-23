
#include <xc.h>
#include <stdint.h>
#include "Interrupciones.h"

uint8_t x = 0;

void Int_Init(void){
    TRISBbits.RB0 = 1;// Entrada
    TRISBbits.RB1 = 1;// Entrada
    INTCONbits.INT0IE = 1; //Habilitando Int0
    INTCON3bits.INT1E = 1; //Habilitando Int1
    INTCONbits.INT0IF = 0; //Limpiar Flag INT0
    INTCON3bits.INT1F = 0; //Flag limpiar INT1
    INTCON2bits.INTEDG0 = 0; // Descendente
    INTCON2bits.INTEDG1 = 0; // 
    RCONbits.IPEN = 1; //Habilitar Prioridades
    INTCON3bits.INT1P = 0;//Prioridad baja
    INTCONbits.GIEL = 1; //Int Periféricos
    INTCONbits.GIEH = 1; //Int Globales
}

//Vector de interrupcion
void __interrupt(high_priority) INT0_ISR(void){
    x++;
    if(x >4){
        x = 1;
    }
    INTCONbits.INT0IF = 0;
}

void __interrupt(low_priority) INT1_ISR(void){
    x--;
    if(x == 0){
        x = 4;
    }
    INTCON3bits.INT1F = 0;
}