#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char nombre[20];
    int edad;
    char apellido[20];
    int titulos;
    int ranking;
    float fortuna;
} jugadores;

void iniciarJugadores(FILE *f);
void analizarDatos(FILE *f);
void imprimirArchivo(FILE *f);
int main()
{
    FILE *f;
    f = fopen("Recursos/Jugadores.dat", "wb+");
    if (f == NULL)
    {
        printf("\nError al abrir archivo fuente\n");
        return 1;
    }
    iniciarJugadores(f);
    imprimirArchivo(f);
    analizarDatos(f);
    fclose(f);
    return 0;
}
void iniciarJugadores(FILE *f)
{
    int i;
    jugadores v;
    for (i = 0; i < 3; i++)
    {
        printf("Ingrese el nombre del jugador: ");
        scanf("%s", v.nombre);
        printf("Ingrese el apellido del jugador: ");
        scanf("%s", v.apellido);
        printf("Ingrese la edad del jugador: ");
        scanf("%d", &v.edad);
        printf("Ingrese la cantidad de titulos del jugador: ");
        scanf("%d", &v.titulos);
        printf("Ingrese el ranking del jugador: ");
        scanf("%d", &v.ranking);
        printf("Ingrese la fortuna del jugador: ");
        scanf("%f", &v.fortuna);
        fwrite(&v, sizeof(jugadores), 1, f);
        printf("-------------------------------------------------\n");
    }
}
void analizarDatos(FILE *f)
{
    jugadores v;
    int i, rankingMax = 9999, titulosMax = -1;
    char nombreMax[20] = " ", apellidoMax[20] = " ", nombreMax2[20] = " ", apellidoMax2[20] = " ";
    for (i = 0; i < 3; i++)
    {
        printf("2\n");
        fread(&v, sizeof(jugadores), 1, f);
        if (v.ranking < rankingMax)
        {
            rankingMax = v.ranking;
            strcpy(nombreMax, v.nombre);
            strcpy(apellidoMax, v.apellido);
        }
        if (v.titulos > titulosMax)
        {
            titulosMax = v.titulos;
            strcpy(nombreMax2, v.nombre);
            strcpy(apellidoMax2, v.apellido);
        }
    }
    printf("El jugador con mayor ranking es %s %s con un ranking de %d\n", nombreMax, apellidoMax, rankingMax);
    printf("El jugador con mas titulos ganados es %s %s con %d titulos\n", nombreMax2, apellidoMax2, titulosMax);
}

void imprimirArchivo(FILE *f)
{
    int i;
    jugadores v;
    for (i = 0; i < 3; i++)
    {
        fread(&v, sizeof(jugadores), 1, f);
        printf("Nombre: %s\n", v.nombre);
        printf("Apellido: %s\n", v.apellido);
        printf("Edad: %d\n", v.edad);
        printf("Titulos: %d\n", v.titulos);
        printf("Ranking: %d\n", v.ranking);
        printf("Fortuna: %f\n", v.fortuna);
        printf("-------------------------------------------------\n");
    }
    fseek(f, 0, SEEK_SET);
}
