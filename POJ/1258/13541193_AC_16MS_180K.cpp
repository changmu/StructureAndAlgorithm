#include <stdio.h>
#include <string.h>

#define maxn 110
#define maxm maxn * maxn
#define inf 0x3f3f3f3f

int n, id, dist[maxn];
int G[maxn][maxn];
bool vis[maxn];

void getMap() {
	int u, v, k, dis, i, j; id = 0;
	for(i = 0; i < n; ++i) 
		for(j = 0; j < n; ++j) 
			scanf("%d", &G[i][j]);
}

int getNext() {
	int i, pos = -1, dis = inf;
	for(i = 0; i < n; ++i)
		if(!vis[i] && dist[i] < dis) {
			dis = dist[i]; pos = i;
		}
	return pos;
}

int Prim() {
	int sum = 0, i, u, v;
	for(i = 0; i < n; ++i) {
		vis[i] = 0; dist[i] = inf;
	}
	u = 0; dist[u] = 0;
	while(u != -1) {
		vis[u] = 1; sum += dist[u];
		for(i = 0; i < n; ++i)
			if(!vis[i] && dist[i] > G[u][i])
				dist[i] = G[u][i];
		u = getNext();
	}
	return sum;
}

void solve() {
	printf("%d\n", Prim());
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	while(scanf("%d", &n) == 1) {
		getMap();
		solve();
	}
	return 0;
}
