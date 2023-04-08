#include <stdio.h>
#include <stdlib.h>
void empezar(int vector[]);
int organizar(int vector[]);
void imprimir(int vector[]);
int main()
{
    int vector[10];
    empezar(vector);
    imprimir(vector);
    printf("-------------------------------------------\n");
    organizar(vector);
    imprimir(vector);
    return 0;
}

void empezar(int vector[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        vector[i] = rand() % 101;
    }
}

int organizar(int vector[])
{
    int i, j, ant = 0, min = 9999;
    int vector2[10];
    for (i = 0; i < 10; i++)
    {
        vector2[i] = 0;
    }
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 10; j++)
        {
            if ((vector[j] <= min) && (vector[j] > ant))
            {
                min = vector[j];
            }
        }
        vector2[i] = min;
        ant = min;
        min = 9999;
    }
    for (i = 0; i < 10; i++)
    {
        vector[i] = vector2[i];
    }
    return vector;
}

void imprimir(int vector[])
{
    int i;
    for (i = 0; i < 10; i++)
    {
        printf("%d\n", vector[i]);
    }
}