#include <stdio.h>
#include <string.h>
#include <queue>
#define inf 0x3f3f3f3f
#define maxN 55
#define maxn maxN * maxN * 2
#define maxm maxn * 4
using std::queue;

int head[maxn], n, k, id;
struct Node {
    int u, v, c, f, next;
} E[maxm];
int dist[maxn], map[maxN][maxN];
int pre[maxn], source, sink;
bool vis[maxn];

void addEdge(int u, int v, int c, int f) {
    E[id].u = u; E[id].v = v; E[id].f = f;
    E[id].c = c; E[id].next = head[u];
    head[u] = id++;
    E[id].u = v; E[id].v = u; E[id].f = -f;
    E[id].c = 0; E[id].next = head[v];
    head[v] = id++;
}

void getMap() {
    memset(head, -1, sizeof(head));
    int i, j, f, pos, down, right; id = 0;
    for(i = 0; i < n; ++i)
        for(j = 0; j < n; ++j) {
            scanf("%d", &map[i][j]);
            pos = i * n + j; right = pos + 1;
            down = pos + n;
            addEdge(pos, pos + n*n, 1, map[i][j]); // 拆点
            addEdge(pos, pos + n*n, inf, 0);
            if(i != n - 1) {
                addEdge(pos + n*n, down, inf, 0);
            }
            if(j != n - 1) {
                addEdge(pos + n*n, right, inf, 0);
            }
        }
    source = 2 * n * n; sink = source + 1;
    map[n][0] = map[n][1] = 0;
    addEdge(source, 0, k, 0);
    addEdge(source - 1, sink, k, 0);
}

bool SPFA(int start, int end) {
    memset(pre, -1, sizeof(pre));
    memset(vis, 0, sizeof(vis));
    memset(dist, -1, sizeof(dist));
    queue<int> Q; Q.push(start);
    int u, v, i; vis[start] = 1; dist[start] = 0;
    while(!Q.empty()) {
        u = Q.front(); Q.pop(); vis[u] = 0;
        for(i = head[u]; i != -1; i = E[i].next) {
            v = E[i].v;
            if(E[i].c && dist[v] < dist[u] + E[i].f) {
                dist[v] = dist[u] + E[i].f;
                pre[v] = i;
                if(!vis[v]) {
                    vis[v] = 1; Q.push(v);
                }
            }
        }
    }
    return dist[end] != -1;
}

void solve() {
    int sum = 0, i, u, v, minCut;
    while(SPFA(source, sink)) {
        minCut = inf;
        for(i = pre[sink]; i != -1; i = pre[E[i].u]) {
            if(minCut > E[i].c) minCut = E[i].c;
        }
        sum += minCut * dist[sink];
        for(i = pre[sink]; i != -1; i = pre[E[i].u]) {
            E[i].c -= minCut;
            E[i^1].c += minCut;
        }
    }
    printf("%d\n", sum);
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d%d", &n, &k) == 2) {
        getMap();
        solve();
    }
    return 0;
}
