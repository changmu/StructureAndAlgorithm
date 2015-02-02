////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-11 22:36:48
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2122
////Problem Title: 
////Run result: Accept
////Run time:93MS
////Run memory:344KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>
#define maxn 1002
#define maxm 10002
using std::sort;

int pre[maxn], count, len;
struct Node {
	int u, v, cost;
} E[maxm];

int ufind(int k)
{
	int a = k, b;
	while(pre[k] != -1) k = pre[k];
	while(a != k) {
		b = pre[a];
		pre[a] = k;
		a = b;
	}
	return k;
}

bool cmp(Node a, Node b) {
	return a.cost < b.cost;
}

void Kruskal(int m)
{
	memset(pre, -1, sizeof(pre));
	int u, v, i; len = 0;
	for(i = 0; i < m && count > 1; ++i) {
		u = ufind(E[i].u);
		v = ufind(E[i].v);
		if(u != v) {
			len += E[i].cost;
			pre[v] = u;
			--count;
		}
	}
	if(1 == count) printf("%d\n\n", len);
	else printf("impossible\n\n");
}

int main()
{
	int n, m, i;
	while(scanf("%d%d", &n, &m) == 2) {
		count = n;
		for(i = 0; i < m; ++i)
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
		sort(E, E + m, cmp);
		Kruskal(m);
	}
	return 0;
}