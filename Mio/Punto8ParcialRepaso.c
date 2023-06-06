#include <stdio.h>
typedef struct nodo
{
    int dato;
    struct nodo *siguiente;
} lista;
void agregar(lista L);
void eliminar(lista L);
int main()
{
    lista *L = malloc(sizeof(lista));
    L->siguiente = NULL;
    return 0;
}

void agregar(lista *L)
{
    int n;
    lista *aux = malloc(sizeof(lista));
    printf("ingrese el dato a agregar: ");
    scanf("%d", &n);
    aux->dato = n;
    aux->siguiente = L;
    L = aux;
}

void eliminar(lista *L)
{
    int n;
    lista *aux = L, *ant = L;
    while (aux != NULL)
    {
        if (n = aux->dato)
        {
            if (aux == L)
            {
                L = L->siguiente;
            }
            else
            {
                ant->siguiente = aux->siguiente;
                free(aux);
                break;
            }
        }
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