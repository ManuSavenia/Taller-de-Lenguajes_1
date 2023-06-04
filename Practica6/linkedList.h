#ifndef linkedList

#include <stdio.h>
#include <stdlib.h>

typedef struct node
{
    int value;
    struct node *next;
} node;

typedef node *list;

list initList()
{
    list aux = (list)malloc(sizeof(node));
    aux->next = NULL;
    return aux;
}

void freeList(list *l)
{
    list aux;
    while (*l != NULL)
    {
        aux = *l;
        *l = (*(*l)).next;
        free(aux);
    }
}

void addatStart(list *l, int n)
{
    list nue = (list)malloc(sizeof(node));
    nue->value = n;
    (*nue).next = *l;
    *l = nue;
}

void addAtEnd(list *l, int n)
{
    list aux;
    aux = (list)malloc(sizeof(node));
    aux->value = n;
    (*aux).next = NULL;
    if (*l != NULL)
    {
        list act = *l;
        while ((*act).next != NULL)
            act = (*act).next;
        (*act).next = aux;
    }
    else
        *l = aux;
}

void addValue(list *l, int n)
{
    list aux;
    aux = (list)malloc(sizeof(node));
    aux->value = n;
    list act = *l;
    list ant = act;
    while ((act != NULL) && ((act->value) < n))
    {
        ant = act;
        act = (*act).next;
    }
    (*aux).next = act;
    if (act == ant)
        *l = aux;
    else
        (*ant).next = aux;
}

int sizeOfList(list l)
{
    int size = 0;
    while (l != NULL)
    {
        size++;
        l = (*l).next;
    }
    return size;
}

void printList(list l)
{
    while ((*l).next != NULL)
    {
        printf("%d -> ", l->value);
        l = (*l).next;
    }
    printf("%d", l->value);
}

// returns 1 if the value was removed, 0 if it was not
int removeValue(list *l, int n)
{
    int ok = 0;
    list ant;
    list act = *l;
    while ((act != NULL) && (act->value != n))
    {
        ant = act;
        act = (*act).next;
    }
    if (act != NULL)
    {
        ok = 1;
        if (act == *l)
            *l = (*l)->next;
        else
            (*ant).next = (*act).next;
        free(act);
    }
    return ok;
}

int removeFirstElement(list *l)
{
    int n = (*l)->value;
    list aux = *l;
    *l = (*l)->next;
    free(aux);
    return n;
}

void removeTraverse(list l, int n)
{
    list act = l, ant = l, aux = l;
    while (act != NULL)
    {
        if ((act->value % 2) == 0)
        { // condicion
            (*ant).next = (*act).next;
            aux = (*act).next;
            free(act);
            act = aux;
        }
        else
        {
            ant = aux;
            aux = (*aux).next;
            act = aux;
        }
    }
}

#define linkedList
#endif