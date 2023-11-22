// lcd_functions.c
#include <xc.h>
#include "lcd_config.h"
#include "lcd_functions.h"
#include "config.h"

#define _XTAL_FREQ 20000000

// lcd_functions.h
#ifndef LCD_FUNCTIONS_H
#define LCD_FUNCTIONS_H

void LCD_Init();
void LCD_Command(char cmd);
void LCD_Char(char dat);
void LCD_String(const char *str);
void LCD_String_xy(char row, char pos, const char *str);
void LCD_Clear();

#endif

void LCD_Init() {
    TRISB = 0x00; // Configura os pinos do LCD como saídas
    __delay_ms(15);

    LCD_Command(0x02); // Retorna o cursor para a posição inicial
    LCD_Command(0x28); // Configurações para um LCD 4-bits, 2 linhas e fonte 5x7
    LCD_Command(0x0C); // Display ON, Cursor OFF, Blink OFF
    LCD_Command(0x06); // Incrementa o cursor à direita após cada caractere
    LCD_Command(0x01); // Limpa o display
    __delay_ms(2);
}

void LCD_Command(char cmd) {
    RS = 0; // Seleciona o registro de comando
    PORTB = (cmd & 0xF0); // Envia os 4 bits superiores
    EN = 1;
    __delay_ms(1);
    EN = 0;
    PORTB = ((cmd << 4) & 0xF0); // Envia os 4 bits inferiores
    EN = 1;
    __delay_ms(1);
    EN = 0;
}

void LCD_Char(char dat) {
    RS = 1; // Seleciona o registro de dados
    PORTB = (dat & 0xF0); // Envia os 4 bits superiores
    EN = 1;
    __delay_ms(1);
    EN = 0;
    PORTB = ((dat << 4) & 0xF0); // Envia os 4 bits inferiores
    EN = 1;
    __delay_ms(1);
    EN = 0;
}

void LCD_String(const char *str) {
    while (*str) {
        LCD_Char(*str++);
    }
}

void LCD_String_xy(char row, char pos, const char *str) {
    char location = 0;
    if (row < 2 && pos < 16) {
        location = (0x80) + (row * 0x40) + pos;
        LCD_Command(location);
        LCD_String(str);
    }
}

void LCD_Clear() {
    LCD_Command(0x01); // Limpa o display
    __delay_ms(2);
}
