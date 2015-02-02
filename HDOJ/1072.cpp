////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-20 20:04:17
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1072
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:320KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <queue>

#define maxn 10

int G[maxn][maxn], n, m;
struct Node { 
	int x, y, time, leftTime;
} S;
const int mov[][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void getMap() {
	scanf("%d%d", &n, &m);
	int i, j;
	for(i = 1; i <= n; ++i)
		for(j = 1; j <= m; ++j) {
			scanf("%d", &G[i][j]);
			if(G[i][j] == 2) {
				S.x = i; S.y = j;
				S.time = 0; S.leftTime = 6;
			}
		}
}

bool check(int x, int y) {
	if(x < 1 || x > n || y < 1 || y > m)
		return false;
	if(G[x][y] == 0) return false;
	return true;
}

int BFS() {
	int i, j, x, y;
	std::queue<Node> Q;
	Q.push(S);
	Node now, tmp;

	while(!Q.empty()) {
		now = Q.front(); Q.pop();
		for(i = 0; i < 4; ++i) {
			x = mov[i][0] + now.x;
			y = mov[i][1] + now.y;
			if(check(x, y)) {
				tmp = now; ++tmp.time;
				if(--tmp.leftTime) {
					if(G[x][y] == 4) {
						tmp.leftTime = 6;
						G[x][y] = 1;
					} else if(G[x][y] == 3)
						return tmp.time;
					tmp.x = x; tmp.y = y;
					Q.push(tmp);
				}
			}
		}
	}

	return -1;
}

void solve() {
	printf("%d\n", BFS());
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int t;
	scanf("%d", &t);
	while(t--) {
		getMap();
		solve();
	}
	return 0;
}