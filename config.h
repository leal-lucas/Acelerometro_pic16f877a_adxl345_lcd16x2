// Arquivo: config.h
#include <xc.h>

#define _XTAL_FREQ 20000000  // Substitua pelo valor correto da frequência do seu oscilador

#ifndef CONFIG_H
#define CONFIG_H

// Configurações específicas do PIC16F877A
#pragma config FOSC = HS        // Oscilador externo de cristal
#pragma config WDTE = OFF       // Desativa o Watchdog Timer
#pragma config PWRTE = ON       // Ativa o Power-up Timer
#pragma config BOREN = ON       // Ativa o Brown-out Reset
#pragma config LVP = OFF        // Desativa a programação de baixa tensão
#pragma config CPD = OFF        // Desativa a proteção de código de dados
#pragma config WRT = OFF        // Desativa a proteção de gravação de código
#pragma config CP = OFF         // Desativa a proteção de código

#endif
