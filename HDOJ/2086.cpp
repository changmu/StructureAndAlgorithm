////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-16 15:51:26
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2086
////Problem Title: 
////Run result: Accept
////Run time:124MS
////Run memory:1104KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int main() {
	// freopen("stdin.txt", "r", stdin);
	int n, i;
	double c, C, a, b;

	while (scanf("%d", &n) == 1) {
		scanf("%lf%lf", &a, &b);
		C = 0.0;
		for (i = n; i >= 1; --i) {
			scanf("%lf", &c);
			C += i * c;
		}
		C *= 2.0;
		printf("%.2lf\n", (b - C + n * a) / (n + 1));
	}
	return 0;
}
