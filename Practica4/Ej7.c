#include <stdio.h>
#include <stdlib.h>
int *incrementar(int *p, int cant, int n);
int main()
{
    int *p, *b, n, i, cant = 1, k = 0;
    printf("debug\n");
    p = (int *)malloc(1 * sizeof(int));
    printf("debug\n");
    while (n != 0)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &n);
        if (n != 0)
        {
            p = incrementar(p, cant, n);
            cant++;
        }
    }
    printf("debug\n");
    b = (int *)malloc(cant * sizeof(int));
    printf("debug\n");
    for (i = cant; i > 0; i--)
    {
        *(b + k) = *(p + i - 1);
        k++;
    }
    printf("debug\n");
    for (i = 0; i < cant; i++)
    {
        printf("%d", *(b + i));
        printf(", ");
    }
    printf("\n");
    for (i = 0; i < cant; i++)
    {
        printf("%d", *(p + i));
        printf(", ");
    }
    free(p);
    free(b);
    return 0;
}
int *incrementar(int *p, int cant, int n)
{
    p = (int *)realloc(p, (cant + 1) * sizeof(int));
    if (p == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }
    *(p + cant) = n;
    return p;
}