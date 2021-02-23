
#include <xc.h>
#include "LCD_Libreria.h"
#include "Configuracion.h"

void LCD_Init(void){
    __delay_ms(15);
    LCD_TRIS = 0x00; // Puerto D es salida
    LCD_Comando(0x30);
    __delay_ms(5);
    LCD_Comando(0x30);
    __delay_us(100);
    LCD_Comando(0x32); //MODO 4 bits
    LCD_Comando(0x28);// 2 Lineas 5x8
    LCD_Comando(0x0C);//Display ON - CURSOR OFF
    LCD_Comando(0x01);//Limpiar LCD
    LCD_Comando(0x06);//Incremento no mover
}

void LCD_Comando(char cmd){
    //cmd = 0x38
    LCD_PORT = (LCD_PORT&0X0F) | (cmd&0xF0); //3
    /*
     * cmd = 0x30;
     * LCD_PORT = LCD_PORT&0X0F | (cmd&0xF0)
     * cmd        1111 0000
     *            0011 1000
     *            0011 0000
     *  
     *            0000 0101 AND
     *            0000 1111
     *            0000 0101 OR 
     *            0011 1000
     *            0011 1101  
     * 
     * LCD = 0b 0011 0000; MASCARA
     *     = 0B 0000 1111 = 0X0F
     */
    RS = 0;//Comando
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
    
    LCD_PORT &= 0X0F;//LCD_PORT = LCD_PORT & 0X0F;
    LCD_PORT |= ((cmd&0x0F)<<4); //LCD_PORT = LCD_PORT | ((cmd&0x0F)<<4);
    /*
     * cmd = 0x38 &
     *       0x0F
     *       0x08 << 4
     *       0b 10000000 <<4 |
     *          00001000 
     *          10001000
     */

    RS = 0;//Comando
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
}

void LCD_XY(int x, int y){
    if(x == 1){
        LCD_Comando(0xC0+y);// Linea 2 + y 
    }
    else{
        LCD_Comando(0x80+y);// Linea 1 + y
    }
}

void LCD_Caracter(char data){
    LCD_PORT = (LCD_PORT&0X0F) | (data&0xF0); //3

    RS = 1;//Caracter
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;
    
    LCD_PORT &= 0X0F;//LCD_PORT = LCD_PORT & 0X0F;
    LCD_PORT |= ((data&0x0F)<<4); //LCD_PORT = LCD_PORT | ((cmd&0x0F)<<4);

    RS = 1;//Comando
    __delay_ms(1);
    E = 1;
    __delay_ms(1);
    E = 0;

}

void LCD_Cadena(char *dat){
    //*dat = "Microchip\0"
    // dat = 0x001 + 1 = 0x002 -> *dat = 'i'
    while(*dat != '\0'){
        LCD_Caracter(*dat);
        dat++;
    }
}
