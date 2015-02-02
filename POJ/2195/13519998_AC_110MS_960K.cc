#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <queue>

const int maxn = 205;
const int inf = 0x3f3f3f3f;
char str[maxn];
int head[maxn], n, m; // n rows, m columns
struct Node {
    int x, y;
} A[maxn], B[maxn];
int id1, id2, id, source, sink;
struct node {
    int f, c, u, v, next;
} E[maxn * maxn];
bool vis[maxn];
int pre[maxn], dist[maxn];

void addEdge(int u, int v, int c, int f) {
    E[id].u = u; E[id].v = v;
    E[id].c = c; E[id].f = f;
    E[id].next = head[u]; head[u] = id++;

    E[id].u = v; E[id].v = u;
    E[id].c = 0; E[id].f = -f;
    E[id].next = head[v]; head[v] = id++;
}

void getMap() {
    int i, j, dis; Node e; 
    id = id1 = id2 = 0;
    for(i = 0; i < n; ++i) {
        scanf("%s", str);
        for(j = 0; str[j] != '\0'; ++j) {
            if(str[j] == '.') continue;
            e.x = i; e.y = j;
            if(str[j] == 'm') A[id1++] = e;
            else B[id2++] = e;
        }
    }

    memset(head, -1, sizeof(head));
    source = id1 + id2; sink = source + 1;
    for(i = 0; i < id1; ++i) {
        for(j = 0; j < id2; ++j) {
            dis = abs(A[i].x - B[j].x) + abs(A[i].y - B[j].y);
            addEdge(i, id1 + j, 1, dis); // uvcf
        }
        addEdge(source, i, 1, 0);
    }
    for(j = 0; j < id2; ++j)
        addEdge(id1 + j, sink, 1, 0);
}

bool SPFA(int start, int end) {
    std::queue<int> Q; int i, u, v;
    memset(vis, 0, sizeof(vis));
    memset(pre, -1, sizeof(pre));
    memset(dist, 0x3f, sizeof(pre));
    Q.push(start); vis[start] = 1; dist[start] = 0;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        vis[u] = 0;
        for(i = head[u]; i != -1; i = E[i].next) {
            v = E[i].v;
            if(E[i].c && dist[v] > dist[u] + E[i].f) {
                dist[v] = dist[u] + E[i].f;
                pre[v] = i;
                if(!vis[v]) {
                    Q.push(v); vis[v] = 1;
                }
            }
        }
    }
    return dist[end] != inf;
}

int Min_Cost_Flow(int start, int end) {
    int ans_cost = 0, u, minCut;
    while(SPFA(start, end)) {
        minCut = inf;
        for(u = pre[end]; u != -1; u = pre[E[u].u]) {
            if(minCut > E[u].c) minCut = E[u].c;
        }
        for(u = pre[end]; u != -1; u = pre[E[u].u]) {
            E[u].c -= minCut; E[u^1].c += minCut;
        }
        ans_cost += minCut * dist[end];
    }
    return ans_cost;
}

void solve() {
    printf("%d\n", Min_Cost_Flow(source, sink));
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d%d", &n, &m), n | m) {
        getMap();
        solve();
    }
    return 0;
}