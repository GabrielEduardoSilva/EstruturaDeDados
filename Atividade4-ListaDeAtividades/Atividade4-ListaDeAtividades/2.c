//
//  2.c
//  Atividade4-ListaDeAtividades
//
//  Created by Gabriel Eduardo on 26/08/23.
//

// Crie uma struct chamada "Tipo" que possa armazenar um valor do tipo inteiro, um valor do tipo ponto flutuante e uma letra. Escreva um programa que demonstre o uso da struct, atribuindo valores de diferentes tipos e imprimindo-os.

#include <stdio.h>

struct Tipo {
    int valorInt;
    float valorFloat;
    char letra;
};

int main(void) {
    struct Tipo meuTipo;

    meuTipo.valorInt = 42;
    meuTipo.valorFloat = 3.14;
    meuTipo.letra = 'A';

    printf("Valor Inteiro: %d\n", meuTipo.valorInt);
    printf("Valor de Ponto Flutuante: %.2f\n", meuTipo.valorFloat);
    printf("Letra: %c\n", meuTipo.letra);

    return 0;
}

