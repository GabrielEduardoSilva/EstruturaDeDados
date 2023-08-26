//
//  6.c
//  Atividade4-ListaDeAtividades
//
//  Created by Gabriel Eduardo on 26/08/23.
//

// Crie uma struct chamada "Estudante" com campos para nome, matrícula e notas em três disciplinas. Implemente funções para calcular a média das notas e determinar se um aluno está aprovado (média maior ou igual a 7).

#include <stdio.h>
#include <stdbool.h>

struct Estudante {
    char nome[50];
    int matricula;
    float nota1, nota2, nota3;
};

float calcularMedia(struct Estudante aluno) {
    return (aluno.nota1 + aluno.nota2 + aluno.nota3) / 3.0;
}

bool estaAprovado(struct Estudante aluno) {
    float media = calcularMedia(aluno);
    return media >= 7.0;
}

int main(void) {
    struct Estudante estudante1;

    printf("Digite o nome do estudante: ");
    fgets(estudante1.nome, sizeof(estudante1.nome), stdin);
    
    printf("Digite a matrícula do estudante: ");
    scanf("%d", &estudante1.matricula);

    printf("Digite a nota da disciplina 1: ");
    scanf("%f", &estudante1.nota1);

    printf("Digite a nota da disciplina 2: ");
    scanf("%f", &estudante1.nota2);

    printf("Digite a nota da disciplina 3: ");
    scanf("%f", &estudante1.nota3);

    float media = calcularMedia(estudante1);
    bool aprovado = estaAprovado(estudante1);

    printf("\nInformacoes do Estudante:\n");
    printf("Nome: %s\n", estudante1.nome);
    printf("Matrícula: %d\n", estudante1.matricula);
    printf("Nota 1: %.2f\n", estudante1.nota1);
    printf("Nota 2: %.2f\n", estudante1.nota2);
    printf("Nota 3: %.2f\n", estudante1.nota3);
    printf("Média: %.2f\n", media);
    printf("Situação: %s\n", aprovado ? "Aprovado" : "Reprovado");

    return 0;
}

