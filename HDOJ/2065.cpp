////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-18 20:28:14
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2065
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1060KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>

int f(int n, __int64 m, int mod) {
	int x = 1;
	for ( ; m ; m >>= 1) {
		if (m & 1) x = x * n % mod;
		n = n * n % mod;
	}
	return x;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, cas;
	__int64 n, a, b;
	while (scanf("%d", &T), T) {
		for (cas = 1; cas <= T; ++cas) {
			scanf("%I64d", &n);
			a = f(2, n - 1, 100);
			b = a + 1;
			if (b == 100) b = 0;
			printf("Case %d: %d\n", cas, a * b % 100); 
		}
		printf("\n");
	}
	return 0;
}
