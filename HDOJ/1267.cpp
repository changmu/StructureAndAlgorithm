////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-28 10:34:40
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1267
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 22

__int64 dp[maxn][maxn];

int main() {
	int i, j;
	for(i = 1; i <= 20; ++i)
		for(j = 1; j <= i; ++j)
			if(1 == j) dp[i][j] = i;
			else dp[i][j] = dp[i][j-1] + dp[i-1][j];
	while(scanf("%d%d", &i, &j) == 2)
		printf("%I64d\n", dp[i][j]);
	return 0;
}