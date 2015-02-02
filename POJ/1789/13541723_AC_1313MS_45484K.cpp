#include <stdio.h>
#include <string.h>

#define maxn 2010
#define maxm maxn * maxn
#define inf 0x3f3f3f3f

int head[maxn], n, id;
struct Node {
	int v, w, next;
} E[maxm];
char map[maxn][8];
int dis[maxn];
bool vis[maxn];

int calDis(int x, int y) {
	int sum = 0;
	for(int i = 0; i < 7; ++i)
		if(map[x][i] != map[y][i]) ++sum;
	return sum;
}

void addEdge(int u, int v, int w) {
	E[id].v = v; E[id].w = w;
	E[id].next = head[u]; head[u] = id++;
}

void getMap() {
	memset(head, -1, sizeof(int) * n);
	int i, j, w; id = 0;
	for(i = 0; i < n; ++i) {
		scanf("%s", map[i]);
		for(j = 0; j < i; ++j) {
			w = calDis(i, j);
			addEdge(i, j, w);
			addEdge(j, i, w);
		}
	}
}

int getNext() {
	int i, pos = -1, w = inf;
	for(i = 0; i < n; ++i)
		if(!vis[i] && w > dis[i]) {
			w = dis[i]; pos = i;
		}
	return pos;
}

int Prim() {
	int i, u, v, sum = 0;
	for(i = 0; i < n; ++i) {
		vis[i] = 0; dis[i] = inf;
	}
	dis[u = 0] = 0;
	while(u != -1) {
		vis[u] = 1; sum += dis[u];
		for(i = head[u]; i != -1; i = E[i].next)
			if(!vis[v = E[i].v] && dis[v] > E[i].w)
				dis[v] = E[i].w;
		u = getNext();
	}
	return sum;
}

void solve() {
	printf("The highest possible quality is 1/%d.\n", Prim());
}

int main() {
	while(scanf("%d", &n), n) {
		getMap();
		solve();
	}
	return 0;
}