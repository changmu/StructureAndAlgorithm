////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-11-23 13:08:24
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 2152
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:280KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 110

// struct Node {
// 	int u, v;
// } arr[maxn];
int c1[maxn], c2[maxn];

int main() {
	int N, M, i, j, k, u, v;
	while(scanf("%d%d", &N, &M) == 2) {
		memset(c1, 0, sizeof(c1));
		memset(c2, 0, sizeof(c2));
		c1[0] = 1;
		for(i = 0; i < N; ++i) {
			scanf("%d%d", &u, &v);
			for(j = 0; j <= M; ++j)
				for(k = u; k <= v && j + k <= M; ++k)
					c2[j+k] += c1[j];
			for(j = 0; j <= M; ++j) {
				c1[j] = c2[j]; c2[j] = 0;
			}
		}
		printf("%d\n", c1[M]);
	}
	return 0;
}