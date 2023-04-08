#include <stdio.h>
#include <string.h>

typedef struct CartasEspañolas
{
    char palo[10];
    int numero;
} carta;
carta sacarCarta(carta baraja[40]);
void imprimirCarta(carta baraja[40]);
void barajar(carta baraja[40]);
void cargarMazo(carta baraja[40]);

int main()
{
    carta baraja[40];
    cargarMazo(baraja);
    for (int i = 0; i < 40; i++)
    {

        printf("Carta %d: %d de %s \n", i + 1, baraja[i].numero, baraja[i].palo);
    }
    // sacarCarta(baraja);
    // imprimirCarta(baraja);
    return 0;
}

void barajar(carta baraja[40])
{
    carta aux;
    for (int i = 0; i < 40; i++)
    {
        aux = baraja[i];
        baraja[i] = baraja[i + 1];
        baraja[i + 1] = aux;
    }
}

carta sacarCarta(carta baraja[40])
{
    carta Carta;
    char palo[10];
    int numero;
    printf("Ingrese el numero de la carta que desea sacar: ");
    scanf("%d", numero);
    Carta.numero = numero;
    printf("Ingrese el palo de la carta que desea sacar:");
    scanf("%s", palo);
    strcpy(Carta.palo, palo);
    return Carta;
}
void imprimirCarta(carta baraja[40])
{
    carta Carta;
    int numero;
    printf("Ingrese el numero de carta para sacar del mazo: ");
    scanf("%d\n", numero);
    Carta = baraja[numero];
    printf("La carta es: %d de %s", Carta.numero, Carta.palo);
}

void cargarMazo(carta baraja[40])
{
    const char palo[4][10] = {"basto", "espada", "oro", "copa"};

    int cardIndex = 0;
    for (int suitIndex = 0; suitIndex < 4; suitIndex++)
    {
        for (int numberIndex = 1; numberIndex <= 10; numberIndex++)
        {
            strcpy(baraja[cardIndex].palo, palo[suitIndex]);
            baraja[cardIndex].numero = numberIndex;
            cardIndex++;
        }
    }
}