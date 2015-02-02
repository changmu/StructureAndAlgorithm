////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-29 11:02:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1102
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 102

int map[maxn][maxn];
bool vis[maxn];

void Prim(int n)
{
	int i, j, len = 0, count = 0, tmp, u;
	vis[1] = 1;
	while(count < n - 1){
		for(i = 1, tmp = -1; i <= n; ++i){
			if(!vis[i]) continue;
			for(j = 1; j <= n; ++j)
				if(!vis[j] && (map[i][j] < tmp || tmp == -1)){
					tmp = map[i][j]; u = j;
				}
		}
		if(tmp != -1){
			++count;
			vis[u] = 1;
			len += tmp;
		}
	}
	printf("%d\n", len);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, q, a, b, i, j;
	while(scanf("%d", &n) != EOF){
		memset(vis, 0, sizeof(vis));
		for(i = 1; i <= n; ++i)
			for(j = 1; j <= n; ++j)
				scanf("%d", &map[i][j]);
		scanf("%d", &q);
		while(q--){
			scanf("%d%d", &a, &b);
			map[a][b] = map[b][a] = 0;
		}
		Prim(n);
	}
	return 0;
}
