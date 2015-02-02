#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 200010
#define delta 1000 * 100
#define inf 0x3f3f3f3f
using namespace std;

int dp[maxn], N, ans; // dp[i] stands when TS is i, the max TF
struct Node {
    int s, f;
} arr[102];

int main() {
    // freopen("stdin.txt", "r", stdin);
    int i, j, s, f, begin, end, u, v, step;
    scanf("%d", &N);
    for(i = 0; i < N; ++i) {
        scanf("%d%d", &s, &f);
        if(s <= 0 && f <= 0) {
            --i; --N;
            continue;
        }
        arr[i].s = s;
        arr[i].f = f;
    }
    fill(dp, dp + maxn, -inf);

    u = v = 0; dp[0 + delta] = 0;
    for(i = 0; i < N; ++i) {
        step = 1;
        u = min(u, u + arr[i].s);
        v = max(v, v + arr[i].s);

        begin = u; end = v;
        if(arr[i].s > 0) {
            step = -1;
            swap(begin, end);
        }

        for(j = begin; j != end + step; j += step) // j maybe negative
            dp[j + delta] = max(dp[j+delta], dp[j+delta-arr[i].s] + arr[i].f);
    }

    for(i = 0; i <= v; ++i)
        if(dp[i+delta] >= 0)
            ans = max(ans, dp[i+delta] + i);
    printf("%d\n", ans);
    return 0;
}