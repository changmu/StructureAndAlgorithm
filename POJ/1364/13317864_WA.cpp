#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 106
#define inf 0x7fffffff
using std::queue;

int head[maxn], out[maxn];
struct Node{
	int to, w, next;
} E[maxn << 1];
bool vis[maxn];
int dist[maxn];

void addEdge(int a, int b, int c, int i)
{
	E[i].to = b; E[i].w = c;
	E[i].next = head[a]; head[a] = i;
}

bool SPFA(int s, int n)
{
	int i, u, v, tmp;
	for(i = 0; i <= n + 1; ++i){
		dist[i] = inf; vis[i] = out[i] = 0;
	}
	vis[0] = 1; dist[0] = 0;
	queue<int> Q; Q.push(0);
	while(!Q.empty()){
		u = Q.front(); Q.pop(); vis[u] = 0;
		if(++out[u] > n + 1) return false;
		for(i = head[u]; i != -1; i = E[i].next){
			tmp = dist[u] + E[i].w;
			v = E[i].to;
			if(tmp < dist[v] && !vis[v]){
				vis[v] = 1; dist[v] = tmp;
				Q.push(v);
			}
		}
	}
	return true;
}

int main()
{
	int n, m, i, a, b, c;
	char str[5];
	while(scanf("%d%d", &n, &m) == 2){
		memset(head, -1, sizeof(head));
		for(i = 0; i < m; ++i){
			scanf("%d%d%s%d", &a, &b, str, &c);
			if(str[0] == 'g') addEdge(b+1, a, -c-1, i);
			else addEdge(a, b+1, c - 1, i);
		}
		for(i = 1; i <= n + 1; ++i)
			addEdge(0, i, 0, m + i - 1);
		if(SPFA(0, n + 1)) printf("lamentable kingdom\n");
		else printf("successful conspiracy\n");
	}
	return 0;
}