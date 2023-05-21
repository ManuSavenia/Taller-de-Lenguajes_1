#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define LONG 300
char **aumentarTamanio(char **diccionario, int *tamanio);
void copiarDiccionario(char **diccionario, FILE *f, int *tamanio);
int isInDictionary(const char **diccionario, int tamanio, char *palabra);
int main()
{
    FILE *f;
    char palabra[LONG], **diccionario;
    int i = 0, tamanio = 1;

    diccionario = (char **)malloc(sizeof(char *));

    diccionario[0] = (char *)malloc(sizeof(char) * LONG);

    f = fopen("Recursos/Diccionario.txt", "r");
    if (f == NULL)
    {
        printf("\nError al abrir archivo fuente\n");
        return 1;
    }
    copiarDiccionario(diccionario, f, &tamanio);
    printf("Ingrese una palabra: ");
    scanf("%s", palabra);
    while (strcmp(palabra, "ZZZ"))
    {
        if (isInDictionary(diccionario, tamanio, palabra))
        {
            printf("La palabra %s esta en el diccionario\n", palabra);
        }
        else
        {
            printf("La palabra %s no esta en el diccionario\n", palabra);
        }
        printf("Ingrese una palabra: ");
        scanf("%s", palabra);
        }
    fclose(f);
    return 0;
}

void copiarDiccionario(char **diccionario, FILE *f, int *tamanio)
{
    char linea[LONG];
    while (fgets(linea, LONG, f) != NULL)
    {
        linea[strcspn(linea, "\n")] = '\0';
        diccionario[(*tamanio)] = strdup(linea);
        diccionario = aumentarTamanio(diccionario, tamanio);
    }
}

char **aumentarTamanio(char **diccionario, int *tamanio)
{
    (*tamanio)++;
    *diccionario = (char *)realloc(*diccionario, (*tamanio) * sizeof(char));
    if (diccionario == NULL)
    {
        printf("\nError al reservar memoria\n");
        exit(1);
    }
    return diccionario;
}

int isInDictionary(const char **diccionario, int tamanio, char *palabra)
{
    int left = 0, right = tamanio;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        int comparison = strcmp(palabra, diccionario[mid]);
        printf("Comparando %s con %s\n", palabra, diccionario[mid]);
        if (comparison == 0)
        {
            return 1;
        }
        else if (comparison < 0)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return 0;
}
