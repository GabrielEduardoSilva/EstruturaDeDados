//
//  9.c
//  Atividade4-ListaDeAtividades
//
//  Created by Gabriel Eduardo on 26/08/23.
//

// Crie uma struct chamada "Funcionario" com campos para nome, cargo, salário e data de admissão. Implemente funções para dar um aumento de salário e calcular quanto tempo um funcionário está na empresa.

#include <stdio.h>
#include <time.h>
#include <string.h>

struct Funcionario {
    char nome[50];
    char cargo[50];
    float salario;
    struct tm dataAdmissao;
};

void darAumento(struct Funcionario *funcionario, float percentual) {
    if (percentual > 0) {
        funcionario->salario *= (1 + percentual / 100);
        printf("Aumento de %.2f%% aplicado com sucesso.\n", percentual);
    } else {
        printf("Percentual de aumento inválido.\n");
    }
}

float calcularTempoAdmissao(struct Funcionario funcionario) {
    time_t agora;
    time(&agora);
    struct tm *dataAtual = localtime(&agora);

    int anos = dataAtual->tm_year - funcionario.dataAdmissao.tm_year;
    int meses = dataAtual->tm_mon - funcionario.dataAdmissao.tm_mon;

    if (meses < 0) {
        anos--;
    }

    return anos + (float) meses / 12;
}

int main(void) {
    struct Funcionario funcionario1;

    printf("Digite o nome do funcionário: ");
    fgets(funcionario1.nome, sizeof(funcionario1.nome), stdin);
    funcionario1.nome[strcspn(funcionario1.nome, "\n")] = '\0';

    printf("Digite o cargo do funcionário: ");
    fgets(funcionario1.cargo, sizeof(funcionario1.cargo), stdin);
    funcionario1.cargo[strcspn(funcionario1.cargo, "\n")] = '\0';

    printf("Digite o salário do funcionário: ");
    scanf("%f", &funcionario1.salario);

    printf("Digite a data de admissão (AAAA MM DD): ");
    scanf("%d %d %d", &funcionario1.dataAdmissao.tm_year, &funcionario1.dataAdmissao.tm_mon,
          &funcionario1.dataAdmissao.tm_mday);

    funcionario1.dataAdmissao.tm_year -= 1900;
    funcionario1.dataAdmissao.tm_mon -= 1;

    darAumento(&funcionario1, 10);

    float tempoAdmissao = calcularTempoAdmissao(funcionario1);

    printf("\nInformacoes do Funcionario:\n");
    printf("Nome: %s\n", funcionario1.nome);
    printf("Cargo: %s\n", funcionario1.cargo);
    printf("Salário: %.2f\n", funcionario1.salario);
    printf("Tempo de Admissão: %.2f anos\n", tempoAdmissao);

    return 0;
}

