////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-11 20:07:57
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2988
////Problem Title: 
////Run result: Accept
////Run time:671MS
////Run memory:3368KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 200002
using std::sort;

struct Node {
	int u, v, cost;
} E[maxn];
int pre[maxn];

void addEdge(int a, int b, int c, int i)
{
	E[i].u = a; E[i].v = b; E[i].cost = c;
}

bool cmp(Node a, Node b) {
	return a.cost < b.cost;
}

int ufind(int k){
	int a = k, b;
	while(pre[k] != -1) k = pre[k];
	while(a != k) {
		b = pre[a];
		pre[a] = k;
		a = b;
	}
	return k;
}

int Kruskal(int n, int m)
{
	memset(pre, -1, sizeof(pre));
	int u, v, i, count = n, len = 0;
	for(i = 0; i < m; ++i) {
		u = ufind(E[i].u);
		v = ufind(E[i].v);
		if(u != v) {
			len += E[i].cost;
			pre[v] = u;
			if(--count == 1) break;
		}
	}
	return len;
}

int main()
{
	int n, m, total, i, a, b, c;
	while(scanf("%d%d", &n, &m), n || m) {
		for(i = total = 0; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			addEdge(a, b, c, i);
			total += c;
		}
		sort(E, E + m, cmp);
		printf("%d\n", total - Kruskal(n, m));
	}
	return 0;
}