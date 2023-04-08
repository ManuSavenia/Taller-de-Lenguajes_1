#include <stdio.h>

int main()
{
    double pi = 3.0;
    double a = -1.0;
    for (int i = 2; i < 3000; i += 2)
    {
        a *= -1;
        pi += a * ((double)4 / (i * (i + 1) * (i + 2)));
    }

    printf("%.10f", pi);
}