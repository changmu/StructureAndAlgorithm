#include <stdio.h>
#include <string.h>
#include <queue>
#define inf 0x3f3f3f3f
#define maxn 1010
#define maxm 10010
using std::queue;

int head[maxn];
struct Node {
    int to, next, c, f; // c是容量,f是费用
} E[maxm << 2];
int n, m, id;
int dist[maxn], pre[maxn], load[maxn];
bool vis[maxn];

void addEdge(int u, int v, int f, int c) {
    E[id].to = v; E[id].c = c;
    E[id].f = f; E[id].next = head[u];
    head[u] = id++;
    E[id].to = u; E[id].c = 0;
    E[id].f = -f; E[id].next = head[v];
    head[v] = id++;
}

void getMap() {
    memset(head, -1, sizeof(int) * (n + 1));
    int u, v, f; id = 0;
    while(m--) {
        scanf("%d%d%d", &u, &v, &f);
        addEdge(u, v, f, 1);
        addEdge(v, u, f, 1);
    }
    addEdge(0, 1, 0, 2); // u, v, f, c
}

bool SPFA(int start, int end) {
    queue<int> Q; int i, u, v;
    memset(vis, 0, sizeof(bool) * (n + 1));
    memset(load, -1, sizeof(int) * (n + 1));
    memset(pre, -1, sizeof(int) * (n + 1));
    memset(dist, 0x3f, sizeof(int) * (n + 1));
    Q.push(start); vis[start] = 1; dist[start] = 0;
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        vis[u] = 0;
        for(i = head[u]; i != -1; i = E[i].next) {
            v = E[i].to;
            if(E[i].c && dist[v] > dist[u] + E[i].f) {
                dist[v] = dist[u] + E[i].f;
                pre[v] = u; load[v] = i;
                if(!vis[v]) {
                    vis[v] = 1; Q.push(v);
                }
            }
        }
    }
    return dist[end] != inf;
}

int Min_Cost_Flow(int start, int end) {
    int ans_cost = 0, ans_flow = 0;
    int u, minCut;
    while(SPFA(start, end)) {
        minCut = inf;
        for(u = end; pre[u] != -1; u = pre[u]) {
            if(minCut > E[load[u]].c)
                minCut = E[load[u]].c;            
        }
        for(u = end; pre[u] != -1; u = pre[u]) {
            E[load[u]].c -= minCut;          
            E[load[u]^1].c += minCut;
        }
        ans_cost += dist[end] * minCut;
        ans_flow += minCut;
    }
    return ans_cost;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d%d", &n, &m) == 2) {
        getMap();
        printf("%d\n", Min_Cost_Flow(0, n));
    }
    return 0;
}