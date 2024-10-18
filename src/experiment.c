#include <stdio.h>
#include "experiment.h"
#include "add_noise.h"
#include "nonlinear_equation.h"
#include "model.h"
#include "precision_analysis.h"
#include "linear_equation.h"

int main() {
    double start_time = 0.0;
    double end_time = 9.9;
    double step = 0.1;
    double precision = 0.0001;

    double time[100] = {};
    double radioactivity[100] = {};

    int N = experiment(radioactivity, time, start_time, end_time, step);

    add_noise(radioactivity, N);

    double time_differences = precision_analysis(radioactivity, time, int N);

    return 0;
}
