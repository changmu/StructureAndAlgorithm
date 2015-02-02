#include <stdio.h>
#include <string.h>

int dp[1010][35];
bool arr[1010];

int max(int a, int b, int c) {
    if(b < c) b = c;
    return a > b ? a : b;
}

int main() {
    int T, W, i, j, tmp, ans = 0;
    scanf("%d%d", &T, &W);
    for(i = 1; i <= T; ++i) {
        scanf("%d", &tmp);
        arr[i] = tmp - 1;
    }
    if(arr[1]) dp[1][1] =1;
    else dp[1][0] = 1;
    ans = 1;
    for(i = 2; i <= T; ++i) {
        dp[i][0] = dp[i-1][0] + !arr[i];
        for(j = 1; j <= W; ++j) {
            dp[i][j] = max(dp[i-1][j], dp[i-1][j-1], dp[i][j-1]);
            dp[i][j] += !((j & 1) ^ arr[i]);
            if(dp[i][j] > ans) ans = dp[i][j];
        }
    }
    printf("%d\n", ans);
    return 0;
}
