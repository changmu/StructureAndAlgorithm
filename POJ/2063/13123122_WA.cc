#include <stdio.h>
#include <string.h>
#define maxn 1200

int dp[maxn], w[42], v[42];

int main()
{
    int t, totalWeight, years, i, j, capital, n;
    scanf("%d", &t);
    while(t--){
        scanf("%d%d", &totalWeight, &years);
        capital = totalWeight;
        scanf("%d", &n);
        for(i = 1; i <= n; ++i){
            scanf("%d%d", &w[i], &v[i]);
            w[i] /= 1000;
        }
        while(years--){
            totalWeight = capital / 1000;
            memset(dp, 0, sizeof(dp));
            for(i = 1; i <= n; ++i){
                for(j = w[i]; j <= totalWeight; ++j){
                    if(dp[j] < dp[j - w[i]] + v[i]) 
                        dp[j] = dp[j - w[i]] + v[i];
                }
            }
            capital += dp[totalWeight];
        }
        printf("%d\n", capital);
    }
    return 0;
}
