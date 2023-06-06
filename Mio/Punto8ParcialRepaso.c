#include <stdio.h>
#include <stdlib.h>
typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
} lista;
void agregar(lista **L);
void eliminar(lista *L);
void eliminarTodo(lista *L);
void printList(lista *l);
int main()
{
    lista *L = NULL;
    agregar(&L);
    agregar(&L);
    printList(L);
    eliminarTodo(L);
    return 0;
}

void agregar(lista **L)
{
    int n;
    lista *aux = malloc(sizeof(lista));
    printf("ingrese el dato a agregar: ");
    scanf("%d", &n);
    aux->dato = n;
    aux->siguiente = *L;
    *L = aux;
}

void eliminar(lista *L)
{
    int n;
    printf("Ingrese dato a eliminar: ");
    scanf("%d", n);
    lista *aux = L, *ant = L;
    while (aux != NULL)
    {
        if (n == aux->dato)
        {
            if (aux == L)
            {
                L = L->siguiente;
                free(aux);
            }
            else
            {
                ant->siguiente = aux->siguiente;
                free(aux);
                break;
            }
        }
        ant = aux;
        aux = aux->siguiente;
    }
}

void eliminarTodo(lista *L)
{
    lista *aux;
    while (L != NULL)
    {
        aux = L;
        L = L->siguiente;
        free(aux);
    }
}

void printList(lista *l)
{
    lista *aux = l;
    while (aux != NULL)
    {
        printf("%d ", aux->dato);
        aux = aux->siguiente;
    }
}