////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-23 13:10:36
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1241
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:316KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 105

char map[maxn][maxn];
int N, M, ans; // n rows
const int mov[][2] = {0, -1, -1, -1, -1, 0, -1, 1, 0, 1, 1, 1, 1, 0, 1, -1};

void DFS(int x, int y) {
	map[x][y] = '*';
	int i, j, xx, yy;
	for(i = 0; i < 8; ++i) {
		xx = x + mov[i][0];
		yy = y + mov[i][1];
		if(xx >= 0 && xx < N && yy >= 0 && yy < M && map[xx][yy] == '@') {
			DFS(xx, yy);
		}
	}
}

int main() {
	int i, j;
	while(scanf("%d%d", &N, &M), N) {
		for(i = 0; i < N; ++i)
			scanf("%s", map[i]);
		ans = 0;
		for(i = 0; i < N; ++i)
			for(j = 0; j < M; ++j)
				if(map[i][j] == '@')
					++ans, DFS(i, j);
		printf("%d\n", ans);
	}
	return 0;
}