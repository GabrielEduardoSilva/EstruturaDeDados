//
//  2.c
//  Atividade4-ListaDeAtividades
//
//  Created by Gabriel Eduardo on 26/08/23.
//

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

