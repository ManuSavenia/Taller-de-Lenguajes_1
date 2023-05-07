#include <stdio.h>
#include<string.h>
typedef struct mensaje
{
    int codigo;
    char texto[144];
    char usuario[50];
    int retwitts;
} tweet;
void cargar_mensaje(tweet *mensaje);
double prom_retwitts(tweet mensajes[], int cantTweets);
int main()
{
    enum {BASTO, Espada, Oro};
    double promedio;
    tweet mensaje, *ptr, mensajes[500];
    for (int i = 0; i < 500; i++)
    {
        ptr = &mensajes[i];
        cargar_mensaje(ptr);
    }
    promedio = prom_retwitts(mensajes, 500);
    printf("el promedio de retwitts es %lf\n", promedio);
    return 0;
}

void cargar_mensaje(tweet *mensaje)
{
    int datoTemp;
    char datoTemp2[144];
    char datoTemp3[50];

    scanf("%d", &datoTemp);
    (*mensaje).codigo = datoTemp;
    scanf("%s", &datoTemp2);
    strcpy((*mensaje).texto, datoTemp2);
    scanf("%s", &datoTemp3);
    strcpy((*mensaje).usuario, datoTemp3);
    scanf("%d", &datoTemp);
    (*mensaje).retwitts = datoTemp;
}

double prom_retwitts(tweet mensajes[], int cantTweets)
{
    double promedio;
    double tot;
    for (int i = 0; i < cantTweets; i++)
    {
        tot += mensajes[i].retwitts;
    }
    promedio = tot / cantTweets;
    return promedio;
}
