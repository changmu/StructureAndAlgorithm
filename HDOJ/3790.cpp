////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-12 15:16:44
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3790
////Problem Title: 
////Run result: Accept
////Run time:265MS
////Run memory:824KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1002
#define maxm 100002
#define inf 0x7fffffff

int head[maxn], id;
struct Node{
	int to, cost, dist, next;
} E[maxm << 1];
bool vis[maxn];
int dist[maxn], cost[maxn];

void addEdge(int u, int v, int d, int c)
{
	E[id].to = v; E[id].cost = c; E[id].dist = d;
	E[id].next = head[u]; head[u] = id++;
	E[id].to = u; E[id].cost = c; E[id].dist = d;
	E[id].next = head[v]; head[v] = id++;
}

int getNext(int n)
{
	int i, tmp = inf, u = -1;
	for(i = 1; i <= n; ++i)
		if(!vis[i] && dist[i] < tmp){
			tmp = dist[i]; u = i;
		}
	return u;
}

void Dijkstra(int n, int s, int t)
{
	int u, v, i, count, tmpd, tmpc;
	memset(vis, 0, sizeof(vis));
	memset(dist, 0x7f, sizeof(dist));
	memset(cost, 0x7f, sizeof(cost));
	dist[s] = 0; u = s; cost[s] = 0;
	while(u != -1){
		for(i = head[u]; i != -1; i = E[i].next){
			tmpd = dist[u] + E[i].dist;
			tmpc = cost[u] + E[i].cost;
			v = E[i].to;
			if(tmpd < dist[v]){
				dist[v] = tmpd; cost[v] = tmpc;
			}else if(tmpd == dist[v] && tmpc < cost[v]){
				dist[v] = tmpd; cost[v] = tmpc;
			}
		}
		vis[u] = true;
		if(vis[t]) break;
		u = getNext(n);
	}
}

int main()
{
	int n, m, i, u, v, c, d, s, t;
	while(scanf("%d%d", &n, &m), n || m){
		memset(head, -1, sizeof(head));		
		for(i = id = 0; i < m; ++i){
			scanf("%d%d%d%d", &u, &v, &d, &c);
			addEdge(u, v, d, c);
		}
		scanf("%d%d", &s, &t);
		Dijkstra(n, s, t);
		printf("%d %d\n", dist[t], cost[t]);
	}
	return 0;
}