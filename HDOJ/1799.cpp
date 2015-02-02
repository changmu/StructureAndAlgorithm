////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-31 20:08:12
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1799
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:15900KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#define maxn 2002

int dp[maxn][maxn];

void count()
{
	int i, j;
	for(i = 1; i < maxn; ++i)
		dp[i][1] = i % 1007;
	for(i = 1; i < maxn; ++i)
		for(j = 2; j < maxn; ++j)
			dp[i][j] = (dp[i-1][j] + dp[i-1][j-1]) % 1007;
}

int main()
{
	int n, m, t;
	count();
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &m, &n);
		printf("%d\n", dp[n][m]);
	}
	return 0;
}