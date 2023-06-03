#include <stdio.h>
#define AREA_CIRCULO(r) (3.141592 * (r) * (r))
int main(){
    int vector[10];
    int i;
    for (i = 0; i < 10; i++){
        vector[i] = rand() % 100;
        printf("vector[%d]= %d\n", i, vector[i]);
    }
    for(i = 0; i < 10; i++){
        printf("El area del circulo de radio %d es: %f\n", vector[i], AREA_CIRCULO(vector[i]));
    }
    return 0;
}