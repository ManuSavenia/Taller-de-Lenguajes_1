#include <stdio.h>
#include <stdlib.h>
int calculomax(int *p, int n);
void inicializar(int *p, int n);
void reservar(int *p, int n);
int main()
{
    int *p, n;
    printf("Ingrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);
    reservar(p, n);
    inicializar(p, n);
    printf("El maximo es: %d", calculomax(p, n));
    return 0;
}
void reservar(int *p, int n)
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
        *(p + i) = rand() % 100;
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