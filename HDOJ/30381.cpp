////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-11 15:01:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3038
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:2288KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define maxn 200010

int pre[maxn], dist[maxn];
int N, M, ans;

int ufind(int k) {
	if (pre[k] == -1) return k;
	int tmp = ufind(pre[k]);
	dist[k] += dist[pre[k]];
	return pre[k] = tmp;
}

void unite(int u, int v, int d) {
	int x = ufind(u);
	int y = ufind(v);
	if (x != y) {
		pre[x] = y;
		dist[x] = d + dist[v] - dist[u];
	} else if (abs(dist[u] - dist[v]) != d)
		++ans;
	
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int u, v, d, i;
	while (scanf("%d%d", &N, &M) == 2) {
		ans = 0;
		for (i = 0; i <= N; ++i) {
			pre[i] = -1; dist[i] = 0;
		}
		while (M--) {
			scanf("%d%d%d", &u, &v, &d);
			unite(u - 1, v, d);
		}
		printf("%d\n", ans);
	}	
	return 0;
}
