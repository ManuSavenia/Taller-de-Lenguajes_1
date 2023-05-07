#include <stdio.h>
#include <stdlib.h>
int calculomax(int *p, int n);
void inicializar(int *p, int n);
int* reservar(int *p, int n);
int main()
{
    int *p, n;
    printf("Ingrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);
    p = reservar(p, n);
    printf("debug\n");
    inicializar(p, n);
    printf("debug\n");
    printf("El maximo es: %d\n", calculomax(p, n));
    free(p);
    return 0;
}
int * reservar(int *p, int n)
{
    p = (int *)malloc(n * sizeof(int));
    if (p == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }
}
void inicializar(int *p, int n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("debug %d\n", i);
        *(p + i) = rand() % 10;
        printf("debug %d\n", i);
    }
}
int calculomax(int *p, int n)
{
    int i, max;
    max = 0;
    for (i = 0; i < n; i++)
    {
        if (*(p + i) > max)
        {
            max = *(p + i);
        }
    }
    return max;
}