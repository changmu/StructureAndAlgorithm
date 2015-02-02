#include <stdio.h>
#include <string.h>
#include <queue>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

#define maxn 5010
#define maxm 200010
#define inf 0x3f3f3f3f

int N, R, head[maxn], id;
struct Node {
    int v, w, next;
} E[maxm];
int dis[maxn], dis2[maxn];
typedef pair<int, int> P;


void addEdge(int u, int v, int w) {
    E[id].v = v; E[id].w = w;
    E[id].next = head[u];
    head[u] = id++;
}

void getMap() {
    int a, b, c; id = 0;
    memset(head, -1, sizeof(int) * (N + 1));
    while(R--) {
        scanf("%d%d%d", &a, &b, &c);
        addEdge(a, b, c);
        addEdge(b, a, c);
    }
}

void Dijkstra() {
    int u = 1, v, d, d2, i;
    P now;
    for(i = 1; i <= N; ++i) {
        dis[i] = dis2[i] = inf;
    }
    priority_queue<P, vector<P>, greater<P> > pq;
    dis[u] = 0;
    pq.push(P(0, u));
    while(!pq.empty()) {
        now = pq.top(); pq.pop();
        d = now.first;
        u = now.second;
        if(d > dis2[u]) continue;

        for(i = head[u]; i != -1; i = E[i].next) {
            v = E[i].v;
            d2 = d + E[i].w;
            if(d2 < dis[v]) {
                swap(dis[v], d2);
                pq.push(P(dis[v], v));
            }
            if(dis2[v] > d2 && dis[v] < d2) {
                dis2[v] = d2;
                pq.push(P(dis2[v], v));
            }
        }
    }
    printf("%d\n", dis2[N]);
}

int main() {
    while(scanf("%d%d", &N, &R) == 2) {
        getMap();
        Dijkstra();
    }
    return 0;
}
