////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-11-02 22:37:34
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1598
////Problem Title: 
////Run result: Accept
////Run time:187MS
////Run memory:240KB
//////////////////System Comment End//////////////////
/*
** 用并查集每次选择一些权值最接近的边组合使得源点跟终点联通
*/
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 210
#define maxm 1010
#define inf 0x3f3f3f3f

int pre[maxn], id;
struct Node {
	int u, v, w;
} E[maxm];

int min(int a, int b) {
	return a < b ? a : b;
}

bool cmp(Node a, Node b) {
	return a.w > b.w;
}

int ufind(int k) {
	int a = k, b;
	while(pre[k]) k = pre[k];
	while(a != k) {
		b = pre[a];
		pre[a] = k;
		a = b;
	}
	return k;
}

bool same(int a, int b) {
	return ufind(a) == ufind(b);
}

void unite(int a, int b) {
	a = ufind(a);
	b = ufind(b);
	if(a != b) pre[a] = b;
}

void addEdge(int u, int v, int w) {
	E[id].u = u;
	E[id].v = v;
	E[id++].w = w;
}

int main() {
	int n, m, i, a, b, c, j, q, ans;
	while(scanf("%d%d", &n, &m) == 2) {
		for(i = id = 0; i < m; ++i) {
			scanf("%d%d%d", &a, &b, &c);
			addEdge(a, b, c);
		}
		std::sort(E, E + m, cmp);
		scanf("%d", &q);
		while(q--) {
			scanf("%d%d", &a, &b);
			ans = inf;
			for(i = 0; i < m; ++i) {
				memset(pre, 0, sizeof(int) * (n + 1));
				for(j = i; j < m; ++j) {
					unite(E[j].u, E[j].v);
					if(same(a, b)) {
						ans = min(ans, E[i].w - E[j].w);
						break;
					}
				}
				if(ans == inf) break; // cut
			}
			if(ans == inf) ans = -1;
			printf("%d\n", ans);
		}
	}
	return 0;
}