#include <stdio.h>
void sumar(int M[][2], int N[][2], int R[][2]);
int main()
{
    int M[2][2];
    int N[2][2];
    int R[2][2];
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            M[i][j] = i + 10;
        }
    }

    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            N[i][j] = i + 10;
        }
    }
    sumar(M, N, R);
}

void sumar(int M[][2], int N[][2], int R[][2])
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            R[i][j] = M[i][j] + N[i][j];
        }
    }
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d ", R[i][j]);
        }
        printf("\n");
    }
}