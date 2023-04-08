#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef union Identificacion
{
    int DNI;
    int pasaporte;
} Identificacion;

typedef struct Estudiante
{
    char nombre[20];
    char apellido[20];
    int legajo;
    Identificacion identificacion;
} estudiante;

int main()
{
    int boolean;
    estudiante estudiante1;
    printf("Ingrese nombre: ");
    scanf("%s", estudiante1.nombre);
    printf("Ingrese apellido: ");
    scanf("%s", estudiante1.apellido);
    printf("Ingrese legajo: ");
    scanf("%d", &estudiante1.legajo);
    printf("Eres Argentino? (1 = si, 0 = no): ");
    scanf("%d", &boolean);
    if (boolean == 1)
    {
        printf("Ingrese DNI: ");
        scanf("%d", &estudiante1.identificacion.DNI);
    }
    else
    {
        printf("Ingrese pasaporte: ");
        scanf("%d", &estudiante1.identificacion.pasaporte);
    }
    printf("Nombre: %s\n", estudiante1.nombre);
    printf("Apellido: %s\n", estudiante1.apellido);
    printf("Legajo: %d\n", estudiante1.legajo);
    if (boolean == 1)
    {
        printf("DNI: %d\n", estudiante1.identificacion.DNI);
    }
    else
    {
        printf("Pasaporte: %d\n", estudiante1.identificacion.pasaporte);
    }
    return 0;
}