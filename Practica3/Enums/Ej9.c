#include <stdio.h>
#include <stdlib.h>
typedef enum {LUNES,MARTES,MIERCOLES,JUEVES,VIERNES,SABADO,DOMINGO} semana;

int main(){
    char dias[7][10] ={"Lunes","Martes","Miercoles","Jueves","Viernes","Sabado","Domingo"};
    semana dia;
    dia = MARTES;
    printf("El dia es %s",dias[dia]);

    int dia2 = 3;
    dia=dia2;
    printf("El dia es %s",dias[dia]);
}