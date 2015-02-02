////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-26 22:57:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2191
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 110

int dp[maxn];

int max(int a, int b) { return a > b ? a : b; }

void zeroOnePack(int v, int w, int TV) {
	for(int i = TV; i >= v; --i)
		dp[i] = max(dp[i], dp[i-v] + w);
} 

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, N, M, i, cnt, m, v, w, j, vv;
	scanf("%d", &T);
	while(T--) {
		scanf("%d%d", &N, &M);
		memset(dp, 0, sizeof(int) * (N + 1));
		for(i = 0; i < M; ++i) {
			scanf("%d%d%d", &v, &w, &m);
			for(j = 1; m; j <<= 1) {
				if(j > m) j = m;
				zeroOnePack(v * j, w * j, N);
				m -= j;
			}
		}
		printf("%d\n", dp[N]);
	}
    return 0;
}