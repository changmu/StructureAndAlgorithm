////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-12 20:22:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1385
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 52
#define inf 0x7f7f7f

int map[maxn][maxn], tax[maxn];
int path[maxn][maxn];

void Floyd(int n)
{
	int k, i, j, tmp;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= n; ++j)
			path[i][j] = j;
	for(k = 1; k <= n; ++k)
		for(i = 1; i <= n; ++i)
			for(j = 1; j <= n; ++j){
				tmp = map[i][k] + map[k][j] + tax[k];
				if(tmp < map[i][j]){
					map[i][j] = tmp;
					path[i][j] = path[i][k];
				}else if(tmp == map[i][j] && path[i][k] < path[i][j])
					path[i][j] = path[i][k];
			}
}

int main()
{
	int n, i, j, a, b, next;
	while(scanf("%d", &n), n){
		for(i = 1; i <= n; ++i)
			for(j = 1; j <= n; ++j){
				scanf("%d", &map[i][j]);
				if(map[i][j] == -1)
					map[i][j] = inf;
			}
		for(i = 1; i <= n; ++i)
			scanf("%d", &tax[i]);

		Floyd(n);

		while(scanf("%d%d", &a, &b), a != -1){
			printf("From %d to %d :\nPath: ", a, b);
			next = a;
			while(next != b){
				printf("%d-->", next);
				next = path[next][b];
			}
			printf("%d\n", next);
			printf("Total cost : %d\n\n", map[a][b]);

		}
	}
	return 0;
}