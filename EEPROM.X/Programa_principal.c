/*
 * File:   Programa_principal.c
 * Author: Wels
 *
 * Created on 1 de febrero de 2021, 08:25 PM
 */

#include <xc.h>
#include <stdint.h>
#include "Configuracion.h"
#include "EEPROM_Libreria.h"

void main(void) {
    TRISD = 0x00;
    EEPROM_Write(0x0F,0xAA);
    LATD = EEPROM_Read(0x0F);
    while(1){
        
        
    }
}    

