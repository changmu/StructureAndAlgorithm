////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-14 10:21:25
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1142
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:4196KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1002
#define inf 0x3f3f3f3f

int map[maxn][maxn];
int dist[maxn], dp[maxn];
bool vis[maxn];

int getNext(int n)
{
	int u = -1, tmp = inf, i;
	for(i = 1; i <= n; ++i)
		if(!vis[i] && tmp > dist[i]){
			tmp = dist[i]; u = i;
		}
	return u;
}

void Dijkstra(int s, int n)
{
	int i, u, tmp;
	for(i = 0; i <= n; ++i){
		dist[i] = inf; vis[i] = false;
	}
	u = s; dist[u] = 0;
	while(u != -1){
		for(i = 1; i <= n; ++i){
			if(map[u][i] == inf) continue;
			tmp = map[u][i] + dist[u];
			if(tmp < dist[i]) dist[i] = tmp;
		}
		vis[u] = true;
		u = getNext(n);
	}
}

int DFS(int s, int n)
{
	if(dp[s]) return dp[s];
	if(s == 2) return 1;
	int i, ans = 0;
	for(i = 1; i <= n; ++i)
		if(map[s][i] != inf && dist[i] < dist[s]){
			ans += DFS(i, n);
		}
	return dp[s] = ans;
}

int main()
{
	int n, m, u, v, d, i, j;
	while(scanf("%d%d", &n, &m) == 2){
		for(i = 0; i <= n; ++i){
			for(j = 0; j <= n; ++j)
				map[i][j] = inf;
			map[i][i] = 0;
		}
		for(i = 0; i < m; ++i){
			scanf("%d%d%d", &u, &v, &d);
			map[u][v] = map[v][u] = d;
		}
		Dijkstra(2, n);
		for(i = 0; i <= n; ++i) dp[i] = 0;
		printf("%d\n", DFS(1, n));
	}
	return 0;
}
