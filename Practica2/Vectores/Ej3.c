#include <stdio.h>

void multiplicar(int M[][3], int c);

int main()
{
    int M[2][3];
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            M[i][j] = i + j;
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    multiplicar(M, 2);
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
}

void multiplicar(int M[][3], int c)
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 3; j++)
        {
            M[i][j] *= c;
        }
    }
}