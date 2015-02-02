#include <stdio.h>
#include <string.h>
#include <queue>
#include <algorithm>
#include <iostream>

#define maxn 2510
using namespace std;
struct Node {
    int first, second;
    friend bool operator<(const Node& a, const Node& b) {
        return a.second > b.second;
    }
} cow[maxn], sun[maxn];

bool cmp(const Node& a, const Node& b) {
    return a.first < b.first;
}

int main() {
    int C, L, i, j, ans = 0;
    Node tmp;
    scanf("%d%d", &C, &L);
    for(i = 0; i < C; ++i)
        scanf("%d%d", &cow[i].first, &cow[i].second);
    for(i = 0; i < L; ++i)
        scanf("%d%d", &sun[i].first, &sun[i].second);
    sort(cow, cow + C, cmp);
    sort(sun, sun + L, cmp);
    priority_queue<Node> PQ;
    for(i = 0; i < C; ++i)
        PQ.push(cow[i]);
    for(i = j = 0; i < L && !PQ.empty(); ++i) {
        while(!PQ.empty() && sun[i].second) {
            tmp = PQ.top();
            if(tmp.second < sun[i].first)
                PQ.pop();
            else if(tmp.first <= sun[i].first) {
                --sun[i].second;
                ++ans; PQ.pop();
            } else break;
        }
    }

    printf("%d\n", ans);
    return 0;
}
