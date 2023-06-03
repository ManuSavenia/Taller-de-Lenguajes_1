#include <stdio.h>
#include "imath.h"
int main()
{
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    while (n != 0)
    {
        if (par(n))
        {
            printf("El cuadrado de %d es %d\n", n, cuadrado(n));
            printf("El cubo de %d es %d\n", n, cubo(n));
        }
        else
        {
            printf("El factorial de %d es %d\n", n, factorial(n));
        }
        printf("Ingrese un numero: ");
        scanf("%d", &n);
    }
    return 0;
}