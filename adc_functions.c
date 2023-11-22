// adc_functions.c
#include "adc_functions.h"

// Implementa��o da fun��o para ler o valor ADC de um determinado canal
int ADC_Read(unsigned char channel) {
    ADCON0 = (channel << 2) | 0x01; // Seleciona o canal e inicia a convers�o
    while (GO_nDONE); // Aguarda a convers�o ser conclu�da
    return (ADRESH << 8) | ADRESL; // Retorna o resultado da convers�o
}
