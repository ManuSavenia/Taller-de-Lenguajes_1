#include <stdio.h>
#include <stdlib.h>
int SWAP(int V[]);
int main()
{
    int V[10];
    int i;
    for (i = 0; i < 10; i++)
    {
        V[i] = i;
    }

    for (i = 0; i < 10; i++)
    {
        printf("%d\n ", V[i]);
    }
    SWAP(V);
    printf("................................\n");
    for (i = 0; i < 10; i++)
    {
        printf("%d\n ", V[i]);
    }
}

int SWAP(int V[])
{
    int i;
    int v[10];
    for (i = 0; i < 10; i++)
    {
        v[i] = i;
    }
    int *ptr = v + 9;
    for (i = 0; i < 10; i++)
    {
        V[i] = *ptr;
        ptr--;
    }
    return V;
}