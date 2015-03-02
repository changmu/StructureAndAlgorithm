////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2015-01-26 20:01:21
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 3427
////Problem Title: 
////Run result: Accept
////Run time:2542MS
////Run memory:1168KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 152
#define YES dp[L][R] = 1
#define NO dp[L][R] = -1, false

int dp[maxn][maxn];
char str[maxn];

bool Judge(int L, int R) {
	if (L == R) return false;	
	if (L > R) return true;
	if (dp[L][R] == 1) return true;
	if (dp[L][R] == -1) return false;

	int i;
	for (i = L + 1; i < R - 1; ++i) // xy
		if (Judge(L, i) && Judge(i + 1, R)) {
			return YES;
		}
	if (str[L] == str[R]) {
		if (Judge(L + 1, R - 1)) return YES; // AxA
		for (i = L + 1; i < R; ++i)
			if (str[i] == str[L] && Judge(L + 1, i - 1) && Judge(i + 1, R - 1)) // AxAyA
				return YES;
	}
	return NO;
}

int main() {
	// freopen("stdin.txt", "r", stdin);
	while (scanf("%s", str) == 1) {
		memset(dp, 0, sizeof(dp));
		if (!Judge(0, strlen(str) - 1)) printf("un");
		puts("solvable");
	}
	return 0;
}
