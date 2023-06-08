#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void leerArchivo();
int main()
{
    leerArchivo();
    return 0;
}

void leerArchivo()
{
    FILE *f = fopen("diccionario.txt", "r");
    FILE *g = fopen("diccionario2.txt", "w");
    char linea[100];
    while (fgets(linea, 100, f) != NULL)
    {
        fprintf(g, "%s", linea);
    }
    fclose(g);
    fclose(f);
}