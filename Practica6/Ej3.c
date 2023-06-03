#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[]){
    int param1 = atoi(argv[1]);
    int param2 = atoi(argv[2]);
    char operador = (*argv[3]);
    printf("Param1: %d\nParam2: %d\nOperador: %c\n", param1, param2, operador);
    int resultado = 0;
    switch (operador)
    {
    case '+':
        resultado = param1 + param2;
        break;
    case '-':
        resultado = param1 - param2;
        break;
    case 'x':
        resultado = param1 * param2;
        break;
    case '/':
        resultado = param1 / param2;
        break;
    default:
        printf("Error: operador invalido");
        return 1;
    }
    printf("El resultado es: %d", resultado);
    return 0;
}