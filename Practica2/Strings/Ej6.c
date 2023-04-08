#include <stdio.h>
int main()
{
    char string[10];
    char minusculas[25];
    int cantMinusculas[25];
    int i, j;
    char *ptr;
    for (i = 0; i < 25; i++)
    {
        minusculas[i] = i + 97;
    }
    for (i = 0; i < 25; i++)
    {
        cantMinusculas[i] = 0;
    }
    printf("Ingrese una palabra: \n");
    scanf("%s", string);
    ptr = string;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 25; j++)
        {
            if (*ptr == minusculas[j])
            {
                cantMinusculas[j]++;
            }
        }
        ptr++;
    }
    for (i = 0; i < 25; i++)
    {
        printf("La cantidad de %c es: %d\n", minusculas[i], cantMinusculas[i]);
    }
    return 0;
}