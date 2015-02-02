#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 355

int dp[maxn][maxn];

int max(int a, int b) { return a > b ? a : b; }

int main() {
    int n, i, j, a;
    scanf("%d", &n);
    for(i = 1; i <= n; ++i) {
        for(j = 1; j <= i; ++j) {
            scanf("%d", &dp[i][j]);
            dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    printf("%d\n", *std::max_element(dp[n], dp[n] + n + 1));
    return 0;
}