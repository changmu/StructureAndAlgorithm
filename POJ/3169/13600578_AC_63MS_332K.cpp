#include <stdio.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>

using namespace std;

#define maxn 1010
#define maxm 60000
#define inf 0x3f3f3f3f

int dis[maxn], N, ML, MD;
int head[maxn], id, out[maxn];
struct Node {
    int v, w, next;
} E[maxm];
bool vis[maxn];

void addEdge(int u, int v, int w) {
    E[id].v = v; E[id].w = w;
    E[id].next = head[u]; 
    head[u] = id++;
}

void getMap() {
    int u, v, i, w; id = 0;
    memset(head, -1, sizeof(int) * (N + 1));
    while(ML--) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
    }
    while(MD--) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(v, u, -w);
    }
    for(i = 1; i < N; ++i) {
        addEdge(i + 1, i, 0);
    }
}

void solve() {
    queue<int> Q;
    int i, u, v, ans = 0;
    for(i = 1; i <= N; ++i) {
        vis[i] = out[i] = 0;
        dis[i] = inf;
    }
    vis[i] = 1; Q.push(1);
    dis[1] = 0;
    while(!Q.empty()) {
        u = Q.front(); Q.pop(); vis[u] = 0;
        if(++out[u] > N + 1) {
            ans = -1; break;
        }
        for(i = head[u]; i != -1; i = E[i].next) {
            if(dis[u] + E[i].w < dis[v=E[i].v]) {
                dis[v] = dis[u] + E[i].w;
                if(!vis[v]) {
                    Q.push(v);
                    vis[v] = 1;
                }
            }
        }
    }
    if(ans == -1) printf("-1\n");
    else if(dis[N] == inf) printf("-2\n");
    else printf("%d\n", dis[N] - dis[1]);
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d%d%d", &N, &ML, &MD) == 3) {
        getMap();
        solve();
    }
    return 0;
}
