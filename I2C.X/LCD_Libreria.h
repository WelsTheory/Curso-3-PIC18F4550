
// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef LCD_H //HEADER
#define	LCD_H //HEADER

#include <xc.h> // include processor files - each processor file is guarded.  

#define LCD_PORT    LATD // D4 D5 D6 D7
#define LCD_TRIS    TRISD
#define RS          LATDbits.LATD2 // RD2 
#define E           LATDbits.LATD3 // RD3
//#define RW -> GND -> escribir

void LCD_Init(void);
void LCD_Comando(char cmd);
void LCD_XY(int x, int y);
void LCD_Caracter(char data);
void LCD_Cadena(char *dat);

#endif	/* XC_HEADER_TEMPLATE_H */

