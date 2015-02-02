#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>

#define maxn 100005
typedef long long LL;

struct Node {
    int t, d;
    friend bool operator<(const Node& a, const Node& b) {
        return a.t * b.d < b.t * a.d;
    }
} cow[maxn];

int main() {
    int N, i, sumt = 0;
    LL sumd = 0;
    scanf("%d", &N);
    for(i = 0; i < N; ++i)
        scanf("%d%d", &cow[i].t, &cow[i].d);
    std::sort(cow, cow + N);
    for(i = 0; i < N; ++i) {
        sumd += cow[i].d * sumt;
        sumt += cow[i].t * 2;
    }
    printf("%lld\n", sumd);
    return 0;
}