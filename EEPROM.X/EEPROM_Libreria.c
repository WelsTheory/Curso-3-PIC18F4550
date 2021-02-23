
#include <xc.h>
#include "Configuracion.h"
#include "EEPROM_Libreria.h"

void EEPROM_Write(char dir, char dato){
    EEADR = dir;
    EEDATA = dato;
    EECON1bits.EEPGD = 0; //EEPROM
    EECON1bits.CFGS = 0; //Configuracion EEPROM
    EECON1bits.WREN = 1; // Habilitar la escritura
    // Pasos requeridos
    EECON2 = 0x55;
    EECON2 = 0xAA;
    EECON1bits.WR = 1; // Inicie la escritura
    EECON1bits.WREN = 0;
}

char EEPROM_Read(char dir){
    EEADR = dir;
    EECON1bits.EEPGD = 0; //EEPROM
    EECON1bits.CFGS = 0; //Configuracion EEPROM
    EECON1bits.RD = 1; //Inicie la lectura
    return EEDATA;
}