////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-29 10:30:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1879
////Problem Title: 
////Run result: Accept
////Run time:531MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 102

int map[maxn][maxn];
bool vis[maxn];

void Prim(int n)
{
	int i, j, count = 0, len = 0, tmp, u;
	vis[1] = 1;
	while(count < n - 1){
		for(i = 1, tmp = -1; i <= n; ++i){
			if(!vis[i]) continue;
			for(j = 1; j <= n; ++j)
				if(map[i][j] != -1 && !vis[j] && (tmp == -1 || map[i][j] < tmp)){
					tmp = map[i][j]; u = j;
				}
		}
		if(tmp != -1){
			++count; vis[u] = 1;
			len += tmp;
		}
	}
	printf("%d\n", len);
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, i, a, b, c, d, m;
	while(scanf("%d", &n), n){
		memset(map, -1, sizeof(map));
		memset(vis, 0, sizeof(vis));
		m = n * (n - 1) / 2;
		for(i = 0; i < m; ++i){
			scanf("%d%d%d%d", &a, &b, &c, &d);
			if(d) map[a][b] = map[b][a] = 0;
			else if(map[a][b] == -1 || c < map[a][b]){
				map[a][b] = map[b][a] = c;
			}
		}
		Prim(n);
	}
	return 0;
}
