//
//  1.c
//  Atividade4-ListaDeAtividades
//
//  Created by Gabriel Eduardo on 26/08/23.
//

#include <stdio.h>

struct Pessoa {
    char nome[50];
    int idade;
    float altura;
};

int main(void) {
    struct Pessoa pessoa1;

    printf("Digite o nome: ");
    fgets(pessoa1.nome, sizeof(pessoa1.nome), stdin);

    printf("Digite a idade: ");
    scanf("%d", &pessoa1.idade);

    printf("Digite a altura: ");
    scanf("%f", &pessoa1.altura);

    printf("\nInformacoes da Pessoa:\n");
    printf("Nome: %s\n", pessoa1.nome);
    printf("Idade: %d\n", pessoa1.idade);
    printf("Altura: %.2f\n", pessoa1.altura);

    return 0;
}

