// adc_functions.c
#include "adc_functions.h"

// Implementação da função para ler o valor ADC de um determinado canal
int ADC_Read(unsigned char channel) {
    ADCON0 = (channel << 2) | 0x01; // Seleciona o canal e inicia a conversão
    while (GO_nDONE); // Aguarda a conversão ser concluída
    return (ADRESH << 8) | ADRESL; // Retorna o resultado da conversão
}
