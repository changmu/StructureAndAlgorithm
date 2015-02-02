#include <stdio.h>
#include <string.h>
#define inf 0x3fffffff
#define maxn 110
#define maxm 1002

int pig[maxm], m, n, sink;
int G[maxn][maxn], queue[maxn];
bool vis[maxn]; int Layer[maxn];

bool countLayer() {
    memset(Layer, 0, sizeof(Layer));
    int id = 0, front = 0, now, i; 
    Layer[0] = 1; queue[id++] = 0;
    while(front < id) {
        now = queue[front++];
        for(i = 0; i <= sink; ++i)
            if(G[now][i] && !Layer[i]) {
                Layer[i] = Layer[now] + 1;
                if(i == sink) return true;
                else queue[id++] = i;
            }
    }
    return false;
}

int Dinic() {
    int minCut, pos, maxFlow = 0;
    int i, id = 0, u, v, now;
    while(countLayer()) {
        memset(vis, 0, sizeof(vis));
        vis[0] = 1; queue[id++] = 0;
        while(id) {
            now = queue[id - 1];
            if(now == sink) {
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
                while(queue[id - 1] != pos)
                    vis[queue[--id]] = 0;
            } else {
                for(i = 0; i <= sink; ++i) {
                    if(G[now][i] && Layer[now] + 1 == Layer[i] && !vis[i]) {
                        vis[i] = 1; queue[id++] = i; break;
                    }
                }
                if(i > sink) --id;
            }
        }
    }
    return maxFlow;
}

int main() {
    //freopen("stdin.txt", "r", stdin);
    int i, keys, num;
    while(scanf("%d%d", &m, &n) == 2) {
        sink = n + 1;
        for(i = 1; i <= m; ++i)
            scanf("%d", &pig[i]);
        memset(G, 0, sizeof(G));
        for(i = 1; i <= n; ++i) {
            scanf("%d", &keys);
            while(keys--) {
                scanf("%d", &num);
                if(pig[num] >= 0) {
                    G[0][i] += pig[num]; // 0 is source
                    pig[num] = -i; // 这里是标记第num个猪圈联通的第一个人
                } else G[-pig[num]][i] = inf;
            }
            scanf("%d", &G[i][sink]);
        }
        printf("%d\n", Dinic());
    }
    return 0;
}