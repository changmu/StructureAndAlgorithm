// 贪心：单纯的求最大风险的牛的最小值
// 题意：有N头牛，每头牛都有重量w和力量s，它们一起玩叠罗汉游戏，
// 每头牛承受的风险是它头上的牛的质量和 - 它自身的力量(结果可以为负)
// 找到一种最优方案使得承受最大风险的牛的这个风险值最小。
// 解法：可以假定已经找到了最优排序，那么当打乱这个序列时最大值一定会更大
// 由此可以得到w1 + s1 < w2 + s2这个排序规则。
#include <stdio.h>
#include <string.h>
#include <algorithm>

const int maxn = 5e4 + 10;
struct Node {
    int w, s;
} COW[maxn];
int N;

int max(int a, int b) { return a > b ? a : b; }

bool cmp(Node a, Node b) {
    return a.w + a.s < b.w + b.s;
}

int main() {
    long long ans, sum_w;

    while (~scanf("%d", &N)) {
        for (int i = 0; i < N; ++i)
            scanf("%d%d", &COW[i].w, &COW[i].s);

        std::sort(COW, COW + N, cmp);

        ans = 0 - COW[0].s;
        sum_w = COW[0].w;
        for (int i = 1; i < N; ++i) {
            ans = max(ans, sum_w - COW[i].s);
            sum_w += COW[i].w;
        }

        printf("%lld\n", ans);
    }
    return 0;
}
