#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int cambiar(char string[]);
int main()
{
    char string[30];
    printf("Ingrese una palabra: \n");
    scanf("%s", string);
    int contador = cambiar(string);
    printf("La cantidad de letras es: %d", contador);
    return 0;
}
int cambiar(char string[])
{
    char *ptr3;
    ptr3 = string;
    int contador = 0;
    while (*ptr3 != '\0')
    {
        ++ptr3;
        contador++;
    }
    return contador;
}