#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>
using namespace std;

struct Node {
	int x, y;
} path[5][5];
int G[5][5];
const int mov[][2] = {0, 1, 0, -1, -1, 0, 1, 0};

bool check(int x, int y) {
	return x >= 0 && x < 5 && y >= 0 && y < 5 && G[x][y] == 0;
}

void Print(int x, int y) {
	if(x == y && !x) {
		printf("(0, 0)\n");
		return;
	}
	Print(path[x][y].x, path[x][y].y);
	printf("(%d, %d)\n", x, y);
}

int main() {
	int i, j, ok = 0;
	for(i = 0; i < 5; ++i)
		for(j = 0; j < 5; ++j)
			scanf("%d", &G[i][j]);
	queue<Node> Q;
	Node u, v;
	u.x = u.y = 0;
	Q.push(u);
	while(!Q.empty() && !ok) {
		u = Q.front(); Q.pop();
		for(i = 0; i < 4; ++i) {
			v = u;
			v.x += mov[i][0];
			v.y += mov[i][1];
			if(check(v.x, v.y)) {
				G[v.x][v.y] = 1;
				path[v.x][v.y].x = u.x;
				path[v.x][v.y].y = u.y;
				if(v.x==v.y && v.x==4) {
					ok = 1; break;
				}
				Q.push(v);
			}
		}		
	}
	Print(4, 4);
	return 0;
}
