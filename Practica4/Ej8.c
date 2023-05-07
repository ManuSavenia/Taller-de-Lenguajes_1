#include <stdio.h>
#include <stdlib.h>
int *incrementar(int *p, int cant, int n);
int *eliminar(int *p, int *c, int n);
int main()
{
    int *p, *c, n, i, cant = 1;
    p = (int *)malloc(1 * sizeof(int));
    c = &cant;
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
    printf("lea un numero\n");
    scanf("%d", &n);
    p = eliminar(p, c, n);
    for (i = 0; i < *(c); i++)
    {
        printf("%d", *(p + i));
        printf(", ");
    }
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
int *eliminar(int *p, int *c, int n)
{
    int i, j;
    for (i = 0; i < *(c); i++)
    {
        if (*(p + i) % n == 0)
        {
            for (j = i; j < *(c); j++)
            {
                *(p + j) = *(p + j + 1);
            }
            *(c)--;
            p = (int *)realloc(p, *(c) * sizeof(int));
            if (p == NULL)
            {
                printf("No se pudo reservar memoria");
                exit(1);
            }
        }
    }
    return p;
}