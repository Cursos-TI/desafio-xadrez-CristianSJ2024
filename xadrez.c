#include <stdio.h>

// Função recursiva para o movimento da Torre (vertical e horizontal)
void moverTorre(int casas) {
    if (casas == 0) return;
    printf("Cima\n");
    moverTorre(casas - 1);
    printf("Baixo\n");
    moverTorre(casas - 1);
    printf("Esquerda\n");
    moverTorre(casas - 1);
    printf("Direita\n");
}

// Função recursiva para o movimento do Bispo (diagonal)
void moverBispo(int casas, int x, int y) {
    if (casas == 0) return;
    printf("Diagonal para cima e direita\n");
    moverBispo(casas - 1, x + 1, y + 1);
    printf("Diagonal para cima e esquerda\n");
    moverBispo(casas - 1, x - 1, y + 1);
    printf("Diagonal para baixo e direita\n");
    moverBispo(casas - 1, x + 1, y - 1);
    printf("Diagonal para baixo e esquerda\n");
    moverBispo(casas - 1, x - 1, y - 1);
}

// Função recursiva para o movimento da Rainha (combinação de Torre e Bispo)
void moverRainha(int casas) {
    if (casas == 0) return;
    moverTorre(casas);
    moverBispo(casas, 0, 0);
}

// Movimento do Cavalo utilizando loops aninhados
void moverCavalo(int maxMovimentos) {
    for (int i = 0; i < maxMovimentos; i++) {
        for (int j = 0; j < maxMovimentos; j++) {
            if (i == j) continue; // Evita repetição do mesmo movimento
            printf("Movendo Cavalo: Duas casas para cima e uma para a direita\n");
            if (i + 2 > maxMovimentos || j + 1 > maxMovimentos) break; // Evita ultrapassar o limite
        }
    }
}

int main() {
    int casas = 3; // Número de casas a serem movidas
    int maxMovimentosCavalo = 3; // Número máximo de movimentos para o cavalo

    printf("Movimento da Torre:\n");
    moverTorre(casas);
    printf("\n");
    
    printf("Movimento do Bispo:\n");
    moverBispo(casas, 0, 0);
    printf("\n");
    
    printf("Movimento da Rainha:\n");
    moverRainha(casas);
    printf("\n");
    
    printf("Movimento do Cavalo:\n");
    moverCavalo(maxMovimentosCavalo);
    
    return 0;
}
