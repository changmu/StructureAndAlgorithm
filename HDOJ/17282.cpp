////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2015-02-01 19:16:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1728
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1140KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 105
const int dir[][2] = {0, 1, 0, -1, 1, 0, -1, 0};

struct Node {
	int x, y, step;
} que[maxn * maxn]; // 点不能重复入队，但能重复走
int M, N, K, X, Y; // M rows
char G[maxn][maxn];

bool check(int x, int y) {
	return x >= 1 && x <= M && y >= 1 && y <= N && G[x][y] != '*';
}

bool BFS(int x0, int y0) {
	Node u, v;
	int front = 0, back = 0, i;

	G[x0][y0] = '*';
	u.x = x0; u.y = y0; u.step = -1;
	que[back++] = u;
	while (front != back) {
		u = que[front++];
		if (u.x == X && u.y == Y) return true;
		if (u.step == K) continue;
		for (i = 0; i < 4; ++i) {
			v = u;
			++v.step;
			while (true) {
				v.x += dir[i][0];
				v.y += dir[i][1];
				if (!check(v.x, v.y)) break;
				if (G[v.x][v.y] == '.') que[back++] = v;
				G[v.x][v.y] = '@'; // mark
			}
		}
	}
	return false;
} 

int main() {
	// freopen("stdin.txt", "r", stdin);
	int x0, y0, T, i;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &M, &N);
		for (i = 1; i <= M; ++i)
			scanf("%s", G[i] + 1);
		scanf("%d%d%d%d%d", &K, &y0, &x0, &Y, &X);
		puts(BFS(x0, y0) ? "yes" : "no");
	}
	return 0;
}
