//
//  main.c
//  ListaOrdenada
//
//  Created by Gabriel Eduardo on 23/09/23.
//

#include <stdio.h>

#include <stdio.h>
#include <stdlib.h>

struct Node {
    int valor;
    struct Node* proximo;
};

struct Node* criarNo(int valor) {
    struct Node* novoNo = (struct Node*)malloc(sizeof(struct Node));
    novoNo->valor = valor;
    novoNo->proximo = NULL;
    return novoNo;
}

void inserirEmOrdem(struct Node** cabeca, int valor) {
    struct Node* novoNo = criarNo(valor);
    struct Node* atual = *cabeca;
    struct Node* anterior = NULL;

    if (*cabeca == NULL || valor < (*cabeca)->valor) {
        novoNo->proximo = *cabeca;
        *cabeca = novoNo;
        return;
    }

    while (atual != NULL && valor > atual->valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    anterior->proximo = novoNo;
    novoNo->proximo = atual;
}

void imprimirLista(struct Node* cabeca) {
    struct Node* atual = cabeca;
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("\n");
}

int main() {
    struct Node* lista = NULL;

    inserirEmOrdem(&lista, 3);
    inserirEmOrdem(&lista, 8);
    inserirEmOrdem(&lista, 4);
    inserirEmOrdem(&lista, 2);
    inserirEmOrdem(&lista, 5);

    printf("Lista Ordenada: ");
    imprimirLista(lista);

    return 0;
}

