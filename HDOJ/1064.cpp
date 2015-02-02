////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-20 20:59:20
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:240KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main() {
	double ans, tmp, i;
	while(scanf("%lf", &tmp) == 1) {
		ans = tmp;
		for(i = 0; i < 11; ++i) {
			scanf("%lf", &tmp);
			ans += tmp;
		}
		printf("$%.2lf\n", ans / 12);
	}
	return 0;
}