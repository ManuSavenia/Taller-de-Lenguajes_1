#include <stdio.h>
#include <stdlib.h>
float calculoprom(float *p, float n);
void inicializar(float *p, float n);
float* reservar(float *p, float n);
int main()
{
    float *p, n;
    printf("Ingrese la cantidad de elementos del arreglo: ");
    scanf("%f", &n);
    p = reservar(p, n);
    inicializar(p, n);
    printf("debugnashe\n");
    printf("El promedio es: %f\n", calculoprom(p, n));
    free(p);
    return 0;
}
float* reservar(float *p, float n)
{
    p = (float *)malloc(n * sizeof(float));
    if (p == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }
}
void inicializar(float *p, float n)
{
    int i;
    for (i = 0; i < n; i++)
    {
        printf("debug %d\n", i);
        scanf("%f", (p + i));
    }
}
float calculoprom(float *p, float n)
{
    int i;
    float suma;
    suma = 0;
    for (i = 0; i < n; i++)
    {
        suma += *(p + i);
    }
    suma = suma / n;
    return suma;
}