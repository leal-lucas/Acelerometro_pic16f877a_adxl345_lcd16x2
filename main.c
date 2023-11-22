#include <xc.h>
#include "config.h"
#include "i2c_functions.h"
#include "lcd_functions.h"
#include "adc_functions.h"

void I2C_Write_ADXL345(int x, int y, int z) {
    I2C_Start();        // Inicia a comunicação I2C
    I2C_Send(0xA6);     // Endereço do ADXL345 em modo de escrita
    I2C_Send(0x32);     // Registrador inicial DATAX0

    // Envia os dados simulados de aceleração nos eixos X, Y, Z
    I2C_Send(x);
    I2C_Send(y);
    I2C_Send(z);

    I2C_Stop();         // Finaliza a comunicação I2C
}

void main(void) {
    // Configurações iniciais
    TRISA = 0xFF;       // Configura as entradas para os potenciômetros
    ADCON1 = 0x0F;      // Configura todas as portas como digitais

    // ...

    while (1) {
        // Lê os valores analógicos dos potenciômetros
        int accelX_simulado = ADC_Read(0);  // Leitura do potenciômetro conectado em RA0
        int accelY_simulado = ADC_Read(1);  // Leitura do potenciômetro conectado em RA1
        int accelZ_simulado = ADC_Read(4);  // Leitura do potenciômetro conectado em RA4

        // Envia os dados simulados via I2C para o PIC
        I2C_Write_ADXL345(accelX_simulado, accelY_simulado, accelZ_simulado);

        // O restante do seu código para processar os dados e exibir no LCD
        // ...

        __delay_ms(25);  // Aguarde um intervalo de tempo (ajuste conforme necessário)
    }
}
