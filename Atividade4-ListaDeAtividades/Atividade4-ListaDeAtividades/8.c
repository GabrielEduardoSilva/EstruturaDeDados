//
//  8.c
//  Atividade4-ListaDeAtividades
//
//  Created by Gabriel Eduardo on 26/08/23.
//

// Crie uma struct chamada "Produto" com campos para nome, preço e quantidade em estoque. Escreva um programa que permita ao usuário comprar produtos, atualizando o estoque e calculando o total da compra.

#include <stdio.h>
#include <stdbool.h>

struct Produto {
    char nome[50];
    float preco;
    int quantidadeEstoque;
};

bool comprarProduto(struct Produto *produto, int quantidadeComprada) {
    if (quantidadeComprada > 0 && quantidadeComprada <= produto->quantidadeEstoque) {
        float totalCompra = quantidadeComprada * produto->preco;
        printf("Compra realizada com sucesso!\n");
        printf("Total da compra: %.2f\n", totalCompra);

        produto->quantidadeEstoque -= quantidadeComprada;
        return true;
    } else {
        printf("Quantidade inválida ou insuficiente em estoque.\n");
        return false;
    }
}

int main(void) {
    struct Produto produto1;

    printf("Digite o nome do produto: ");
    fgets(produto1.nome, sizeof(produto1.nome), stdin);


    printf("Digite o preço do produto: ");
    scanf("%f", &produto1.preco);

    printf("Digite a quantidade em estoque: ");
    scanf("%d", &produto1.quantidadeEstoque);

    int quantidadeComprada;
    do {
        printf("Quantidade a comprar (0 para sair): ");
        scanf("%d", &quantidadeComprada);

        if (quantidadeComprada > 0) {
            comprarProduto(&produto1, quantidadeComprada);
        }
    } while (quantidadeComprada > 0);

    printf("\nInformacoes do Produto:\n");
    printf("Nome: %s\n", produto1.nome);
    printf("Preço: %.2f\n", produto1.preco);
    printf("Quantidade em Estoque: %d\n", produto1.quantidadeEstoque);

    return 0;
}

