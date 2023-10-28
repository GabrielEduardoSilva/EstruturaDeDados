//
//  pilha.c
//  Atividade10-Pilha
//
//  Created by Gabriel Eduardo on 28/10/23.
//

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_PECAS 100

typedef struct {
    char nome[100];
    int quantidade;
} Peca;

typedef struct {
    Peca itens[MAX_PECAS];
    int topo;
} Pilha;

void inicializarPilha(Pilha *pilha) {
    pilha->topo = -1;
}

int estaVazia(Pilha *pilha) {
    return pilha->topo == -1;
}

int estaCheia(Pilha *pilha) {
    return pilha->topo == MAX_PECAS - 1;
}

void empilhar(Pilha *pilha, char nome[], int quantidade) {
    if (!estaCheia(pilha)) {
        pilha->topo++;
        strcpy(pilha->itens[pilha->topo].nome, nome);
        pilha->itens[pilha->topo].quantidade = quantidade;
    } else {
        printf("A pilha está cheia. Não é possível empilhar mais peças.\n");
    }
}

void desempilhar(Pilha *pilha) {
    if (!estaVazia(pilha)) {
        printf("Desempilhando: %s (Quantidade: %d)\n", pilha->itens[pilha->topo].nome, pilha->itens[pilha->topo].quantidade);
        pilha->topo--;
    } else {
        printf("A pilha está vazia. Não é possível desempilhar mais peças.\n");
    }
}

int main(void) {
    Pilha pilha;
    inicializarPilha(&pilha);
    
    char objeto[100];
    printf("Digite o nome do objeto: ");
    scanf("%s", objeto);
    
    while (1) {
        int opcao;
        printf("\nMenu:\n");
        printf("1. Empilhar peça\n");
        printf("2. Desempilhar peça\n");
        printf("3. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        
        if (opcao == 1) {
            char nomePeca[100];
            int quantidade;
            printf("Digite o nome da peça: ");
            scanf("%s", nomePeca);
            printf("Digite a quantidade: ");
            scanf("%d", &quantidade);
            empilhar(&pilha, nomePeca, quantidade);
        } else if (opcao == 2) {
            desempilhar(&pilha);
        } else if (opcao == 3) {
            break;
        } else {
            printf("Opção inválida.\n");
        }
    }
    
    printf("\nObjeto desmontado: %s\n", objeto);
    while (!estaVazia(&pilha)) {
        desempilhar(&pilha);
    }

    return 0;
}
