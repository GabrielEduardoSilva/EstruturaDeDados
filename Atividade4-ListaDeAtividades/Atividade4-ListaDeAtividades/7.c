//
//  7.c
//  Atividade4-ListaDeAtividades
//
//  Created by Gabriel Eduardo on 26/08/23.
//

// Crie uma struct chamada "ContaBancaria" com campos para nome do titular, número da conta e saldo. Implemente funções para depositar, sacar e verificar o saldo.

#include <stdio.h>
#include <stdbool.h>


struct ContaBancaria {
    char nomeTitular[50];
    int numeroConta;
    float saldo;
};

void depositar(struct ContaBancaria *conta, float valor) {
    if (valor > 0) {
        conta->saldo += valor;
        printf("Depósito de %.2f realizado com sucesso.\n", valor);
    } else {
        printf("Valor inválido para depósito.\n");
    }
}

void sacar(struct ContaBancaria *conta, float valor) {
    if (valor > 0 && valor <= conta->saldo) {
        conta->saldo -= valor;
        printf("Saque de %.2f realizado com sucesso.\n", valor);
    } else {
        printf("Valor inválido para saque ou saldo insuficiente.\n");
    }
}

float verificarSaldo(struct ContaBancaria conta) {
    return conta.saldo;
}

int main(void) {
    struct ContaBancaria conta1;

    printf("Digite o nome do titular da conta: ");
    fgets(conta1.nomeTitular, sizeof(conta1.nomeTitular), stdin);


    printf("Digite o número da conta: ");
    scanf("%d", &conta1.numeroConta);

    conta1.saldo = 0.0;


    float valorDeposito, valorSaque;
    printf("Digite o valor a depositar: ");
    scanf("%f", &valorDeposito);
    depositar(&conta1, valorDeposito);

    printf("Digite o valor a sacar: ");
    scanf("%f", &valorSaque);
    sacar(&conta1, valorSaque);

    float saldoAtual = verificarSaldo(conta1);

    printf("\nInformacoes da Conta Bancaria:\n");
    printf("Nome do Titular: %s\n", conta1.nomeTitular);
    printf("Número da Conta: %d\n", conta1.numeroConta);
    printf("Saldo Atual: %.2f\n", saldoAtual);

    return 0;
}
