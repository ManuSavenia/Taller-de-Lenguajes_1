#include <stdio.h>
int encontrar(int n, int vector[]);
int main()
{
    int vector[1000];
    int n;
    for (int i = 0; i < 1000; i++)
    {
        vector[i] = rand() % 1000;
    }
    printf("%d\n", vector[10]);
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    printf("El numero %d se encuentra en la posicion %d", n, encontrar(n, vector));
    return 0;
}

int encontrar(int n, int vector[])
{
    for (int i = 0; i < 1000; i++)
    {
        printf("i:%d\n", i);
        if (vector[i] == n)
        {
            return i;
        }
    }
    return -1;
}