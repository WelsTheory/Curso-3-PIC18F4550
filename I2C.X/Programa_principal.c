/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 22 de febrero de 2021, 07:56 PM
 */


#include <xc.h>
#include "Configuracion.h"
#include "I2C_Libreria.h"
#include "DS1307_Libreria.h"
#include "LCD_Libreria.h"

extern char segundos, minutos, horas;

void main(void) {
    LCD_Init();
    I2C_Init();
    LCD_Cadena("Bienvenido");
    LCD_Comando(0x01);
    Escirbir_Hora();
    while(1){
        Leer_Hora();
        LCD_XY(0,0);
        LCD_Caracter(((horas&0xF0)>>4) + '0'); //0x09 0x30 -> 0
        LCD_Caracter((horas&0x0F) + '0');
        LCD_Caracter(':');
        LCD_Caracter(((minutos&0xF0)>>4) + '0'); //0x09 0x30 -> 0
        LCD_Caracter((minutos&0x0F) + '0');
        LCD_Caracter(':');
        LCD_Caracter(((segundos&0xF0)>>4) + '0'); //0x09 0x30 -> 0
        LCD_Caracter((segundos&0x0F) + '0');
        __delay_ms(100);
    }
    return;
}

//I2C_Start();
//        I2C_Tx(0x41);//DIR + RW
//        I2C_ACK();
//        LATD = I2C_Rx();
//        I2C_NACK();
//        I2C_Stop();
//        __delay_ms(200);
////        for(char i=0;i<17;i++){
////            I2C_Start();
////            I2C_Tx(0x40);// dir + RW
////            I2C_ACK();
////            I2C_Tx(i);//0b11100
////            I2C_ACK();
////            I2C_Stop();
////            __delay_ms(200);
////        }
