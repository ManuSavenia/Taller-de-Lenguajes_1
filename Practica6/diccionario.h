#include <stdio.h>
#include <stdlib.h>
#include <string.h>
FILE *crearDiccionario(){
    FILE *f = fopen("diccionario.txt", "w+");
    if(f == NULL){
        printf("Error al abrir el archivo");
        exit(-1);
    }
    fclose(f);
    return f;
}

int AgregarPalabra(FILE *f,char palabra[],char nombreArchivo[]){
    f = fopen(nombreArchivo, "a");
    fprintf(f, "%s\n", palabra);
    if(ferror(f))
        fclose(f);
        return 1;
    fclose(f);
    return 0;
}

int ExistePalabra(FILE *f, char palabra[]){
    f = fopen("diccionario.txt", "r");
    char aux[20];
    fgets(aux, 20, f);
    while (!feof(f))
    {
        printf("%s", aux);
        aux[strcspn(aux, "\n")] = 0; //saco el \n del final
        if(strcmp(aux, palabra) == 0){
            fclose(f);
            return 1;
        }
        fgets(aux, 20, f);
    }
    fclose(f);
    return 0;
}

void CargarDesdeUnArchivo(FILE *f, char nombreArchivo[]){
    FILE *g;
    g = fopen(nombreArchivo, "r");
    char aux[50];
    while(!feof(f)){
        fgets(aux,1,g);
        AgregarPalabra(f, aux,nombreArchivo);
    }
    fclose(f);
    fclose(g);
}

void GuardarAUnArchivo(FILE *f, char nombreArchivo[])
{
    FILE *g;
    f = fopen("diccionario.txt", "r");
    char aux[50];
    while (!feof(f))
    {
        printf("hola");
        fgets(aux, 20, g);
        aux[strcspn(aux, "\n")] = 0; // saco el \n del final
        AgregarPalabra(g, aux,nombreArchivo);
    }
    fclose(f);
    fclose(g);
}

void DestruirDiccionario(FILE *f){
    remove("diccionario.txt");
}