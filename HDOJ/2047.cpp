////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-01-27 23:46:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2047
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
__int64 x[40] = {0, 3, 8};

int main(){
	int n;
	for(n = 3; n != 40; ++n)
		x[n] = 2 * (x[n-1] + x[n-2]);
	while(scanf("%d", &n) == 1)
		printf("%I64d\n", x[n]);
	return 0;
}