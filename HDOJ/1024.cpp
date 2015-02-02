////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-10-21 23:15:31
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1024
////Problem Title: 
////Run result: Accept
////Run time:562MS
////Run memory:1428KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 1000010
#define inf 0x7fffffff

int dp[maxn], preMax[maxn], arr[maxn];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	int n, m, i, j, ans;
	while(scanf("%d%d", &n, &m) == 2) {
		for(i = 1; i <= m; ++i) {
			scanf("%d", &arr[i]);
			preMax[i] = dp[i] = 0;
		}
		preMax[0] = dp[0] = 0;
		for(j = 1; j <= n; ++j) { // 分成j份
			ans = -inf;
			for(i = j; i <= m; ++i) {
				dp[i] = max(dp[i-1], preMax[i-1]) + arr[i];
				preMax[i-1] = ans;
				ans = max(ans, dp[i]);
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}