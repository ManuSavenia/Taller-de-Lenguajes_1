#include <stdio.h>
#include <stdlib.h>
int *ReservarMatriz(int *T, int tamanio);
int *InicializarMatriz(int *T, int *tamanio, int n);
void imprimirMatriz(int *T, int tamanio, int n);
void liberarMatriz(int *T, int tamanio);
int main()
{
    int n, tamanio = 0;
    printf("Ingrese el grado de la matriz triangular a crear: ");
    scanf("%d", &n);
    int *T = InicializarMatriz(T, &tamanio, n);
    imprimirMatriz(T, tamanio, n);
    liberarMatriz(T, tamanio);
    return 0;
}

int *ReservarMatriz(int *T, int tamanio)
{
    T = realloc(T, sizeof(int) * tamanio);
    T[tamanio - 1] = rand() % 20;
    return T;
}

int *InicializarMatriz(int *T, int *tamanio, int n)
{
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n - j; k++)
        {
            (*tamanio) += 1;
            T = ReservarMatriz(T, (*tamanio));
        }
        j--;
    }
    return T;
}

void imprimirMatriz(int *T, int tamanio, int n)
{
    //imprimir el triangulo en la parte inferior de la matriz
    int j = n - 1;
    for (int i = 0; i < n; i++)
    {
        for (int k = 0; k < n - j; k++)
        {
            printf("%d ", T[i + k]);
        }
        j--;
        printf("\n");
    }
}

void liberarMatriz(int *T, int tamanio)
{
    free(T);
}