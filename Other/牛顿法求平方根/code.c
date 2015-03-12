/************************************************************* 
 * y = sqrt(x): y is the average of y and x / y.
 *************************************************************/ 
#include <stdio.h>

const double eps = 1e-8;

double Fabs(double x) { return x < 0.0 ? -x : x; }

double mySqrt(double x, double y) {
	if (Fabs(x - y * y) < eps) 
		return y;
	else return mySqrt(x, (x / y + y) / 2.0);
}

int main()
{
	double x;
	while (~scanf("%lf", &x))
		printf("%lf\n", mySqrt(x, 1.0));
	return 0;
}
