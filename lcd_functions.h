// lcd_config.h
#ifndef LCD_CONFIG_H
#define LCD_CONFIG_H

// Configuração de pinos para o LCD
#define RS RC0 // Pino RS
#define EN RC1 // Pino EN
#define D4 RC2 // Pino D4
#define D5 RC3 // Pino D5
#define D6 RC4 // Pino D6
#define D7 RC5 // Pino D7

#endif

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

// lcd_functions.h
#ifndef LCD_FUNCTIONS_H
#define LCD_FUNCTIONS_H

// Outras declarações de funções...

void LCD_Command(char cmd);

#endif
