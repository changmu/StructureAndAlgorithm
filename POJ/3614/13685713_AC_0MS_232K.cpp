#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

#define maxn 2502

struct Node {
    int u, v;
    friend bool operator<(Node a, Node b) {
        return a.v > b.v;
    }
} cow[maxn], spf[maxn];
int C, L;
priority_queue<Node> Q;

bool cmp(Node a, Node b) {
    return a.u < b.u;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int i, j, ans = 0;
    Node tmp;
    scanf("%d%d", &C, &L);
    for(i = 0; i < C; ++i)
        scanf("%d%d", &cow[i].u, &cow[i].v);
    for(i = 0; i < L; ++i)
        scanf("%d%d", &spf[i].u, &spf[i].v);
    sort(cow, cow + C, cmp);
    sort(spf, spf + L, cmp);
    for(i = j = 0; i < L; ++i) {
        while(j < C && cow[j].u <= spf[i].u)
            Q.push(cow[j++]);
        while(!Q.empty() && spf[i].v) {
            tmp = Q.top(); Q.pop();
            if(tmp.v < spf[i].u) continue;
            --spf[i].v; ++ans;
        }
    }
    printf("%d\n", ans);
    return 0;
}