
#include <xc.h>
#include "EUSART_Libreria.h"
#include "Configuracion.h"

void EUSART_Init(uint8_t baud){// 31
    SPBRG = baud; // 9600 baudios
    BAUDCONbits.BRG16 = 0;
    TXSTAbits.BRGH = 0;
    TXSTAbits.SYNC = 0;//asincrono
    RCSTAbits.SPEN = 1;//TX Y RX
    TXSTAbits.TX9 = 0;// 8 bits
    //Habilitar transmisión
    TXSTAbits.TXEN = 1;
    //Habilitar Recepción
    RCSTAbits.RX9 = 0;//8 bits
    RCSTAbits.CREN = 1;
    PIR1bits.RCIF = 0;
    PIE1bits.RCIE = 1;//habilitando int
    IPR1bits.RCIP = 1;//prioridad alta
}

void EUSART_Cadena(char *dat){
    while(*dat != '\0'){
        EUSART_Tx(*dat);
        dat++;
    }
}


void EUSART_Tx(char data){
    while(!TXSTAbits.TRMT);//lleno
    TXREG = data;    
}

char EUSART_Rx(void){
    return RCREG;
}