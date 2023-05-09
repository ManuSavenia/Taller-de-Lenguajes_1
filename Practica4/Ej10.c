#include <stdio.h>
#include <stdlib.h>
void inicializar(double *p, int n);
double *reservar(double *p, int n);
int main()
{
    double *p;
    int n;
    printf("Ingrese la cantidad de elementos del arreglo: ");
    scanf("%d", &n);
    p = reservar(p, n);
    inicializar(p, n);
    free(p);
    return 0;
}
double *reservar(double *p, int n)
{
    p = (double *)malloc(n * sizeof(double));
    if (p == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }
}
void inicializar(double *p, int n)
{
    int i;
    double j;
    for (i = 0; i < n; i++)
    {
        printf("ingrese un numero: ");
        scanf("%lf", &j);
        p[i] = j;
    }
}