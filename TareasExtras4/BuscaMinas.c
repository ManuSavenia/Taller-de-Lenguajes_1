#include <stdio.h>
#include <stdlib.h>
typedef struct Celda
{
    int esMina;
    int esVisible;
    int tieneBandera;
    int cantMinasCercanas;
} celda;
celda **crearMatriz();
void iniciarMatriz(celda **matriz, int *Cantminas);
int VerSiesMina(int *Cantminas);
void PonerMinas(celda **matriz, int *Cantminas);
void MarcarAlrededor(celda **matriz, int i, int j);
int ObtenerColumna(char k);
void LiberarCasilla(celda **matriz, int *CantCasillas);
void PonerBandera(celda **matriz, int *Cantminas);
void AnalizarCasilla(celda **matriz, int i, int j);
void ImprimirTablero(celda **matriz);
void show_board(celda **board);
int main()
{
    int CantMinas = 10;
    int CantCasillas = 54;
    printf("Bienvenido al Buscaminas\n");
    celda **matriz = crearMatriz();
    printf("Tablero inicial\n");
    iniciarMatriz(matriz, &CantMinas);
    show_board(matriz);
    CantMinas = 10;
    while (CantCasillas > 0 && CantMinas > 0)
    {
        int i;
        printf("Ingrese 0 para marcar casilla, 1 para poner bandera: ");
        scanf("%d", &i);
        if (i == 0)
        {
            LiberarCasilla(matriz, &CantCasillas);
        }
        else if (i == 1)
        {
            PonerBandera(matriz, &CantMinas);
        }
        show_board(matriz);
    }

    return 0;
}

celda **crearMatriz()
{
    celda **matriz;
    matriz = (celda **)malloc(8 * sizeof(celda *));
    for (int i = 0; i < 8; i++)
    {
        matriz[i] = (celda *)malloc(8 * sizeof(celda));
    }
    return matriz;
}

void iniciarMatriz(celda **matriz, int *Cantminas)
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            matriz[i][j].esVisible = 0;
            matriz[i][j].tieneBandera = 0;
            matriz[i][j].cantMinasCercanas = 0;
        }
    }
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if ((*Cantminas) > 0)
                PonerMinas(matriz, Cantminas);
        }
    }
}

void PonerMinas(celda **matriz, int *Cantminas)
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            matriz[i][j].esMina = VerSiesMina(Cantminas);
            if (matriz[i][j].esMina == 1)
                MarcarAlrededor(matriz, i, j);
        }
    }
}

int VerSiesMina(int *Cantminas)
{
    int i;
    int mina = 0;
    for (i = 0; i < (*Cantminas); i++)
    {
        mina = rand() % 2;
    }
    if (mina == 1)
    {
        (*Cantminas)--;
    }
    return mina;
}

void MarcarAlrededor(celda **matriz, int i, int j)
{
    int k, l;
    for (k = i - 1; k <= i + 1; k++)
    {
        for (l = j - 1; l <= j + 1; l++)
        {
            if (k >= 0 && k < 8 && l >= 0 && l < 8)
            {
                matriz[k][l].cantMinasCercanas++;
            }
        }
    }
}

int ObtenerColumna(char k)
{
    int j;
    if (k >= 'a' && k <= 'h')
        j = k - 'a';
    else if (k >= 'A' && k <= 'H')
        j = k - 'A';
    else
        printf("Error");
    return j;
}

void LiberarCasilla(celda **matriz, int *CantCasillas)
{
    int i, j;
    char m;
    printf("Ingrese la fila: ");
    scanf("%d", &i);
    getchar();
    printf("Ingrese la columna: ");
    scanf("%c", &m);
    j = ObtenerColumna(m);
    matriz[i][j].esVisible = 1;
    if (matriz[i][j].esMina == 1)
    {
        printf("JAJAJAJA PERDISTE MALO DE MIERDA\n");
        show_board(matriz);
        exit(0);
    }
    else if (matriz[i][j].cantMinasCercanas == 0)
    {
        for (int k = i - 1; k <= i + 1; k++)
        {
            for (int l = j - 1; l <= j + 1; l++)
            {
                if (k >= 0 && k < 8 && l >= 0 && l < 8)
                {
                    if (matriz[k][l].esVisible == 0)
                        AnalizarCasilla(matriz, k, l);
                }
            }
        }
    }
    (*CantCasillas)--;
}

void PonerBandera(celda **matriz, int *Cantminas)
{
    int i, j;
    char k;
    printf("Ingrese la fila: ");
    scanf("%d", &i);
    getchar();
    printf("Ingrese la columna: ");
    scanf("%c", &k);
    j = ObtenerColumna(k);
    if (matriz[i][j].tieneBandera == 1)
        matriz[i][j].tieneBandera = 0;
    else if (matriz[i][j].tieneBandera == 0)
        matriz[i][j].tieneBandera = 1;
    if (matriz[i][j].esMina == 1)
        (*Cantminas)--;
}

void AnalizarCasilla(celda **matriz, int i, int j)
{
    if (matriz[i][j].cantMinasCercanas == 0)
    {
        matriz[i][j].esVisible = 1;
        for (int k = i - 1; k <= i + 1; k++)
        {
            for (int l = j - 1; l <= j + 1; l++)
            {
                if (k >= 0 && k < 8 && l >= 0 && l < 8)
                {
                    if (matriz[k][l].esVisible == 0)
                        AnalizarCasilla(matriz, k, l);
                }
            }
        }
    }
}

void ImprimirTablero(celda **matriz)
{
    int i, j;
    for (i = 0; i < 8; i++)
    {
        for (j = 0; j < 8; j++)
        {
            if (matriz[i][j].esVisible == 0)
            {
                printf("X");
            }
            else if (matriz[i][j].esVisible == 1)
            {
                if (matriz[i][j].esMina == 1)
                {
                    printf("*");
                }
                else if (matriz[i][j].cantMinasCercanas == 0)
                {
                    printf(" ");
                }
                else
                {
                    printf("%d", matriz[i][j].cantMinasCercanas);
                }
            }
            else if (matriz[i][j].tieneBandera == 1)
            {
                printf("B");
            }
        }
        printf("\n");
    }
}

void show_board(celda **board)
{
    printf("-------------------------------------\n");
    printf("|   | A | B | C | D | E | F | G | H |\n");
    printf("-------------------------------------\n");
    for (int i = 0; i < 8; i++)
    {
        for (int j = 0; j < 8 + 1; j++)
        {
            if (j == 0)
            {
                printf("| %d |", i + 1);
            }
            else if (board[i][j - 1].esVisible)
            {
                if (board[i][j - 1].esMina)
                {
                    printf(" X |");
                }
                else if (board[i][j - 1].cantMinasCercanas == 0)
                {
                    printf("   |");
                }
                else if (board[i][j - 1].cantMinasCercanas > 0)
                {
                    printf(" %d |", board[i][j - 1].cantMinasCercanas);
                }
            }
            else
            {
                if (board[i][j - 1].tieneBandera)
                {
                    printf(" M |");
                }
                else
                {
                    printf(" ? |");
                }
            }
        }
        printf("\n-------------------------------------");
        printf("\n");
    }
}
