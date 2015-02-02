#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#include <queue>
using namespace std;
typedef long long LL;

#define maxn 505
#define maxm 5210
#define inf 0x3f3f3f3f

int T, N, W, M;
int head[maxn], id;
struct Node {
    int v, w, next;
} E[maxm];
int out[maxn], dist[maxn];
bool vis[maxn];

void addEdge(int u, int v, int w) {
    E[id].v = v; E[id].w = w;
    E[id].next = head[u]; 
    head[u] = id++;
}

void getMap() {
    memset(head, -1, sizeof(int) * (N + 1));
    int u, v, w; id = 0;
    while(M--) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, w);
        addEdge(v, u, w);
    }
    while(W--) {
        scanf("%d%d%d", &u, &v, &w);
        addEdge(u, v, -w);
    }
}

bool SPFA() {
    int i, j, u, v, w;
    queue<int> Q;
    for(i = 1; i <= N; ++i) {
        vis[i] = 1; out[i] = 0;
        dist[i] = 0; Q.push(i);
    }
    while(!Q.empty()) {
        u = Q.front(); Q.pop(); 
        if(++out[u] > N)
            return false; 
        vis[u] = 0;
        for(i = head[u]; i != -1; i = E[i].next) {
            v = E[i].v; w = E[i].w;
            if(dist[v] > dist[u] + w) {
                dist[v] = dist[u] + w;
                if(!vis[v]) {
                    vis[v] = 1;
                    Q.push(v);
                }
            }
        }
    }
    return true;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &N, &M, &W);
        getMap();
        printf(SPFA() ? "NO\n" : "YES\n");
    }
    return 0;
}