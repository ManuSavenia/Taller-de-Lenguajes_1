#include <stdio.h>
#include <stdlib.h>
int main(){
    int n,n2, i;
    FILE *f, *g;
    f = fopen("Recursos/numeros.txt", "w");
    if(f == NULL){
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    g = fopen("Recursos/numeros.dat", "wb");
    printf("Ingrese la cantidad de numeros a generar: ");
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%d\n", &n2);
        fwrite(&n2, sizeof(int), 1, g);
        fprintf(f, "%d", n2);
    }
    fclose(f);
    fclose(g);
    return 0;
}