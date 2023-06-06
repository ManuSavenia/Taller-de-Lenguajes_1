#include <stdio.h>
#define MOSTRAR 0
#define pares(x) (x % 2 ? 0 : 1)
int main()
{
int i;
for (i = 10; i > 5; i--)
    {
    #ifdef MOSTRAR
        printf("%d ", i);
        #undef MOSTRAR
    #else
        #define MOSTRAR 0
    #endif
    }
return (0);
}
