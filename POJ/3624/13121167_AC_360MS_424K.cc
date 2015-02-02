#include <stdio.h>
#define maxn 12882

int dp[maxn];

int max(int a, int b){ return a > b ? a : b; }

int main()
{
    int n, totalWeight, i, j, weight, val;
    scanf("%d%d", &n, &totalWeight);
    for(i = 1; i <= n; ++i){
        scanf("%d%d", &weight, &val);
        for(j = totalWeight; j; --j){
            if(j >= weight) dp[j] = max(dp[j], dp[j - weight] + val);
        }
    }
    printf("%d\n", dp[totalWeight]);
    return 0;
}
