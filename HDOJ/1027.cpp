////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-21 15:32:19
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1027
////Problem Title: 
////Run result: Accept
////Run time:484MS
////Run memory:276KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 1002

int vis[maxn], n, m, arr[maxn], count, ok;

void PRINT()
{
	for(int i = 1; i <= n; ++i)
		if(i != n) printf("%d ", arr[i]);
		else printf("%d\n", arr[i]);
}

void DFS(int k)
{
	if(k > n || ok) return;
	for(int i = 1; i <= n; ++i){
		if(!vis[i]){
			vis[i] = 1; arr[k] = i;
			if(k == n && m == ++count){
				PRINT(); ok = 1; return;
			}
			DFS(k + 1); vis[i] = 0;
		}
	}
}

int main()
{
	while(scanf("%d%d", &n, &m) != EOF){
		memset(vis, 0, sizeof(vis));
		ok = count = 0; DFS(1);
	}
	return 0;
}