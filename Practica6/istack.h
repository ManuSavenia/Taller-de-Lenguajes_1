#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int *data;
} Stack;

Stack *s_create()
{
    Stack *s = (Stack *)malloc(sizeof(Stack));
    s->data = NULL;
    return s;
}

int s_push(Stack *s, int n)
{
    s->data = (int *)malloc(sizeof(int));
    *(s->data) = n;
    return n;
}

int s_pop(Stack *s)
{
    int n = *(s->data);
    s->data--;
    free(s->data);
    return n;
}

int s_top(Stack *s)
{
    return *(s->data);
}
int s_empty(Stack *s)
{
    if (s->data == NULL)
    {
        return 1;
    }
    return 0;
}
int s_length(Stack *s)
{
    int tamanio = 0;
    int *current = s->data;
    while (current != NULL)
    {
        printf("nashe\n");
        tamanio++;
        current++;
    }
    return tamanio;
}