#include <stdio.h>
#include <string.h>
#define inf 0x3fffffff
#define maxn 250

int m, n, sink, ssource, ssink; // m rows, n columns
int G[maxn][maxn], G0[maxn][maxn], flow[maxn][maxn];
int low[maxn][maxn], high[maxn][maxn];
int in[maxn], out[maxn], Layer[maxn], que[maxn];
bool vis[maxn];

int min(int a, int b) {
    return a > b ? b : a;
}

int max(int a, int b) {
    return a < b ? b : a;
}

bool countLayer() {
    memset(Layer, 0, sizeof(Layer));
    int i, now, id = 0, front = 0;
    Layer[ssource] = 1; que[id++] = ssource;
    while(front < id) {
        now = que[front++];
        for(i = 0; i <= ssink; ++i)
            if(G[now][i] > 0 && !Layer[i]) {
                Layer[i] = Layer[now] + 1;
                if(i == ssink) return true;
                else que[id++] = i;
            }
    }
    return false;
}

int Dinic() {
    int maxFlow = 0, minCut, pos, i, now, u, v, id = 0;
    while(countLayer()) {
        memset(vis, 0, sizeof(vis));
        vis[ssource] = 1; que[id++] = ssource;
        while(id) {
            now = que[id - 1];
            if(now == ssink) {
                minCut = inf;
                for(i = 1; i < id; ++i) {
                    u = que[i - 1];
                    v = que[i];
                    if(minCut > G[u][v]) {
                        minCut = G[u][v];
                        pos = u;
                    }
                }
                maxFlow += minCut;
                for(i = 1; i < id; ++i) {
                    u = que[i - 1];
                    v = que[i];
                    G[u][v] -= minCut;
                    G[v][u] += minCut;
                }
                while(que[id - 1] != pos)
                    vis[que[--id]] = 0;
            } else {
                for(i = 0; i <= ssink; ++i) {
                    if(G[now][i] > 0 && Layer[now] + 1 == Layer[i] && !vis[i]) {
                        vis[i] = 1; que[id++] = i; break;
                    }
                }
                if(i > ssink) --id;
            }
        }
    }
    return maxFlow;
}

void solve() {
    int i, j, sum = 0;
    for(i = 0; i <= sink; ++i)
        for(j = 0; j <= sink; ++j) {
            G[i][j] = high[i][j] - low[i][j];
            out[i] += low[i][j];
            in[j] += low[i][j];
            sum += low[i][j];
        }
    for(i = 0; i <= sink; ++i) {
        G[ssource][i] = in[i];
        G[i][ssink] = out[i];
    }
    memcpy(G0, G, sizeof(G));
    G[sink][0] = inf;
    if(sum != Dinic()) {
        printf("IMPOSSIBLE\n");
        return;
    }
    G[sink][0] = G[0][sink] = 0;
    for(i = 1; i <= m; ++i) {
        printf("%d", G0[i][1 + m] - G[i][1 + m] + low[i][1 + m]);
        for(j = 2; j <= n; ++j)
            printf(" %d", G0[i][j + m] - G[i][j + m] + low[i][j + m]);
        printf("\n");
    }
}

int main() {
    //freopen("stdin.txt", "r", stdin);
     // freopen("POJ2396.txt", "r", stdin);
     // freopen("ans1.txt", "w", stdout);
    int t, c, x, y, z, i, j;
    char ch;
    scanf("%d", &t);
    while(t--) {
        memset(G, 0, sizeof(G));
        memset(low, 0, sizeof(low));
        memset(high, 0, sizeof(high));
        memset(out, 0, sizeof(out));
        memset(in, 0, sizeof(in));
        memset(flow, 0, sizeof(flow));
        scanf("%d%d", &m, &n);
        sink = m + n + 1;
        ssource = sink + 1;
        ssink = ssource + 1;
        for(i = 1; i <= m; ++i) {
            scanf("%d", &z);
            low[0][i] = high[0][i] = z;
        }
        for(i = 1; i <= n; ++i) {
            scanf("%d", &z);
            low[m + i][sink] = high[m + i][sink] = z;
        }
        for(i = 1; i <= m; ++i) {
            for(j = 1; j <= n; ++j) {
                high[i][j + m] = inf;
            }
        }
        scanf("%d", &c);
        while(c--) {
            scanf("%d%d %c %d", &x, &y, &ch, &z);
            if(!x && y) { // 所有行的第y个元素
                if(ch == '=') {
                    for(i = 1; i <= m; ++i)
                        low[i][m + y] = high[i][m + y] = z;
                } else if(ch == '<') {
                    for(i = 1; i <= m; ++i)
                        high[i][m + y] = min(z - 1, high[i][m + y]);
                } else {
                    for(i = 1; i <= m; ++i)
                        low[i][m + y] = max(z + 1, low[i][m + y]);
                }
            } else if(x && !y) {
                if(ch == '=') {
                    for(i = 1; i <= n; ++i)
                        low[x][m + i] = high[x][m + i] = z;
                } else if(ch == '<') {
                    for(i = 1; i <= n; ++i)
                        high[x][m + i] = min(high[x][m + i], z - 1);
                } else {
                    for(i = 1; i <= n; ++i)
                        low[x][m + i] = max(low[x][m + i], z + 1);
                }
            } else if(!x && !y) {
                for(i = 1; i <= m; ++i)
                    for(j = 1; j <= n; ++j) {
                        if(ch == '=')
                            low[i][m + j] = high[i][m + j] = z;
                        else if(ch == '<')
                            high[i][m + j] = min(high[i][m + j], z - 1);
                        else low[i][m + j] = max(low[i][m + j], z + 1);
                    }
            } else {
                if(ch == '=')
                    low[x][m + y] = high[x][m + y] = z;
                else if(ch == '<')
                    high[x][m + y] = min(high[x][m + y], z - 1);
                else low[x][m + y] = max(low[x][m + y], z + 1);
            }
        }
        solve();
        printf("\n");
    }
    return 0;
}
