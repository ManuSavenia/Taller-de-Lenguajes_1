#include <stdio.h>
#include <stdlib.h>
void imprimirCantBytes(FILE *f);
int main(){
    FILE *f;
    f = fopen("Recursos/Jugadores.dat", "rb");
    if (f == NULL){
        printf("\nError al abrir archivo fuente\n");
        return 1;
    }
    imprimirCantBytes(f);
    return 0;
}

void imprimirCantBytes(FILE *f){
    int cantBytes;
    fseek(f, 0, SEEK_END);
    cantBytes = ftell(f);
    printf("La cantidad de bytes del archivo es: %d\n", cantBytes);
}