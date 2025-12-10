#include <stdio.h>
#include <stdlib.h>   // Para abs()

#define TAM_TABULEIRO 10   // Tamanho fixo do tabuleiro (10x10)
#define TAM_NAVIO 3        // Tamanho fixo de cada navio (3 posições)
#define TAM_HABILIDADE 5   // Tamanho fixo das matrizes de habilidade (5x5, para cone, cruz, octaedro)

int main() {
    // Declaração da matriz bidimensional para o tabuleiro (10 linhas x 10 colunas)
    int tabuleiro[TAM_TABULEIRO][TAM_TABULEIRO];

    // Inicialização do tabuleiro com 0 (água) usando loops aninhados
    int linha, coluna;
    for (linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            tabuleiro[linha][coluna] = 0;  // Água em todas as posições
        }
    }

    // Definição das coordenadas iniciais dos navios (definidas diretamente no código)
    // Navio 1: Horizontal - começa na linha 2, coluna 3
    int linha_horiz1 = 2;
    int coluna_horiz1 = 3;

    // Navio 2: Vertical - começa na linha 5, coluna 7
    int linha_vert = 5;
    int coluna_vert = 7;

    // Navio 3: Diagonal crescente - começa na linha 0, coluna 0
    int linha_diag_cresc = 0;
    int coluna_diag_cresc = 0;

    // Navio 4: Diagonal decrescente - começa na linha 0, coluna 9
    int linha_diag_decresc = 0;
    int coluna_diag_decresc = 9;

    // ======================================================================
    // Posicionamento e Validação dos Navios (mantido do Nível Aventureiro)
    // ======================================================================

    // Navio 1 (Horizontal)
    if (coluna_horiz1 + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio horizontal 1 não cabe no tabuleiro!\n");
        return 1;
    }
    int pos;
    for (pos = 0; pos < TAM_NAVIO; pos++) {
        if (tabuleiro[linha_horiz1][coluna_horiz1 + pos] != 0) {
            printf("Erro: Sobreposição no navio horizontal 1!\n");
            return 1;
        }
    }
    for (pos = 0; pos < TAM_NAVIO; pos++) {
        tabuleiro[linha_horiz1][coluna_horiz1 + pos] = 3;
    }

    // Navio 2 (Vertical)
    if (linha_vert + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio vertical não cabe no tabuleiro!\n");
        return 1;
    }
    for (pos = 0; pos < TAM_NAVIO; pos++) {
        if (tabuleiro[linha_vert + pos][coluna_vert] != 0) {
            printf("Erro: Sobreposição no navio vertical!\n");
            return 1;
        }
    }
    for (pos = 0; pos < TAM_NAVIO; pos++) {
        tabuleiro[linha_vert + pos][coluna_vert] = 3;
    }

    // Navio 3 (Diagonal Crescente)
    if (linha_diag_cresc + TAM_NAVIO > TAM_TABULEIRO || coluna_diag_cresc + TAM_NAVIO > TAM_TABULEIRO) {
        printf("Erro: Navio diagonal crescente não cabe no tabuleiro!\n");
        return 1;
    }
    for (pos = 0; pos < TAM_NAVIO; pos++) {
        if (tabuleiro[linha_diag_cresc + pos][coluna_diag_cresc + pos] != 0) {
            printf("Erro: Sobreposição no navio diagonal crescente!\n");
            return 1;
        }
    }
    for (pos = 0; pos < TAM_NAVIO; pos++) {
        tabuleiro[linha_diag_cresc + pos][coluna_diag_cresc + pos] = 3;
    }

    // Navio 4 (Diagonal Decrescente)
    if (linha_diag_decresc + TAM_NAVIO > TAM_TABULEIRO || coluna_diag_decresc - (TAM_NAVIO - 1) < 0) {
        printf("Erro: Navio diagonal decrescente não cabe no tabuleiro!\n");
        return 1;
    }
    for (pos = 0; pos < TAM_NAVIO; pos++) {
        if (tabuleiro[linha_diag_decresc + pos][coluna_diag_decresc - pos] != 0) {
            printf("Erro: Sobreposição no navio diagonal decrescente!\n");
            return 1;
        }
    }
    for (pos = 0; pos < TAM_NAVIO; pos++) {
        tabuleiro[linha_diag_decresc + pos][coluna_diag_decresc - pos] = 3;
    }

    // ======================================================================
    // Criação das Matrizes de Habilidades (5x5, construídas dinamicamente com loops + condicionais)
    // ======================================================================

    // Matriz para habilidade "Cone" (apontando para baixo, expandindo da linha 0 para baixo)
    int matriz_cone[TAM_HABILIDADE][TAM_HABILIDADE];
    for (linha = 0; linha < TAM_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {
            matriz_cone[linha][coluna] = 0;  // Inicializa com 0
        }
    }
    // Constrói o cone dinamicamente: linha 0: 1 célula central; linha 1: 3 células; linha 2: 5 células, etc.
    for (linha = 0; linha < TAM_HABILIDADE; linha++) {
        int largura_base = 2 * linha + 1;  // Largura aumenta com a linha (1,3,5...)
        if (largura_base > TAM_HABILIDADE) largura_base = TAM_HABILIDADE; // evita ultrapassar a matriz
        int inicio_coluna = (TAM_HABILIDADE - largura_base) / 2;  // Centraliza
        for (coluna = inicio_coluna; coluna < inicio_coluna + largura_base; coluna++) {
            if (coluna >= 0 && coluna < TAM_HABILIDADE) {  // Condicional para limites
                matriz_cone[linha][coluna] = 1;  // Área afetada
            }
        }
    }

    // Matriz para habilidade "Cruz" (centro na posição [2][2] para 5x5)
    int matriz_cruz[TAM_HABILIDADE][TAM_HABILIDADE];
    for (linha = 0; linha < TAM_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {
            matriz_cruz[linha][coluna] = 0;  // Inicializa com 0
        }
    }
    // Constrói a cruz: linha central e coluna central com 1
    int centro = TAM_HABILIDADE / 2;  // Centro em [2][2]
    for (linha = 0; linha < TAM_HABILIDADE; linha++) {
        matriz_cruz[linha][centro] = 1;  // Coluna central (vertical)
    }
    for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {
        matriz_cruz[centro][coluna] = 1;  // Linha central (horizontal)
    }

    // Matriz para habilidade "Octaedro" (losango, centro em [2][2])
    int matriz_octaedro[TAM_HABILIDADE][TAM_HABILIDADE];
    for (linha = 0; linha < TAM_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {
            matriz_octaedro[linha][coluna] = 0;  // Inicializa com 0
        }
    }
    // Constrói o losango (octaedro vista frontal): distância de Manhattan <= raio
    int raio = TAM_HABILIDADE / 2;  // Raio 2 para 5x5
    for (linha = 0; linha < TAM_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {
            int dist_linha = abs(linha - centro);  // Distância vertical do centro
            int dist_coluna = abs(coluna - centro);  // Distância horizontal do centro
            if (dist_linha + dist_coluna <= raio) {  // Condicional para forma de losango
                matriz_octaedro[linha][coluna] = 1;
            }
        }
    }

    // ======================================================================
    // Definição dos pontos de origem para as habilidades (fixos no código)
    // ======================================================================
    // Habilidade Cone: origem em linha 1, coluna 4 (aponta para baixo)
    int origem_cone_linha = 1;
    int origem_cone_coluna = 4;

    // Habilidade Cruz: origem em linha 8, coluna 8 (centro)
    int origem_cruz_linha = 8;
    int origem_cruz_coluna = 8;

    // Habilidade Octaedro: origem em linha 4, coluna 1 (centro)
    int origem_octa_linha = 4;
    int origem_octa_coluna = 1;

    // ======================================================================
    // Sobreposição das habilidades no tabuleiro
    // ======================================================================

    

    // Sobreposição Cone (centralizado na origem, apontando para baixo)
    for (linha = 0; linha < TAM_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {
            int tab_linha = origem_cone_linha + linha;  // Ajusta linha no tabuleiro
            int tab_coluna = origem_cone_coluna + coluna - (TAM_HABILIDADE / 2);  // Centraliza coluna
            if (tab_linha >= 0 && tab_linha < TAM_TABULEIRO &&  // Valida limites
                tab_coluna >= 0 && tab_coluna < TAM_TABULEIRO &&
                matriz_cone[linha][coluna] == 1) {  // Apenas se afetado
                // A área de efeito deve ser marcada, mesmo sobre navios (valor 3)
                tabuleiro[tab_linha][tab_coluna] = 5;  // Marca área afetada
            }
        }
    }

    // Sobreposição Cruz (centralizado na origem)
    for (linha = 0; linha < TAM_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {
            int tab_linha = origem_cruz_linha + linha - (TAM_HABILIDADE / 2);  // Centraliza linha
            int tab_coluna = origem_cruz_coluna + coluna - (TAM_HABILIDADE / 2);  // Centraliza coluna
            if (tab_linha >= 0 && tab_linha < TAM_TABULEIRO &&  // Valida limites
                tab_coluna >= 0 && tab_coluna < TAM_TABULEIRO &&
                matriz_cruz[linha][coluna] == 1) {  // Apenas se afetado
                // A área de efeito deve ser marcada, mesmo sobre navios (valor 3)
                tabuleiro[tab_linha][tab_coluna] = 5;
            }
        }
    }

    // Sobreposição Octaedro (centralizado na origem)
    for (linha = 0; linha < TAM_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {
            int tab_linha = origem_octa_linha + linha - (TAM_HABILIDADE / 2);  // Centraliza linha
            int tab_coluna = origem_octa_coluna + coluna - (TAM_HABILIDADE / 2);  // Centraliza coluna
            if (tab_linha >= 0 && tab_linha < TAM_TABULEIRO &&  // Valida limites
                tab_coluna >= 0 && tab_coluna < TAM_TABULEIRO &&
                matriz_octaedro[linha][coluna] == 1) {  // Apenas se afetado
                // A área de efeito deve ser marcada, mesmo sobre navios (valor 3)
                tabuleiro[tab_linha][tab_coluna] = 5;
            }
        }
    }




    // Sobreposição Octaedro (centralizado na origem)
    for (linha = 0; linha < TAM_HABILIDADE; linha++) {
        for (coluna = 0; coluna < TAM_HABILIDADE; coluna++) {
            int tab_linha = origem_octa_linha + linha - (TAM_HABILIDADE / 2);  // Centraliza linha
            int tab_coluna = origem_octa_coluna + coluna - (TAM_HABILIDADE / 2);  // Centraliza coluna
            if (tab_linha >= 0 && tab_linha < TAM_TABULEIRO &&  // Valida limites
                tab_coluna >= 0 && tab_coluna < TAM_TABULEIRO &&
                matriz_octaedro[linha][coluna] == 1 &&  // Apenas se afetado
                tabuleiro[tab_linha][tab_coluna] == 0) {  // Apenas se vazio
                tabuleiro[tab_linha][tab_coluna] = 5;
            }
        }
    }

    // ======================================================================
    // Exibição do tabuleiro usando loops aninhados
    // ======================================================================
    printf("\n=== TABULEIRO DE BATALHA NAVAL COM HABILIDADES ===\n");
    for (linha = 0; linha < TAM_TABULEIRO; linha++) {
        for (coluna = 0; coluna < TAM_TABULEIRO; coluna++) {
            printf("%d ", tabuleiro[linha][coluna]);  // Imprime cada posição com espaço separador
        }
        printf("\n");  // Nova linha para a próxima linha do tabuleiro
    }

    printf("\nFim da simulação! Habilidades sobrepostas com sucesso.\n");

    return 0;
}
