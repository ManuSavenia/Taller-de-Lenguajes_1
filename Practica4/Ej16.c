#include <stdio.h>
#include <stdlib.h>
int *verificar(int n, int *tamanio);
int main()
{
    int n, tamanio = 1;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    int *p = verificar(n, &tamanio);
    printf("%d\n", n);
    printf("%d\n", tamanio);
    for (int i = 0; i < tamanio; i++)
    {
        printf("%d ", *(p + i));
    }

    return 0;
}
int *verificar(int n, int *tamanio)
{
    int *p = (int *)malloc((*tamanio) * (sizeof(int)));
    p[0] = 1;
    for (int i = 2; i <= n; i++)
    {
        if (n % i == 0)
        {
            
            (*tamanio)++;
            p = realloc(p, ((*tamanio) * sizeof(int)));
            printf("%d ", *(p + i));
            p[(*tamanio) - 1] = i;
        }
    }
    return p;
}