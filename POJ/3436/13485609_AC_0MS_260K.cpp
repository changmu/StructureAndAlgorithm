#include <stdio.h>
#include <string.h>
#define maxn 55
#define inf 0x3fffffff

struct Node {
    int in[10], out[10]; // 拆点
    int Q; // 容量
} M[maxn];
int G[maxn << 1][maxn << 1], que[maxn << 1], m, n, mp;
int G0[maxn << 1][maxn << 1], deep[maxn << 1], vis[maxn << 1];

bool equals(int a[], int b[]) {
    for(int k = 0; k < n; ++k) {
        if(a[k] != 2 && b[k] != 2 && a[k] != b[k])
            return false;
    }
    return true;
}

bool countLayer() {
    int i, id = 0, now, front = 0;
    memset(deep, 0, sizeof(deep));
    deep[0] = 1; que[id++] = 0;
    while(front < id) {
        now = que[front++];
        for(i = 0; i <= mp; ++i)
            if(G[now][i] && !deep[i]) {
                deep[i] = deep[now] + 1;
                if(i == mp) return true;
                que[id++] = i;
            }
    }
    return false;
}

int Dinic() {
    int i, id = 0, maxFlow = 0, minCut, pos, u, v, now;
    while(countLayer()) {
        memset(vis, 0, sizeof(vis));
        vis[0] = 1; que[id++] = 0;
        while(id) {
            now = que[id - 1];
            if(now == mp) {
                minCut = inf;
                for(i = 1; i < id; ++i) {
                    u = que[i - 1]; v = que[i];
                    if(G[u][v] < minCut) {
                        minCut = G[u][v]; pos = u;
                    }
                }
                maxFlow += minCut;
                for(i = 1; i < id; ++i) {
                    u = que[i - 1]; v = que[i];
                    G[u][v] -= minCut;
                    G[v][u] += minCut;
                }
                while(id && que[id - 1] != pos)
                    vis[que[--id]] = 0;                
            } else {
                for(i = 0; i <= mp; ++i) {
                    if(G[now][i] && deep[now] + 1 == deep[i] && !vis[i]) {
                        que[id++] = i; vis[i] = 1; break;
                    }
                }
                if(i > mp) --id;
            }
        } 
    }
    return maxFlow;
}

int main() {
    //freopen("stdin.txt", "r", stdin);
    int i, j, sum, count;
    while(scanf("%d%d", &n, &m) == 2) {
        memset(G, 0, sizeof(G));
        for(i = 1; i <= m; ++i) {
            scanf("%d", &M[i].Q);
            for(j = 0; j < n; ++j) scanf("%d", &M[i].in[j]);
            for(j = 0; j < n; ++j) scanf("%d", &M[i].out[j]);
            G[i][i + m] = M[i].Q;
        }
        // 连接出口跟入口
        for(i = 1; i <= m; ++i) {
            for(j = i + 1; j <= m; ++j) {
                if(equals(M[i].out, M[j].in))
                    G[i + m][j] = inf;
                if(equals(M[j].out, M[i].in))
                    G[j + m][i] = inf;
            }
        }
        // 设置超级源点和超级汇点
        for(i = 1; i <= m; ++i) { // 源点
            G[0][i] = inf;
            for(j = 0; j < n; ++j)
                if(M[i].in[j] == 1) {
                    G[0][i] = 0; break;
                }
        }
        mp = m << 1 | 1;
        for(i = 1; i <= m; ++i) { // 汇点
            G[i + m][mp] = inf;
            for(j = 0; j < n; ++j)
                if(M[i].out[j] != 1) {
                    G[i + m][mp] = 0; break;
                }
        }
        // 备份原图
        memcpy(G0, G, sizeof(G));
        sum = Dinic();
        count = 0;
        // 判断哪些路径有流走过
        for(i = m + 1; i < mp; ++i)
            for(j = 1; j <= m; ++j)
                if(G0[i][j] > G[i][j]) ++count;
        printf("%d %d\n", sum, count);
        // 输出机器间的关系
        if(count)
            for(i = m + 1; i < mp; ++i)
                for(j = 1; j <= m; ++j)
                    if(G0[i][j] > G[i][j])
                        printf("%d %d %d\n", i - m, j, G0[i][j] - G[i][j]);
    }
    return 0;
}
