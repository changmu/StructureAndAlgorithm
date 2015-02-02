////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-26 15:29:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1171
////Problem Title: 
////Run result: Accept
////Run time:109MS
////Run memory:536KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 250010

int dp[maxn], V[maxn];

int max(int a, int b) {
	return a > b ? a : b;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int N, i, j, v, m, cnt, sum;
	while(scanf("%d", &N), N >= 0) {
		sum = cnt = 0;
		while(N--) {
			scanf("%d%d", &v, &m);
			for(i = 1; i <= m; i <<= 1) {
				V[cnt++] = i * v;
				sum += i * v;
				m -= i;
			}
			if(m > 0) {
				V[cnt++] = m * v;
				sum += m * v;
			}
		}
		v = sum >> 1;
		memset(dp, 0, sizeof(int) * (v + 1));
		for(i = 0; i < cnt; ++i)
			for(j = v; j >= V[i]; --j)
				dp[j] = max(dp[j], dp[j-V[i]] + V[i]);
		v = sum - dp[v];
		m = sum - v;
		printf("%d %d\n", v, m);
	}
    return 0;
}