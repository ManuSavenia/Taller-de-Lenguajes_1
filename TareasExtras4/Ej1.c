#include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct
{
    char letra;
    float frecuencia;
} FrecuenciasLetras;
typedef struct
{
    char word[20];
    float frequency;
} Word;
FILE *PasarAbinario(const FrecuenciasLetras frecuencias[]);
float codificar(char palabra[], const FrecuenciasLetras frecuencias[]);
void insert(Word **arr, int *capacity, Word data);
void heapify(Word arr[], int n, int i);
void heapSort(Word arr[], int n);
Word *crearHeap(Word *palabras, int *capacity, FILE *g);
void crearLosArchivos(Word *palabras, int capacity);
void printFile();
int main()
{
    const FrecuenciasLetras frecuencias[] = {{'A', 12.53}, {'B', 1.42}, {'C', 4.68}, {'D', 5.86}, {'E', 13.68}, {'F', 0.69}, {'G', 1.01}, {'H', 0.70}, {'I', 6.25}, {'J', 0.44}, {'K', 0.01}, {'L', 4.97}, {'M', 3.15}, {'N', 6.71}, {'1', 0.31}, {'O', 8.68}, {'P', 2.51}, {'Q', 0.88}, {'R', 6.87}, {'S', 7.98}, {'T', 4.63}, {'U', 3.93}, {'V', 0.90}, {'W', 0.02}, {'X', 0.22}, {'Y', 0.90}, {'Z', 0.52}};
    FILE *g = PasarAbinario(frecuencias);
    g = fopen("archivo.bin", "rb");
    Word *palabras;
    int capacity = 1;
    palabras = (Word *)malloc(capacity * sizeof(Word));
    if (palabras == NULL)
    {
        printf("Error allocating memory.");
        exit(EXIT_FAILURE);
    }
    printFile();
    palabras = crearHeap(palabras, &capacity, g);
    printf("capacity: %d\n", capacity);
    crearLosArchivos(palabras, capacity);
    fclose(g);
    return 0;
}

FILE *PasarAbinario(const FrecuenciasLetras frecuencias[])
{
    FILE *f, *g;
    f = fopen("archivo.txt", "r");
    g = fopen("archivo.bin", "wb");
    char palabra[20];
    int i;
    float resul;
    while (fgets(palabra, 20, f) != NULL)
    {
        if ((strlen(palabra) >= 4) && strlen(palabra) <= 14)
        {
            palabra[strcspn(palabra, "\n")] = '\0';
            resul = codificar(palabra, frecuencias);
            Word data;
            strcpy(data.word, palabra);
            data.frequency = resul;
            fwrite(&data, sizeof(Word), 1, g);
        }
    }
    fclose(g);
    fclose(f);
    return g;
}

float codificar(char palabra[], const FrecuenciasLetras frecuencias[])
{
    int i, j;
    float resul = 0, aux;
    for (i = 0; i < strlen(palabra); i++)
    {
        for (j = 0; j < 27; j++)
        {
            if (palabra[i] == frecuencias[j].letra)
            {
                aux = frecuencias[j].frecuencia * frecuencias[j].frecuencia;
                resul += aux;
                break;
            }
        }
    }
    return resul;
}

void insert(Word **arr, int *capacity, Word data)
{
    (*capacity)++;
    Word *temp = (Word *)realloc(*arr, *capacity * sizeof(Word));
    if (temp == NULL)
    {
        printf("Error reallocating memory.");
        exit(EXIT_FAILURE);
    }
    *arr = temp;
    int n = *capacity - 1;
    while (n / 2 > 0 && (*arr)[n / 2].frequency > data.frequency)
    {
        (*arr)[n] = (*arr)[n / 2];
        n /= 2;
    }
    (*arr)[n] = data;
}

void heapify(Word arr[], int n, int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < n && arr[left].frequency > arr[largest].frequency)
    {
        largest = left;
    }

    if (right < n && arr[right].frequency > arr[largest].frequency)
    {
        largest = right;
    }

    if (largest != i)
    {
        Word temp = arr[i];
        arr[i] = arr[largest];
        arr[largest] = temp;
        heapify(arr, n, largest);
    }
}

void heapSort(Word arr[], int n)
{
    for (int i = n / 2 - 1; i >= 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = n - 1; i > 0; i--)
    {
        Word temp = arr[0];
        arr[0] = arr[i];
        arr[i] = temp;
        heapify(arr, i, 0);
    }
}

void printFile()
{
    FILE *f = fopen("archivo.bin", "rb");
    Word word;
    while (fread(&word, sizeof(Word), 1, f) != 0)
    {
        printf("%s %.2f\n", word.word, word.frequency);
    }
    fclose(f);
}

Word *crearHeap(Word *palabras, int *capacity, FILE *g)
{
    Word word;
    char palabra[20];
    float frecuencia;
    while (fread(&word,sizeof(word), 1, g) != 0)
    {
        if (strlen(palabra) >= 4 && strlen(palabra) <= 14)
        {
            insert(&palabras, capacity, word);
        }
    }
    int aux = (*capacity);
    heapSort(palabras, aux);
    //imprimir array
    for (int i = 0; i < aux; i++)
    {
        printf("%s %.2f\n", palabras[i].word, palabras[i].frequency);
    }
    return palabras;
}

void crearLosArchivos(Word *palabras, int capacity)
{
    int i, posicion = 0;
    for (i = 1; i <= 10; i++)
    {
        char path[20];
        sprintf(path, "archivo%d.bin", i);
        FILE *r = fopen(path, "wb");
        int k = (i <= capacity % 10) ? 1 : 0;
        for (int j = 0; j < (capacity / 10) + k; j++)
        {
            fwrite(&palabras[posicion], sizeof(Word), 1, r);
            printf("%s %.2f\n", palabras[posicion].word, palabras[posicion].frequency);
            posicion++;
        }
        fclose(r);
    }
}