#include <stdio.h>
typedef struct Direccion{
    char calle[50];
    char ciudad[50];
    int codigoPostal;
    char pais[50];
}direccion;
typedef struct Persona{
    char nombre[50];
    char apellido[50];
    char legajo[8];
    float promedio;
    direccion domicilio;
}persona;

typedef struct Pun3d
{
    float x;
    float y;
    float z;
} punto3d;
int main(){
    punto3d punto;
    printf("tamanio punto: %d\n", sizeof(punto));
    punto3d puntos[4];
    printf("tamanio puntos: %d\n", sizeof(puntos));
    return 0;
}