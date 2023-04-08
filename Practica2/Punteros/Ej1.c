#include <stdio.h>
#include <stdlib.h>

void todoEnUno(float V[], float *promedio, int *minimo, int *maximo);
int main()
{
    float promedio;
    int minimo;
    int maximo;
    int i;
    float V[10];
    for (i = 0; i < 10; i++)
    {
        V[i] = i;
    }
    todoEnUno(V, &promedio, &minimo, &maximo);
    printf("el promedio es igual a %0.2f\n", promedio);
    printf("el minimo es %d\n", minimo);
    printf("la posicion del nro maximo es %d\n", maximo);
    return 0;
}
void todoEnUno(float V[], float *promedio, int *minimo, int *maximo)
{
    float suma = 0;
    for (int i = 0; i < 10; i++)
    {
        suma += V[i];
    }
    *promedio = suma / 10;

    int min = 99999;
    for (int i = 0; i < 10; i++)
    {
        if (V[i] < min)
            min = V[i];
    }
    *minimo = min;

    int posmax = 0;
    int max = 0;
    for (int i = 0; i < 10; i++)
    {
        if (max < V[i])
        {
            max = V[i];
            posmax = i;
        }
    }
    *maximo = posmax;
}