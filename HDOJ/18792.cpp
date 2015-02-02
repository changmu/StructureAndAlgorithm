////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-14 21:42:52
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1879
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:300KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define inf 0x3f3f3f3f
#define maxn 102

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

void Prim(int n)
{
	int i, count = 0, tmp, u, len = 0;
	for(i = 1; i <= n; ++i){
		dist[i] = map[1][i]; vis[i] = 0;
	}
	vis[1] = 1; u = getNext(n);
	while(count < n - 1){
		if(u == -1) return;
		for(i = 1; i <= n; ++i)
			if(!vis[i] && dist[i] > map[u][i])
				dist[i] = map[u][i];
		len += dist[u]; vis[u] = 1;
		++count;
		u = getNext(n);
	}
	printf("%d\n", len);
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	int n, i, a, b, c, d, m;
	while(scanf("%d", &n), n){
		memset(map, 0x3f, sizeof(map));
		m = n * (n - 1) / 2;
		for(i = 0; i < m; ++i){
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if(d) map[a][b] = map[b][a] = 0;
			else if(c < map[a][b]){
				map[a][b] = map[b][a] = c;
			}
		}
		Prim(n);
	}
	return 0;
}
