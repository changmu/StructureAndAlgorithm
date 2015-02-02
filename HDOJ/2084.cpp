////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-16 22:56:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2084
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:1100KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int dp[102][102];

int max(int a, int b) { return a > b ? a : b; }

int main() {
	// freopen("stdin.txt", "r", stdin);
	// freopen("stdout.txt", "w", stdout);
	int T, n, i, j, ans;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (i = 1; i <= n; ++i)
			for (j = 1; j <= i; ++j) {
				scanf("%d", &dp[i][j]);
				dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
			}
		for (ans = 0, i = 1; i <= n; ++i)
			ans = max(ans, dp[n][i]);
		printf("%d\n", ans);
	}
	return 0;
}
