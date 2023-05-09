#include <stdio.h>
#include <stdlib.h>
void inicializar(int *p, int n);
int main()
{
    int *p;
    int n;
    printf("Ingrese el orden de la matriz triangular: ");
    scanf("%d", &n);
    p = (int *)malloc(n * n * sizeof(int));
    inicializar(p, n);
    // imprimir en forma de matriz
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            printf("%d ", *(p + i * n + j));
        }
        printf("\n");
    }
    free(p);
    return 0;
}
void inicializar(int *p, int n)
{
    int j = 1, k = 0;
    for (int i = 0; i < n*n; i+=n)
    {
        while (k < j)
        {
            printf("ingrese un numero: ");
            scanf("%d", p + i + k);
            k++;
        }
        while (k < n)
        {
            *(p + k + i) = 0;
            k++;
            printf("debug%d\n",i);
        }
        j++;
        k = 0;
    }
}