//
//  main.c
//  BubbleSort
//
//  Created by Gabriel Eduardo on 26/08/23.
//

// Fazer o programa em C, que receba um conjunto de caracteres e coloque-os em ordem alfabética utilizando uma função que implemente o método Bubble Sort.

#include <stdio.h>
#include <string.h>

void bubbleSort(char conjunto[], int tamanho) {
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (conjunto[j] > conjunto[j + 1]) {
                char temp = conjunto[j];
                conjunto[j] = conjunto[j + 1];
                conjunto[j + 1] = temp;
            }
        }
    }
}

int main(void) {
    char conjunto[100];
    int tamanho;

    printf("Digite um conjunto de caracteres: ");
    fgets(conjunto, sizeof(conjunto), stdin);
    tamanho = strlen(conjunto);

    if (conjunto[tamanho - 1] == '\n') {
        conjunto[tamanho - 1] = '\0';
        tamanho--;
    }

    bubbleSort(conjunto, tamanho);

    printf("Conjunto ordenado: %s\n", conjunto);

    return 0;
}

