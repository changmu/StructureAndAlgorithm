////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-03 17:12:38
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1027
////Problem Title: 
////Run result: Accept
////Run time:375MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1002

bool vis[maxn];
int ans[maxn], n, m, count, ok;

void PRINT()
{
	for(int i = 0; i < n; ++i)
		if(i != n - 1) printf("%d ", ans[i]);
		else printf("%d\n", ans[i]);
}

void DFS(int id){
	if(id == n){
		if(++count == m && (ok = 1)) PRINT(); 
		return;
	}
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			ans[id] = i; vis[i] = 1;
			DFS(id + 1); vis[i] = 0;
			if(ok) return;
		}
	}
}

int main()
{
	while(scanf("%d%d", &n, &m) == 2){
		memset(vis, 0, sizeof(vis));
		DFS(count = ok = 0);
	}
	return 0;
}
