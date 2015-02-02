#include <stdio.h>
#include <string.h>
#include <algorithm>
using namespace std;

#define maxn 1505

int dp[maxn] = {0, 1, 2, 3, 4, 5};

int min(int a, int b, int c) {
	if(c < b) b = c;
	return a < b ? a : b;
}

int main() {
	int n, i, c2 = 3, c3 = 2, c5 = 2;
	for(i = 6; i < maxn; ++i) {
		dp[i] = min(dp[c2]*2, dp[c3]*3, dp[c5]*5);
		while(dp[c2] * 2 <= dp[i]) ++c2;
		while(dp[c3] * 3 <= dp[i]) ++c3;
		while(dp[c5] * 5 <= dp[i]) ++c5;
	}
	while(scanf("%d", &n), n) {
		printf("%d\n", dp[n]);
	}
	return 0;
}