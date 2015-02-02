#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 22
using namespace std;
typedef pair<int, int> P;

int N, C;
P coin[maxn];

int main() {
    // freopen("stdin.txt", "r", stdin);
    int i, sum = 0, j, a, b, c, d, pre;
    scanf("%d%d", &N, &C);
    for(i = 0; i < N; ++i) {
        scanf("%d%d", &coin[i].first, &coin[i].second);
        if(coin[i].first >= C) {
            sum += coin[i].second;
            --i; --N;
        }
    }
    sort(coin, coin + N);
    for(i = N - 1, j = pre = 0; i > j; --i) {
        a = C - coin[i].first; // 一个i硬币需要补齐的价值数
        b = (a + coin[j].first - 1) / coin[j].first; //补齐一个i硬币需要的j硬币数
        /* 优先使用pre匹配 */
        if(pre) {
            /* 需要j币的数量 */
            d = (coin[i].first - pre + coin[j].first - 1) / coin[j].first; 
            if(coin[j].second >= d) {
                coin[j].second -= d;
                --coin[i].second;
                ++sum; pre = 0;
            } else {
                pre += coin[j].second * coin[j].first;
                ++j;
            }

            if(coin[i].second) ++i;
        } else if(coin[j].second >= coin[i].second * b) { // 所有的硬币i能匹配完
            coin[j].second -= coin[i].second * b;
            sum += coin[i].second;
        } else {
            c = coin[j].second / b; // c为j币能匹配的i币数量
            coin[i].second -= c;
            sum += c;
            pre = (coin[j].second - c * b) * coin[j].first;
            ++j; ++i; // i未匹配完，j有剩余，下一轮优先使用pre
        }
    }

    if(pre) {
        d = (C - coin[i].first - pre + coin[i].first - 1) / coin[i].first;
        if(coin[i].second >= d) {
           coin[i].second -= d;
           ++sum;
        }
        pre = 0;
    }
    a = (C + coin[i].first - 1) / coin[i].first;
    sum += coin[i].second / a;

    printf("%d\n", sum);
    return 0;
}
