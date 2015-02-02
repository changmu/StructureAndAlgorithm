////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-30 09:44:34
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1874
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:220KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 202
#define maxm 2002

int head[maxn], dist[maxn];
struct Node{
	int to, w, next;
} edge[maxm];
bool vis[maxn];

int getNext(int n)
{
	int i, u = -1, tmp = -1;
	for(i = 0; i < n; ++i)
		if(!vis[i] && dist[i] != -1 && (dist[i] < tmp || tmp == -1)){
			tmp = dist[i]; u = i;
		}
	return u;
}

void Dijkstra(int v, int u, int n)
{
	int i, tmp;
	dist[v] = 0;
	while(v != -1){
		for(i = head[v]; i != -1; i = edge[i].next){
			if(vis[edge[i].to]) continue;
			tmp = dist[v] + edge[i].w;
			if(dist[edge[i].to] == -1 || tmp < dist[edge[i].to])
				dist[edge[i].to] = tmp;
		}
		vis[v] = true;
		v = getNext(n);
		if(vis[u]) return;
	}
}

int main()
{
	int n, m, i, a, b, c;
	while(scanf("%d%d", &n, &m) != EOF){
		memset(head, -1, sizeof(head));
		memset(vis, 0, sizeof(vis));
		memset(dist, -1, sizeof(dist));
		for(i = 0; i < m; ++i){
			scanf("%d%d%d", &a, &b, &c);
			edge[i].to = b; edge[i].w = c;
			edge[i].next = head[a];
			head[a] = i;
			edge[m+i].to = a; edge[m+i].w = c;
			edge[m+i].next = head[b];
			head[b] = m + i;
		}
		scanf("%d%d", &a, &b);
		Dijkstra(a, b, n);
		printf("%d\n", dist[b]);
	}
	return 0;
}