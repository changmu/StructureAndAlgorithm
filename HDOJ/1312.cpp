////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-13 19:02:40
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1312
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:232KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 22

int n, m, ans;
const int mov[][2] = {1, 0, -1, 0, 0, 1, 0, -1};
char map[maxn][maxn];

bool check(int x, int y){
	return x >= 0 && y >= 0 && 
		x < n && y < m && map[x][y] != '#';
}

void DFS(int x, int y)
{
	int a, b, i;
	for(i = 0; i < 4; ++i){
		a = x + mov[i][0];
		b = y + mov[i][1];
		if(check(a, b)){
			++ans; map[a][b] = '#';
			DFS(a, b);
		}
	}
}

int main()
{
	int i, j, x, y;
	while(scanf("%d%d", &m, &n) == 2 && (m || n)){
		for(i = 0; i < n; ++i){
			getchar();
			for(j = 0; j < m; ++j){
				map[i][j] = getchar();
				if(map[i][j] == '@'){
					x = i; y = j;
				}
			}
		}
		map[x][y] = '#';
		ans = 1; DFS(x, y);
		printf("%d\n", ans);
	}
	return 0;
}