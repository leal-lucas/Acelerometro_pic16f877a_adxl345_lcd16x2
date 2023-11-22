// Arquivo: config.h
#include <xc.h>

#define _XTAL_FREQ 20000000  // Substitua pelo valor correto da frequ�ncia do seu oscilador

#ifndef CONFIG_H
#define CONFIG_H

// Configura��es espec�ficas do PIC16F877A
#pragma config FOSC = HS        // Oscilador externo de cristal
#pragma config WDTE = OFF       // Desativa o Watchdog Timer
#pragma config PWRTE = ON       // Ativa o Power-up Timer
#pragma config BOREN = ON       // Ativa o Brown-out Reset
#pragma config LVP = OFF        // Desativa a programa��o de baixa tens�o
#pragma config CPD = OFF        // Desativa a prote��o de c�digo de dados
#pragma config WRT = OFF        // Desativa a prote��o de grava��o de c�digo
#pragma config CP = OFF         // Desativa a prote��o de c�digo

#endif
