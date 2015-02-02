#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 1002
#define maxm 100002
#define inf 0x7fffffff
using std::priority_queue;
using std::queue;

int head[maxn], Rhead[maxn]; //Rhead[] save the reverse Graph
struct Node{
	int to, dist, next;
} E[maxm], RE[maxm];
int dist[maxn]; //reverse
struct  Node2{
	int to, f, g; //估价函数和已走路径长度
	bool operator<(const Node2& a) const{
		return a.f < f;
	}
};
bool vis[maxn];

void addEdge(int u, int v, int d, int i)
{
	E[i].to = v; E[i].dist = d;
	E[i].next = head[u]; head[u] = i;
	RE[i].to = u; RE[i].dist = d;
	RE[i].next = Rhead[v]; Rhead[v] = i;
}

void SPFA(int s, int n, int dist[], int head[], Node E[])
{
	int i, u, v, tmp;
	for(i = 0; i <= n; ++i){
		dist[i] = inf; vis[i] = false;
	}
	u = s; vis[u] = true; dist[u] = 0;
	queue<int> Q; Q.push(s);
	while(!Q.empty()){
		u = Q.front(); Q.pop(); vis[u] = 0;
		for(i = head[u]; i != -1; i = E[i].next){
			v = E[i].to;
			tmp = dist[u] + E[i].dist;
			if(tmp < dist[v]){
				dist[v] = tmp;
				if(!vis[v]){
					vis[v] = 1;
					Q.push(v);
				}
			}
		}
	}
}

int A_star(int s, int t, int k, int n)
{
	priority_queue<Node2> Q;
	int i, u, v, cnt = 0;
	Node2 tmp, now;
	if(s == t) ++k; //起点跟终点相同
	now.to = s; now.g = 0;
	now.f = now.g + dist[now.to];
	Q.push(now);
	while(!Q.empty()){
		now = Q.top(); Q.pop();
		if(now.to == t && ++cnt == k)
			return now.g;
		for(i = head[now.to]; i != -1; i = E[i].next){
			tmp.to = E[i].to; tmp.g = now.g + E[i].dist;
			tmp.f = tmp.g + dist[tmp.to]; Q.push(tmp);
		}
	}
	return -1;
}

int main()
{
	int n, m, s, t, k, u, v, d, i;
	while(scanf("%d%d", &n, &m) == 2){
		for(i = 0; i <= n; ++i)
			head[i] = Rhead[i] = -1;
		for(i = 0; i < m; ++i){
			scanf("%d%d%d", &u, &v, &d);
			addEdge(u, v, d, i);
		}
		scanf("%d%d%d", &s, &t, &k);
		//SPFA(s, n, dist, head, E);
		SPFA(t, n, dist, Rhead, RE);
		printf("%d\n", A_star(s, t, k, n));
	}
	
	return 0;
}
