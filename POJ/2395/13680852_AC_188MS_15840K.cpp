#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

#define maxn 2002
#define maxm 1010
#define inf 0x3f3f3f3f

int N, M, map[maxn][maxn], dist[maxn];
bool vis[maxn];

void getMap() {
    int i, j, u, v, d;
    memset(map, 0x3f, sizeof(map));
    memset(dist, 0x3f, sizeof(int) * (N + 1));
    while(M--) {
        scanf("%d%d%d", &u, &v, &d);
        if(map[u][v] > d) {
            map[u][v] = map[v][u] = d;
        }
    }
}

int getNext() {
    int u = -1, d = inf;
    for(int i = 1; i <= N; ++i)
        if(!vis[i] && dist[i] < d) {
            d = dist[i];
            u = i;
        }
    return u;
}

void Dijkstra() {
    int u, v, i, ans = 0;
    u = 1; dist[u] = 0;
    while(u != -1) {
        vis[u] = 1;
        ans = max(dist[u], ans);
        for(i = 1; i <= N; ++i)
            if(i != u) dist[i] = min(dist[i], map[u][i]);
        u = getNext();
    }
    printf("%d\n", ans);
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    scanf("%d%d", &N, &M);
    getMap();
    Dijkstra();
    return 0;
} 