#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 20010
#define maxm 100010
#define COST 10000

int N, M, R, id;
int pre[maxn];
struct Node {
    int u, v, w;
} E[maxm];

bool cmp(Node a, Node b) {
    return a.w < b.w;
}

void addEdge(int u, int v, int w) {
    E[id].u = u; E[id].v = v; E[id++].w = w;
}

void getMap() {
    int x, y, d; id = 0;
    while(R--) {
        scanf("%d%d%d", &x, &y, &d);
        addEdge(x, y + N, COST - d);
    }
}

int ufind(int k) {
    int a = k, b;
    while(pre[k] != -1) k = pre[k];
    while(a != k) {
        b = pre[a];
        pre[a] = k;
        a = b;
    }
    return k;
}

bool same(int x, int y) {
    return ufind(x) == ufind(y);
}

void unite(int x, int y) {
    x = ufind(x);
    y = ufind(y);
    if(x != y) pre[y] = x;
}

void Kruskal() {
    int cnt = N + M, i, x, y, ans = 0;
    memset(pre, -1, sizeof(int) * (N + M));
    std::sort(E, E + id, cmp);
    for(i = 0; i < id; ++i) {
        if(!same(E[i].u, E[i].v)) {
            unite(E[i].u, E[i].v);
            ans += E[i].w;
            if(--cnt == 1) break;
        }
    }
    printf("%d\n", ans + COST * cnt);
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int T;
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &N, &M, &R); // G B
        getMap();
        Kruskal();
    }
    return 0;
}