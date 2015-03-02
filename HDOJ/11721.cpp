////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-27 11:11:02
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1172
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1076KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

struct Node {
	char str[5];
	int a, b;
} A[102];

bool Judge(int v, int id) {
	char buf[4], *str = A[id].str;
	int i = 3, a = 0, b = 0, j;
	bool vis[4] = {0};
	for ( ; i >= 0; --i) {
		buf[i] = v % 10 + '0';
		v /= 10;
	}
	for (i = 0; i < 4; ++i) {
		for (j = 0; j < 4; ++j)
			if (str[i] == buf[j] && !vis[j]) {
				vis[j] = 1; ++a; break;
			}
		if (str[i] == buf[i]) ++b;
	}
	return a == A[id].a && b == A[id].b;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int N, i, j, val, cnt;
	while (scanf("%d", &N), N) {
		for (i = 0; i < N; ++i) {
			scanf("%s%d%d", A[i].str, &A[i].a, &A[i].b);
		}
		cnt = 0;
		for (i = 1000; i < 10000; ++i) {
			for (j = 0; j < N; ++j)
				if (!Judge(i, j)) break;
			if (j == N) {
				if (++cnt == 2) break;
				val = i;
			}
		}
		if (cnt == 1) printf("%d\n", val);
		else printf("Not sure\n");
	}
	return 0;
}
