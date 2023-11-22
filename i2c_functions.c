// i2c_functions.c
#include <xc.h>
#include "i2c_config.h"
#include "i2c_functions.h"
#include "config.h"

void I2C_Init(void) {
    TRISB0 = 1;  // Configura SDA como entrada
    TRISB1 = 1;  // Configura SCL como entrada
    TRISA = 0xFF;  // Configura todos os pinos de RA como entradas
    ADCON1 = 0x06; // Configura os pinos de RA0, RA1 e RA4 como entradas analógicas
    SSPSTAT |= 0x80; // SDA e SCL como entradas
    SSPCON = 0x28; // Habilita o modo I2C, mestre
    SSPCON2 = 0x00; // Não usa interrupção, velocidade padrão
    SSPADD = 49;  // Valor para I2C a 100 kHz
    PIR1bits.SSPIF = 0; // Limpa a flag de interrupção
    PIR2bits.BCLIF = 0; // Limpa a flag de colisão
}

void I2C_Start(void) {
    SEN = 1; // Inicia a condição de START
    while(SEN); // Espera até a condição de START ser concluída
}

void I2C_Stop(void) {
    PEN = 1; // Inicia a condição de STOP
    while(PEN); // Espera até a condição de STOP ser concluída
}

void I2C_Restart(void) {
    RSEN = 1; // Inicia a condição de RESTART
    while(RSEN); // Espera até a condição de RESTART ser concluída
}

void I2C_Ack(void) {
    ACKDT = 0; // Configura para ACK
    ACKEN = 1; // Inicia a condição de ACK
    while(ACKEN); // Espera até a condição de ACK ser concluída
}

void I2C_Nak(void) {
    ACKDT = 1; // Configura para NAK
    ACKEN = 1; // Inicia a condição de NAK
    while(ACKEN); // Espera até a condição de NAK ser concluída
}

void I2C_Wait(void) {
    while ((SSPCON2 & 0x1F) || (SSPSTAT & 0x04));
}

void I2C_Send(unsigned char data) {
    SSPBUF = data; // Envia o byte
    while(BF); // Espera até o buffer estar vazio
}

unsigned char I2C_Read(void) {
    unsigned char data;

    I2C_Wait(); // Espera até a comunicação estar pronta
    RCEN = 1;    // Habilita a recepção
    while(!BF);  // Espera até o buffer estar cheio
    return SSPBUF; // Retorna o byte recebido
}

// i2c_functions.h
#ifndef I2C_FUNCTIONS_H
#define I2C_FUNCTIONS_H

// Outras declarações de funções...

void I2C_Wait(void);

#endif
