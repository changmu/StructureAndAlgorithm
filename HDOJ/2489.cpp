////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-10 17:45:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2489
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:228KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <limits.h>
#define maxn 16

int map[maxn][maxn], node[maxn];
int n, m, store[maxn], vis[maxn];
double ans;
bool visted[maxn]; //hash to vis array

double prim()
{
	int i, j, u, count = 0, tmp, vnv = 0, vne = 0;
	for(i = 1; i <= m; ++i) vnv += node[vis[i]];
	memset(visted, 0, sizeof(visted));
	visted[1] = 1;
	while(count < m - 1){
		for(i = 1, tmp = INT_MAX; i <= m; ++i){
			if(!visted[i]) continue;
			for(j = 1; j <= m; ++j){
				if(!visted[j] && map[vis[i]][vis[j]] < tmp){
					tmp = map[vis[i]][vis[j]]; u = j;
				}
			}
		}
		if(tmp != INT_MAX){
			visted[u] = 1;
			vne += tmp; ++count;
		}
	}
	return vne * 1.0 / vnv;
}

void DFS(int k, int id)
{
	if(id > m){
		double tmp = prim();
		if(tmp - ans < -(1e-8)){
			ans = tmp; memcpy(store, vis, sizeof(vis));
		}
		return;
	}
	for(int i = k; i <= n; ++i){
		vis[id] = i;
		DFS(i + 1, id + 1);
	}
}

int main()
{
	int i, j;
	while(scanf("%d%d", &n, &m), n || m){
		for(i = 1; i <= n; ++i) scanf("%d", &node[i]);
		for(i = 1; i <= n; ++i)
			for(j = 1; j <= n; ++j)
				scanf("%d", &map[i][j]);
		ans = INT_MAX;
		DFS(1, 1);
		for(i = 1; i <= m; ++i)
			if(i != m) printf("%d ", store[i]);
			else printf("%d\n", store[i]);
	}
	return 0;
}