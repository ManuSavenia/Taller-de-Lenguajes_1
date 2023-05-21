#include <stdio.h>
#include <stdlib.h>
#define LONG 300
void procesar(char *linea, int *mayus, int *minus, int *dig);
int main()
{
    FILE *f;
    char linea[LONG];
    int mayus = 0, minus = 0, dig = 0;
    f = fopen("EJ2.txt", "r");
    if (f == NULL)
    {
        printf("\nError al abrir archivo fuente\n");
        return 1;
    }
    fgets(linea, LONG, f);
    while (!feof(f))
    {
        puts(linea);
        procesar(linea, &mayus, &minus, &dig);
        fgets(linea, LONG, f);
    }
    fclose(f);
    printf("Mayusculas: %d\nMinusculas: %d\nDigitos: %d\n", mayus, minus, dig);

    return 0;
}

void procesar(char *linea, int *mayus, int *minus, int *dig)
{
    int i = 0;
    while (linea[i] != '\0')
    {
        if (linea[i] >= 48 && linea[i] <= 57)
        {
            (*dig)++;
        }
        else if (linea[i] >= 65 && linea[i] <= 90)
        {
            (*mayus)++;
        }
        else if (linea[i] >= 97 && linea[i] <= 122)
        {
            (*minus)++;
        }
        i++;
    }
}
