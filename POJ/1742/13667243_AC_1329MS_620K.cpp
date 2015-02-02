#include <stdio.h>
#include <string.h>

#define maxm 100005

int V[102], sum[maxm];
bool dp[maxm];

int main() {
	// freopen("stdin.txt", "r", stdin);
	int N, M, i, j, m, ans;
	while(scanf("%d%d", &N, &M), N|M) {
		for(i = 0; i < N; ++i)
			scanf("%d", &V[i]);
		memset(dp, 0, sizeof(bool) * (M + 1));
		dp[0] = true;
		for(i = ans = 0; i < N; ++i) {
			scanf("%d", &m);
			memset(sum, 0, sizeof(int) * (M + 1));
			for(j = V[i]; j <= M; ++j)
				if(!dp[j] && dp[j-V[i]] && sum[j-V[i]] < m) {
					sum[j] = sum[j-V[i]] + 1;
					dp[j] = true;
					++ans;
				}
		}
		printf("%d\n", ans);
	}
    return 0;
}