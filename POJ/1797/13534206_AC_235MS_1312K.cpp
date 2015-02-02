#include <stdio.h>
#include <string.h>

#define maxn 1010
#define maxm maxn * maxn
#define inf 0x3f3f3f3f

int head[maxn], n, m, id, ans, cas = 1;
struct Node {
    int v, c, next;
} E[maxm];
int dis[maxn];
bool vis[maxn];

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

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

int getNext() {
    int pos = -1, val = 0; 
    for(int i = 1; i <= n; ++i)
        if(dis[i] > val && !vis[i]) {
            val = dis[i]; pos = i;
        }
    return pos;
}

void Dijkstra(int start, int end) {
    memset(dis, 0, sizeof(int) * (n + 1));
    dis[start] = inf;
    int i, u = start, v;
    while(u != -1) {
        vis[u] = 1;
        if(u == end) return;
        for(i = head[u]; i != -1; i = E[i].next) {
            if(!vis[v = E[i].v]) dis[v] = max(dis[v], min(E[i].c, dis[u]));
        }
        u = getNext();
    }   
}

void solve() {
    memset(vis, 0, sizeof(bool) * (n + 1));
    Dijkstra(1, n);
    printf("Scenario #%d:\n%d\n\n", cas++, dis[n]);
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