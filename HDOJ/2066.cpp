////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-28 16:46:17
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2066
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:4144KB
//////////////////System Comment End//////////////////
//Dijkstra
#include <stdio.h>
#include <string.h>
#define INF -1
#define maxn 1002

int map[maxn][maxn];
int dist[maxn];
bool vis[maxn], exis[maxn];

int getNext(int n)
{
	int u = -1, tmp = 100000000;
	for(int i = 0; i <= n; ++i)
		if(!vis[i] && exis[i] && dist[i] != INF && dist[i] < tmp){
			tmp = dist[i]; u = i;
		}
	return u;
}

void Dijkstra(int v, int n)
{
	int i, tmp;
	dist[v] = 0;
	while(v != -1){
		for(i = 1; i <= n; ++i){
			if(map[v][i] != -1){
				tmp = dist[v] + map[v][i];
				if(dist[i] == INF || tmp < dist[i])
					dist[i] = tmp;
			}
		}
		vis[v] = 1;
		v = getNext(n);
	}
}

int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t, s, d, a, b, c, i, ans;
	while(scanf("%d%d%d", &t, &s, &d) != EOF){
		memset(map, -1, sizeof(map));
		memset(dist, -1, sizeof(dist));
		memset(vis, 0, sizeof(vis));
		memset(exis, 0, sizeof(exis));
		for(i = 0; i <= 1000; ++i) map[i][i] = 0;
		for(i = 0; i < t; ++i){
			scanf("%d%d%d", &a, &b, &c);
			if(map[a][b] == INF || c < map[a][b])
				map[a][b] = map[b][a] = c;			
			exis[a] = exis[b] = 1;
		}
		for(i = 0; i < s; ++i){
			scanf("%d", &a);
			map[0][a] = map[a][0] = 0;
		}
		Dijkstra(0, 1000);
		ans = 100000000;
		while(d--){
			scanf("%d", &a);
			if(dist[a] != INF && dist[a] < ans)
				ans = dist[a];
		}
		printf("%d\n", ans);
	}
	return 0;
}