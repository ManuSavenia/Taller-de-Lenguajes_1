#include <stdio.h>
int main()
{
    int a, i;
    for (i = 1; i <= 2; ++i)
    {
        printf("Hola\n");
    }
    printf("enter a number: ");
    scanf("%d", &a);
    if (a < 0)
    {
        printf("the number %d is negative", a);
        return 0;
    }
    else
    {
        printf("the number %d is not negative", a);
        return 0;
    }
    return 0;
}
