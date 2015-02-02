////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-05-03 17:04:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2039
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:212KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	double a, b, c;
	int t;
	scanf("%d", &t);
	while(t--){
		scanf("%lf%lf%lf", &a, &b, &c);
		if(a + b > c && a + c > b && b + c > a) printf("YES\n");
		else printf("NO\n");
	}
	return 0;
}