#include <stdio.h>
#include <stdlib.h>
void analizar(char *p, int k);
int main()
{
    char *p, palabra[10];
    int i;
    p = (char *)malloc(100 * sizeof(char));
    for (i = 0; i < 100; i += 10)
    {
        printf("Ingrese una palabra de 10 caracteres: ");
        fgets(palabra, sizeof(palabra), stdin);
        for (int j = 0; j < 10; j++)
            *(p + i + j) = *(palabra + j);
        while(getchar() != '\n');
    }

    for (int i = 0; i < 100; i += 10)
    {
        analizar(p, i);
    }

    free(p);
    return 0;
}
void analizar(char *p, int k)
{
    int i, cantmin = 0, cantmay = 0;
    for (i = 0; i < 10; i++)
    {
        if (*(p + i + k) >= 65 && *(p + i + k) <= 90)
        {
            cantmay++;
        }
        else if (*(p + i + k) >= 97 && *(p + i + k) <= 122)
        {
            cantmin++;
        }
    }
    printf("La cantidad de mayusculas es: %d\n", cantmay);
    printf("La cantidad de minusculas es: %d\n", cantmin);
    printf("-----------------------------\n");
}