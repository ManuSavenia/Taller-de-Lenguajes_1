#include <stdio.h>
#include <stdlib.h>
void inicializar(int *p,int n,int m);
int main(){
    int *p;
    int m,n;
    printf("Ingrese la cantidad de filas de la matriz: ");
    scanf("%d", &n);
    printf("Ingrese la cantidad de columnas de la matriz: ");
    scanf("%d", &m);
    p = (int *)malloc(n * m * sizeof(int));
    inicializar(p,n,m);
    //imprimir en forma de matriz
    for(int i = 0;i<n;i++){
        for(int j = 0;j<m;j++){
            printf("%d ",*(p+i*m+j));
        }
        printf("\n");
    }
    free(p);
    return 0;
}
void inicializar(int *p,int n,int m){
    for(int i = 0;i<m*n;i++){
        printf("ingrese un numero: ");
        scanf("%d",p+i);
    }
}