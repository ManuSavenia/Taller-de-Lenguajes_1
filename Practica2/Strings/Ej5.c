#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *copiar(char string[], char string2[]);
int main()
{
    char string[30];
    char string2[30];
    printf("Ingrese una palabra: \n");
    scanf("%s", string);
    char *ptr = copiar(string2, string);
    printf("La palabra es: %s", string2);
    return 0;
}
char *copiar(char string2[], char string[])
{
    char *ptr1, *ptr2;
    ptr1 = string;
    ptr2 = string2;
    while (*ptr1 != '\0')
    {
        *ptr2 = *ptr1;
        ++ptr1;
        ++ptr2;
    }
    *ptr2 = *ptr1;
    return string2;
}