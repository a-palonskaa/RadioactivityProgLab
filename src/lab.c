#include <stdio.h>
#include "experiment.h"
#include "add_noise.h"
#include "nonlinear_equation.h"
#include "linear_equation.h"
#include "precision_analysis.h"

int main() {
    double start_time = 0.0;
    double end_time = 9.9;
    double step = 0.1;
    const double precision = 0.001;

    double time[100] = {};
    double radioactivity[100] = {};

    int N = experiment(radioactivity, time, start_time, end_time, step);

    double decay_rate = linear_equation(radioactivity, time, N);

    add_noise(radioactivity, N);

    double decay_time = nonlinear_equation(radioactivity, time, N, precision);
    printf("decay_time = %f\n decay_rate = %f\n", decay_time, decay_rate);


    double time_differences = precision_analysis(radioactivity, time, N);
    printf("time_differences = %f\n", time_differences);

    return 0;
}
