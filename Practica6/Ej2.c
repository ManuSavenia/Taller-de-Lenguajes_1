#include <stdio.h>
#include <stdlib.h>
int main(int argc, char *argv[])
{
    float promedio = 0;
    if(argc != 5){
        printf("Error: el vector no tiene 4 elementos");
        return 1;
    }
    for (int i = 1; i < argc; i++)
    {
        promedio += atoi(argv[i]);
    }
    promedio /= (argc -1);
    printf("El promedio es: %f", promedio);
    return 0;
}