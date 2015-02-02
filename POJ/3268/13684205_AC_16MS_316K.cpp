#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

#define maxn 1010
#define maxm 100010
#define inf 0x3f3f3f3f

int N, M, X;
int head1[maxn], head2[maxn], id1, id2;
struct Node {
    int v, w, next;
} E1[maxm], E2[maxm];
int dist1[maxn], dist2[maxn];
bool vis1[maxn], vis2[maxn];

void addEdge(int head[], Node E[], int& id, int u, int v, int w) {
    E[id].v = v; E[id].w = w;
    E[id].next = head[u]; head[u] = id++;
}

void getMap() {
    int u, v, w; id1 = id2 = 1;
    while(M--) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(head1, E1, id1, u, v, w);
        addEdge(head2, E2, id2, v, u, w); // reverse
    }
}

int getNext(int dist[], bool vis[]) {
    int u = 0, i, v = inf;
    for(i = 1; i <= N; ++i)
        if(!vis[i] && dist[i] < v) {
            v = dist[i]; u = i;
        }
    return u;
}

void Dijkstra(int source, int head[], Node E[], int dist[], bool vis[]) {
    int i, u = source, v, w;
    memset(dist, 0x3f, sizeof(int) * (N + 1));
    dist[u] = 0;
    while(u) {
        vis[u] = 1;
        for(i = head[u]; i; i = E[i].next)
            dist[v=E[i].v] = min(dist[v], dist[u] + E[i].w);
        u = getNext(dist, vis);
    }
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    scanf("%d%d%d", &N, &M, &X);
    getMap();
    Dijkstra(X, head1, E1, dist1, vis1);
    Dijkstra(X, head2, E2, dist2, vis2);
    int ans = 0;
    for(int i = 1; i <= N; ++i)
        ans = max(ans, dist1[i] + dist2[i]);
    printf("%d\n", ans);
    return 0;
}