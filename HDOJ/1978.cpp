////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-27 18:45:50
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1978
////Problem Title: 
////Run result: Accept
////Run time:280MS
////Run memory:1140KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 102
const int mod = 1e4;

int dp[maxn][maxn], que[maxn * maxn << 1];
int G[maxn][maxn];

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, N, M, i, j, front, back, x, y, t;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &N, &M);
		for (i = 1; i <= N; ++i)
			for (j = 1; j <= M; ++j)
				scanf("%d", &G[i][j]);
		memset(dp, 0, sizeof(dp));
		dp[1][1] = 1;
		for (i = 1; i <= N; ++i)
			for (j = 1; j <= M; ++j) {
				t = dp[i][j]; dp[i][j] = 0;
				for (x = 0; x <= G[i][j]; ++x)
					for (y = G[i][j] - x; y >= 0; --y) 
						if (i + x <= N && j + y <= M) {
							dp[i+x][j+y] += t;
							if (dp[i+x][j+y] >= mod) dp[i+x][j+y] -= mod; 
						}
					
			}
		printf("%d\n", dp[N][M]);
	}
	return 0;
}
