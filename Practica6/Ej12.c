#include <stdio.h>
#include "diccionario.h"
#include <stdlib.h>
int main()
{
    FILE *f = crearDiccionario();
    char palabra[20],nombreArchivo[20];

    printf("Ingrese 1l nombre del archivo\n");
    scanf("%s", nombreArchivo);
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese una palabra: ");
        scanf("%s", palabra);
        AgregarPalabra(f, palabra, nombreArchivo);
    }
    int condicion = ExistePalabra(f, "hola");
    if (condicion == 1)
    {
        printf("La palabra existe\n");
    }
    else
    {
        printf("La palabra no existe\n");
    }
    GuardarAUnArchivo(f, "diccionario2.txt");
    DestruirDiccionario(f);
    return 0;
}