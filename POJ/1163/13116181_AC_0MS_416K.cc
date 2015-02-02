#include <stdio.h>

int dp[102][102];

int max(int a, int b){ return a > b ? a : b; }

int main()
{
    int n, i, j, ans;
    scanf("%d", &n);
    for(i = 1; i <= n; ++i){
        for(j = 1; j <= i; ++j){
            scanf("%d", &dp[i][j]);
            dp[i][j] += max(dp[i-1][j], dp[i-1][j-1]);
        }
    }
    
    ans = 0;
    for(i = 1; i <= n; ++i)
        if(dp[n][i] > ans) ans = dp[n][i];
    printf("%d\n", ans);
    return 0;
}