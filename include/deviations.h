#ifndef DEVIATIONS_H
#define DEVIATIONS_H

double dev_exp   (double *radioactivity, double *time, int N, double decay_time);
double dev_linear(double *radioactivity, double *time, int M, double decay_rate);

#endif
