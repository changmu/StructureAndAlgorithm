////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-27 22:23:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2159
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:324KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 110

int dp[maxn][maxn];

int max(int a, int b) { return a > b ? a : b; }

int main() {
	// freopen("stdin.txt", "r", stdin);
	int N, M, K, S, i, j, k, a, b, ok;
	while(scanf("%d%d%d%d", &N, &M, &K, &S) == 4) {
		memset(dp, 0, sizeof(dp));
		for(i = ok = 0; i < K; ++i) {
			scanf("%d%d", &a, &b);
			for(j = 1; j <= S; ++j) {
				for(k = b; k <= M; ++k) {
					dp[j][k] = max(dp[j][k], dp[j-1][k-b] + a);
				}
			}
		}
		if(dp[S][M] < N) printf("-1\n");
		else {
			for(i = 1, ok = 0; i <= M && !ok; ++i)
				for(j = 1; j <= S && !ok; ++j)
					if(dp[j][i] >= N) ok = i;
			printf("%d\n", M - ok);
		}
	}
    return 0;
}