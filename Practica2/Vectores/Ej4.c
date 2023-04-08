#include <stdio.h>

void girar(int M[][2]);
int main()
{
    int M[2][2];
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
            printf("%d ", M[i][j]);
        }
        printf("\n");
    }
    printf("------------------------------\n");
    girar(M);
}

void girar(int M[][2])
{
    int i, j;
    for (i = 0; i < 2; i++)
    {
        for (j = 0; j < 2; j++)
        {
            printf("%d ", M[j][i]);
        }
        printf("\n");
    }
}