#include <stdio.h>
#include <string.h>

#define maxn 1010
#define maxm maxn * maxn
#define inf 0x3f3f3f3f

int head[maxn], n, m, id, ans, cas = 1;
struct Node {
    int v, c, next;
} E[maxm];
bool vis[maxn];

void addEdge(int u, int v, int c) {
    E[id].v = v; E[id].c = c;
    E[id].next = head[u]; head[u] = id++;

    E[id].v = u; E[id].c = c;
    E[id].next = head[v]; head[v] = id++;
}

void getMap() {
    int u, v, c; id = 0;
    scanf("%d%d", &n, &m);
    memset(head, -1, sizeof(int) * (n + 1));
    while(m--) {
        scanf("%d%d%d", &u, &v, &c);
        addEdge(u, v, c);
    }
}

void DFS(int k, int dis) {
    if(k == n) {
        if(dis > ans) ans = dis;
        return;
    }
    for(int i = head[k]; i != -1; i = E[i].next) {        
        if(!vis[E[i].v]) {
            int pre = dis;
            vis[E[i].v] = 1;
            if(E[i].c < dis) dis = E[i].c;
            DFS(E[i].v, dis);
            dis = pre; vis[E[i].v] = 0;
        }
    }
}

void solve() {
    ans = 0;
    memset(vis, 0, sizeof(bool) * (n + 1));
    vis[1] = 1; DFS(1, inf);
    printf("Scenario #%d:\n%d\n\n", cas++, ans);
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        getMap();
        solve();
    }
    return 0;
}