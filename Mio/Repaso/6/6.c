#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int **inicicalizar(int n);
int **rellenar(int **M, int n);
void imprimirMatriz(int **M, int n);
void liberar(int **M, int n);
int main()
{
    int n;
    printf("ingrese el tamanio de la matriz: ");
    scanf("%d", &n);
    int **M = inicicalizar(n);
    M = rellenar(M, n);
    imprimirMatriz(M, n);
    liberar(M,n);
    return 0;
}

int **inicicalizar(int n)
{
    int **M = (int **)malloc(sizeof(int *) * n);
    for (int i = 0; i < n; i++)
    {
        *(M + i) = (int *)malloc(sizeof(int) * n);
    }
    return M;
}

int **rellenar(int **M, int n)
{
    int i, j;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < n; j++)
        {
            M[i][j] = rand() % 9;
        }
    }
    return M;
}

void imprimirMatriz(int **M, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}
void liberar(int **M, int n)
{
    for (int i = 0; i < n; i++)
    {
        free(M[i]);
    }
    free(M);
}