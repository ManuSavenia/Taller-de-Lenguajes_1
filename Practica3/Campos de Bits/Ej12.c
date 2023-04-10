#include <stdio.h>
#include <stdlib.h>
typedef struct RGB1
{
    unsigned int rojo:8;
    unsigned int verde:8;
    unsigned int azul:8;
}RGB1;
typedef struct RGB2
{
    unsigned int rojo:5;
    unsigned int verde:6;
    unsigned int azul:5;
}RGB2;
RGB1 convertirArgb1(RGB2 rgb2);
RGB2 convertirArgb2(RGB1 rgb1);
int main(){
    RGB1 rgb1;
    RGB2 rgb2;
}

RGB1 convertirArgb1(RGB2 rgb2){
    RGB1 rgb1;
    rgb1.rojo = rgb2.rojo << 3;
    rgb1.verde = rgb2.verde << 2;
    rgb1.azul = rgb2.azul << 3;
    return rgb1;
}

RGB2 convertirArgb2(RGB1 rgb1){
    RGB2 rgb2;
    rgb2.rojo = rgb1.rojo >> 3;
    rgb2.verde = rgb1.verde >> 2;
    rgb2.azul = rgb1.azul >> 3;
    return rgb2;
}