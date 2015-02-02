#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

#define maxn 100005
typedef __int64 LL;

struct Node {
    int t, d;
    friend bool operator<(const Node& a, const Node& b) {
        return (double)a.d / a.t > (double)b.d / b.t;
    }
} cow[maxn];

int main() {
    int N, i, sumt;
    LL sumd;
    while(scanf("%d", &N) == 1) {
        sumd = sumt = 0;
        for(i = 0; i < N; ++i)
            scanf("%d%d", &cow[i].t, &cow[i].d);
        std::sort(cow, cow + N);
        for(i = 0; i < N; ++i) {
            sumd += cow[i].d * sumt;
            sumt += cow[i].t * 2;
        }
        printf("%I64d\n", sumd);
    }
    return 0;
}