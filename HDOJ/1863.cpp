////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-29 09:46:46
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1863
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:244KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 102

int map[maxn][maxn];
bool vis[maxn];

void Prim(int n)
{
	int len = 0, i, j, tmp, u, v, count = 0;
	vis[1] = true;
	while(count < n - 1){
		for(i = 1, tmp = -1; i <= n; ++i){
			for(j = 1; vis[i] && j <= n; ++j) //cut
				if(map[i][j] != -1 && !vis[j] && (tmp == -1 || map[i][j] < tmp)){
					tmp = map[i][j]; u = j; v = i;
				}			
		}
		if(tmp != -1){
			map[v][u] = -1;
			len += tmp; ++count;
			vis[u] = 1;
		}else break;
	}
	if(count == n - 1) printf("%d\n", len);
	else printf("?\n");
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m, a, b, c, i;
	while(scanf("%d%d", &n, &m), n){
		memset(map, -1, sizeof(map));
		memset(vis, 0, sizeof(vis));
		for(i = 0; i < n; ++i){
			scanf("%d%d%d", &a, &b, &c);
			if(map[a][b] == -1 || c < map[a][b])
				map[a][b] = map[b][a] = c;
		}
		Prim(m);
	}
	return 0;
}
