#include <stdio.h>

#define TAM 10     // Tamanho do tabuleiro (10x10)
#define AGUA 0     // Representa água
#define NAVIO 3    // Representa parte do navio
#define TAM_NAVIO 3 // Tamanho fixo dos navios

// Função para inicializar o tabuleiro com água (0)
void inicializarTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            tabuleiro[i][j] = AGUA;
        }
    }
}

// Função para verificar se é possível posicionar um navio sem sair dos limites ou sobrepor
int podePosicionar(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    /*
        direcao:
            0 = horizontal
            1 = vertical
        diagonal:
            0 = não é diagonal
            1 = diagonal principal (↘)
            2 = diagonal secundária (↙)
    */

    for (int k = 0; k < TAM_NAVIO; k++) {
        int l = linha, c = coluna;

        if (diagonal == 1) { // ↘
            l += k;
            c += k;
        } else if (diagonal == 2) { // ↙
            l += k;
            c -= k;
        } else if (direcao == 0) { // horizontal
            c += k;
        } else if (direcao == 1) { // vertical
            l += k;
        }

        // Verifica limites
        if (l < 0 || l >= TAM || c < 0 || c >= TAM)
            return 0;

        // Verifica sobreposição
        if (tabuleiro[l][c] == NAVIO)
            return 0;
    }

    return 1; // Pode posicionar
}

// Função para posicionar o navio
void posicionarNavio(int tabuleiro[TAM][TAM], int linha, int coluna, int direcao, int diagonal) {
    for (int k = 0; k < TAM_NAVIO; k++) {
        int l = linha, c = coluna;

        if (diagonal == 1) { // ↘
            l += k;
            c += k;
        } else if (diagonal == 2) { // ↙
            l += k;
            c -= k;
        } else if (direcao == 0) { // horizontal
            c += k;
        } else if (direcao == 1) { // vertical
            l += k;
        }

        tabuleiro[l][c] = NAVIO;
    }
}

// Função para exibir o tabuleiro formatado
void exibirTabuleiro(int tabuleiro[TAM][TAM]) {
    for (int i = 0; i < TAM; i++) {
        for (int j = 0; j < TAM; j++) {
            printf("%d ", tabuleiro[i][j]);
        }
        printf("\n");
    }
}

int main() {
    int tabuleiro[TAM][TAM];

    inicializarTabuleiro(tabuleiro);

    // Coordenadas pré-definidas dos 4 navios (evitando sobreposição)
    // Dois navios horizontais/verticais
    if (podePosicionar(tabuleiro, 0, 0, 0, 0))
        posicionarNavio(tabuleiro, 0, 0, 0, 0); // Horizontal
    if (podePosicionar(tabuleiro, 5, 2, 1, 0))
        posicionarNavio(tabuleiro, 5, 2, 1, 0); // Vertical

    // Dois navios diagonais
    if (podePosicionar(tabuleiro, 2, 2, 0, 1))
        posicionarNavio(tabuleiro, 2, 2, 0, 1); // Diagonal ↘
    if (podePosicionar(tabuleiro, 1, 8, 0, 2))
        posicionarNavio(tabuleiro, 1, 8, 0, 2); // Diagonal ↙

    // Exibe o tabuleiro
    exibirTabuleiro(tabuleiro);

    return 0;
}
