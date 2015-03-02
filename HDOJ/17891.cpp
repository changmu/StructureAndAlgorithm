////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-27 11:31:00
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1789
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:1060KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 1010

struct Node {
	int a, b;
} A[maxn];
bool vis[maxn];

bool cmp(Node x, Node y) {
	return x.b > y.b;
} 

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, N, i, j;
	int sum;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &N);
		for (i = 0; i < N; ++i)
			scanf("%d", &A[i].a);
		for (i = 0; i < N; ++i)
			scanf("%d", &A[i].b);
		memset(vis, 0, sizeof(vis));

		std::sort(A, A + N, cmp);
		for (i = sum = 0; i < N; ++i) {
			for (j = A[i].a; j && vis[j]; --j);
			if (j) vis[j] = 1;
			else sum += A[i].b;
		}
		printf("%d\n", sum);
	}
	return 0;
}
