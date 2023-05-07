#include <stdio.h>
#include <stdlib.h>
int main(){
    int *p;
    int i;
    p = (int *)malloc(5 * sizeof(int));
    for (i = 0; i < 5; i++)
    {
        *(p + i) = i;
    }
    printf("debug\n");
    p = (int *)realloc(p, 0 * sizeof(int));
    printf("debug\n");
    if (p == NULL)
    {
        printf("p es NULL por lo que no tiene elementos\n");
        return 0;
    }
    *p = 5;
    *(p + 4) = 6;
    printf("debug\n");
    
    for (i = 0; i < 5; i++)
    {
        printf("%d", *(p + i));
        printf(", ");
    }
    return 0;
}