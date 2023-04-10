#include <stdio.h>
#include <stdlib.h>
typedef struct fecha
{
    unsigned int hora:5;
    unsigned int minuto:6;
    unsigned int segundo:5;

}Hora;

int main(){
    Hora hora;
    unsigned int x;
    printf("Introduce la hora: ");
    scanf("%d",&x);
    hora.hora = x;
    printf("Introduce los minutos: ");
    scanf("%d",&x);
    hora.minuto = x;
    printf("Introduce los segundos: ");
    scanf("%d",&x);
    hora.segundo = x;

    printf("La hora es %d:%d:%d",hora.hora,hora.minuto,hora.segundo);
}