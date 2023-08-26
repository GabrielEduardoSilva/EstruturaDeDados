//
//  10.c
//  Atividade4-ListaDeAtividades
//
//  Created by Gabriel Eduardo on 26/08/23.
//

// Crie uma struct chamada "Moeda" que possa armazenar valores em dólares e euros. Escreva um programa que permita ao usuário escolher uma moeda e converter um valor entre dólares e euros, usando a taxa de câmbio atual.

#include <stdio.h>
#include <stdbool.h>

struct Moeda {
    float dolares;
    float euros;
};

float converterDolaresParaEuros(float valorDolares, float taxaCambio) {
    return valorDolares * taxaCambio;
}

float converterEurosParaDolares(float valorEuros, float taxaCambio) {
    return valorEuros / taxaCambio;
}

int main(void) {
    struct Moeda moeda1;
    float taxaCambio;

    printf("Digite a taxa de câmbio (1 dólar = x euros): ");
    scanf("%f", &taxaCambio);

    printf("Digite o valor em dólares: ");
    scanf("%f", &moeda1.dolares);

    moeda1.euros = converterDolaresParaEuros(moeda1.dolares, taxaCambio);

    printf("Valor em Euros: %.2f\n", moeda1.euros);

    printf("Digite o valor em euros: ");
    scanf("%f", &moeda1.euros);

    moeda1.dolares = converterEurosParaDolares(moeda1.euros, taxaCambio);

    printf("Valor em Dólares: %.2f\n", moeda1.dolares);

    return 0;
}
