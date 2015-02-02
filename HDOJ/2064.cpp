////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-25 21:26:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2064
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>

__int64 dp[36] = {0, 2};

int main()
{
	int n;
	for(n = 2; n < 36; ++n) dp[n] = dp[n-1] * 3 + 2;
	while(scanf("%d", &n) == 1) printf("%I64d\n", dp[n]);
	return 0;
}