#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct destino
{
    int codProv;
    int codLoc;
    char nomLoc[30];
    int nHab;
}Destino;
void calcular();
void pasarAbinario();
int main(){
    pasarAbinario();
    calcular();
    return 0;
}
void pasarAbinario()
{
    FILE *f = fopen("Habitantes.txt", "r");
    FILE *g = fopen("Habitantes.dat", "wb");
    char linea[100];
    Destino destinos;
    while (fgets(linea, 100, f) != NULL)
    {
        sscanf(linea, "%d %d %s %d", &destinos.codProv, &destinos.codLoc, destinos.nomLoc, &destinos.nHab);
        fwrite(&destinos, sizeof(Destino), 1, g);
    }
    fclose(f);
    fclose(g);
}

void calcular(){
    FILE *f = fopen("Habitantes.txt", "r");
    char linea[100];
    Destino destinos, Max;
    Max.nHab = 0;
    while(fgets(linea,100,f) != NULL){
        sscanf(linea, "%d %d %s %d", &destinos.codProv, &destinos.codLoc, destinos.nomLoc, &destinos.nHab);
        if(destinos.nHab > Max.nHab){
            Max.nHab = destinos.nHab;
            Max.codLoc = destinos.codLoc;
            strcpy(Max.nomLoc,destinos.nomLoc);
        }
    }
    printf("La localidad con mas habitantes es %s cuyo codigo es %d y tiene %d habitantes",Max.nomLoc,Max.codLoc,Max.nHab);
    fclose(f);
}