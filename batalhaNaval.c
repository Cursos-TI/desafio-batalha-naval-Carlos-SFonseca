#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

int main()
{
    // Nível Novato - Posicionamento dos Navios
    // Sugestão: Declare uma matriz bidimensional para representar o tabuleiro (Ex: int tabuleiro[5][5];).
    // Sugestão: Posicione dois navios no tabuleiro, um verticalmente e outro horizontalmente.
    // Sugestão: Utilize `printf` para exibir as coordenadas de cada parte dos navios.

    // Nível Aventureiro - Expansão do Tabuleiro e Posicionamento Diagonal
    // Sugestão: Expanda o tabuleiro para uma matriz 10x10.
    // Sugestão: Posicione quatro navios no tabuleiro, incluindo dois na diagonal.
    // Sugestão: Exiba o tabuleiro completo no console, mostrando 0 para posições vazias e 3 para posições ocupadas.

    // Nível Mestre - Habilidades Especiais com Matrizes
    // Sugestão: Crie matrizes para representar habilidades especiais como cone, cruz, e octaedro.
    // Sugestão: Utilize estruturas de repetição aninhadas para preencher as áreas afetadas por essas habilidades no tabuleiro.
    // Sugestão: Exiba o tabuleiro com as áreas afetadas, utilizando 0 para áreas não afetadas e 1 para áreas atingidas.

    // Exemplos de exibição das habilidades:
    // Exemplo para habilidade em cone:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 1 1 1 1 1

    // Exemplo para habilidade em octaedro:
    // 0 0 1 0 0
    // 0 1 1 1 0
    // 0 0 1 0 0

    // Exemplo para habilidade em cruz:
    // 0 0 1 0 0
    // 1 1 1 1 1
    // 0 0 1 0 0
    printf("     Jogo Batalha Naval\n\n");

    int tabuleiro[10][10];         // Matriz que representa um tabuleiro 10 x 10
    int navio01[3] = {3, 3, 3};    // Declarando e iniciando o navio 01
    int navio02[3] = {3, 3, 3}; // Declarando e iniciando o navio 02

    for (int i = 0; i < 10; i++)
    { // Loop para inicializar os valores do tabuleiro com 0

        for (int j = 0; j < 10; j++)
        {

            tabuleiro[i][j] = 0;
        }
    }

    // Inserir os navios no tabuleiro:

    // Insere o navio01 horizontalmente na 7º linha do tabuleiro
    for (int i = 2, j = 0; i < 5 && j < 3; i++, j++)
    { // A variável i manipula a posição da matriz e a j representa as posições do navio01
        tabuleiro[6][i] = navio01[j];
    }

    // Insere o navio02 verticalmente na 8º coluna do tabuleiro
    for (int i = 2, j = 0; i < 5 && j < 3; i++, j++)
    { // A variável i manipula a posição da matriz e a j representa as posições do navio02
        tabuleiro[i][7] = navio02[j];
    }

    // Loop para exibir o tabuleiro com os navios
    for (int i = 0; i < 10; i++)
    {

        for (int j = 0; j < 10; j++)
        {

            if (j == 0)
            {
                printf("     "); // Inicia cada linha com uma sequencia de espaços em branco para melhorar a visibilidade
            }

            printf("%d ", tabuleiro[i][j]);
        }

        printf("\n");
    }

    printf("\n\n");

    return 0;
}
