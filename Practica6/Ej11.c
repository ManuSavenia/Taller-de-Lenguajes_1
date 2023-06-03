#include <stdio.h>
#include "istack.h"
#include <stdlib.h>

int main()
{
    int n;
    Stack *s;
    s = s_create();
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    // apilamos los numeros hasta que se ingrese un 0
    while (n != 0)
    {
        s_push(s, n);
        printf("Ingrese un numero: ");
        scanf("%d", &n);
    }
    // desapilamos los numeros y los imprimimos
    //printf("La longitud de la pila es: %d\n", s_length(s));
    printf("Los numeros ingresados son:\n");
    while (!s_empty(s))
    {
        printf("%d\n", s_pop(s));
    }
    return 0;
}