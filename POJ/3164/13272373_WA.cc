#include <stdio.h>
#include <string.h>
#include <math.h>
#include <limits.h>
#define maxn 102
#define maxm 10002
#define inf INT_MAX

struct Node{
	double x, y;
} ver[maxn];
struct Node2{
	int u, v;
	double cost;
} edge[maxm];
double ans;
int pre[maxn], hash[maxn], vis[maxn];
double in[maxn];

bool ZL_MST(int root, int nv, int ne)
{
	ans = 0;
	int i, u, v, cntnode;
	while(true){
		for(i = 0; i < nv; ++i) in[i] = inf;
		for(i = 0; i < ne; ++i){
			u = edge[i].u; v = edge[i].v;
			if(edge[i].cost < in[v] && u != v){
				pre[v] = u; in[v] = edge[i].cost;
			}
		}
		for(i = 0; i < nv; ++i)
			if(i != root && in[i] == inf) return false;
		memset(hash, -1, sizeof(hash));
		memset(vis, -1, sizeof(vis));
		in[root] = cntnode = 0;
		for(i = 0; i < nv; ++i){
			ans += in[i];
			v = i;
			while(vis[v] != i && hash[v] == -1 && v != root){
				vis[v] = i; v = pre[v];
			}
			if(v != root && hash[v] == -1){
				for(u = pre[v]; u != v; u = pre[u]){
					hash[u] = cntnode;
				}
				hash[v] = cntnode++;
			}
		}
		if(cntnode == 0) break;
		for(i = 0; i < nv; ++i)
			if(hash[i] == -1) hash[i] = cntnode++;

		for(i = 0; i < ne; ++i){
			v = edge[i].v;
			edge[i].u = hash[edge[i].u];
			edge[i].v = hash[edge[i].v];
			if(edge[i].u != edge[i].v){
				edge[i].cost -= in[v];
			}
		}

		nv = cntnode;
		root = hash[root];
	}
	return true;
}

int main()
{
	int n, m, a, b, i;
	double x, y;
	while(scanf("%d%d", &n, &m) == 2){
		for(i = 0; i < n; ++i)
			scanf("%lf%lf", &ver[i].x, &ver[i].y);
		for(i = 0; i < m; ++i){
			scanf("%d%d", &a, &b);
			x = ver[--a].x - ver[--b].x;
			y = ver[a].y - ver[b].y;
			edge[i].cost = sqrt(x * x + y * y);
			edge[i].u = a; edge[i].v = b;
		}
		if(ZL_MST(0, n, m)) printf("%.2lf\n", ans);
		else printf("poor snoopy\n");
	}
	return 0;
}