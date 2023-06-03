int potencia(int x, int y){
    int i, pot = 1;
    for(i = 0; i < y; i++){
        pot *= x;
    }
    return pot;
}
int cuadrado(int x){
    return x * x;
}
int cubo(int x){
    return x * x * x;
}
int factorial(int x){
    int i, fact = 1;
    for(i = 1; i <= x; i++){
        fact *= i;
    }
    return fact;
}
int absoluto(int i){
    if(i < 0){
        return -i;
    }
    return i;
}
int sumatoria(int i){
    int j, suma = 0;
    for(j = 1; j <= i; j++){
        suma += j;
    }
    return suma;
}
int multiplo(int x, int y){
    if(x % y == 0){
        return 1;
    }
    return 0;
}
int divisor(int x, int y){
    if(y % x == 0){
        return 1;
    }
    return 0;
}
int par(int i){
    if(i % 2 == 0){
        return 1;
    }
    return 0;
}
int impar(int i){
    if(i % 2 != 0){
        return 1;
    }
    return 0;
}