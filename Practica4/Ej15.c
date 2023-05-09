#include <stdio.h>
#include <stdlib.h>
int ** reservar(int **p,int n,int m);
void inicializar(int **p,int n);
void imprimir(int **p,int n);
int main(){
    int **p;
    int i,j,n;
    printf("Ingrese la cantidad de filas de la piramide: ");
    scanf("%d",&n);
    p = reservar(p,n,n);
    inicializar(p,n);
    imprimir(p,n);
    for(i=0;i<n;i++){
        free(p[i]);
    }
    free(p);
    return 0;
}
int ** reservar(int **p,int n,int m){
    p = (int **)malloc(n * sizeof(int *));
    for (int i = 0; i < n; i++)
    {
        p[i] = (int *)malloc(m * sizeof(int));
    }
    if (p == NULL)
    {
        printf("No se pudo reservar memoria");
        exit(1);
    }
    return p;
}
void inicializar(int **p, int n)
{
    p[0][0] = 1;
    for (int i = 1; i < n; i++)
    { // for each row
        p[i][0] = p[i][i] = 1;
        for (int j = 1; j < i; j++)
        { // for each column
            p[i][j] = p[i - 1][j - 1] + p[i - 1][j];
        }
    }
}

void imprimir(int **p, int n)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < (i + 1); j++)
        {
            int val = p[i][j];
            printf("[%d][%d] : %d  -  ", i, j, val);
        }
        printf("\n");
    }
}