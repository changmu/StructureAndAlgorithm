////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-12 17:03:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1224
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:260KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 102
#define maxm (maxn * maxn) >> 1
using std::queue;

int city[maxn], head[maxn];
int dist[maxn], pre[maxn];
struct Node{
	int to, next;
} E[maxm];
bool vis[maxn];

void SPFA(int n, int s)
{
	int i, u, v, tmp;
	for(i = 0; i <= n; ++i){
		dist[i] = 0; vis[i] = false;
	} 
	dist[n + 1] = 0;
	vis[s] = true;
	queue<int> Q;
	Q.push(s);
	while(!Q.empty()){
		u = Q.front(); Q.pop();
		vis[u] = false;
		for(i = head[u]; i != -1; i = E[i].next){
			v = E[i].to;
			tmp = dist[u] + city[v];
			if(tmp > dist[v]){
				dist[v] = tmp;
				vis[v] = true;
				pre[v] = u;
				Q.push(v);
			}
		}
	}
}

void printPath(int k, int n)
{
	if(k == 1) return;
	printPath(pre[k], n);
	printf("->%d", k > n ? 1 : k);
}

int main()
{
	int t, cas, n, i, m, u, v;
	scanf("%d", &t);
	for(cas = 1; cas <= t; ++cas){
		scanf("%d", &n);
		for(i = 1; i <= n; ++i){
			scanf("%d", &city[i]);
		}
		city[n + 1] = 0;
		scanf("%d", &m);
		memset(head, -1, sizeof(head));
		for(i = 0; i < m; ++i){
			scanf("%d%d", &u, &v);
			E[i].to = v; E[i].next = head[u];
			head[u] = i;
		}
		SPFA(n, 1);
		printf("CASE %d#\n", cas);
		printf("points : %d\n", dist[n + 1]);
		printf("circuit : 1");
		printPath(n + 1, n); printf("\n");
		if(cas != t) printf("\n");
	}
	return 0;
}