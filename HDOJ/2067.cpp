////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-18 20:01:58
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2067
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1072KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>

__int64 dp[40][40];

int main() {
	// freopen("stdin.txt", "r", stdin);
	int i, j, n, cas = 1;
	for (i = 0; i <= 35; ++i)
		dp[0][i] = 1;
	for (i = 1; i <= 35; ++i) {
		for (j = i; j <= 35; ++j) {
			if (i == j) {
				dp[i][i] = dp[i-1][j];
			} else dp[i][j] = dp[i-1][j] + dp[i][j-1];
		}
	}
	while (scanf("%d", &n), n > 0)
		printf("%d %d %I64d\n", cas++, n, dp[n][n] << 1);
	return 0;
}
