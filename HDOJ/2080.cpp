////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-16 23:34:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2080
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1116KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>

const double PI = acos(-1.0);

int main() {
	// freopen("stdin.txt", "r", stdin);
	double x1, y1, x2, y2, a, b, c, y;
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%lf%lf%lf%lf", &x1, &y1, &x2, &y2);
		a = x1 * x1 + y1 * y1;
		b = x2 * x2 + y2 * y2;
		c = (x1 - x2) * (x1 - x2) + (y1 - y2) * (y1 - y2);
		printf("%.2lf\n", acos((a + b - c) / (2 * sqrt(a * b))) * 180.0 / PI);
	}
	return 0;
}
