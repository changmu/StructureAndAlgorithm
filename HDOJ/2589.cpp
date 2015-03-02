////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-26 21:34:08
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2589
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1060KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

bool vis[22][22], stone[22][22];
int L, N, cnt;

int cnt_stone(int x, int y, int len) {
	int cnt = 0, i, j;
	for (i = x; i < x + len; ++i)
		for (j = y; j < y + len; ++j)
			if (stone[i][j]) ++cnt;
	return cnt;
}

void paint(int x, int y, int len, bool col) {
	int i, j;
	for (i = x; i < x + len; ++i)
		for (j = y; j < y + len; ++j)
			vis[i][j] = col;
}

void getNext(int& x, int& y) {
	int i, j;
	for ( ; x < L; ++x, y = 0)
		for ( ; y < L; ++y)
			if (!vis[x][y]) return;
}

bool DFS(int x, int y) {
	int i, t;
	for (i = 1; i <= L; ++i) {
		if (x + i > L || y + i > L) break;
		t = cnt_stone(x, y, i);
		if (t == 0) continue;
		if (t == 1) {
			paint(x, y, i, true);
			cnt += i * i;
			if (cnt == L * L) return true;
			int xx = x, yy = y;
			getNext(x, y);
			if (x == L) {
				x = xx; y = yy;
				paint(x, y, i, false);
				cnt -= i * i;
				return false;
			}
			if (DFS(x, y)) return true;
		} else {
			paint(x, y, i, false);
			cnt -= i * i;
			return false;
		}
	}
	return false;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, i, x, y;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &L, &N);
		memset(vis, cnt = 0, sizeof(vis));
		memset(stone, 0, sizeof(stone));
		for (i = 0; i < N; ++i) {
			scanf("%d%d", &x, &y);
			stone[--x][--y] = true;
		}
		puts(DFS(0, 0) ? "YES" : "NO");
	}
	return 0;
}
