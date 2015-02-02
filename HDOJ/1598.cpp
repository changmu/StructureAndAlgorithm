////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-09 16:27:06
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1598
////Problem Title: 
////Run result: Accept
////Run time:171MS
////Run memory:252KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <limits.h>
#include <algorithm>
#define maxn 202
#define maxm 1002
using std::sort;
using std::min;

int pre[maxn];
struct Node{
	int u, v, cost;
} E[maxm];

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

bool cmp(Node a, Node b){
	return a.cost < b.cost;
}

int main()
{
	int n, m, q, a, b, i, j, x, y, ans;
	while(scanf("%d%d", &n, &m) == 2){
		for(i = 0; i < m; ++i)
			scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].cost);
		sort(E, E + m, cmp);
		scanf("%d", &q);
		while(q--){
			scanf("%d%d", &a, &b);
			ans = INT_MAX;
			for(i = 0; i < m; ++i){
				memset(pre, -1, sizeof(pre));
				for(j = i; j < m; ++j){
					x = ufind(E[j].u);
					y = ufind(E[j].v);
					if(x != y) pre[x] = y;
					if(ufind(a) == ufind(b)){
						ans = min(ans, E[j].cost - E[i].cost);
						break;
					}
				}
			}
			if(ans == INT_MAX) printf("-1\n");
			else printf("%d\n", ans);
			
		}
	}
	return 0;
}