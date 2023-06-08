#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void crearArchivo();
int main(){
    crearArchivo();
    return 0;
}
void crearArchivo(){
    FILE *f = fopen("diccionario.txt", "w");
    char linea[100];
    printf("Ingrese una palabra: ");
    scanf("%s", linea);
    while(strcmp(linea,"ZZZ")){        
        fprintf(f, "%s\n", linea);
        printf("Ingrese una palabra: ");
        scanf("%s", linea);
    }
    fclose(f);
}