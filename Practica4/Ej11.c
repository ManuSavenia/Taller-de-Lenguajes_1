#include <stdio.h>
#include <stdlib.h>
void inicializar(int **p, int n, int m);
int **reservar(int **p, int n, int m);
void muliploDeTres(int **p, int n, int m);
int main()
{
    int **p;
    int n, m;
    printf("Ingrese la cantidad de filas de la matriz: ");
    scanf("%d", &n);
    printf("Ingrese la cantidad de columnas de la matriz: ");
    scanf("%d", &m);
    p = reservar(p, n, m);
    inicializar(p, n, m);
    muliploDeTres(p, n, m);
    for (int i = 0; i < n; i++)
    {
        free(p[i]);
    }
    free(p);
    return 0;
}
int **reservar(int **p, int n, int m)
{
    p = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        p[i] = (int *)malloc(m * sizeof(int));
    }
    if (p == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }
    return p;
}
void inicializar(int **p, int n, int m)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            printf("ingrese un numero: ");
            scanf("%d", &k);
            printf("debug\n");
            p[i][j] = k;
            printf("debug\n");
        }
    }
}
void muliploDeTres(int **p, int n, int m)
{
    int i, j, k;
    for (i = 0; i < n; i++)
    {
        for (j = 0; j < m; j++)
        {
            if (p[i][j] % 3 == 0)
            {
                printf("%d [%d][%d]\n", p[i][j], i, j);
            }
        }
    }
}