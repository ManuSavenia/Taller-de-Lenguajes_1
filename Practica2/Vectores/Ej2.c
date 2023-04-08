#include <stdio.h>

void promedio(float V[]);
void minimo(float V[]);
void maximo(float V[]);
int main()
{
    float V[10];
    for (int i = 0; i < 10; i++)
    {
        V[i] = i;
    }
    promedio(V);
    minimo(V);
    maximo(V);
}

void promedio(float V[])
{
    float suma = 0;
    for (int i = 0; i < 10; i++)
    {
        suma += V[i];
    }
    printf("el promedio es igual a %0.2f\n", suma / 10);
}

void minimo(float V[])
{
    int min = 99999;
    for (int i = 0; i < 10; i++)
    {
        if (V[i] < min)
            min = V[i];
    }
    printf("el minimo es %d\n", min);
}

void maximo(float V[])
{
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
    printf("la posicion del nro maximo es %d\n", posmax);
}
