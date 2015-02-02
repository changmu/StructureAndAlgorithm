////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-30 12:47:25
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2061
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
char buf[31];

int main(){
	int t, n, ok;
	double a, b, sa, sb;
	scanf("%d", &t);
	while(t-- && scanf("%d", &n)){
		sa = sb = 0; ok = 1;
		while(n-- && scanf("%s%lf%lf", buf, &a, &b)){
			if(b >=0 && b < 60) ok = 0;
			if(ok){
				sa += a;
				sb += a * b;
			}
		}
		if(ok) printf("%.2lf\n", sb / sa);
		else printf("Sorry!\n");
		if(t) printf("\n");
	}
	return 0;
}