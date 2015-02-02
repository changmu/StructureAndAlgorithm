////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-26 16:01:13
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2844
////Problem Title: 
////Run result: Accept
////Run time:453MS
////Run memory:376KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 100010

int Va[105];
bool dp[maxn];

void zeroOnePack(int v, int tv) {
	for(int i = tv; i >= v; --i)
		if(dp[i-v]) dp[i] = true;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int N, M, i, j, v, m;
	while(scanf("%d%d", &N, &M), N | M) {
		if(M > 0) 
			memset(dp, 0, sizeof(bool) * (M + 1));
		for(i = 0; i < N; ++i)
			scanf("%d", &Va[i]);
		dp[0] = true;
		for(i = 0; i < N; ++i) {
			scanf("%d", &m);
			for(j = 1; j <= m; j <<= 1) {
				v = j * Va[i];
				zeroOnePack(v, M);
				m -= j;
			}
			if(m > 0) {
				v = m * Va[i];
				zeroOnePack(v, M);
			}
		}
		for(i = 1, m = 0; i <= M; ++i)
			if(dp[i]) ++m;
		printf("%d\n", m);		
	}
    return 0;
}