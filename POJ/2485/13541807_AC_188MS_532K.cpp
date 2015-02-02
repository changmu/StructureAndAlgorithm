#include <stdio.h>
#include <string.h>

#define maxn 505
#define inf 0x3f3f3f3f

int G[maxn][maxn], n;
int dis[maxn];
bool vis[maxn];

void getMap() {
	scanf("%d", &n);
	int i, j;
	for(i = 0; i < n; ++i)
		for(j = 0; j < n; ++j)
			scanf("%d", &G[i][j]);
}

int getNext() {
	int i, pos = -1, val = inf;
	for(i = 0; i < n; ++i)
		if(!vis[i] && dis[i] < val) {
			val = dis[i]; pos = i;
		}
	return pos;
}

void solve() {
	int i, u, ans = 0;
	for(i = 0; i < n; ++i) {
		vis[i] = 0; dis[i] = inf;
	}
	dis[u=0] = 0;
	while(u != -1) {
		vis[u] = 1;
		if(ans < dis[u]) ans = dis[u];
		for(i = 0; i < n; ++i)
			if(!vis[i] && dis[i] > G[u][i])
				dis[i] = G[u][i];
		u = getNext();
	}
	printf("%d\n", ans);
}

int main() {
	int t;
	scanf("%d", &t);
	while(t--) {
		getMap();
		solve();
	}
	return 0;
}