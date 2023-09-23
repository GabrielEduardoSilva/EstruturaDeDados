//
//  main.c
//  BuscaBinaria
//
//  Created by Gabriel Eduardo on 23/09/23.
//

#include <stdio.h>

int buscaBinaria(int arr[], int tamanho, int chave) {
    int inicio = 0;
    int fim = tamanho - 1;

    while (inicio <= fim) {
        int meio = inicio + (fim - inicio) / 2;

        if (arr[meio] == chave) {
            return meio;
        }

        if (arr[meio] < chave) {
            inicio = meio + 1;
        }

        else {
            fim = meio - 1;
        }
    }

    return -1;
}

int main(void) {
    int arr[] = {2, 3, 4, 5, 8};
    int tamanho = sizeof(arr) / sizeof(arr[0]);
    int chave = 4;

    int resultado = buscaBinaria(arr, tamanho, chave);

    if (resultado != -1) {
        printf("Chave encontrada no índice %d\n", resultado);
    } else {
        printf("Chave não encontrada\n");
    }

    return 0;
}
