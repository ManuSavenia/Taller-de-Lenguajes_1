#include <stdio.h>
#include <stdlib.h>
void copiarContenidoC(FILE *f, FILE *g);
void copiarContenidoS(FILE *f, FILE *g);
void copiarContenidoWR(FILE *f, FILE *g);
int main()
{
    FILE *f, *g;
    f = fopen("Recursos/prueba.txt", "r");
    g = fopen("Recursos/prueba2.txt", "w");
    copiarContenidoS(f, g);
    return 0;
}

void copiarContenidoC(FILE *f, FILE *g)
{
    char c;
    while ((c = fgetc(f)) != EOF)
    {
        fputc(c, g);
    }
}

void copiarContenidoS(FILE *f, FILE *g)
{
    char c[100];
    while (fgets(c, 100, f) != NULL)
    {
        fputs(c, g);
    }
}

void copiarContenidoWR(FILE *f, FILE *g){
    char c[100];
    while (fread(c, 100, 1, f) != NULL)
    {
        fwrite(c, 100, 1, g);
    }
}