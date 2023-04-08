#include <stdio.h>
typedef struct Rectangulo
{
    float altura;
    float base;
} rectangulo;
rectangulo cargar(rectangulo r);
int main()
{
    rectangulo r[10];
    rectangulo r1;
    int area;
    for (int i = 0; i < 10; i++)
    {
        r[i] = cargar(r[i]);
    }
    for (int i = 0; i < 10; i++)
    {
        area = Area(r[i]);
        printf("El area es: %d", area);
    }
    printf("El area es: %d", area);
    return 0;
}

rectangulo cargar(rectangulo r)
{
    printf("Ingrese la altura: ");
    scanf("%f", &r.altura);
    printf("Ingrese la base: ");
    scanf("%f", &r.base);
    return r;
}
int Area(rectangulo r)
{
    return r.altura * r.base;
}