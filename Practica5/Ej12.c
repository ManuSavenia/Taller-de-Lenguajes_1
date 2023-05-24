#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    int dni;
    int posicion;
} datos;
typedef struct
{
    unsigned id, dni;
    char *surname, *name, *work, *mail, *city, *country;
} persona;
datos *aumentarTamanio(datos *indice, int *tamanio);
datos *copiarDatos(datos *indice, int *tamanio, FILE *f);
void crearArchivo(datos *indiceOrdenado, int *tamanio);
void insert(datos **indice, int *tamanio, datos data);
void heapify(datos *indice, int n, int i);
void heapSort(datos *indice, int n);
void imprimirArray(datos *indice, int *tamanio);
int buscar(FILE *personas, datos *indice, int tamanio, int dni, persona *persona);
int main()
{
    FILE *f;
    int dni;
    persona persona;
    f = fopen("Recursos/personas.csv", "r");
    if (f == NULL)
    {
        printf("\nError al abrir archivo fuente\n");
        return 1;
    }
    datos *indice;
    int tamanio = 1;
    indice = (datos *)malloc(sizeof(datos));
    if (indice == NULL)
    {
        printf("\nError al reservar memoria\n");
        return 1;
    }
    //--------------------------------------------------------------
    indice = copiarDatos(indice, &tamanio, f);
    printf("El tamanio es: %d\n", tamanio);
    heapSort(indice, tamanio);
    printf("El tamanio es: %d\n", tamanio);
    imprimirArray(indice, &tamanio);
    crearArchivo(indice, &tamanio);
    printf("Ingrese el dni de la persona a buscar: ");
    scanf("%d", &dni);
    if (buscar(f, indice, tamanio, dni, &persona) == 1)
    {
        printf("La persona se encuentra en el archivo\n");
    }
    else
    {
        printf("La persona no se encuentra en el archivo\n");
    }
    printf("La persona se encuentra en el archivo\n");
    fclose(f);
    return 0;
}

datos *aumentarTamanio(datos *indice, int *tamanio)
{
    datos *aux;
    aux = (datos *)realloc(indice, sizeof(datos) * (*tamanio + 1));
    if (aux == NULL)
    {
        printf("\nError al reservar memoria\n");
        return NULL;
    }
    indice = aux;
    *tamanio = *tamanio + 1;
    return indice;
}

datos *copiarDatos(datos *indice, int *tamanio, FILE *f)
{
    int basura;
    char linea[200];
    char *ptr;
    fgets(linea, 200, f);
    datos data;
    while (fgets(linea, 200, f) != NULL)
    {
        ptr = strtok(linea, ";");
        ptr = strtok(NULL, ";");
        data.dni = atoi(ptr);
        data.posicion = ftell(f);
        insert(&indice, tamanio, data);
    }
    printf("El tamanio es: %d\n", *tamanio);
    return indice;
}

void insert(datos **indice, int *tamanio, datos data)
{
    (*tamanio)++;
    datos *temp = (datos *)realloc((*indice), *tamanio * sizeof(datos));
    if (temp == NULL)
    {
        printf("Error reallocating memory.");
        exit(EXIT_FAILURE);
    }
    (*indice) = temp;
    int n = *tamanio - 1;
    while (n / 2 > 0 && (*indice)[n / 2].dni > data.dni)
    {
        (*indice)[n] = (*indice)[n / 2];
        n /= 2;
    }
    (*indice)[n] = data;
}

void heapify(datos *indice, int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if (left < n && indice[left].dni > indice[largest].dni)
    {
        largest = left;
    }
    if (right < n && indice[right].dni > indice[largest].dni)
    {
        largest = right;
    }
    if (largest != i)
    {
        datos temp = indice[i];
        indice[i] = indice[largest];
        indice[largest] = temp;
        heapify(indice, n, largest);
    }
}

void heapSort(datos *indice, int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(indice, n, i);
    }
    printf("tu mama");
    for (int i = n - 1; i > 0; i--)
    {
        datos temp = indice[0];
        indice[0] = indice[i];
        indice[i] = temp;
        heapify(indice, i, 0);
    }
    printf("tu mama");
}

void crearArchivo(datos *indiceOrdenado, int *tamanio)
{
    int i;
    FILE *g = fopen("Recursos/personas.idx", "wb");
    if (g == NULL)
    {
        printf("\nError al abrir archivo fuente\n");
        exit(1);
    }
    for (i = 0; i < *tamanio; i++)
    {
        fwrite(&indiceOrdenado[i], sizeof(datos), 1, g);
    }
    fclose(g);
}

void imprimirArray(datos *indice, int *tamanio)
{
    int i;
    for (i = 0; i < *tamanio; i++)
    {
        printf("El dni es: %d\n", indice[i].dni);
        printf("La posicion es: %d\n", indice[i].posicion);
    }
}

int buscar(FILE *personas, datos *indice, int tamanio, int dni, persona *persona)
{
    int posicion;
    posicion = binarySearch(indice, tamanio, dni);
    printf("la posicion es: %d\n", posicion);
    char linea[200];
    if (posicion == 0)
    {
        printf("No se encontro el dni");
        return 0;
    }
    fseek(personas, posicion, SEEK_SET);
    printf("hola");
    /*if (fgets(linea, 200, personas) != NULL)
    {
        printf("%s\n", linea);
        char *field = strtok(linea, ";");
        printf("field: %s\n", field);
        persona->id = atoi(field);
        printf("hola");
        field = strtok(NULL, ";");
        persona->dni = atoi(field);
        printf("hola");
        field = strtok(NULL, ";");
        persona->surname = strdup(field);
        printf("hola");
        field = strtok(NULL, ";");
        persona->name = strdup(field);
        printf("hola");
        field = strtok(NULL, ";");
        persona->work = strdup(field);
        printf("hola");
        field = strtok(NULL, ";");
        persona->mail = strdup(field);
        printf("hola");
        field = strtok(NULL, ";");
        persona->city = strdup(field);
        printf("hola");
        field = strtok(NULL, ";");
        persona->country = strdup(field);
        printf("hola");
        return 1;
    }*/
    fscanf(personas, "%d;%d;%[^;];%[^;];%[^;];%[^;];%[^;];%[^\n]", &persona->id, &persona->dni, persona->surname, persona->name, persona->work, persona->mail, persona->city, persona->country);
    printf("hola");
    return 1;
}

int binarySearch(datos *index, int size, int dni)
{
    int left = 0, right = size;

    while (left <= right)
    {
        int mid = (left + right) / 2;
        if (dni == index[mid].dni)
        {
            return index[mid].posicion;
        }
        else if (dni < index[mid].dni)
        {
            right = mid - 1;
        }
        else
        {
            left = mid + 1;
        }
    }
    return 0;
}