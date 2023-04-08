#include <stdio.h>
#include <stdlib.h>

void menos(int M[][12][30]);
void promedio(int M[][12][30]);
int main()
{
    srand(540);
    int M[10][12][30];
    int i, j, k;
    printf("Llega\n");
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 12; j++)
        {
            for (k = 0; k < 30; k++)
            {
                M[i][j][k] = rand() % 10;
            }
        }
    }
    menos(M);
    promedio(M);
}

void menos(int M[][12][30])
{
    int i, j, k;
    int min = 9999;
    int suma = 0;
    int mes;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 12; j++)
        {
            for (k = 0; k < 30; k++)
            {
                suma += M[i][j][k];
            }
            if (suma < min)
            {
                min = suma;
                mes = j;
            }
            suma = 0;
        }
        printf("El mes con menos precipitaciones en el anio %d fue: %d\n", i, mes);
    }
}

void promedio(int M[][12][30])
{
    int i, j, k;
    double suma = 0.0;
    double promedio;
    double min = 9999.0;
    int aniomin;
    for (i = 0; i < 10; i++)
    {
        for (j = 0; j < 12; j++)
        {
            for (k = 0; k < 30; k++)
            {
                suma += M[i][j][k];
            }
        }
        printf("suma: %lf\n", suma);
        promedio = suma / 360;
        printf("promedio: %lf\n", promedio);
        if (promedio < min)
        {
            min = promedio;
            aniomin = i;
        }
        suma = 0;
    }
    printf("El promedio minimo de precipitaciones fue en el anio %d y fue: %lf\n", aniomin, min);
}