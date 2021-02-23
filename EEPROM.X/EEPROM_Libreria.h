

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef EEPROM_H
#define	EEPROM_H

#include <xc.h> // include processor files - each processor file is guarded.  

void EEPROM_Write(char dir, char dato);
char EEPROM_Read(char dir);

#endif	/* XC_HEADER_TEMPLATE_H */

