#include "experiment.h"
#include <math.h>

double const betta = 3.0;

int experiment(double *radioactivity, double *time, double start_time, double end_time, double step)
{
    double R0 = 1;
    int N = 0;
    int i = 0;
    double current_time = start_time;

    for (i = 0; current_time <= end_time; i++) {
        time[i] = current_time;
        radioactivity[i] = R0 * exp(-current_time / betta);

        // printf("time[%d] = %lg\n", N, time[N]);
        // printf("radioactivity[%d] = %lg\n", N, radioactivity[N]);

        current_time += step;
    }
    N = i;

//     printf("------%d\n, %d", N, i);
//     for (i = 0; i <= N; i++) {
//
//         printf("time[%d] = %lg\n", i, time[i]);
//         printf("radioactivity[%d] = %lg\n", i, radioactivity[i]);
//
//     }
    return N;
}
