////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-27 16:29:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2571
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1216KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 22
#define maxm 1002

int V[maxn][maxm], dp[maxn][maxm];
bool vis[maxm];

int max(int a, int b) { return a > b ? a : b; }

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, N, M, i, j, k;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		for (i = 1; i <= N; ++i)
			for (j = 1; j <= M; ++j) {
				scanf("%d", &V[i][j]);
			}
		memset(vis, 0, sizeof(vis));
		dp[1][1] = 0;
		for (j = 1, i = 1; j <= M; ++j) {
			dp[1][j] += V[1][j];
			if (j + 1 <= M) {
				if (!vis[j+1]) dp[i][j+1] = dp[i][j], vis[j+1] = 1;
				else dp[1][j+1] = max(dp[1][j+1], dp[1][j]);
			}
			if (N > 1) dp[2][j] = dp[1][j];
			for (k = 2; j * k <= M; ++k) {
				if (!vis[j*k]) dp[i][j*k] = dp[i][j], vis[j*k] = 1;
				dp[1][j*k] = max(dp[1][j*k], dp[1][j]);
			}
		}
		for (i = 2; i <= N; ++i)
			for (j = 1; j <= M; ++j) {
				dp[i][j] += V[i][j];
				if (i + 1 <= N) dp[i+1][j] = dp[i][j];
				if (j + 1 <= M) {
					dp[i][j+1] = max(dp[i][j+1], dp[i][j]);
				}
				for (k = 2; j * k <= M; ++k) {
					dp[i][j*k] = max(dp[i][j*k], dp[i][j]);
				}
			}
		printf("%d\n", dp[N][M]);
	}
	return 0;
}
