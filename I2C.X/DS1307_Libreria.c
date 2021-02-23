
#include <xc.h>
#include "I2C_Libreria.h"
#include "DS1307_Libreria.h"
#include "Configuracion.h"

char set[6] ={'1','9','2','3','0','0'};
char horas, minutos, segundos =0;

void Escirbir_Hora(void){

    horas = ((set[0]&0x0F)<<4) + (set[1]&0x0F); // 0x10 + 0x08 = 0x18
    /*
     *    = 0x31 & 0x0F = 0x01 << 4 = 0x10
     *    = 0x38 & 0x0F = 0x08
     */
    minutos = ((set[2]&0x0F)<<4) + (set[3]&0x0F);
    segundos = ((set[4]&0x0F)<<4) + (set[5]&0x0F);
    I2C_Start();
    I2C_Tx(0b11010000);// DIR + RW
    I2C_ACK();
    I2C_Tx(0b00000000);//REGISTRO 0 SEC
    I2C_Tx(segundos);//'1' 0x31
    I2C_Tx(minutos);
    I2C_Tx(horas);
    I2C_Stop();
}

void Leer_Hora(void){
    I2C_Start();
    I2C_Tx(0b11010000);// DIR + RW
    I2C_ACK();
    I2C_Tx(0b00000000);//REGISTRO 0 SEC
    I2C_Restart();
    I2C_Tx(0b11010001);// DIR + RW
    I2C_ACK();
    segundos = I2C_Rx();
    I2C_ACK();
    minutos = I2C_Rx();
    I2C_ACK();
    horas = I2C_Rx();
    I2C_NACK();
    I2C_Stop();
}