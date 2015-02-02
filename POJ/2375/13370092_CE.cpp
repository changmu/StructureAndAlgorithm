#include <stdio.h>
#include <string.h>
#define maxn 502

int map[maxn][maxn], scc[maxn][maxn];
int sccNum, id, head[maxn * maxn], n, m;
bool vis[maxn * maxn][maxn * maxn], in[maxn * maxn], out[maxn * maxn];
struct Node{
    int to, next;
} E[maxn * maxn << 2];

void addEdge(int u, int v)
{
    E[id].to = v;
    E[id].next = head[u];
    head[u] = id++;
}

void getMap(int n, int m)
{
    int i, j; id = 0;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j)
            scanf("%d", &map[i][j]);
}

void DFS(int x, int y)
{
    if(scc[x][y]) return;
    scc[x][y] = sccNum;    
    if(x + 1 <= n && map[x+1][y] == map[x][y]) DFS(x + 1, y);
    if(x - 1 >= 0 && map[x-1][y] == map[x][y]) DFS(x - 1, y);
    if(y + 1 <= m && map[x][y+1] == map[x][y]) DFS(x, y + 1);
    if(y - 1 >= 0 && map[x][y-1] == map[x][y]) DFS(x, y - 1);
}

void solve(int n, int m)
{
    memset(scc, 0, sizeof(scc));
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(vis, 0, sizeof(vis));
    memset(head, -1, sizeof(head));
    sccNum = 0;
    int i, j, ans1 = 0, ans2 = 0;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j)
            if(!scc[i][j]){
                ++sccNum; DFS(i, j);
            }
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= m; ++j){
            if(i + 1 <= n && scc[i][j] != scc[i+1][j] && !vis[scc[i][j]][scc[i+1][j]]){
                if(map[i][j] > map[i+1][j]){
                    addEdge(scc[i][j], scc[i+1][j]);
                    in[scc[i+1][j]] = out[scc[i][j]] = 1;
                } else{
                    addEdge(scc[i+1][j], scc[i][j]);
                    in[scc[i][j]] = out[scc[i+1][j]] = 1;
                }
                vis[scc[i][j]][scc[i+1][j]] = vis[scc[i+1][j]][scc[i][j]] = 1;
            }
            if(j + 1 <= m && scc[i][j] != scc[i][j+1] && !vis[scc[i][j]][scc[i][j+1]]){
                if(map[i][j] > map[i][j+1]){
                    addEdge(scc[i][j], scc[i][j+1]);
                    in[scc[i][j+1]] = out[scc[i][j]] = 1;
                } else{
                    addEdge(scc[i][j+1], scc[i][j]);
                    in[scc[i][j]] = out[scc[i][j+1]] = 1;
                }
                vis[scc[i][j]][scc[i][j+1]] = vis[scc[i][j+1]][scc[i][j]] = 1;
            }
        }
    if(sccNum != 1)
        for(i = 1; i <= sccNum; ++i){
            if(!in[i]) ++ans1;
            if(!out[i]) ++ans2;
        }
    if(ans1 < ans2) ans1 = ans2;
    printf("%d\n", ans1);
}

int main()
{
    while(scanf("%d%d", &m, &n) == 2){
        getMap(n, m);
        solve(n, m);
    }
    return 0;
}
