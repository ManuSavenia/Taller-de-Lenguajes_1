#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int recorrer(char *ptr, char V[], int boolean);
int main()
{
    int boolean;
    int contador = 0;
    char string[100];
    char *ptr = string;
    printf("Enter a string: ");
    scanf("%s", string);
    printf("..............................\n");
    boolean = recorrer(ptr, string, boolean);
    while (boolean = 0)
    {
        printf("Enter a string: ");
        scanf("%s", string);
        printf("..............................\n");
        boolean = recorrer(ptr, string, boolean);
        --ptr;
        if (*ptr == 'o')
        {
            ++contador;
        }
    }
    printf("La cantidad de palabras que terminan en 'o' es: %d", contador);
    return 0;
}
int recorrer(char *ptr, char V[], int boolean)
{
    int contador = 0;
    int contador2 = 0;
    for (int i = 0; i < strlen(V); i++)
    {
        if (*ptr == "X")
        {
            ++contador;
        }
        if (*ptr != "X")
        {
            contador = 0;
        }
        ++ptr;
    }
    if (contador == 3)
    {
        boolean = 1;
    }
    else
    {
        boolean = 0;
    }
    return boolean;
}