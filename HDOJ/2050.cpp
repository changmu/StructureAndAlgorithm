////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-29 12:25:37
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2050
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:304KB
//////////////////System Comment End//////////////////
//a[n] = a[n-1] + 4 * (n - 1) + 1
#include <stdio.h>
#define MAX 10000 + 2
__int64 a[MAX] = {1, 2, 7};

int main(){	
	int t, i;
	for(i = 3; i != MAX; ++i)
		a[i] = a[i - 1] + 4 * i - 3;
	scanf("%d", &t);
	while(t-- && scanf("%d", &i))
		printf("%I64d\n", a[i]);	
	return 0;
}