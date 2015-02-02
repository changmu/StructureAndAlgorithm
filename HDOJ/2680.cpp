////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-13 20:30:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2680
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:4236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1010
#define maxm 20010
#define inf 0x3f3f3f3f

int map[maxn][maxn];
int dist[maxn];
bool vis[maxn];

int getNext(int n)
{
	int u = -1, tmp = inf, i;
	for(i = 1; i <= n; ++i)
		if(!vis[i] && dist[i] < tmp){
			tmp = dist[i]; u = i;
		}
	return u;
}

void Dijkstra(int n, int s)
{
	int i, u, v, tmp;
	for(i = 0; i <= n; ++i){
		vis[i] = false; dist[i] = inf;
	}
	u = 0; dist[0] = 0;
	while(u != -1){
		for(i = 0; i <= n; ++i){
			tmp = dist[u] + map[u][i];
			if(tmp < dist[i]) dist[i] = tmp;
		}
		vis[u] = true;
		if(vis[s]) return;
		u = getNext(n);
	}
}

int main()
{
	int n, m, s, w, i, u, v, c;
	while(scanf("%d%d%d", &n, &m, &s) == 3){
		memset(map, 0x3f, sizeof(map));
		for(i = 0; i < m; ++i){
			scanf("%d%d%d", &u, &v, &c);
			if(map[u][v] > c) map[u][v] = c;
		}
		scanf("%d", &w);
		while(w--){
			scanf("%d", &u);
			map[0][u] = 0;
		}
		Dijkstra(n, s);
		printf("%d\n", dist[s] == inf ? -1 : dist[s]);
	}
	return 0;
}
