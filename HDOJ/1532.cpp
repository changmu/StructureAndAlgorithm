////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: 长木
////Run ID: 
////Submit time: 2014-10-12 10:22:44
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 1532
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:236KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 205
#define maxm 410
#define inf 0x3f3f3f3f

int head[maxn], n, m, source, sink, id; // n个点m条边
struct Node {
    int u, v, c, next;
} E[maxm];
int que[maxn], pre[maxn], Layer[maxn];
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
    int u, v, c; id = 0;
    memset(head, -1, sizeof(int) * (n + 1));
    source = 1; sink = n;
    while(m--) {
        scanf("%d%d%d", &u, &v, &c);
        addEdge(u, v, c);
    }
}

bool countLayer() {
    memset(Layer, 0, sizeof(int) * (n + 1));
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
        memset(vis, 0, sizeof(bool) * (n + 1));
        memset(pre, -1, sizeof(int) * (n + 1));
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

void solve() {
    printf("%d\n", Dinic());
}

int main() {
    while(scanf("%d%d", &m, &n) == 2) {
        getMap();
        solve();
    }
}