//
//  4.c
//  Atividade4-ListaDeAtividades
//
//  Created by Gabriel Eduardo on 26/08/23.
//

// Crie uma struct chamada "Contato" que armazene o nome e o número de telefone de uma pessoa. escreva um programa que permita ao usuário adicionar contatos, listar todos os contatos e buscar um contato pelo nome.

#include <stdio.h>
#include <string.h>

struct Contato {
    char nome[50];
    char telefone[15];
};

void adicionarContato(struct Contato listaContatos[], int *numContatos) {
    if (*numContatos < 100) {
        printf("Digite o nome do contato: ");
        getchar();
        fgets(listaContatos[*numContatos].nome, sizeof(listaContatos[*numContatos].nome), stdin);

        printf("Digite o número de telefone: ");
        fgets(listaContatos[*numContatos].telefone, sizeof(listaContatos[*numContatos].telefone), stdin);

        (*numContatos)++;
        printf("Contato adicionado com sucesso!\n");
    } else {
        printf("Limite máximo de contatos atingido.\n");
    }
}

void listarContatos(struct Contato listaContatos[], int numContatos) {
    printf("Lista de Contatos:\n");
    for (int i = 0; i < numContatos; i++) {
        printf("Nome: %s\n", listaContatos[i].nome);
        printf("Telefone: %s\n", listaContatos[i].telefone);
        printf("\n");
    }
}

void buscarContato(struct Contato listaContatos[], int numContatos, char nomeBusca[]) {
    int encontrado = 0;
    printf("Resultado da busca:\n");
    for (int i = 0; i < numContatos; i++) {
        if (strcmp(listaContatos[i].nome, nomeBusca) == 0) {
            printf("Nome: %s\n", listaContatos[i].nome);
            printf("Telefone: %s\n", listaContatos[i].telefone);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Contato não encontrado.\n");
    }
}

int main(void) {
    struct Contato listaContatos[100];
    int numContatos = 0;

    int opcao;
    char nomeBusca[50];

    do {
        printf("Escolha uma opção:\n");
        printf("1. Adicionar contato\n");
        printf("2. Listar contatos\n");
        printf("3. Buscar contato pelo nome\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarContato(listaContatos, &numContatos);
                break;
            case 2:
                listarContatos(listaContatos, numContatos);
                break;
            case 3:
                printf("Digite o nome do contato a ser buscado: ");
                getchar(); // Limpar o buffer
                fgets(nomeBusca, sizeof(nomeBusca), stdin);
                nomeBusca[strcspn(nomeBusca, "\n")] = '\0';
                buscarContato(listaContatos, numContatos, nomeBusca);
                break;
            case 4:
                printf("Saindo do programa.\n");
                break;
            default:
                printf("Opção inválida. Escolha novamente.\n");
        }
    } while (opcao != 4);

    return 0;
}

