#include <stdio.h>
#include <string.h>

#define maxn 102

char G[maxn][maxn];
int n, m;
const int mov[][2] = {0, 1, 0, -1, 1, 0, -1, 
				0, 1, -1, -1, 1, 1, 1, -1, -1};

void DFS(int x, int y) {
	G[x][y] = '.';
	int i, j, nx, ny;
	for(i = 0; i < 8; ++i) {
		nx = x + mov[i][0];
		ny = y + mov[i][1];
		if(nx >= 0 && nx < n && ny >= 0 && ny < m && G[nx][ny] == 'W')
			DFS(nx, ny);
	}
}

int main() {
	int i, j, ret;
	while(scanf("%d%d", &n, &m) == 2) {
		for(i = 0; i < n; ++i)
			scanf("%s", G[i]);
		ret = 0;
		for(i = 0; i < n; ++i)
			for(j = 0; j < m; ++j)
				if(G[i][j] == 'W') {
					DFS(i, j);
					++ret;
				}
		printf("%d\n", ret);
	}
	return 0;
}