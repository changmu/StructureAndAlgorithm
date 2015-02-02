#include <stdio.h>
#include <string.h>

#define maxn 1000002
int dp[maxn];

int main() {
    int i, n;
    scanf("%d", &n);
    dp[1] = 1;
    for(i = 2; i <= n; ++i) {
        if(i & 1) dp[i] = dp[i-1];
        else dp[i] = dp[i-1] + dp[i/2];
        dp[i] %= 1000000000;
    }
    printf("%d\n", dp[n]);
    return 0;
}