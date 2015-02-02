////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-08-08 20:45:37
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2121
////Problem Title: 
////Run result: Accept
////Run time:328MS
////Run memory:384KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <limits.h>
#include <string.h>
#define maxn 1002
#define maxm 12000

struct Node{
	int u, v, cost;
} E[maxm];
int pre[maxn], vis[maxn], in[maxn], hash[maxn], ansNum;
int ans;

bool ZL_MST(int root, int nv, int ne)
{
	ans = 0;
	int i, u, v, cntnum, tmp;
	while(true){
		for(i = 0; i < nv; ++i) in[i] = INT_MAX;
		for(i = tmp = 0; i < ne; ++i){
			u = E[i].u; v = E[i].v;
			if(E[i].cost < in[v] && v != u){
				in[v] = E[i].cost; pre[v] = u;
				if(u == root) ansNum = i;
			}
		}
		in[root] = 0;
		for(i = 0; i < nv; ++i)
			if(in[i] == INT_MAX) return false;

		cntnum = 0;
		memset(vis, -1, sizeof(vis));
		memset(hash, -1, sizeof(hash));
		for(i = 0; i < nv; ++i){
			ans += in[i]; v = i;
			while(vis[v] != i && v != root && hash[v] == -1){
				vis[v] = i; v = pre[v];
			}
			if(v != root && hash[v] == -1){
				for(u = pre[v]; u != v; u = pre[u])
					hash[u] = cntnum;
				hash[v] = cntnum++;
			}
		}
		if(cntnum == 0) return true;
		
		for(i = 0; i < nv; ++i)
			if(hash[i] == -1) hash[i] = cntnum++;

		for(i = 0; i < ne; ++i){
			v = E[i].v;
			E[i].u = hash[E[i].u];
			E[i].v = hash[E[i].v];
			if(E[i].u != E[i].v) E[i].cost -= in[v];
		}

		nv = cntnum; root = hash[root];
	}
	return true;
}

int main()
{
	int n, m, a, b, c, i, maxVal;
	while(scanf("%d%d", &n, &m) == 2){
		for(i = maxVal = 0; i < m; ++i){
			scanf("%d%d%d", &a, &b, &c);
			E[i].u = a; E[i].v = b; 
			E[i].cost = c; maxVal += c;
		}
		//添加虚拟节点以及n条虚拟边
		for(++maxVal, i = 0; i < n; ++i){
			E[m+i].u = n; E[m+i].v = i;
			E[m+i].cost = maxVal;
		}
		if(!ZL_MST(n, n + 1, n + m) || ans >= 2 * maxVal) 
			printf("impossible\n\n");
		else printf("%d %d\n\n", ans - maxVal, ansNum - m);
	}
	return 0;
}
