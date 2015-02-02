////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-14 15:47:16
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3339
////Problem Title: 
////Run result: Accept
////Run time:156MS
////Run memory:548KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <queue>
#define inf 0x3f3f3f3f
#define maxn 102
#define maxm 10002
using std::queue;

int head[maxn], id, dist[maxn];
int pow[maxn], dp[100 * maxn];
struct Node{
	int to, cost, next;
} E[maxm << 1];
bool vis[maxn];

int max(int a, int b){
	return a > b ? a : b;
}

void addEdge(int u, int v, int cost)
{
	E[id].to = v; E[id].cost = cost;
	E[id].next = head[u]; head[u] = id++;
	E[id].to = u; E[id].cost = cost;
	E[id].next = head[v]; head[v] = id++;
}

void SPFA(int s, int n, int m)
{
	int i, u, v, tmp;
	for(i = 0; i <= n; ++i){
		vis[i] = false; dist[i] = inf;
	}
	u = s; vis[u] = true; dist[u] = 0;
	queue<int> Q;
	Q.push(u);
	while(!Q.empty()){
		u = Q.front(); Q.pop();
		vis[u] = false;
		for(i = head[u]; i != -1; i = E[i].next){
			tmp = dist[u] + E[i].cost;
			v = E[i].to;
			if(tmp < dist[v]){
				dist[v] = tmp;
				if(!vis[v]){
					vis[v] = true;
					Q.push(v);
				}
			}
		}
	}
}

void zeroOnePack(int n, int sumDist)
{
	int i, j;
	memset(dp, 0, sizeof(int) * (sumDist + 1));
	for(i = 1; i <= n; ++i)
		for(j = sumDist; j >= dist[i]; --j){
			dp[j] = max(dp[j], dp[j-dist[i]] + pow[i]);
		}
}

int main()
{
	int n, m, u, v, cost, i, t, sumDist, sumCost;
	scanf("%d", &t);
	while(t--){
		scanf("%d%d", &n, &m);
		memset(head, -1, sizeof(int) * (n + 1));
		for(i = id = 0; i < m; ++i){
			scanf("%d%d%d", &u, &v, &cost);
			addEdge(u, v, cost);
		}
		for(i = 1, sumCost = 0; i <= n; ++i){
			scanf("%d", &pow[i]);
			sumCost += pow[i];
		}
		SPFA(0, n, id);
		for(i = sumDist = 0; i <= n; ++i)
			if(dist[i] != inf) sumDist += dist[i];
		zeroOnePack(n, sumDist);
		sumCost >>= 1;
		cost = -1;
		for(i = 1; i <= sumDist; ++i)
			if(dp[i] > sumCost){
				cost = i; 
				printf("%d\n", cost);
				break;
			}
		if(cost == -1) printf("impossible\n");
	}
	return 0;
}