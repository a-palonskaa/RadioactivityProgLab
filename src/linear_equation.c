#include "linear_equation.h"

double linear_equation(double * radioactivity, double *time, int N)
{
	double TimeSum = 0;
	double RadioactivitySum = 0;

	for(int i = 0; i < N; i++)
	{
		RadioactivitySum += radioactivity[i];
		TimeSum += time[i];
	}

	return (TimeSum / N) / (1 - RadioactivitySum / N);
}
