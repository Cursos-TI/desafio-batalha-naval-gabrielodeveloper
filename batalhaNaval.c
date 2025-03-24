#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define LINHAS 10
#define COLUNAS 10
#define TAMANHO_NAVIO 3
#define VALOR_AGUA 0
#define VALOR_NAVIO 3

// Verifica se a posição não ultrapassa os limites.
int validarPosicao(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        if (orientacao == 'H') c += i;
        else if (orientacao == 'V') l += i;
        else if (orientacao == 'D') { l += i; c += i; }  
        else if (orientacao == 'E') { l += i; c -= i; }      

        if (l < 0 || l >= LINHAS || c < 0 || c >= COLUNAS)
            return 0;

        if (tabuleiro[l][c] != VALOR_AGUA)
            return 0;
    }
    return 1;
}

// Posicionar o navio no tabuleiro
void posicionarNavio(int tabuleiro[LINHAS][COLUNAS], int linha, int coluna, char orientacao) {
    for (int i = 0; i < TAMANHO_NAVIO; i++) {
        int l = linha, c = coluna;

        if (orientacao == 'H') c += i;
        else if (orientacao == 'V') l += i;
        else if (orientacao == 'D') { l += i; c += i; }
        else if (orientacao == 'E') { l += i; c -= i; }

        tabuleiro[l][c] = VALOR_NAVIO;
    }
}

// Exibir o tabuleiro 
void exibirTabuleiro(int tabuleiro[LINHAS][COLUNAS]) {
    printf("Tabuleiro Final:\n\n");
    for (int i = 0; i < LINHAS; i++) {
        for (int j = 0; j < COLUNAS; j++) {
            printf("%2d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[LINHAS][COLUNAS] = {VALOR_AGUA};

    int coordenadas[4][2] = {
        {1, 1},  
        {5, 4},  
        {6, 6},  // Diagonal principal 
        {6, 2}   // Diagonal secundária 
    };
    char orientacoes[4] = {'H', 'V', 'D', 'E'};

    for (int i = 0; i < 4; i++) {
        int linha = coordenadas[i][0];
        int coluna = coordenadas[i][1];
        char orientacao = orientacoes[i];

        if (validarPosicao(tabuleiro, linha, coluna, orientacao)) {
            posicionarNavio(tabuleiro, linha, coluna, orientacao);
        } else {
            printf("Erro: não foi possível posicionar o navio %d (linha: %d, coluna: %d, orientação: %c)\n",
                   i + 1, linha, coluna, orientacao);
        }
    }

    exibirTabuleiro(tabuleiro);
    return 0;
}


