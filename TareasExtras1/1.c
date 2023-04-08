#include <stdio.h>

typedef struct Pais
{
    int codigo;
    int CantidadEspecies;
} paises;

void LeerPais(paises P[]);

void Menor(paises P[]);

int porcentaje(paises P[]);

int main()
{
    int i;
    paises P[14];
    LeerPais(P);
    Menor(P);
    printf("el porcentaje de paises con mas de 40 especies es %d\n", porcentaje(P));

    for (i = 0; i < 14; i++)
    {
        printf("El pais %d tiene %d especies\n", P[i].codigo, P[i].CantidadEspecies);
    }
    return 0;
}

void LeerPais(paises P[])
{
    for (int i = 0; i < 14; i++)
    {
        printf("Ingrese el codigo del pais: ");
        scanf("%d", &P[i].codigo);
        printf("Ingrese la cantidad de especies: ");
        scanf("%d", &P[i].CantidadEspecies);
    }
}

void Menor(paises P[])
{
    int min1 = 9999, min2 = 9999, i;
    for (i = 0; i < 14; i++)
    {
        if (P[i].CantidadEspecies < min1)
        {
            min2 = min1;
            min1 = P[i].codigo;
        }
        else if (P[i].CantidadEspecies < min2)
        {
            min2 = P[i].codigo;
        }
    }
    printf("Los paises con menor cantidad de especies fueron %d y %d respectivamente\n", min1, min2);
}

int porcentaje(paises P[])
{
    int i, cant;
    cant = 0;
    for (i = 0; i < 14; i++)
    {
        if (P[i].CantidadEspecies > 40)
        {
            cant++;
        }
    }
    return cant * 100 / 14;
}