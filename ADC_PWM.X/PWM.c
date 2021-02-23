
#include <xc.h>
#include "PWM.h"

void PWM_Init(void){
    PR2 = 77; // PERIODO 250uS
    //CCPR1L + 2 BITS = 313 -> 100%
    /*
     * 313 -> 100%
     *  X  -> 10%
     *  X = 156.5 = 157
     */
    // DUTY CYCLE = CCPR1L + 2 BITS
    CCPR1L = 0b00000000; 
    CCP1CONbits.DC1B = 0b01;
    TRISCbits.RC2 = 0; //CCP1
    T2CONbits.T2CKPS = 0b10;//Prescaler 16 bits
    T2CONbits.TMR2ON = 1;
    CCP1CONbits.CCP1M = 0b1100;
}
