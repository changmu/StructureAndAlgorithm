////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-03-11 09:22:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1021
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:4144KB
//////////////////System Comment End//////////////////
//2014-3-11 09:16:50
#include <stdio.h>
#define MAX 1000000
int a[MAX] = {1, 2};

int main(){
	int n;
	for(n = 2; n != MAX; ++n)
		a[n] = (a[n - 1] + a[n - 2]) % 3;
	while(scanf("%d", &n) == 1)
		printf(a[n] ? "no\n" : "yes\n");
	return 0;
}