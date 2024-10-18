#include <assert.h>
#include <math.h>

#include "deviations.h"

double dev_exp(double *radioactivity, double *time, int N, double decay_time)
{
    assert(radioactivity);
    assert(time);

    double deviation_exp = 0, sum_residuals_exp = 0;
    int i = 0;

    for (i = 0, sum_residuals_exp = 0; i < N; i++)
        sum_residuals_exp += (radioactivity[i] - exp(time[i] / decay_time * -1)) *
                             (radioactivity[i] - exp(time[i] / decay_time * -1));

    deviation_exp = sqrt(sum_residuals_exp) / N;

    return deviation_exp;
}

double dev_linear(double *radioactivity, double *time, int M, double decay_rate)
{
    assert(radioactivity);
    assert(time);

    double deviation_linear = 0, sum_residuals_linear = 0;
    int i = 0;

    for (i = 0, sum_residuals_linear = 0; i < M; i++)
        sum_residuals_linear += (radioactivity[i] - (1 - time[i] / decay_rate)) *
                                (radioactivity[i] - (1 - time[i] / decay_rate));

    deviation_linear = sqrt(sum_residuals_linear) / M;

    return deviation_linear;
}
