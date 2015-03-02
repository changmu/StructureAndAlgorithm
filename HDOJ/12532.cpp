////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-02-13 21:58:06
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1253
////Problem Title: 
////Run result: Accept
////Run time:733MS
////Run memory:1668KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

const int dir[][3] = {0, 0, 1, 0, 0, -1, 0, 1, 0, 0, -1, 0, 1, 0, 0, -1, 0, 0};
int G[52][52][52];
int T, A, B, C, Ti;
struct Node {
	int x, y, z;
	int time;
} que[125010];

void getMap() {
	int i, j, k;
	for (i = 0; i < A; ++i)
		for (j = 0; j < B; ++j)
			for (k = 0; k < C; ++k)
				scanf("%d", &G[i][j][k]);
}

bool check(int x, int y, int z) {
	return x >= 0 && x < A && y >= 0 && y < B && z >= 0 && z < C && 
		!G[x][y][z];
}

void BFS() {
	int i, j, k;
	int front = 0, back = 0;
	if (A + B + C - 3 > Ti) {
		printf("-1\n"); return;
	}

	Node u = {0, 0, 0, 0}, v;
	que[back++] = u;
	while (front != back) {
		u = que[front++];
		if (u.x + 1 == A && u.y + 1 == B && u.z + 1 == C) {
			printf("%d\n", u.time); return;
		}
		for (i = 0; i < 6; ++i) {
			v = u;
			v.x += dir[i][0];
			v.y += dir[i][1];
			v.z += dir[i][2];
			if (check(v.x, v.y, v.z) && v.time < Ti) {
				G[v.x][v.y][v.z] = 1;
				++v.time;
				que[back++] = v;
			}
		}
	}
	printf("-1\n");
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d%d%d", &A, &B, &C, &Ti);
		getMap();
		BFS();
	}
	return 0;
}
