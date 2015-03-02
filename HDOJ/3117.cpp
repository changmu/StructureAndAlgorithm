////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-26 15:26:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3117
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1128KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <math.h>

int fib_4[15010] = {0, 1}, fib[40] = {0, 1};
const double x = log10(1.0 / sqrt(5.0));
const double y = log10((1.0 + sqrt(5.0)) / 2.0);

int main() {
	int n, i, b;
	double a;
	for (i = 2; i < 40; ++i) fib[i] = fib[i-1] + fib[i-2];
	for (i = 2; i <= 15000; ++i) {
		fib_4[i] = fib_4[i-1] + fib_4[i-2];
		if (fib_4[i] >= 10000) fib_4[i] -= 10000;
	}
	while (scanf("%d", &n) == 1) {
		if (n < 40) printf("%d\n", fib[n]);
		else {
			a = x + n * y;
			a -= (int)a;
			a = pow(10, a);
			printf("%d...%0.4d\n", (int)(a * 1000), fib_4[n%15000]);
		}
	}
	return 0;
}
