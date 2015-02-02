#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;
#define maxn 200010
#define inf 0x3f3f3f3f
#define shift 100000

int N, dp[maxn];

int main() {
    // freopen("stdin.txt", "r", stdin);
    int i, j, c, v, ans = 0, left, right;
    scanf("%d", &N);
    fill(dp, dp + maxn, -inf);
    dp[shift] = 0;
    left = right = shift;
    for(i = 0; i < N; ++i) {
        scanf("%d%d", &c, &v);
        if(c <= 0 && v <= 0)
            continue;
        if(c < 0) left = min(left, left + c);
        else right = max(right, right + c);

        if(c < 0) for(j = left; j <= right; ++j)
            dp[j] = max(dp[j], dp[j-c] + v);
        else for(j = right; j >= left; --j)
            dp[j] = max(dp[j], dp[j-c] + v);
    }

    for(i = shift; i <= right; ++i)
        if(dp[i] >= 0) ans = max(ans, dp[i] + i - shift);
    printf("%d\n", ans);
    return 0;
}