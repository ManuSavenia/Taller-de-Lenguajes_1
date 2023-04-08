#include <stdio.h>
#include <stdlib.h>
#include <string.h>
char *cambiar(char *ptr1, char *ptr2, char string[]);
int main()
{
    char string[30];
    char *ptr1, *ptr2;
    char a = 'a', b = 'b';
    printf("Ingrese una palabra: \n");
    scanf("%s", string);
    ptr1 = &a;
    ptr2 = &b;
    strcpy(string, cambiar(ptr1, ptr2, string));
    printf("La palabra es: %s", string);
    return 0;
}

char *cambiar(char *ptr1, char *ptr2, char string[])
{
    char *ptr3;
    ptr3 = string;
    while (*ptr3 != '\0')
    {
        if (*ptr3 == *ptr1)
        {
            *ptr3 = *ptr2;
        }
        ++ptr3;
    }
    return string;
}