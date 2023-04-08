#include <stdio.h>
int binario(int n);
int main()
{
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    binario(n);
}

int binario(int n)
{
    if (n == 0)
    {
        return 0;
    }
    else
    {
        binario(n / 2);
        printf("%d", n % 2);
    }
}