#include <stdio.h>
#define maxn 12882

int dp[maxn];

int main()
{
    int n, totalWeight, i, j, weight, val;
    scanf("%d%d", &n, &totalWeight);
    for(i = 1; i <= n; ++i){
        scanf("%d%d", &weight, &val);
        for(j = totalWeight; j; --j){
        	if(j < weight) break;
            if(dp[j - weight] + val > dp[j]) 
				dp[j] = dp[j - weight] + val;
        }
    }
    printf("%d\n", dp[totalWeight]);
    return 0;
}
