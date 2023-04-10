#include<stdio.h>
#include<stdlib.h>
#include<string.h>

typedef struct Rectangulo{
    int ancho;
    int alto;
}Rectangulo;
typedef struct Cuadrado{
    int lado;
}Cuadrado;
typedef struct Circulo{
    int radio;
}Circulo;
typedef struct Triangulo{
    int base;
    int altura;
}Triangulo;
typedef struct Elipse{
    int radio1;
    int radio2;
}Elipse;
typedef union Figura{
    Rectangulo rectangulo;
    Cuadrado cuadrado;
    Circulo circulo;
    Triangulo triangulo;
    Elipse elipse;
}Figura;

void calcularArea(int opcion, Figura figura);

int main(){
    Figura figura;
    int opcion;
    printf("1. Rectangulo\n");
    printf("2. Cuadrado\n");
    printf("3. Circulo\n");
    printf("4. Triangulo\n");
    printf("5. Elipse\n");
    printf("Elige una opcion: ");
    scanf("%d",&opcion);
    switch(opcion){
        case 1:
            printf("Introduce el ancho: ");
            scanf("%d",&figura.rectangulo.ancho);
            printf("Introduce el alto: ");
            scanf("%d",&figura.rectangulo.alto);
            break;
        case 2:
            printf("Introduce el lado: ");
            scanf("%d",&figura.cuadrado.lado);
            break;
        case 3:
            printf("Introduce el radio: ");
            scanf("%d",&figura.circulo.radio);
            break;
        case 4:
            printf("Introduce la base: ");
            scanf("%d",&figura.triangulo.base);
            printf("Introduce la altura: ");
            scanf("%d",&figura.triangulo.altura);
            break;
        case 5:
            printf("Introduce el radio 1: ");
            scanf("%d",&figura.elipse.radio1);
            printf("Introduce el radio 2: ");
            scanf("%d",&figura.elipse.radio2);
            break;
        default:
            printf("Opcion no valida");
            break;
    }
    calcularArea(opcion,figura);
}

void calcularArea(int opcion, Figura figura){
    switch(opcion){
        case 1:
            printf("El area del rectangulo es: %d",figura.rectangulo.ancho*figura.rectangulo.alto);
            break;
        case 2:
            printf("El area del cuadrado es: %d",figura.cuadrado.lado*figura.cuadrado.lado);
            break;
        case 3:
            printf("El area del circulo es: %f",3.14*figura.circulo.radio*figura.circulo.radio);
            break;
        case 4:
            printf("El area del triangulo es: %f",figura.triangulo.base*figura.triangulo.altura/2);
            break;
        case 5:
            printf("El area de la elipse es: %f",3.14*figura.elipse.radio1*figura.elipse.radio2);
            break;
        default:
            printf("Opcion no valida");
            break;
    }
}