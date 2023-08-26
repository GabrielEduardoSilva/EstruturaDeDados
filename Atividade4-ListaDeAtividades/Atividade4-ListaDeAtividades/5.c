//
//  5.c
//  Atividade4-ListaDeAtividades
//
//  Created by Gabriel Eduardo on 26/08/23.
//

// Crie uma struct chamada "Livro" com campos para título, autor e ano de publicação. Escreva um programa que permita ao usuário adicionar informações de livros, listar todos os livros cadastrados e buscar livros por autor.

#include <stdio.h>
#include <string.h>

struct Livro {
    char titulo[100];
    char autor[100];
    int anoPublicacao;
};

void adicionarLivro(struct Livro listaLivros[], int *numLivros) {
    if (*numLivros < 100) {
        printf("Digite o título do livro: ");
        getchar();
        fgets(listaLivros[*numLivros].titulo, sizeof(listaLivros[*numLivros].titulo), stdin);
        listaLivros[*numLivros].titulo[strcspn(listaLivros[*numLivros].titulo, "\n")] = '\0';

        printf("Digite o autor do livro: ");
        fgets(listaLivros[*numLivros].autor, sizeof(listaLivros[*numLivros].autor), stdin);
        listaLivros[*numLivros].autor[strcspn(listaLivros[*numLivros].autor, "\n")] = '\0';

        printf("Digite o ano de publicação do livro: ");
        scanf("%d", &listaLivros[*numLivros].anoPublicacao);

        (*numLivros)++;
        printf("Livro adicionado com sucesso!\n");
    } else {
        printf("Limite máximo de livros atingido.\n");
    }
}

void listarLivros(struct Livro listaLivros[], int numLivros) {
    printf("Lista de Livros:\n");
    for (int i = 0; i < numLivros; i++) {
        printf("Título: %s\n", listaLivros[i].titulo);
        printf("Autor: %s\n", listaLivros[i].autor);
        printf("Ano de Publicação: %d\n", listaLivros[i].anoPublicacao);
        printf("\n");
    }
}

void buscarLivrosPorAutor(struct Livro listaLivros[], int numLivros, char autorBusca[]) {
    int encontrados = 0;
    printf("Resultado da busca por autor:\n");
    for (int i = 0; i < numLivros; i++) {
        if (strcmp(listaLivros[i].autor, autorBusca) == 0) {
            printf("Título: %s\n", listaLivros[i].titulo);
            printf("Autor: %s\n", listaLivros[i].autor);
            printf("Ano de Publicação: %d\n", listaLivros[i].anoPublicacao);
            printf("\n");
            encontrados++;
        }
    }
    if (encontrados == 0) {
        printf("Nenhum livro encontrado para o autor especificado.\n");
    }
}

int main(void) {
    struct Livro listaLivros[100];
    int numLivros = 0;

    int opcao;
    char autorBusca[100];

    do {
        printf("Escolha uma opção:\n");
        printf("1. Adicionar livro\n");
        printf("2. Listar livros\n");
        printf("3. Buscar livros por autor\n");
        printf("4. Sair\n");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                adicionarLivro(listaLivros, &numLivros);
                break;
            case 2:
                listarLivros(listaLivros, numLivros);
                break;
            case 3:
                printf("Digite o autor para a busca: ");
                getchar();
                fgets(autorBusca, sizeof(autorBusca), stdin);
                autorBusca[strcspn(autorBusca, "\n")] = '\0';
                buscarLivrosPorAutor(listaLivros, numLivros, autorBusca);
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

