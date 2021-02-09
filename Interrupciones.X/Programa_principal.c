/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 1 de febrero de 2021, 08:25 PM
 */

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "Interrupciones.h"

extern uint8_t x;

/*
#include <stdint.h>
int8_t -> int 8 bits = -127 +127
uint8_t -> unsigned int 8 bits -> 0 al 255

int -> 16 bits

microcontrolador 16 bits
int -> 32 bits*/
unsigned char display[10]={0x3F, 0x06, 0x5B, 0x4F, 0x66, 0x6D, 0x7D, 0x07, 0x7F, 0x67};
int uni = 0, dec =0, cen = 0;

void main(void) {
    Int_Init();
    TRISA = 0x00;
    TRISD = 0x00;
    LATD = 0x00;
    LATAbits.LA0 = 0;
    LATAbits.LA1 = 0;
    while(1){
        /*for(int i = 0;i<999;i++){
            cen = i/100;
            LATAbits.LA0 = 1;
            LATD = display[cen];
            __delay_ms(20);
            LATAbits.LA0 = 0;
            dec = i/10;// 110 /10 = 11 
            if(dec>=10){
                dec = dec%10; //11/10 -> 1
            }
            LATAbits.LA1 = 1;
            LATD = display[dec];
            __delay_ms(20);
            LATAbits.LA1 = 0;
            uni = i%10; //-> 54/10 = 5 4  
            LATAbits.LA2 = 1;
            LATD = display[uni];
            __delay_ms(20);
            LATAbits.LA2 = 0;
        }*/
        
        if(x == 1){
            LATAbits.LA0 = 1;
            LATAbits.LA1 = 0;
            LATD = display[4];
            __delay_ms(250);
        }
        if(x == 2){
            for(int i = 0;i<999;i++){
                cen = i/100;
                LATAbits.LA0 = 1;
                LATD = display[cen];
                __delay_ms(20);
                LATAbits.LA0 = 0;
                dec = i/10;// 110 /10 = 11 
                if(dec>=10){
                    dec = dec%10; //11/10 -> 1
                }
                LATAbits.LA1 = 1;
                LATD = display[dec];
                __delay_ms(20);
                LATAbits.LA1 = 0;
                uni = i%10; //-> 54/10 = 5 4  
                LATAbits.LA2 = 1;
                LATD = display[uni];
                __delay_ms(20);
                LATAbits.LA2 = 0;
            }
        }
    }    
    return;
}
