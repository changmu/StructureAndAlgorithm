////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-25 21:47:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2070
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
__int64 dp[52] = {0, 1};
int main()
{
	int n;
	for(n = 2; n < 51; ++n) dp[n] = dp[n-1] + dp[n-2];
	while(scanf("%d", &n), n != -1) printf("%I64d\n", dp[n]);
	return 0;
}