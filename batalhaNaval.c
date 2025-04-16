#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

void PosicionaNavioHorizontal(int _tabuleiro[][10], int navio[], int indexlinha, int indexColuna, int numNavio)
{
    int sobreposicao = 0; // verifica se já exite navio nesta posição

    for (int i = indexColuna, j = 0; i < indexColuna + 3 && j < 3; i++, j++)
    {
        if (!_tabuleiro[indexlinha][i] == 0)
        {
            printf("Erro ao inserir o navio Nº: %d, já existe um navio nesta posição\n", numNavio);
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao == 0)
    {
        for (int i = indexColuna, j = 0; i < indexColuna + 3 && j < 3; i++, j++)
        { // A variável i manipula a posição da matriz e a j representa as posições do navio
            if (indexColuna + 2 > 9)
            { // Valida se o navio está nos limites do tabuleiro
                printf("Erro ao inserir o navio Nº: %d, fora dos limites do tabuleiro\n", numNavio);
                break;
            }
            _tabuleiro[indexlinha][i] = navio[j];
        }
    }
}

void PosicionaNavioVertical(int _tabuleiro[][10], int navio[], int indexlinha, int indexColuna, int numNavio)
{
    int sobreposicao = 0; // verifica se já exite navio nesta posição

    for (int i = indexlinha, j = 0; i < indexlinha + 3 && j < 3; i++, j++)
    {
        if (!_tabuleiro[i][indexColuna] == 0)
        {
            printf("Erro ao inserir o navio Nº: %d, já existe um navio nesta posição\n", numNavio);
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao == 0)
    {
        for (int i = indexlinha, j = 0; i < indexlinha + 3 && j < 3; i++, j++)
        { // A variável i manipula a posição da matriz e a j representa as posições do navio
            if (indexlinha + 2 > 9)
            { // Valida se o navio está nos limites do tabuleiro
                printf("Erro ao inserir o navio Nº: %d, fora dos limites do tabuleiro\n", numNavio);
                break;
            }
            _tabuleiro[i][indexColuna] = navio[j];
        }
    }
}


void PosicionaNavioDiagonal(int _tabuleiro[][10], int navio[], int indexlinha, int indexColuna,int direcao, int numNavio)
{ 
    int sobreposicao = 0; // verifica se já exite navio nesta posição
    

    for (int i = 0, j = 0; i < 3; i++)
    {
        int coluna = (direcao!= 1)?indexColuna+i:indexColuna-i;// o parametro direcao determina a direção da diagonal, se igual à 1 é para a direita se diferente de 1 é para a esquerda
        int linha = i+indexlinha;
        if (_tabuleiro[linha][coluna] != 0)
        {
            printf("Erro ao inserir o navio Nº: %d, já existe um navio nesta posição\n", numNavio);
            sobreposicao = 1;
            break;
        }
    }

    if (sobreposicao == 0)
    {
        for (int i = 0, j = 0; i < 3; i++)
        { // A variável i manipula a posição da matriz e a j representa as posições do navio
            int coluna = (direcao!= 1)?indexColuna+i:indexColuna-i;
            int linha = i+indexlinha;
            if (indexlinha + 2 > 9 || (direcao ==1 && indexColuna -2 <0)||(direcao !=1 && indexColuna +2 >9) )
            { // Valida se o navio está nos limites do tabuleiro
                printf("Erro ao inserir o navio Nº: %d, fora dos limites do tabuleiro\n", numNavio);
                break;
            }
            _tabuleiro[linha][coluna] = navio[i];
        }
    }
}

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

    int tabuleiro[10][10];      // Matriz que representa um tabuleiro 10 x 10
    int navio01[3] = {3, 3, 3}; // Declarando e iniciando o navio 01
    int navio02[3] = {3, 3, 3}; // Declarando e iniciando o navio 02
    int navio03[3] = {3, 3, 3}; // Declarando e iniciando o navio 03 - Nível aventureiro
    int navio04[3] = {3, 3, 3}; // Declarando e iniciando o navio 04 - Nível aventureiro

    for (int i = 0; i < 10; i++)
    { // Loop para inicializar os valores do tabuleiro com 0

        for (int j = 0; j < 10; j++)
        {

            tabuleiro[i][j] = 0;
        }
    }

    // Inserir os navios no tabuleiro:

    // Insere o navio01 horizontalmente na 7º linha do tabuleiro
    PosicionaNavioHorizontal(&tabuleiro, navio01, 6, 4, 1);

    // Insere o navio02 verticalmente na 8º coluna do tabuleiro
    PosicionaNavioVertical(&tabuleiro, navio02, 2, 7, 2);

    // Insere o navio03 diagonalmente no tabuleiro
    PosicionaNavioDiagonal(&tabuleiro,navio03,1,4,1,3);

    // Insere o navio04 diagonalmente no tabuleiro
    PosicionaNavioDiagonal(&tabuleiro,navio04,7,4,0,4);
    

    // Loop para exibir o tabuleiro com os navios
    for (int i = 0; i <= 10; i++)
    {
        if (i > 0)
        {
            printf("  %d", i - 1); // Cria os índices de linha do tabuleiro
        }

        for (int j = 0; j < 10; j++)
        {

            if (j == 0)
            {
                printf("  "); // Inicia cada linha com uma sequencia de espaços em branco para melhorar a visibilidade
            }

            if (i == 0)
            {// Cria os índices de coluna do tabuleiro
                if (j == 0)
                {
                    printf("   "); // Alinha os índices de coluna com o tabuleiro
                }
                printf("%d ", j);
            }
            else
            {

                printf("%d ", tabuleiro[i - 1][j]);
            }
        }

        printf("\n");
    }

    printf("\n\n");

    return 0;
}
