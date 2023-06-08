#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void pasarAbinario();
int main(){
    pasarAbinario();
    return 0;
}

void pasarAbinario(){
    FILE *f = fopen("diccionario.txt","r");
    FILE *g = fopen("diccionarioBinario.dat","wb");
    char linea[100];
    while(fgets(linea,100,f) != NULL){
        fwrite(linea,sizeof(linea),1,g);
    }
    fclose(f);
    fclose(g);
}