#include <stdio.h>
#include <stdlib.h>
#include <string.h>
int analizar(char *ptr);
int main()
{
    char string[10];
    char *ptr;
    printf("Ingrese una palabra: \n");
    scanf("%s", string);
    ptr = string;
    printf("%d", analizar(ptr));
    return 0;
}
int analizar(char *ptr)
{
    int i;
    int boolean = 0;
    char *ptr2, *ptr3;
    ptr2 = ptr;
    ptr3 = ptr + strlen(ptr) - 1;
    for (i = 0; i < strlen(ptr); i++)
    {
        if (*ptr2 == *ptr3)
        {
            boolean = 1;
        }
        else
        {
            boolean = 0;
        }
        ++ptr2;
        --ptr3;
    }
    return boolean;
}