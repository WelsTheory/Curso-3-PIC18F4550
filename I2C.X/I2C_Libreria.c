
#include <xc.h>
#include "I2C_Libreria.h"
#include "Configuracion.h"

void I2C_Init(void){
    SSPADD = 49; // 100KHz
    TRISBbits.RB0 = 1;
    TRISBbits.RB1 = 1;
    
    SSPSTATbits.SMP = 1;//100KHz
    SSPSTATbits.CKE = 0;
    
    SSPCON1bits.SSPEN = 1; //SDA y SCL
    SSPCON1bits.SSPM = 0b1000;// Maestro
    
    SSPCON2 = 0x00;//
}

void I2C_Start(void){
    SSPCON2bits.SEN = 1;// Inicia condicion Start
    while(SSPCON2bits.SEN == 1);
}

void I2C_Stop(void){
    SSPCON2bits.PEN = 1;// Inicia condicion Stop
    while(SSPCON2bits.PEN == 1);
}

void I2C_Restart(void){
    SSPCON2bits.RSEN = 1;// Inicia condicion ReStart
    while(SSPCON2bits.RSEN == 1);
}

void I2C_ACK(void){
    PIR1bits.SSPIF = 0;// Interrupcion I2C
    SSPCON2bits.ACKDT = 0; // ACK
    SSPCON2bits.ACKEN = 1;// Habilitamos ACK
    while(PIR1bits.SSPIF == 0);// eSPERANDO QUE LLEGUE ACK
    PIR1bits.SSPIF = 0;//LLEGÓ y limpias la bandera
}

void I2C_NACK(void){
    PIR1bits.SSPIF = 0;// Interrupcion I2
    SSPCON2bits.ACKDT = 1; // NACK
    SSPCON2bits.ACKEN = 1;// Habilitamos ACK
    while(PIR1bits.SSPIF == 0);// eSPERANDO QUE LLEGUE ACK
    PIR1bits.SSPIF = 0;//LLEGÓ y limpias la bandera
}

void I2C_Tx(char data){
    SSPBUF = data;
    while(PIR1bits.SSPIF == 0);// eSPERANDO QUE LLEGUE ACK
    PIR1bits.SSPIF = 0;//LLEGÓ y limpias la bandera
}

char I2C_Rx(void){
    PIR1bits.SSPIF = 0;
    SSPCON2bits.RCEN = 1; // Habilitando Recepción
    while(PIR1bits.SSPIF == 0);// eSPERANDO QUE LLEGUE ACK
    PIR1bits.SSPIF = 0;//LLEGÓ y limpias la bandera
    return SSPBUF;
}

