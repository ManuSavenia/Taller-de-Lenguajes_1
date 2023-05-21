#include <stdio.h>
#include <stdlib.h>
int main(){
    FILE *f;
    int caracter;
    int max = 0;
    f = fopen("Recursos/precipitaciones.txt", "r");
    if(f == NULL){
        printf("\nError al abrir archivo fuente\n");
        return 1;
    }
    fscanf(f, "%d-", &caracter);
    while(!feof(f)){
        printf("%d", caracter);
        if(caracter > max){
            max = caracter;
        }
        fscanf(f, "%d-", &caracter);
    }
    fclose(f);
    printf("\nEl maximo es: %d\n", max);
    return 0;
}