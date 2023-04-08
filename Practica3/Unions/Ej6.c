#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef union Fecha
{
    unsigned int dia;
    unsigned int mes;
    unsigned int anio;
    char datoAct[20];
} fecha;
int comparar(fecha f1, fecha f2, int datos[3], int datos2[3]);
void numToStr(int n, char v[]);

int main()
{
    int datos[3];
    int datos2[3];
    char str[20];
    char str2[20];
    fecha Fecha;
    fecha Fecha2;
    int i = 0;
    printf("Ingrese dia, mes y anio de la primera fecha: ");
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &datos[i]);
        numToStr(datos[i], str);
        strcat(str, "/");
        strcat(Fecha.datoAct, str);
        strcpy(str, "");
    }
    printf("Ingrese dia, mes y anio de la segunda fecha: ");
    for (i = 0; i < 3; i++)
    {
        scanf("%d", &datos2[i]);
        numToStr(datos2[i], str2);
        strcat(str2, "/");
        strcat(Fecha.datoAct, str2);
        strcpy(str2, "");
    }
    printf("Fecha 1: %s\n", Fecha.datoAct);
    printf("Fecha 2: %s\n", Fecha2.datoAct);

    if (comparar(Fecha, Fecha2, datos, datos2) == 1)
    {
        printf("Las fechas son iguales");
    }
    else
    {
        printf("Las fechas son diferentes");
    }
    return 0;
}

int comparar(fecha f1, fecha f2, int datos[3], int datos2[3])
{
    int i = 0;
    for (i = 0; i < 3; i++)
    {
        strcmp(f1.datoAct, f2.datoAct);
        if (strcmp(f1.datoAct, f2.datoAct) == 0)
        {
            return 0;
        }
        else
        {
            return 1;
        }
    }
}

void numToStr(int n, char v[])
{
    int i, j, aux, aux2;
    for (i = 0; n > 0; i++)
    {
        aux = n % 10;
        n = n / 10;
        v[i] = aux + 48;
    }
    v[i] = '\0';
    for (i = 0; v[i] != '\0'; i++)
    {
        for (j = i + 1; v[j] != '\0'; j++)
        {
            if (v[i] > v[j])
            {
                aux2 = v[i];
                v[i] = v[j];
                v[j] = aux2;
            }
        }
    }
}