////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-18 19:33:05
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2068
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1056KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>

int D[20] = {1, 0, 1};

__int64 f(int n, int m) {
	if (m > n / 2) m = n - m;
	__int64 ans = 1;
	for (int i = 0; i < m; ++i)
		ans = ans * (n - i) / (i + 1);
	return ans;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	int n, i, j;
	__int64 sum;
	for (i = 3; i <= 15; ++i) D[i] = (i - 1) * (D[i-1] + D[i-2]);
	while (scanf("%d", &n), n) {
		sum = 0;
		i = n >> 1;
		for (j = 0; j <= i; ++j)
			sum += D[j] * f(n, n - j);
		printf("%I64d\n", sum);
	}
	return 0;
}
