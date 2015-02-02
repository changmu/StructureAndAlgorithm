////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-20 22:46:48
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1078
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:312KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 105

int G[maxn][maxn], n, m;
int dp[maxn][maxn];
const int mov[][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void getMap() {
	int i, j;
	for(i = 0; i < n; ++i)
		for(j = 0; j < n; ++j)
			scanf("%d", &G[i][j]);
}

int max(int a, int b) {
	return a > b ? a : b;
}

bool check(int x, int y) {
	if(x < 0 || x >= n || y < 0 || y >= n)
		return 0;
	return 1;
}

int DFS(int xx, int yy) {
	int i, j, x, y, maxv = 0;
	if(dp[xx][yy]) return dp[xx][yy];
	for(i = 1; i <= m; ++i) {
		for(j = 0; j < 4; ++j) {
			x = xx + mov[j][0] * i;
			y = yy + mov[j][1] * i;
			if(check(x, y) && G[x][y] > G[xx][yy])
				maxv = max(maxv, DFS(x, y));
		}
	}
	return dp[xx][yy] = maxv + G[xx][yy];
}

void solve() {
	int i, j;
	memset(dp, 0, sizeof(dp));
	printf("%d\n", DFS(0, 0));
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	while(scanf("%d%d", &n, &m), n > 0) {
		getMap();
		solve();
	}
	return 0;
}
