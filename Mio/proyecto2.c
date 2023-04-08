#include <stdio.h>
#include <stdlib.h>

int main()
{
    int *array, c, n, i, l;
    printf("Ingrese la cantidad de numeros deseada\n");
    scanf("%d", &c);
    array = (int *)malloc(c * sizeof(int));
    printf("Ingrese los numeros (con 0 puedes cambiar el tamanio del vector)\n");
    for (i = 0; i < c; ++i)
    {
        printf("n%d= ", i + 1);
        scanf("%d", &n);
        if (n == 0)
        {
            printf("Ingrese nuevamente la cantidad de numeros deseada\n");
            scanf("%d", &c);
            if (i > c)
            {
                array = realloc(array, c * sizeof(int)); // me da paja eliminar la memoria dinamica pero habria que hacerlo
                printf("Ingrese 0 si quiere terminar el programa o 1 si quiere agrandar el vector y continuar el programa, el tamanio debe ser mayor o igual a %d\n", i);
                scanf("%d", &l);
                if (l == 0)
                    return 0;
                else
                {
                    printf("Ingrese nuevamente la cantidad de numeros deseada\n");
                    scanf("%d", &c);
                    array = realloc(array, c * sizeof(int));
                    printf("n%d= ", i + 1);
                    scanf("%d", &n);
                }
            }
            else
            {
                if (c > i)
                {
                    array = realloc(array, c * sizeof(int));
                    printf("n%d= ", i + 1);
                    scanf("%d", &n);
                }
            }
        }
        *(array + i) = n;
    }
    printf("---------------------------------------\n");
    for (i = 0; i < c; ++i)
    {
        printf("n%d= ", i + 1);
        printf("%d\n", *(array + i));
    }
    return 0;
}
