//
//  3.c
//  Atividade4-ListaDeAtividades
//
//  Created by Gabriel Eduardo on 26/08/23.
//

// Crie uma struct chamada "Ponto" que represente um ponto no plano cartesiano com coordenadas x e y. Em seguida, implemente funções para calcular a distância entre dois pontos e a inclinação da reta que os conecta.

#include <stdio.h>
#include <math.h>

struct Ponto {
    float x;
    float y;
};

float calcularDistancia(struct Ponto ponto1, struct Ponto ponto2) {
    float distancia = sqrt(pow(ponto2.x - ponto1.x, 2) + pow(ponto2.y - ponto1.y, 2));
    return distancia;
}

float calcularInclinacao(struct Ponto ponto1, struct Ponto ponto2) {
    float inclinacao = (ponto2.y - ponto1.y) / (ponto2.x - ponto1.x);
    return inclinacao;
}

int main(void) {
    struct Ponto ponto1, ponto2;

    ponto1.x = 1.0;
    ponto1.y = 2.0;

    ponto2.x = 4.0;
    ponto2.y = 6.0;

    float distancia = calcularDistancia(ponto1, ponto2);
    printf("Distancia entre os pontos: %.2f\n", distancia);

    float inclinacao = calcularInclinacao(ponto1, ponto2);
    printf("Inclinacao da reta: %.2f\n", inclinacao);

    return 0;
}

