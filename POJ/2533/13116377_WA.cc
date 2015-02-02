#include <stdio.h>

int arr[1002], dp[1002];

int main()
{
    int n, i, j, ans;
    scanf("%d", &n);
    for(i = 1; i <= n; ++i) scanf("%d", arr + i);
    dp[1] = ans = 1;
    for(i = 2; i <= n; ++i){
        for(j = i - 1; j >= 1; --j){
            if(arr[i] > arr[j] && dp[i] < dp[j]){
                dp[i] = dp[j] + 1;
                if(dp[i] > ans) ans = dp[i];
            }
        }
    }
    printf("%d\n", ans);
    return 0;
}