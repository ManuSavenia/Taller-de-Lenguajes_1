#include <stdio.h>
#include <stdlib.h>

void agrandar(int *ptr, int i, int n)
{
    ptr = realloc(ptr, sizeof(ptr) + i);
    *(ptr + i) = n;
}

int main()
{
    int array[5], i, c, n;
    printf("Ingrese la cantidad de numeros deseada\n");
    scanf("%d", &c);
    printf("Ingrese los numeros\n");
    for (i = 0; i < c; ++i)
    {
        printf("n%d= ", i + 1);
        scanf("%d", &n);
        if (i <= 5)
        {
            array[i] = c;
        }
        else
        {
            agrandar(array, i, n);
        }
    }
    
    return 0;
}