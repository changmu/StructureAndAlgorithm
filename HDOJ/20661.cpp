////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-28 17:06:15
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2066
////Problem Title: 
////Run result: Accept
////Run time:593MS
////Run memory:4140KB
//////////////////System Comment End//////////////////
//Floyd
#include <stdio.h>
#include <string.h>
#define maxn 1002
#define INF -1

int map[maxn][maxn];

void Floyd(int n)
{
	int i, j, k;
	for(k = 0; k <= n; ++k)
		for(i = 0; i <= n; ++i)
			for(j = 0; j <= n && map[i][k] != -1; ++j)
				if(map[i][k] != -1 && map[k][j] != -1 && (map[i][k] + map[k][j] < map[i][j] || map[i][j] == -1))
					map[i][j] = map[i][k] + map[k][j];
}

int main()
{
	// freopen("in.txt", "r", stdin);
	// freopen("out.txt", "w", stdout);
	int t, s, d, a, b, c, i, ans;
	while(scanf("%d%d%d", &t, &s, &d) != EOF){
		memset(map, -1, sizeof(map));
		for(i = 0; i <= 1000; ++i) map[i][i] = 0;
		for(i = 0; i < t; ++i){
			scanf("%d%d%d", &a, &b, &c);
			if(map[a][b] == -1 || c < map[a][b])
				map[a][b] = map[b][a] = c;
		}
		for(i = 0; i < s; ++i){
			scanf("%d", &a);
			map[0][a] = map[a][0] = 0;
		}
		Floyd(1000);
		ans = 100000000;
		for(i = 0; i < d; ++i){
			scanf("%d", &a);
			if(map[0][a] != -1 && map[0][a] < ans)
				ans = map[0][a];
		}
		printf("%d\n", ans);
	}
	return 0;
}