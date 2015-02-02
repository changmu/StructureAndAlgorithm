////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-28 15:34:54
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1869
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define INF -1
#define maxn 102

int map[maxn][maxn], ok;

void Floyd(int n)
{
	int i, j, k;
	for(k = 0; k < n; ++k)
		for(i = 0; i < n; ++i)
			for(j = 0; j < n; ++j)
				if(map[i][k] != INF && map[k][j] != INF && (map[i][k] + map[k][j] < map[i][j] || map[i][j] == INF))
					map[i][j] = map[i][k] + map[k][j];
	
}

int main()
{
	int n, m, i, j, a, b;
	while(scanf("%d%d", &n, &m) != EOF){
		memset(map, -1, sizeof(map));
		for(i = 0; i < n; ++i) map[i][i] = 0;
		for(i = 0; i < m; ++i){
			scanf("%d%d", &a, &b);
			map[a][b] = map[b][a] = 1;
		}
		Floyd(n);
		for(i = 0, ok = 1; i < n && ok; ++i)
			for(j = 0; j < n; ++j)
				if(map[i][j] == INF || map[i][j] > 7){
					ok = 0; break;
				}
		printf(ok ? "Yes\n" : "No\n");
	}
	return 0;
}