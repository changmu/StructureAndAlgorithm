////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-28 10:33:59
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 4883
////Problem Title: 
////Run result: Accept
////Run time:546MS
////Run memory:1056KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 1450

int A[maxn];

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, N, x, i, y, h, m, ret;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		memset(A, 0, sizeof(A));
		while (N--) {
			scanf("%d%d:%d", &x, &h, &m);
			m += h * 60;
			A[m] += x;
			scanf("%d:%d", &h, &m);
			m += h * 60;
			A[m] -= x;
		}
		y = ret = 0;
		for (i = 0; i < maxn; ++i) {
			y += A[i];
			if (y > ret) ret = y;
		}
		printf("%d\n", ret);
	}
	return 0;
}
