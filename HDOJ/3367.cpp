////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-09 11:28:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3367
////Problem Title: 
////Run result: Accept
////Run time:437MS
////Run memory:1480KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 10002
#define maxm 100002
using std::sort;

struct Node{
	int u, v, cost;
} E[maxm];
int pre[maxn];
bool Ring[maxn];

bool cmp(Node a, Node b){
	return a.cost > b.cost;
}

int ufind(int k)
{
	int a = k, b;
	while(pre[k] != -1) k = pre[k];
	while(a != k){
		b = pre[a];
		pre[a] = k;
		a = b;
	}
	return k;
}

int greedy(int n, int m)
{
	int ans = 0, i, u, v;
	for(i = 0; i < m; ++i){
		u = E[i].u; v = E[i].v;
		u = ufind(u); v = ufind(v);
		if(Ring[u] && Ring[v]) continue;
		if(u != v){
			if(Ring[v]) pre[u] = v;
			else pre[v] = u;
			ans += E[i].cost;
		}else if(Ring[v] == false){
			Ring[v] = true;
			ans += E[i].cost;
		}
	}
	return ans;
}

int main()
{
	int n, m, a, b, c, i;
	while(scanf("%d%d", &n, &m), n||m){
		memset(pre, -1, sizeof(pre));
		memset(Ring, 0, sizeof(Ring));
		for(i = 0; i < m; ++i)
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
		sort(E, E + m, cmp);
		printf("%d\n", greedy(n, m));
	}
	return 0;
}