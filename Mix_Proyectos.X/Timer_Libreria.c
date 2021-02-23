
#include <xc.h>
#include "Timer_Libreria.h"

void Timer0_Init(void){
    T0CONbits.T0CS = 0;//Temporizador
    T0CONbits.PSA = 0;//Asignamos el Prescaler
    T0CONbits.T0PS = 0b111;
    T0CONbits.T08BIT = 1; // 8bits TMR0L
    T0CONbits.TMR0ON = 0;// Habilitado TMR0
    //TMR0L = 255 - ((TIEMPO*FOSC)/(4*PRESCALER)) = 59.6875 = 60
    TMR0L = 60;
    INTCONbits.TMR0IE = 1;//Habilitar Int TMR0
    INTCONbits.TMR0IF = 0;
    INTCON2bits.TMR0IP = 0;// Prioridad Baja
}

/*void Timer0_Init(void){
    T0CONbits.T0CS = 0;//Temporizador
    T0CONbits.PSA = 0;//Asignamos el Prescaler
    T0CONbits.T0PS = 0b111;
    T0CONbits.T08BIT = 0; // 16bits TMR0L + TMR0H = TMR0
    T0CONbits.TMR0ON = 1;// Habilitado TMR0
    //TMR0L = 65535 - ((TIEMPO*FOSC)/(4*PRESCALER)) = 46003,75 = 46004
    TMR0 = 46004;
    INTCONbits.TMR0IE = 1;//Habilitar Int TMR0
    INTCONbits.TMR0IF = 0;
    INTCON2bits.TMR0IP = 1;// Prioridad Alta
}*/

void Timer1_Init(void){
    TMR1H = 0x80;
    TMR1L = 0x00;
    T1CON = 0x0F;
    PIE1bits.TMR1IE = 1; //Habilitamos Int
    PIR1bits.TMR1IF = 0;
    IPR1bits.TMR1IP = 1;
}

