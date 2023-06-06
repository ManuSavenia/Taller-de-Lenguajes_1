#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct destino
{
    int codProv;
    int codLoc;
    char nomLoc[30];
    int nHab;
} Destino;
void pasar(FILE *f);
void calcular(FILE *f);
int main()
{
    FILE *f;
    f = fopen("Habitantes.txt", "r");
    if (f == NULL)
    {
        printf("Error al abrir el archivo\n");
        exit(1);
    }
    pasar(f);
    calcular(f);
    fclose(f);
    return 0;
}

void pasar(FILE *f)
{
    char linea[100];
    FILE *g;
    g = fopen("Habitantes.dat", "wb");
    Destino destino;
    while (fgets(linea, 100, f) != NULL)
    {
        sscanf(linea, "%d %d %s %d", &destino.codProv, &destino.codLoc, destino.nomLoc, &destino.nHab);
        fwrite(&destino, sizeof(Destino), 1, g);
    }
    fclose(g);
    fseek(f, 0, SEEK_SET);
}

void calcular(FILE *f)
{
    char linea[100];
    int max = 0, basura, basura2, n;
    Destino destino, Max;
    Max.nHab = -1;
    while (fgets(linea, 100, f) != NULL)
    {
        sscanf(linea, "%d %d %s %d", &destino.codProv, &destino.codLoc, destino.nomLoc, &destino.nHab);
        printf("linea = %s\n", linea);
        if (destino.nHab > Max.nHab)
        {
            Max.nHab = destino.nHab;
            strcpy(Max.nomLoc, destino.nomLoc);
        }
    }
    printf("La localidad con mas habitantes es %s con %d habitantes", Max.nomLoc, Max.nHab);
}
