////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-17 11:19:11
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2077
////Problem Title: 
////Run result: Accept
////Run time:0MS
////Run memory:1056KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

int dp[22] = {0, 2};

int main() {
	// freopen("stdin.txt", "r", stdin);
	int T, n, i;
	for (i = 2; i <= 20; ++i)
		dp[i] = (dp[i-1] - 1) * 3 + 1;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		printf("%d\n", dp[n]);
	}
	return 0;
}
