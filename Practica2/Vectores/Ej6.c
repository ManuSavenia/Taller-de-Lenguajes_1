#include <stdio.h>
void contar(int n);
int main()
{
    int n;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    contar(n);
}

void contar(int n)
{
    int dig;
    int i;
    int V[10];
    for (i = 0; i < 10; i++)
    {
        V[i] = 0;
    }
    for (i = 0; i < n; i++)
    {
        dig = n % 10;
        switch (dig)
        {
        case 0:
            V[0]++;
            break;
        case 1:
            V[1]++;
            break;
        case 2:
            V[2]++;
            break;
        case 3:
            V[3]++;
            break;
        case 4:
            V[4]++;
            break;
        case 5:
            V[5]++;
            break;
        case 6:
            V[6]++;
            break;
        case 7:
            V[7]++;
            break;
        case 8:
            V[8]++;
            break;
        case 9:
            V[9]++;
            break;

        default:
            break;
        }
        n = n / 10;
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d ", V[i]);
    }
}