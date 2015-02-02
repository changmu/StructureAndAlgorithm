////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-13 17:16:22
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3572
////Problem Title: 
////Run result: Accept
////Run time:218MS
////Run memory:2872KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 1200
#define maxm 700000
#define inf 0x3f3f3f3f

int head[maxn], n, m, id; // n machines
struct Node {
    int u, v, c, next;
} E[maxm];
int source, sink, tar, maxDay, nv;
int que[maxn], Layer[maxn], pre[maxn];
bool vis[maxn];

void addEdge(int u, int v, int c) {
    E[id].u = u; E[id].v = v;
    E[id].c = c; E[id].next = head[u];
    head[u] = id++;

    E[id].u = v; E[id].v = u;
    E[id].c = 0; E[id].next = head[v];
    head[v] = id++;
}

void getMap() {
    int i, j, u, v, p, s, e; 
    id = tar = maxDay = 0;
    scanf("%d%d", &m, &n);
    memset(head, -1, sizeof(head));
    source = 0; sink = 705;
    for(i = 1; i <= m; ++i) {
        scanf("%d%d%d", &p, &s, &e);
        tar += p;
        if(e > maxDay) maxDay = e;
        addEdge(source, i, p);
        for(j = s; j <= e; ++j)
            addEdge(i, m + j, 1);
    }
    sink = m + maxDay + 1; nv = sink + 1;
    for(i = 1; i <= maxDay; ++i)
        addEdge(m + i, sink, n);
}

bool countLayer() {
    memset(Layer, 0, sizeof(int) * nv);
    int id = 0, front = 0, u, v, i;
    Layer[source] = 1; que[id++] = source;
    while(front != id) {
        u = que[front++];
        for(i = head[u]; i != -1; i = E[i].next) {
            v = E[i].v;
            if(E[i].c && !Layer[v]) {
                Layer[v] = Layer[u] + 1;
                if(v == sink) return true;
                else que[id++] = v;
            }
        }
    }
    return false;
}

int Dinic() {
    int i, u, v, minCut, maxFlow = 0, pos, id = 0;
    while(countLayer()) {
        memset(vis, 0, sizeof(bool) * nv);
        memset(pre, -1, sizeof(int) * nv);
        que[id++] = source; vis[source] = 1;
        while(id) {
            u = que[id - 1];
            if(u == sink) {
                minCut = inf;
                for(i = pre[sink]; i != -1; i = pre[E[i].u])
                    if(minCut > E[i].c) {
                        minCut = E[i].c; pos = E[i].u;
                    }
                maxFlow += minCut;
                for(i = pre[sink]; i != -1; i = pre[E[i].u]) {
                    E[i].c -= minCut;
                    E[i^1].c += minCut;
                }
                while(que[id-1] != pos)
                    vis[que[--id]] = 0;
            } else {
                for(i = head[u]; i != -1; i = E[i].next)
                    if(E[i].c && Layer[u] + 1 == Layer[v = E[i].v] && !vis[v]) {
                        vis[v] = 1; que[id++] = v; pre[v] = i; break;
                    }
                if(i == -1) --id;
            }
        }
    }
    return maxFlow;
}

void solve(int cas) {
    printf("Case %d: %s\n\n", cas, tar == Dinic() ? "Yes" : "No");
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int t, cas;
    scanf("%d", &t);
    for(cas = 1; cas <= t; ++cas) {
        getMap();
        solve(cas);
    }
    return 0;
}