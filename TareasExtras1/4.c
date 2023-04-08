#include <stdio.h>

int Sumar(int n, int suma);

int main()
{
    int n, suma;
    suma = 0;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    while ((n / 10) != 0)
    {
        n = Sumar(n, suma);
        printf("%d\n", n);
    }
    return 0;
}

int Sumar(int n, int suma)
{
    if (n == 0)
    {
        return suma;
    }
    else
    {
        suma += n % 10;
        Sumar(n / 10, suma);
    }
}