#include <stdio.h>
#include <stdlib.h>
int main()
{
    FILE *f;
    float apuesta, total = 0.0;
    int i = 0, codigo;
    f = fopen("Recursos/apuestas.txt", "r");
    if (f == NULL)
    {
        printf("\nError al abrir archivo fuente\n");
        return 1;
    }
    fscanf(f, "%d|%f;", &codigo, &apuesta);
    while (!feof(f))
    {
        printf("%d|%f;", codigo, apuesta);
        total += apuesta;
        fscanf(f, "%d|%f;", &codigo, &apuesta);
    }
    fclose(f);
    printf("\nEl total es: %f\n", total);
    return 0;
}