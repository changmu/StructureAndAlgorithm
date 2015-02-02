////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 21:41:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2044
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>

int main(){
	__int64 aa[50] = {1, 1, 2};
	int i, n, a, b;
	for(i = 3; i != 50; ++i)
		aa[i] = aa[i - 1] + aa[i - 2];
	scanf("%ld", &n);
	while(n-- && scanf("%d%d", &a, &b))
		printf("%I64d\n", aa[b - a]);
	return 0;
}