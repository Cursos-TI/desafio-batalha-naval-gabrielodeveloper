#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main() {
    // Tamanho do tabuleiro
    int tabuleiro[10][10] = {0};

    // Declaração para as cordenadas de cada navio.
    int navioHorizontalLinha = 2, navioHorizontalColuna = 2;
    int navioVerticalLinha = 5, navioVerticalColuna = 5;

    // Posicionando o navio na horizontal.
    for (int i = 0; i < 3; i++) {
        tabuleiro[navioHorizontalLinha][navioHorizontalColuna + i] = 3;
    }

    // Posicionando o navio na vertical.
    for (int i = 0; i < 3; i++) {
        tabuleiro[navioVerticalLinha + i][navioVerticalColuna] = 3;
    }

    // Resultado do tabuleiro com as posições horizontal e vertical.
    printf("Tabuleiro final:\n");
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }


    return 0;
}
