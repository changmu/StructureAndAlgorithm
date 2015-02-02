#include <stdio.h>
#define maxn 12882

int dp[3404][maxn];

int max(int a, int b){ return a > b ? a : b; }

int main()
{
    int n, m, weight, val, i, j;
    scanf("%d%d", &n, &m);
    for(i = 1; i <= n; ++i){
        scanf("%d%d", &weight, &val);
        for(j = 1; j <= m; ++j)
            if(j >= weight)
                dp[i][j] = max(dp[i-1][j], dp[i-1][j-weight] + val);
            else dp[i][j] = dp[i-1][j];
    }
    printf("%d\n", dp[n][m]);
    return 0;
}
