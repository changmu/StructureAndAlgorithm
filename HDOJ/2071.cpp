////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-18 18:52:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2071
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1104KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, n;
	double x, y;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%lf", &n, &x);
		y = x;
		while (--n) {
			scanf("%lf", &x);
			if (x > y) y = x;
		}
		printf("%.2lf\n", y);
	}
	return 0;
}
