#include <stdio.h>
#include "precision_analysis.h"
#include "linear_equation.h"
#include "nonlinear_equation.h"
#include "deviations.h"

double precision_analysis (double *radioactivity, double *time, int N)
{
    int num_exp_pnt = 9;
    const double precision = 0.001;

    double dev_ex = 1, dev_ln = 0;
    while (dev_ex * 2 >= dev_ln)
    {
        if (num_exp_pnt++ >= N)
        {
            fprintf (stderr, "nise error\n");
            return 0;
        }
        double decay_time = nonlinear_equation (radioactivity, time, num_exp_pnt, precision);
        double decay_rate = linear_equation    (radioactivity, time, num_exp_pnt);
        dev_ex            = dev_exp            (radioactivity, time, num_exp_pnt , decay_time);
        dev_ln            = dev_linear         (radioactivity, time, num_exp_pnt, decay_rate);
    }

    return time[num_exp_pnt] - time[0];
}
