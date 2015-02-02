////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-07 15:08:35
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3371
////Problem Title: 
////Run result: Accept
////Run time:593MS
////Run memory:500KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define maxn 502
#define maxm 25002

int id, pre[maxn];
int count, ans;
struct Node{
	int from, to, val;
} edge[maxm];

void addEdge(int a, int b, int c)
{
	edge[id].from = a;
	edge[id].to = b;
	edge[id++].val = c;
}

int unionFind(int k)
{
	int a = k;
	while(pre[k] != -1) k = pre[k];
	int b;
	while(a != k){
		b = pre[a];
		pre[a] = k;
		a = b;
	}
	return k;
}

int cmp(const void* a, const void* b){
	return ((Node *)a)->val - ((Node *)b)->val;
}

bool kruskal()
{
	qsort(edge, id, sizeof(Node), cmp);
	int x, y, i;
	for(i = 0; i < id; ++i){
		x = unionFind(edge[i].from);
		y = unionFind(edge[i].to);
		if(x != y){
			ans += edge[i].val;
			--count; pre[y] = x;
			if(1 == count) return true;
		}		
	}

	return 1 == count;
}

int main()
{
	//freopen("stdin.txt", "r", stdin);
	int cas, n, m, k, t, a, b, c, i;
	scanf("%d", &cas);
	while(cas--){
		memset(pre, -1, sizeof(pre));
		scanf("%d%d%d", &n, &m, &k);
		for(i = id = 0; i < m; ++i){
			scanf("%d%d%d", &a, &b, &c);
			addEdge(a, b, c);
		}
		count = n; ans = 0;
		for(i = 0; i < k; ++i){
			scanf("%d%d", &t, &a);
			a = unionFind(a);
			while(--t){
				scanf("%d", &b);
				b = unionFind(b);
				if(a != b){
					pre[b] = a;
					--count;
				}
			}
		}
		if(!kruskal()) printf("-1\n");
		else printf("%d\n", ans);
	}
	return 0;
}
