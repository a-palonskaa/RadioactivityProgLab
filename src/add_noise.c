#include <stdio.h>
#include "add_noise.h"

// int main()
// {
//     int i = 0;
//     for (i = 0; i < 100; i++)
//     printf("%.5f\n", rand_range(-1, 1) * 0.05);
//     printf("%d", RAND_MAX);


//     return 0;
// }


void add_noise(double *radioactivity, int N)
{
    for (int i = 0; i < N; i++) {
        radioactivity[i] += rand_range(-1, 1) * 0.05;
    }

    return;
}

double rand_range(double min, double max)
{
    double random = ((double) rand()) / RAND_MAX;
    double range = (max - min) * random;
    double number = min + range;

    return number;
}
