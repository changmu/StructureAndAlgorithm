////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 19:37:56
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2039
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define ABS(a, b) (a - b >= 0 ? a - b : b - a)

int main(){
	int n, ok;
	double a, b, c;
	scanf("%d", &n);
	while(n-- && scanf("%lf%lf%lf", &a, &b, &c)){
		ok = 1;
		if(!(a + b > c && ABS(a, b) < c && a + c > b && ABS(a, c) < b && b + c > a && ABS(b, c) < a))
			ok = 0;
		if(ok) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}