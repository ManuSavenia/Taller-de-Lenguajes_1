#include "linkedlist.h"
typedef list Stack;

Stack s_create()
{
    return initList();
}

int s_push(Stack *s, int n)
{
    addatStart(s, n);
    return n;
}

int s_pop(Stack *s)
{
    return removeFirstElement(s);
}

int s_empty(Stack s)
{
    if (sizeOfList(s))
        return 0;
    return 1;
}

int s_length(Stack s)
{
    return sizeOfList(s);
}