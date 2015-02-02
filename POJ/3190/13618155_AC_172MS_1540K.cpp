#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <queue>

#define maxn 50010
using namespace std;

struct Node2 {
    int num, u, v;
    friend bool operator<(const Node2& a, const Node2& b) {
        return a.v > b.v;
    } 
} cow[maxn];
int ans[maxn];

bool cmp(const Node2& a, const Node2& b) {
    return a.u < b.u;
}

int main() {
    int N, i, j, sum, u, v, flag;
    Node2 tmp;
    while(scanf("%d", &N) == 1) {
        sum = 0;
        for(i = 0; i < N; ++i) {
            scanf("%d%d", &u, &v);
            cow[i].num = i + 1;
            cow[i].u = u;
            cow[i].v = v;
            ans[i + 1] = 0;
        }
        sort(cow, cow + N, cmp);

        priority_queue<Node2> PQ;
        PQ.push(cow[0]);
        ans[cow[0].num] = ++sum;

        for(i = 1; i < N; ++i) {
            tmp = PQ.top();
            if(cow[i].u > tmp.v) {
                tmp.v = cow[i].v;
                ans[cow[i].num] = ans[tmp.num];
                PQ.pop(); PQ.push(tmp);
            } else {
                ans[cow[i].num] = ++sum;
                PQ.push(cow[i]);
            }
        }

        printf("%d\n", sum);
        for(i = 1; i <= N; ++i)
            printf("%d\n", ans[i]);
    }
    return 0;
}