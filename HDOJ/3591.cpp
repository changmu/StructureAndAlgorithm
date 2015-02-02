////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-28 12:43:23
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3591
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 102
#define maxv 20002
#define inf 0x3f3f3f3f

int V[maxn], dp[maxv], dp2[maxv], N, T;

int min(int a, int b) { return a < b ? a : b; }

void zeroOnePack(int v, int c) {
	for(int i = maxv - 1; i >= v; --i)
		dp[i] = min(dp[i], dp[i-v] + c);
}

void completePack(int v) {
	for(int i = v; i < maxv; ++i)
		dp2[i] = min(dp2[i], dp2[i-v] + 1);
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int i, j, m, ans, cas = 1;
	while(scanf("%d%d", &N, &T), N | T) {
		for(i = 0; i < N; ++i)
			scanf("%d", &V[i]);
		memset(dp, 0x3f, sizeof(dp));
		memset(dp2, 0x3f, sizeof(dp2));
		dp[0] = dp2[0] = 0;
		for(i = 0; i < N; ++i) {
			scanf("%d", &m);
			for(j = 1; m; j <<= 1) {
				if(j > m) j = m;
				zeroOnePack(V[i] * j, j);
				m -= j;
			}
			completePack(V[i]);
		}
		ans = inf;
		for(i = T; i < maxv; ++i)
			ans = min(ans, dp[i] + dp2[i-T]);
		if(ans == inf) ans = -1;
		printf("Case %d: %d\n", cas++, ans);
	}
    return 0;
}