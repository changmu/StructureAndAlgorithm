#include <stdio.h>
#include <string.h>

#define maxn 30
#define maxm 160
#define inf 0x3f3f3f3f

int n, head[maxn], id, dist[maxn];
struct Node {
	int v, dis, next;
} E[maxm];
bool vis[maxn];

void addEdge(int u, int v, int dis) {
	E[id].v = v; E[id].dis = dis;
	E[id].next = head[u]; head[u] = id++;
}

void getMap() {
	int u, v, k, dis, i; id = 0;
	char ch[2];
	memset(head, -1, sizeof(head));
	for(i = 1; i < n; ++i) {
		scanf("%s%d", ch, &k);
		u = ch[0] - 'A';
		while(k--) {
			scanf("%s%d", ch, &dis);
			v = ch[0] - 'A';
			addEdge(u, v, dis);
			addEdge(v, u, dis);
		}
	}
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
		for(i = head[u]; i != -1; i = E[i].next)
			if(dist[v = E[i].v] > E[i].dis)
				dist[v] = E[i].dis;
		u = getNext();
	}
	return sum;
}

void solve() {
	printf("%d\n", Prim());
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	while(scanf("%d", &n), n) {
		getMap();
		solve();
	}
	return 0;
}
