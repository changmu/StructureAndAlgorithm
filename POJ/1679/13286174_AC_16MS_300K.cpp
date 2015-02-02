#include <stdio.h>
#include <string.h>
#include <limits.h>
#define maxn 102
#define maxm (maxn * maxn) >> 1

int head[maxn], max[maxn][maxn];
struct Node{
	int u, v, cost, next;
	bool vis;
} E[maxm];
bool vis[maxn];

int mini(int a, int b){
	return a < b ? a : b;
}

int prim(int n, int m)
{
	int u, i, tmp, j, len = 0, count = 0;
	memset(max, 0x7f, sizeof(max));
	memset(vis, 0, sizeof(vis));
	vis[1] = 1;
	while(count < n - 1){
		for(i = 1, tmp = INT_MAX; i <= n; ++i){
			if(!vis[i]) continue;
			for(j = head[i]; j != -1; j = E[j].next){
				if(vis[E[j].v]) continue;
				if(E[j].cost < tmp){
					tmp = E[j].cost; u = j;
				}
			}
		}
		++count; len += tmp;
		for(i = 1; i <= n; ++i){
			if(!vis[i]) continue;
			max[i][E[u].v] = max[E[u].v][i] = E[u].cost;
		}
		vis[E[u].v] = 1; E[u].vis = 1;
	}
	return len;
}

int getSecLen(int n, int m)
{
	int min = INT_MAX, u, v, w;
	for(int i = 0; i < m; ++i){
		if(E[i].vis) continue;
		u = E[i].u; v = E[i].v;
		w = E[i].cost;
		min = mini(min, w - max[u][v]);
		if(min == 0) return 0;
	}
	return min;
}

int main()
{
	int t, n, m, i, minLen, secLen;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		memset(head, -1, sizeof(head));
		for(i = 0; i < m; ++i){
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
			E[i].vis = 0; E[i].next = head[E[i].u];
			head[E[i].u] = i;
		}
		minLen = prim(n, m);
		secLen = getSecLen(n, m);
		if(secLen == 0) printf("Not Unique!\n");
		else printf("%d\n", minLen);
	}
	return 0;
}