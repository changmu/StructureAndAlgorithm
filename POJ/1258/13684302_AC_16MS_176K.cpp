#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

#define maxn 102
#define inf 0x3f3f3f3f

int G[maxn][maxn], N;
int dist[maxn];
bool vis[maxn];

void getMap() {
    int i, j;
    for(i = 1; i <= N; ++i)
        for(j = 1; j <= N; ++j)
            scanf("%d", &G[i][j]);
}

int getNext() {
    int u = 0, v = inf;
    for(int i = 1; i <= N; ++i)
        if(!vis[i] && v > dist[i]) {
            v = dist[i]; u = i;
        }
    return u;
}

void Prim() {
    int sum = 0, i, j, u = 1;
    memset(dist, 0x3f, sizeof(int) * (N + 1));
    memset(vis, 0, sizeof(bool) * (N + 1));
    dist[u] = 0;
    while(u) {
        vis[u] = 1;
        sum += dist[u];
        for(i = 1; i <= N; ++i)
            dist[i] = min(dist[i], G[u][i]);
        u = getNext();
    }
    printf("%d\n", sum);
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(~scanf("%d", &N)) {
        getMap();
        Prim();
    }
    return 0;
}
