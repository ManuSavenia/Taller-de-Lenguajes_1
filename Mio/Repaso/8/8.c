#include <stdio.h>
#include <stdlib.h>
typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
} lista;
void agregarNodo(lista **L);
void eliminarNodo(lista **L);
void eliminarLista(lista **L);
void imprimirLista(lista *L);
int main()
{
    lista *L;
    L = NULL;
    agregarNodo(&L);
    agregarNodo(&L);
    agregarNodo(&L);
    imprimirLista(L);
    eliminarLista(&L);
    imprimirLista(L);
    return 0;
}

void agregarNodo(lista **L)
{
    int n;
    lista *nue;
    printf("ingrese el numero a agregar: ");
    scanf("%d", &n);
    nue = (lista *)malloc(sizeof(lista));
    (*nue).dato = n;
    (*nue).siguiente = (*L);
    (*L) = nue;
}

void eliminarNodo(lista **L)
{
    lista *aux = (*L);
    while (aux->siguiente != NULL)
    {
        aux = aux->siguiente;
    }
    free(aux);
}

void eliminarLista(lista **L)
{
    while ((*L) != NULL)
    {
        eliminarNodo(L);
    }
    *L = NULL;
}

void imprimirLista(lista *L)
{
    if (L == NULL)
    {
        printf("esta vacia");
        return;
    }
    lista *aux = L;
    while (aux->siguiente != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->siguiente;
    }
    printf("%d ", aux->dato);
}