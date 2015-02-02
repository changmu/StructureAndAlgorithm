#include <stdio.h>
#include <string.h>

#define maxn 110
#define inf 0x3f3f3f3f

struct Node {
    int price, level, down;
} G[maxn];
int head[maxn], m, n, id;
struct Node2 {
    int v, val, next;
} E[maxn * maxn];
bool vis[maxn];

void addEdge(int u, int v, int val) {
    E[id].v = v; E[id].next = head[u];
    E[id].val = val; head[u] = id++;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int DFS(int u) {
    int v, ans = G[u].price;
    for(int i = head[u]; i != -1; i = E[i].next) {
        if(vis[v = E[i].v]) return inf;
        vis[v] = 1;
        ans = min(ans, E[i].val + DFS(v));
        vis[v] = 0;
    }
    return ans;
}

int solve() {
    memset(vis, 0, sizeof(bool) * (n + 1));
    int i, j, v, ans = G[1].price; vis[1] = 1;
    for(i = head[1]; i != -1; i = E[i].next) {
        v = E[i].v; 
        ans = min(ans, E[i].val + DFS(v));
    }
    return ans;
}

int main() {
    int i, j, v, val;
    while(scanf("%d%d", &m, &n) == 2) {
        memset(head, -1, (n + 1) * sizeof(int));
        for(i = 1, id = 0; i <= n; ++i) {
            scanf("%d%d%d", &G[i].price, &G[i].level, &G[i].down);
            for(j = 0; j < G[i].down; ++j) {
                scanf("%d%d", &v, &val);
                addEdge(i, v, val);
            }
        }
        printf("%d\n", solve());
    }
    return 0;
}
