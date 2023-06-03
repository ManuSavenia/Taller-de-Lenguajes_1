#include <stdio.h>
#include <stdlib.h>
int main(){
    char comando[100];
    sprintf(comando, "Ej2 %d %d %d %d", 1, 2, 3, 4);
    system(comando);
    return 0;
}