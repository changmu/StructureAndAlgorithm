////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-05 16:27:31
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2391
////Problem Title: 
////Run result: Accept
////Run time:1140MS
////Run memory:4140KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1002

int dp[maxn][maxn];

int max(int a, int b){
	return a > b ? a : b;
}

int main()
{
	int t, m, n, i, j, cas;
	scanf("%d", &t);
	for(cas = 1; cas <= t; ++cas){
		scanf("%d%d", &m, &n);
		for(i = 1; i <= m; ++i)
			for(j = 1; j <= n; ++j){
				scanf("%d", &dp[i][j]);
				dp[i][j] += max(dp[i-1][j], dp[i][j-1]);
			}
		printf("Scenario #%d:\n%d\n\n", cas, dp[m][n]);
	}
	return 0;
}