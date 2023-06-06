#include <stdio.h>
#include <string.h>
int main(int argc, char *argv[]){
    if(argc == 1){
        printf("Error");
        return 1;
    }
    char palabra [100];
    for(int i = 1; i < argc; i++){
        strcat(palabra, argv[i]);
        strcat(palabra," ");
    }
    palabra[strlen(palabra)-1] = '\0';
    printf("%s",palabra);
    return 0;
}
