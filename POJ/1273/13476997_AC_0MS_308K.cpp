#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 202
#define inf 0x7fffffff
using std::queue;

int G[maxn][maxn], Layer[maxn];
int Sta[maxn];
bool vis[maxn];

bool countLayer(int m) {
    queue<int> Q; Q.push(1);
    memset(Layer, 0, sizeof(int) * (m + 1));
    int i, now;
    Layer[1] = 1;
    while(!Q.empty()) {
        now = Q.front(); Q.pop();
        for(i = 1; i <= m; ++i) {
            if(G[now][i] && !Layer[i]) {
                Layer[i] = Layer[now] + 1;
                if(m == i) return true;
                else Q.push(i);
            }
        }
    }
    return false;
}

int Dinic(int m) {
    int minCut, minCutPos, maxFlow = 0;
    int s, t, i, id = 0, now;
    while(countLayer(m)) {
        memset(vis, 0, sizeof(bool) * (m + 1));
        vis[1] = 1; Sta[id++] = 1;
        while(id) {
            //栈中需要存放路径，所以不出栈
            now = Sta[id - 1];
            if(now == m) {
                minCut = inf;
                for(i = 1; i < id; ++i) {
                    s = Sta[i - 1];
                    t = Sta[i];
                    if(G[s][t] && G[s][t] < minCut) {
                        minCut = G[s][t];
                        minCutPos = s;
                    }
                }
                //增广，添加取消流
                maxFlow += minCut;
                for(i = 1; i < id; ++i) {
                    s = Sta[i - 1]; t = Sta[i];
                    G[s][t] -= minCut;
                    G[t][s] += minCut;
                }
                //出栈到最小割位置
                while(id && Sta[id - 1] != minCutPos) {
                    vis[Sta[--id]] = 0;
                }
            } else {
                for(i = 1; i <= m; ++i) {
                    if(G[now][i] && !vis[i] && Layer[now] + 1 == Layer[i]) {
                        Sta[id++] = i; vis[i] = 1;
                        break;
                    }
                }
                if(i > m) --id;
            }
        }
    }
    return maxFlow;
}

int main() {
    //freopen("stdin.txt", "r", stdin);
    int n, m, i, s, t, c;
    while(scanf("%d%d", &n, &m) == 2) {
        memset(G, 0, sizeof(G));
        for(i = 0; i < n; ++i) {
            scanf("%d%d%d", &s, &t, &c);
            G[s][t] += c;
        }
        printf("%d\n", Dinic(m));
    }
    return 0;
}