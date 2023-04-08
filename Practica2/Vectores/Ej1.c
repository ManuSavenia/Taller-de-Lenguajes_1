#include <stdio.h>
#include <stdlib.h>

void par(int a, int *b)
{
    a %= 2;
    if (a == 0)
        *b = 1;
    else
        *b = 0;
}

int main()
{
    int V[50];
    int pares = 0;
    int impares = 0;
    int n1, n2;
    for (int i = 0; i < 50; i++)
    {
        V[i] = rand() % 50;
    }
    for (int i = 0; i < 50; i++)
    {
        n2 = i;
        par(V[i], &n1);
        par(i, &n2);
        if (n1 == 1 && n2 == 0)
        {
            pares++;
        }
        else
        {
            if (n1 == 0 && n2 == 1)
            {
                impares++;
            }
        }
    }
    printf("la cantidad de numeros pares en i impar es %d, y la cantidad de numeros impares en i par es %d", pares, impares);
}