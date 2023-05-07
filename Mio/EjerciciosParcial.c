#include <stdio.h>
typedef struct tiempo
{
    unsigned int hora : 6;
    unsigned int minutos : 6;
    unsigned int segundos : 6;
    unsigned int centecimas : 6;
} Hora;

void cargarHora(Hora *dato);
int main()
{
    Hora tiempo, *ptr;
    ptr = &tiempo;
    cargarHora(ptr);
    printf("la hora es: %d:%d:%d:%d", tiempo.hora, tiempo.minutos, tiempo.segundos, tiempo.centecimas);
    return 0;
}

void cargarHora(Hora *dato)
{
    int Dato;
    printf("ingrese la hora ");
    scanf("%d", &Dato);
    (*dato).hora = Dato;
    printf("ingrese los minutos ");
    scanf("%d", &Dato);
    (*dato).minutos = Dato;
    printf("ingrese los segundos ");
    scanf("%d", &Dato);
    (*dato).segundos = Dato;
    printf("ingrese las centesimas ");
    scanf("%d", &Dato);
    (*dato).centecimas = Dato;
}