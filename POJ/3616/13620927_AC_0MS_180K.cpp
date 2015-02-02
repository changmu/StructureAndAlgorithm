#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 1010
using namespace std;

struct Node {
    int u, v, w;
    friend bool operator<(const Node& a, const Node& b) {
        return a.u < b.u;
    }
} E[maxn];
int N, M, R, dp[maxn]; // dp[i]表示以第i个区间作为结束区间能得到的最大值

int main() {
    int ans, i, j;
    while(scanf("%d%d%d", &N, &M, &R) == 3) {
        for(i = 0; i < M; ++i)
            scanf("%d%d%d", &E[i].u, &E[i].v, &E[i].w);
        sort(E, E + M);
        ans = dp[0] = E[0].w;

        for(i = 1; i < M; ++i) {
            dp[i] = E[i].w;
            for(j = i - 1; j >= 0; --j)
                if(E[i].u - E[j].v >= R)
                    dp[i] = max(dp[i], dp[j] + E[i].w);
            ans = max(ans, dp[i]);
        }
        printf("%d\n", ans);
    }
    return 0;
}