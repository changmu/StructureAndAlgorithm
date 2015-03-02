////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-16 23:55:32
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2079
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:1052KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int c1[42], c2[42];

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, n, m, i, j, k, a, b;
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (i = 0; i <= n; ++i)
			c1[i] = c2[i] = 0;
		c1[0] = 1;
		for (i = 0; i < m; ++i) {
			scanf("%d%d", &a, &b);
			for (j = 0; j <= n; ++j)
				for (k = 0; k <= b && k * a + j <= n; ++k)
					c2[k*a + j] += c1[j];
			for (j = 0; j <= n; ++j) {
				c1[j] = c2[j]; c2[j] = 0;
			}
		}
		printf("%d\n", c1[n]);
	}
	return 0;
}
