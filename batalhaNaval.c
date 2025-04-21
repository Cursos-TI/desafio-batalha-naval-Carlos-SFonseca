#include <stdio.h>

// Desafio Batalha Naval - MateCheck
// Este código inicial serve como base para o desenvolvimento do sistema de Batalha Naval.
// Siga os comentários para implementar cada parte do desafio.

#define TAMANHO_TABULEIRO 10 // Define o tamanho do tabuleiro como 10x10
#define TAMANHO_NAVIO 3      // Define o tamanho dos navios como 3
#define TAMANHO_HABILIDADE 5 // Define o tamanho das habilidades como 5x5

// Função que recebe o tabuleiro, um navio, o índice da linha inicial, o índice da coluna inicial, o número do navio
// e posiciona o navio recebido horizontalmente no tabuleiro:
void PosicionaNavioHorizontal(int _tabuleiro[][TAMANHO_TABULEIRO], int navio[], int indexlinha, int indexColuna, int numNavio)
{
    // Valida se o navio está nos limites do tabuleiro:
    if (indexColuna + TAMANHO_NAVIO - 1 > TAMANHO_TABULEIRO - 1)
    {
        printf("Erro ao inserir o navio Nº: %d, fora dos limites do tabuleiro\n", numNavio);
        return;
    }

    // verifica se já exite navio nesta posição:
    for (int i = indexColuna, j = 0; i < indexColuna + TAMANHO_NAVIO && j < TAMANHO_NAVIO; i++, j++)
    {
        if (!_tabuleiro[indexlinha][i] == 0)
        {
            printf("Erro ao inserir o navio Nº: %d, já existe um navio nesta posição\n", numNavio);
            return;
        }
    }

    // posiciona o navio no tabuleiro:
    for (int i = indexColuna, j = 0; i < indexColuna + TAMANHO_NAVIO && j < TAMANHO_NAVIO; i++, j++)
    { // A variável i manipula a posição da matriz e a j representa as posições do navio

        _tabuleiro[indexlinha][i] = navio[j];
    }
}

// Função que recebe o tabuleiro, um navio, o índice da linha inicial, o índice da coluna inicial, o número do navio
// e posiciona o navio recebido verticalmente no tabuleiro:
void PosicionaNavioVertical(int _tabuleiro[][TAMANHO_TABULEIRO], int navio[], int indexlinha, int indexColuna, int numNavio)
{
    // Valida se o navio está nos limites do tabuleiro:
    if (indexlinha + TAMANHO_NAVIO - 1 > TAMANHO_TABULEIRO - 1)
    {
        printf("Erro ao inserir o navio Nº: %d, fora dos limites do tabuleiro\n", numNavio);
        return;
    }

    // verifica se já exite navio nesta posição:
    for (int i = indexlinha, j = 0; i < indexlinha + TAMANHO_NAVIO && j < TAMANHO_NAVIO; i++, j++)
    {
        if (!_tabuleiro[i][indexColuna] == 0)
        {
            printf("Erro ao inserir o navio Nº: %d, já existe um navio nesta posição\n", numNavio);
            return;
        }
    }

    // posiciona o navio no tabuleiro:
    for (int i = indexlinha, j = 0; i < indexlinha + TAMANHO_NAVIO && j < TAMANHO_NAVIO; i++, j++)
    { // A variável i manipula a posição da matriz e a j representa as posições do navio

        _tabuleiro[i][indexColuna] = navio[j];
    }
}

// Função que recebe o tabuleiro, um navio, o índice da linha inicial, o índice da coluna inicial, a direção da diagonal, o número do navio
// e posiciona o navio recebido diagonalmente no tabuleiro:
// Obs.: Quando o parametro derecao for igual à 1 a diagonal será para a direita, para qualquer outro valor a diagonal será para a esquerda.
void PosicionaNavioDiagonal(int _tabuleiro[][TAMANHO_TABULEIRO], int navio[], int indexlinha, int indexColuna, int direcao, int numNavio)
{
    // Valida se o navio está nos limites do tabuleiro:
    if (indexlinha + TAMANHO_NAVIO - 1 > TAMANHO_TABULEIRO - 1 || (direcao == 1 && indexColuna - TAMANHO_NAVIO + 1 < 0) || (direcao != 1 && indexColuna + TAMANHO_NAVIO - 1 > TAMANHO_TABULEIRO - 1))
    {
        printf("Erro ao inserir o navio Nº: %d, fora dos limites do tabuleiro\n", numNavio);
        return;
    }

    // verifica se já exite navio nesta posição:
    for (int i = 0, j = 0; i < TAMANHO_NAVIO; i++)
    {
        int coluna = (direcao != 1) ? indexColuna + i : indexColuna - i;

        int linha = i + indexlinha;
        if (_tabuleiro[linha][coluna] != 0)
        {
            printf("Erro ao inserir o navio Nº: %d, já existe um navio nesta posição\n", numNavio);
            return;
        }
    }

    // posiciona o navio no tabuleiro:
    for (int i = 0, j = 0; i < TAMANHO_NAVIO; i++)
    { // A variável i manipula a posição da matriz e a j representa as posições do navio
        int coluna = (direcao != 1) ? indexColuna + i : indexColuna - i;
        int linha = i + indexlinha;

        _tabuleiro[linha][coluna] = navio[i];
    }
}

// Função que recebe o tabuleiro, o valor inicial
// e preenche todo o tabuleiro com o valor inicial:
void InciarTabuleiro(int _tabuleiro[][TAMANHO_TABULEIRO], int valorInicial)
{
    // Loop para inicializar os valores do tabuleiro com o valorInicial:
    for (int i = 0; i < TAMANHO_TABULEIRO; i++)
    {
        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {
            _tabuleiro[i][j] = valorInicial;
        }
    }
}

// Função que recebe o tabuleiro como parâmetro e realiza a exibição:
void ExibirTabuleiro(int _tabuleiro[][TAMANHO_TABULEIRO])
{
    // Loop para exibir o tabuleiro:
    for (int i = 0; i <= TAMANHO_TABULEIRO; i++)
    {
        if (i > 0)
        {
            printf("  %d", i - 1); // Cria os índices de linha do tabuleiro
        }

        for (int j = 0; j < TAMANHO_TABULEIRO; j++)
        {

            if (j == 0)
            {
                printf("  "); // Inicia cada linha com uma sequência de espaços em branco para melhorar a visibilidade
            }

            if (i == 0)
            { // Cria os índices de coluna do tabuleiro
                if (j == 0)
                {
                    printf("   "); // Alinha os índices de coluna com o tabuleiro
                }
                printf("%d ", j);
            }
            else
            {

                printf("%d ", _tabuleiro[i - 1][j]);
            }
        }

        printf("\n");
    }
}

// Função que recebe o tabuleiro, o índice da linha inicial, o índice da coluna inicial, o número que será exibido na representação da habilidade
// e posiciona a habilidade Cone no tabuleiro:
void PosicionaCone(int _tabuleiro[][TAMANHO_TABULEIRO], int indexlinha, int indexColuna, int numHabilidade)
{
    int centroDoCone = TAMANHO_HABILIDADE / 2; // Define o índice da coluna central do cone

    // Verifica se o número que representará a habilidade é válido, ou seja, diferente de 0:
    if (numHabilidade == 0)
    {
        printf("Erro ao inserir a habilidade Cone, o número da habilidade não pode ser 0\n");
        return;
    }

    // Valida se o Cone está nos limites do tabuleiro:
    if (indexColuna + TAMANHO_HABILIDADE - 1 > TAMANHO_TABULEIRO - 1 || indexlinha + centroDoCone > TAMANHO_TABULEIRO - 1)
    {
        printf("Erro ao inserir a habilidade Cone, fora dos limites do tabuleiro\n");
        return;
    }

    // verifica se já exite uma habilidade nesta posição:
    for (int i = 0; i <= centroDoCone; i++)
    {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++)
        {
            if (j >= centroDoCone - i && j <= centroDoCone + i && _tabuleiro[indexlinha + i][indexColuna + j] != 0)
            {
                printf("Erro ao inserir o Cone, já existe outra habilidade nesta posição\n");
                return;
            }
        }
    }

    // insere o Cone no tabuleiro:
    for (int i = 0; i <= centroDoCone; i++)
    {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++)
        {
            if (j >= centroDoCone - i && j <= centroDoCone + i)
            {
                _tabuleiro[indexlinha + i][indexColuna + j] = numHabilidade;
            }
        }
    }
}

// Função que recebe o tabuleiro, o índice da linha inicial, o índice da coluna inicial, o número que será exibido na representação da habilidade
// e posiciona a habilidade Octaedro no tabuleiro:
void PosicionaOctaedro(int _tabuleiro[][TAMANHO_TABULEIRO], int indexlinha, int indexColuna, int numHabilidade)
{
    // Verifica se o número que representará a habilidade é válido, ou seja, diferente de 0:
    if (numHabilidade == 0)
    {
        printf("Erro ao inserir a habilidade Octaedro, o número da habilidade não pode ser 0\n");
        return;
    }

    // Valida se o Octaedro está nos limites do tabuleiro:
    if (indexColuna + TAMANHO_HABILIDADE - 1 > TAMANHO_TABULEIRO - 1 || indexlinha + TAMANHO_HABILIDADE - 1 > TAMANHO_TABULEIRO - 1)
    {
        printf("Erro ao inserir a habilidade Octaedro, fora dos limites do tabuleiro\n");
        return;
    }

    int linhaCentral = TAMANHO_HABILIDADE / 2;  // Define a linha central da habilidade
    int colunaCentral = TAMANHO_HABILIDADE / 2; // Define a coluna central da habilidade

    // verifica se já exite uma habilidade nesta posição:
    for (int i = 0; i < TAMANHO_HABILIDADE; i++)
    {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++)
        {
            if (i <= linhaCentral && j >= colunaCentral - i && j <= colunaCentral + i && _tabuleiro[indexlinha + i][indexColuna + j] != 0)
            {
                printf("Erro ao inserir o Octaedro, já existe outra habilidade nesta posição\n");
                return;
            }

            if (i > linhaCentral && j >= i - linhaCentral && j <= TAMANHO_HABILIDADE - 1 - i + linhaCentral && _tabuleiro[indexlinha + i][indexColuna + j] != 0)
            {
                printf("Erro ao inserir o Octaedro, já existe outra habilidade nesta posição\n");
                return;
            }
        }
    }

    // insere o Octaedro no tabuleiro:
    for (int i = 0; i < TAMANHO_HABILIDADE; i++)
    {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++)
        {
            if (i <= linhaCentral && j >= colunaCentral - i && j <= colunaCentral + i)
            {
                _tabuleiro[indexlinha + i][indexColuna + j] = numHabilidade;
            }

            if (i > linhaCentral && j >= i - linhaCentral && j <= TAMANHO_HABILIDADE - 1 - i + linhaCentral)
            {
                _tabuleiro[indexlinha + i][indexColuna + j] = numHabilidade;
            }
        }
    }
}

// Função que recebe o tabuleiro, o índice da linha inicial, o índice da coluna inicial, o número que será exibido na representação da habilidade
// e posiciona a habilidade Cruz no tabuleiro:
void PosicionaCruz(int _tabuleiro[][TAMANHO_TABULEIRO], int indexlinha, int indexColuna, int numHabilidade)
{
    // Verifica se o número que representará a habilidade é válido, ou seja, diferente de 0:
    if (numHabilidade == 0)
    {
        printf("Erro ao inserir a habilidade Cruz, o número da habilidade não pode ser 0\n");
        return;
    }

    // Valida se a Cruz está nos limites do tabuleiro:
    if (indexColuna + TAMANHO_HABILIDADE - 1 > TAMANHO_TABULEIRO - 1 || indexlinha + TAMANHO_HABILIDADE - 1 > TAMANHO_TABULEIRO - 1)
    {
        printf("Erro ao inserir a habilidade Cruz, fora dos limites do tabuleiro\n");
        return;
    }

    int linhaCentral = TAMANHO_HABILIDADE / 2;  // Define a linha central da habilidade
    int colunaCentral = TAMANHO_HABILIDADE / 2; // Define a coluna central da habilidade

    // verifica se já exite uma habilidade nesta posição:
    for (int i = 0; i < TAMANHO_HABILIDADE; i++)
    {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++)
        {
            if (j == colunaCentral && _tabuleiro[indexlinha + i][indexColuna + j] != 0)
            {
                printf("Erro ao inserir a Cruz, já existe outra habilidade nesta posição\n");
                return;
            }

            if (i == linhaCentral && _tabuleiro[indexlinha + i][indexColuna + j] != 0)
            {
                printf("Erro ao inserir a Cruz, já existe outra habilidade nesta posição\n");
                return;
            }
        }
    }

    // insere a Cruz no tabuleiro:
    for (int i = 0; i < TAMANHO_HABILIDADE; i++)
    {
        for (int j = 0; j < TAMANHO_HABILIDADE; j++)
        {
            if (j == colunaCentral)
            {
                _tabuleiro[indexlinha + i][indexColuna + j] = numHabilidade;
            }

            if (i == linhaCentral)
            {
                _tabuleiro[indexlinha + i][indexColuna + j] = 3;
            }
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

    int tabuleiro[TAMANHO_TABULEIRO][TAMANHO_TABULEIRO]; // Matriz que representa um tabuleiro 10 x 10
    int navio01[TAMANHO_NAVIO] = {3, 3, 3};              // Declarando e iniciando o navio 01
    int navio02[TAMANHO_NAVIO] = {3, 3, 3};              // Declarando e iniciando o navio 02
    int navio03[TAMANHO_NAVIO] = {3, 3, 3};              // Declarando e iniciando o navio 03 - Nível aventureiro
    int navio04[TAMANHO_NAVIO] = {3, 3, 3};              // Declarando e iniciando o navio 04 - Nível aventureiro

    // Inicia os valores do tabuleiro com 0:
    InciarTabuleiro(tabuleiro, 0);

    // Inserir os navios no tabuleiro:

    // Insere o navio01 horizontalmente na 7º linha a partir da 5º coluna do tabuleiro:
    PosicionaNavioHorizontal(tabuleiro, navio01, 6, 4, 1);

    // Insere o navio02 verticalmente na 8º coluna a partir da 3º linha do tabuleiro:
    PosicionaNavioVertical(tabuleiro, navio02, 2, 7, 2);

    // Insere o navio03 diagonalmente no tabuleiro:
    PosicionaNavioDiagonal(tabuleiro, navio03, 2, 2, 1, 3);

    // Insere o navio04 diagonalmente no tabuleiro:
    PosicionaNavioDiagonal(tabuleiro, navio04, 7, 2, 0, 4);

    // Exibe o tabuleiro com os navios:
    printf("     Tabuleiro com os navios:\n");
    ExibirTabuleiro(tabuleiro);

    // Reinicia o tabuleiro com valores 0:
    InciarTabuleiro(tabuleiro, 0);
    printf("\n");
    printf("     Tabuleiro com as Habilidades:\n");

    // Pociciona o cone no tabuleiro:
    PosicionaCone(tabuleiro, 5, 0, 1);

    // Pociciona o octaedro no tabuleiro:
    PosicionaOctaedro(tabuleiro, 3, 5, 2);

    // Pociciona a cruz no tabuleiro:
    PosicionaCruz(tabuleiro, 0, 1, 3);

    // Exibe o tabuleiro com as habilidades:
    ExibirTabuleiro(tabuleiro);
    printf("\n\n");

    return 0;
}
