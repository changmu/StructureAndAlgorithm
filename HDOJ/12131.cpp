////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-26 13:13:19
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1213
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1052KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 1010

int pre[maxn];

int ufind(int x) {
	return pre[x] == -1 ? x : (pre[x] = ufind(pre[x]));
}

bool unite(int x, int y) {
	x = ufind(x);
	y = ufind(y);
	if (x == y) return false;
	pre[x] = y;
	return true;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, n, m, i, cnt, x, y;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		memset(pre, -1, sizeof(int) * (n + 1));
		cnt = n;
		while (m--) {
			scanf("%d%d", &x, &y);
			if (unite(x, y)) --cnt;
		}
		printf("%d\n", cnt);
	}
	return 0;
}
