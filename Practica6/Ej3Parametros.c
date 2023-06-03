#include <stdio.h>
#include <stdlib.h>
int main()
{
    char comando[100];
    sprintf(comando, "Ej3 %d %d x", 4, 2);
    system(comando);
    return 0;
}