
#include <xc.h>
#include <stdint.h>
#include "Interrupciones.h"

uint8_t sec = 8, sec_d = 5, min = 9, min_d = 5, hor = 3, hor_d = 2;

void Int_Init(void){
//    TRISBbits.RB0 = 1;// Entrada
//    TRISBbits.RB1 = 1;// Entrada
//    INTCONbits.INT0IE = 1; //Habilitando Int0
//    INTCON3bits.INT1E = 1; //Habilitando Int1
//    INTCONbits.INT0IF = 0; //Limpiar Flag INT0
//    INTCON3bits.INT1F = 0; //Flag limpiar INT1
//    INTCON2bits.INTEDG0 = 0; // Descendente
//    INTCON2bits.INTEDG1 = 0; // 
    RCONbits.IPEN = 1; //Habilitar Prioridades
    INTCON3bits.INT1P = 0;//Prioridad baja
    INTCONbits.GIEL = 1; //Int Periféricos
    INTCONbits.GIEH = 1; //Int Globales
}

//Vector de interrupcion
void __interrupt(high_priority) TMR1_ISR(void){
    TMR1H = 0x80;
    TMR1L = 0x00;
    sec++;
    if(sec >9){
        sec_d++;
        sec =0;
    }
    if(sec_d > 5){
        sec_d = 0;
        min++;
    }
    if(min > 9){
        min = 0;
        min_d++;
    }
    if(min_d > 5){
        min_d = 0;
        hor++;
    }
    if(hor > 9){
        hor = 0;
        hor_d++;
    }
    if(hor_d == 2 & hor == 4){
        hor_d = 0;
        hor =0;
    }
    LATDbits.LATD0 = ~LATDbits.LATD0;
    PIR1bits.TMR1IF = 0;
}

void __interrupt(low_priority) INT1_ISR(void){
    
}