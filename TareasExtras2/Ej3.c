#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void upperStr(char v[]);
void lowerStr(char v[]);
void numToStr(int n, char v[]);
void numToText(int n, char v[]);
int main()
{
    int n = 123;
    int n2 = 44;
    char string[10] = "hola";
    char string2[10] = "HOLA";
    printf("%s\n", string2);
    char string3[10];
    char string4[50];
    /*upperStr(string);
    printf("%s\n", string);
    lowerStr(string2);
    printf("%s\n", string2);
    numToStr(n, string3);
    printf("%s\n", string3);*/
    printf("%d\n", n2);
    numToText(n2, string4);
    printf("%s\n", string4);
    return 0;
}
void upperStr(char v[])
{
    int i;
    for (i = 0; v[i] != '\0'; i++)
    {
        if (v[i] >= 'a' && v[i] <= 'z')
        {
            v[i] = v[i] - 32;
        }
    }
}

void lowerStr(char v[])
{
    int i;
    for (i = 0; v[i] != '\0'; i++)
    {
        if (v[i] >= 'A' && v[i] <= 'Z')
        {
            v[i] = v[i] + 32;
        }
    }
}

void numToStr(int n, char v[])
{
    int i, j, aux, aux2;
    for (i = 0; n > 0; i++)
    {
        aux = n % 10;
        n = n / 10;
        v[i] = aux + 48;
    }
    v[i] = '\0';
    for (i = 0; v[i] != '\0'; i++)
    {
        for (j = i + 1; v[j] != '\0'; j++)
        {
            if (v[i] > v[j])
            {
                aux2 = v[i];
                v[i] = v[j];
                v[j] = aux2;
            }
        }
    }
}

void numToText(int n, char v[])
{
    char decenas2[10][20] = {"nashe", "nashe", "veinti", "treinta", "cuarenta", "cincuenta", "sesenta", "setenta", "ochenta", "noventa"};
    char unidades[10][20] = {"cero", "uno", "dos", "tres", "cuatro", "cinco", "seis", "siete", "ocho", "nueve"};
    char decenas1[10][20] = {"diez", "once", "doce", "trece", "catorce", "quince", "dieciseis", "diecisiete", "dieciocho", "diecinueve"};
    int i, Decenas, Unidades;

    Decenas = n / 10;
    Unidades = n % 10;

    if (n < 10)
    {
        printf("%s\n", unidades[n]);
    }
    else if (n < 20)
    {
        printf("%s\n", decenas1[n - 10]);
    }
    else if (n < 100)
    {
        if (Unidades == 0)
        {
            if ((n < 30) && (n > 19))
            {
                printf("veinte\n");
                strcpy(v, "veinte");
            }
            else
            {
                printf("%s\n", decenas2[Decenas]);
                strcpy(v, decenas2[Decenas]);
            }
        }
        else
        {
            if ((n < 30) && (n > 19))
            {
                printf("%s%s\n", decenas2[Decenas], unidades[Unidades]);
                strcpy(v, decenas2[Decenas]);
                strcat(v, unidades[Unidades]);
            }
            else
            {
                printf("%s y %s\n", decenas2[Decenas], unidades[Unidades]);
                strcpy(v, decenas2[Decenas]);
                strcat(v, " y ");
                strcat(v, unidades[Unidades]);
            }
        }
    }
    else
    {
        printf("Numero no valido\n");
    }
}