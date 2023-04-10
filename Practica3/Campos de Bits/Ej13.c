#include<stdio.h>
#include<stdlib.h>
#include<string.h>
typedef struct flags {
    unsigned int Bluetooth:1;
    unsigned int Wifi:1;
    unsigned int GPS:1;
    unsigned int Datos:1;
    unsigned int Frontal:1;
    unsigned int Trasera:1;
    unsigned int Linterna:1;
    unsigned int Vibrar:1;
    }flags;
flags prenderFlag(flags f);
flags apagarFlag(flags f);
flags invertirflag(flags f);
void flagActivo(flags f);
int main(){
    flags f;
    f.Bluetooth = 1;
    f.Wifi = 1;
    f.GPS = 1;
    f.Datos = 1;
    f.Frontal = 1;
    f.Trasera = 1;
    f.Linterna = 1;
    f.Vibrar = 1;
    flagActivo(f);
    f = apagarFlag(f);
    flagActivo(f);
    f = prenderFlag(f);
    flagActivo(f);
}

flags prenderFlag(flags f){
    char flag[10];
    printf("cual flag quieres prender?\n");
    scanf("%s",flag);
    if(strcmp(flag,"Bluetooth") == 0){
        f.Bluetooth = 1;
    }
    else if(strcmp(flag,"Wifi") == 0){
        f.Wifi = 1;
    }
    else if(strcmp(flag,"GPS") == 0){
        f.GPS = 1;
    }
    else if(strcmp(flag,"Datos") == 0){
        f.Datos = 1;
    }
    else if(strcmp(flag,"Frontal") == 0){
        f.Frontal = 1;
    }
    else if(strcmp(flag,"Trasera") == 0){
        f.Trasera = 1;
    }
    else if(strcmp(flag,"Linterna") == 0){
        f.Linterna = 1;
    }
    else if(strcmp(flag,"Vibrar") == 0){
        f.Vibrar = 1;
    }
    return f;
}

flags apagarFlag(flags f){
    char flag[10];
    printf("cual flag quieres apagar?\n");
    scanf("%s",flag);
    if(strcmp(flag,"Bluetooth") == 0){
        f.Bluetooth = 0;
    }
    else if(strcmp(flag,"Wifi") == 0){
        f.Wifi = 0;
    }
    else if(strcmp(flag,"GPS") == 0){
        f.GPS = 0;
    }
    else if(strcmp(flag,"Datos") == 0){
        f.Datos = 0;
    }
    else if(strcmp(flag,"Frontal") == 0){
        f.Frontal = 0;
    }
    else if(strcmp(flag,"Trasera") == 0){
        f.Trasera = 0;
    }
    else if(strcmp(flag,"Linterna") == 0){
        f.Linterna = 0;
    }
    else if(strcmp(flag,"Vibrar") == 0){
        f.Vibrar = 0;
    }
    return f;
}


void flagActivo(flags f){
    printf("Bluetooth: %d, Wifi: %d, GPS: %d, Datos: %d, Camara frontal: %d, Camara trasera: %d, Linterna: %d, Vibrar: %d\n",f.Bluetooth,f.Wifi,f.GPS,f.Datos,f.Frontal,f.Trasera,f.Linterna,f.Vibrar);
}

flags invertirflag(flags f){
    char flag[10];
    printf("Que flag quieres cambiar?\n");
    printf("1. Bluetooth\n");
    printf("2. Wifi\n");
    printf("3. GPS\n");
    printf("4. Datos\n");
    printf("5. Camara frontal\n");
    printf("6. Camara trasera\n");
    printf("7. Linterna\n");
    printf("8. Vibrar\n");
    scanf("%s",flag);

    if (strcmp(flag,"Bluetooth") == 0)
    {
        f.Bluetooth = !f.Bluetooth;
    }
    else if (strcmp(flag,"Wifi") == 0)
    {
        f.Wifi = !f.Wifi;
    }
    else if (strcmp(flag,"GPS") == 0)
    {
        f.GPS = !f.GPS;
    }
    else if (strcmp(flag,"Datos") == 0)
    {
        f.Datos = !f.Datos;
    }
    else if (strcmp(flag,"Frontal") == 0)
    {
        f.Frontal = !f.Frontal;
    }
    else if (strcmp(flag,"Trasera") == 0)
    {
        f.Trasera = !f.Trasera;
    }
    else if (strcmp(flag,"Linterna") == 0)
    {
        f.Linterna = !f.Linterna;
    }
    else if (strcmp(flag,"Vibrar") == 0)
    {
        f.Vibrar = !f.Vibrar;
    }
    return f;
}