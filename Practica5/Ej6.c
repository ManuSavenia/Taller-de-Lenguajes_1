#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <float.h>
typedef struct
{
    float maximo[8];
    float minimo[8];
    float promedio[8];
} datos;
void iniciarVectores(datos *totales);
int main()
{
    FILE *f, *g;
    char *field;
    float informacionAct;
    int contador = 0, i;
    char linea[200];
    datos totales;
    iniciarVectores(&totales);
    f = fopen("Recursos/vinos.csv", "r");
    g = fopen("Recursos/Reportevinos.txt", "w");
    if (f == NULL || g == NULL)
    {
        printf("\nError al abrir archivo fuente\n");
        return 1;
    }
    fgets(linea, 200, f);
    while (fgets(linea, 200, f) != NULL)
    {
        field = strtok(linea, ";");
        int index = 0;

        while (field != NULL)
        {
            if (index < 8)
            {
                float value = atof(field);
                if (value > totales.maximo[index])
                {
                    totales.maximo[index] = value;
                }
                else if (value < totales.minimo[index])
                {
                    totales.minimo[index] = value;
                }

                totales.promedio[index] += value;
            }
            field = strtok(NULL, ";");
            index++;
        }
        contador++;
    }
    for (int i = 0; i < 8; i++)
    {
        totales.promedio[i] /= contador;
    }

    printf("%d", contador);
    for (i = 0; i < 8; i++)
    {
        fprintf(g, "%.2f;", totales.maximo[i]);
    }
    fprintf(g, "\n");
    for (i = 0; i < 8; i++)
    {
        fprintf(g, "%.2f;", totales.minimo[i]);
    }
    fprintf(g, "\n");
    for (i = 0; i < 8; i++)
    {
        fprintf(g, "%.2f;", totales.promedio[i]);
    }

    fclose(f);
    fclose(g);
    return 0;
}

void iniciarVectores(datos *totales)
{
    for (int i = 0; i < 8; i++)
    {
        totales->maximo[i] = 0;
        totales->minimo[i] = 9999;
        totales->promedio[i] = 0;
    }
}
