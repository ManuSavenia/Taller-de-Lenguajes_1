#include <stdio.h>
#include <stdlib.h>
typedef enum {Bluetooth= 1 ,Wifi = 2,GPS = 4,Datos = 8,Frontal = 16,Trasera = 32,Linterna = 64,Vibrar = 128} flags;
flags cambiarFlag(flags f, flags f2,flags v[]);
void flagActivo(flags f);
flags invertirflag(flags f, flags f2);
int main(){
    flags f,f2,f3;
    f = Bluetooth | Wifi | GPS | Datos | Frontal | Trasera | Linterna | Vibrar;
    f3 = Bluetooth;
    flags v[8];
    v[0] = Bluetooth;
    v[1] = Wifi;
    v[2] = GPS;
    v[3] = Datos;
    v[4] = Frontal;
    v[5] = Trasera;
    v[6] = Linterna;
    v[7] = Vibrar;
    f = cambiarFlag(f,f2,v);
    flagActivo(f);
    f = invertirflag(f,f3);
    flagActivo(f);
    return 0;
    
}
flags invertirflag(flags f, flags f2){
    if ((f & f2) == f2)
    {
        f = f & ~f2;
    }
    else
    {   
        f = f | f2;
    }
    return f;
}


flags cambiarFlag(flags f, flags f2,flags v[]){
    int boolean;
    printf("Que flag quieres cambiar?\n");
    printf("1. Bluetooth\n");
    printf("2. Wifi\n");
    printf("3. GPS\n");
    printf("4. Datos\n");
    printf("5. Camara frontal\n");
    printf("6. Camara trasera\n");
    printf("7. Linterna\n");
    printf("8. Vibrar\n");
    scanf("%d",&boolean);
    f2 = v[boolean-1];
    printf("quieres activar o desactivar el flag? (1 para activar, 0 para desactivar)\n");
    scanf("%d",&boolean);
    if(boolean){
        f = f | f2;
    }
    else
    {
        f = f & ~f2;
    }
    return f;
}

void flagActivo(flags f){
    if(f & Bluetooth){
        printf("Bluetooth activo\n");
    }
    else
    {
        printf("Bluetooth inactivo\n");
    }
    if(f & Wifi){
        printf("Wifi activo\n");
    }
    else
    {
        printf("Wifi inactivo\n");
    }
    if(f & GPS){
        printf("GPS activo\n");
    }
    else
    {
        printf("GPS inactivo\n");
    }
    if(f & Datos){
        printf("Datos activo\n");
    }
    else
    {
        printf("Datos inactivo\n");
    }
    if(f & Frontal){
        printf("Camara frontal activo\n");
    }
    else
    {
        printf("Camara frontal inactivo\n");
    }
    if(f & Trasera){
        printf("Camara trasera activo\n");
    }
    else
    {
        printf("Camara trasera inactivo\n");
    }
    if(f & Linterna){
        printf("Linterna activo\n");
    }
    else
    {
        printf("Linterna inactivo\n");
    }
    if(f & Vibrar){
        printf("Vibrar activo\n");
    }
    else
    {
        printf("Vibrar inactivo\n");
    }

}