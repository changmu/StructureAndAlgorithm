#include <stdio.h>
#include <string.h>
#define inf 0x3fffffff
#define maxn 235

int dist[maxn][maxn], k, c, m, n;
int G[maxn][maxn], Layer[maxn];
int queue[maxn], maxDist;
bool vis[maxn];

void Floyd() {
    int x, i, j;
    maxDist = 200;
    for(x = 1; x <= n; ++x)
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
                if(dist[i][j] > dist[i][x] + dist[x][j]) {
                    dist[i][j] = dist[i][x] + dist[x][j];
                    if(maxDist < dist[i][j]) maxDist = dist[i][j];
                }
}

void build(int flow) {
    memset(G, 0, sizeof(G));
    int i, j;
    for(i = k + 1; i <= n; ++i) {
        G[0][i] = 1;
        for(j = 1; j <= k; ++j)
            if(dist[i][j] <= flow)
                G[i][j] = 1;
    }
    for(j = 1; j <= k; ++j)
        G[j][n + 1] = m;
}

bool countLayer() {
    int id = 0, front = 0, now, i;
    memset(Layer, 0, sizeof(Layer));
    Layer[0] = 1; queue[id++] = 0;
    while(front < id) {
        now = queue[front++];
        for(i = 0; i <= n + 1; ++i)
            if(G[now][i] && !Layer[i]) {
                Layer[i] = Layer[now] + 1;
                if(i == n + 1) return true;
                else queue[id++] = i;
            }
    }
    return false;
}

bool Dinic() {
    int i, maxFlow = 0, id = 0, now, minCut, pos, u, v;
    while(countLayer()) {
        memset(vis, 0, sizeof(vis));
        vis[0] = 1; queue[id++] = 0;
        while(id) {
            now = queue[id - 1];
            if(now == n + 1) {
                minCut = inf;
                for(i = 1; i < id; ++i) {
                    u = queue[i - 1];
                    v = queue[i];
                    if(G[u][v] < minCut) {
                        minCut = G[u][v];
                        pos = u;
                    } 
                }
                maxFlow += minCut;
                for(i = 1; i < id; ++i) {
                    u = queue[i - 1];
                    v = queue[i];
                    G[u][v] -= minCut;
                    G[v][u] += minCut;
                }
                while(id && queue[id - 1] != pos)
                    vis[queue[--id]] = 0;
            } else {
                for(i = 0; i <= n + 1; ++i) {
                    if(G[now][i] && !vis[i] && Layer[now] + 1 == Layer[i]) {
                        queue[id++] = i;
                        vis[i] = 1; break;
                    }
                }
                if(i > n + 1) --id;
            }
        }
    }
    return maxFlow == c;
}

int binarySolve() {
    int left = 0, right = maxDist, mid;
    while(left < right) {
        mid = (left + right) >> 1;
        build(mid);
        if(Dinic()) right = mid;
        else left = mid + 1;
    }
    return left;
}

int main() {
    //freopen("stdin.txt", "r", stdin);
    int i, j;
    while(scanf("%d%d%d", &k, &c, &m) == 3) {
        for(i = 1, n = k + c; i <= n; ++i)
            for(j = 1; j <= n; ++j) {
                scanf("%d", &dist[i][j]);
                if(!dist[i][j] && i != j)
                    dist[i][j] = inf;
            }
        Floyd();
        printf("%d\n", binarySolve());
    }
    return 0;
}