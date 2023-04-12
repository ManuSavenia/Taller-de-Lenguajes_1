#include <stdio.h>

typedef struct fec
{
    unsigned int anio;
    unsigned int mes;
    unsigned int dia;
} fecha;

typedef union fech
{
    fecha f1;
    long int f2;
} fech;

int main()
{
    fech fecha1;
    fecha1.f1.dia = 20;
    fecha1.f1.mes = 3;
    fecha1.f1.anio = 2014;
    fech fecha2;
    fecha2.f1.dia = 20;
    fecha2.f1.mes = 3;
    fecha2.f1.anio = 2014;

    if (fecha1.f2 > fecha2.f2)
        printf("La fecha 1 es mayor que la fecha 2");
    else if (fecha1.f2 < fecha2.f2)
        printf("La fecha 2 es mayor que la fecha 1");
    else
        printf("Las fechas son iguales");

    return 0;
}