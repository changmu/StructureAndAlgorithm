////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-13 13:33:43
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2112
////Problem Title: 
////Run result: Accept
////Run time:1468MS
////Run memory:536KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <map>
#include <string>
#define maxn 160
#define maxm 10002
#define inf 0x7f7f7f7f
using namespace std;

int head[maxn], dist[maxn], id;
struct Node{
	int to, cost, next;
} E[maxm << 1];
bool vis[maxn];

void addEdge(int u, int v, int c)
{
	E[id].to = v; E[id].cost = c;
	E[id].next = head[u]; head[u] = id++;
	E[id].to = u; E[id].cost = c;
	E[id].next = head[v]; head[v] = id++;
}

int getNext(int n)
{
	int u = -1, tmp = inf, i, j;
	for(i = 1; i <= n; ++i)
		if(!vis[i] && dist[i] < tmp){
			tmp = dist[i]; u = i;
		}
	return u;
}

bool Dijkstra(int n)
{
	int i, u, v, tmp;
	memset(vis, 0, sizeof(vis));
	memset(dist, 0x7f, sizeof(dist));
	u = 1; dist[u] = 0;
	while(u != -1){
		for(i = head[u]; i != -1; i = E[i].next){
			tmp = dist[u] + E[i].cost;
			v = E[i].to;
			if(tmp < dist[v]){
				dist[v] = tmp;
			}
		}
		vis[u] = true;
		if(vis[2]) return true;
		u = getNext(n);
	}
	return false;
}

int main()
{
	int n, i, cost, s, t, u, v, num;
	char car[32], car2[32];
	map<string, int> mp;
	while(scanf("%d", &n), n != -1){
		memset(head, -1, sizeof(head));
		mp.clear(); s = 1; t = 2;
		scanf("%s%s", car, car2);
		if(strcmp(car, car2) == 0) s = t;
		mp[car] = 1; mp[car2] = 2;
		for(i = 0, id = 0, num = 2; i < n; ++i){
			scanf("%s%s%d", car, car2, &cost);
			if(0 == mp[car]) mp[car] = ++num;
			if(0 == mp[car2]) mp[car2] = ++num;
			u = mp[car]; v = mp[car2];
			addEdge(u, v, cost);
		}
		if(s == t){
			printf("0\n"); continue;
		}
		if(Dijkstra(num)) printf("%d\n", dist[2]);
		else printf("-1\n");
	}
	return 0;
}