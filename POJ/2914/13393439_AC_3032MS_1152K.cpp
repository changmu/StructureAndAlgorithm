#include <stdio.h>
#include <string.h>
#define inf 0x7fffffff
#define maxn 502

int map[maxn][maxn], W[maxn], hash[maxn];
bool vis[maxn];

void getMap(int n, int m)
{
    int i, u, v, c;
    memset(map, 0, sizeof(map));
    for(i = 0; i < m; ++i){
        scanf("%d%d%d", &u, &v, &c);
        map[u][v] += c; map[v][u] += c;
    }
}

int Stoer_Wagner(int n)
{
    int minCut = inf, nowCut, now, pre, i, j;
    for(i = 0; i < n; ++i) hash[i] = i;
    while(n > 1){
        nowCut = -1; now = 1; vis[hash[0]] = 1; pre = 0;
        for(i = 1; i < n; ++i){
            W[hash[i]] = map[hash[0]][hash[i]];
            vis[hash[i]] = 0;
            if(W[hash[i]] > nowCut){
                nowCut = W[hash[i]]; now = i;
            }
        }
        for(j = 1; j < n; ++j){
            vis[hash[now]] = 1;
            if(j == n - 1){
                if(nowCut < minCut) minCut = nowCut;
                for(i = 0; i < n; ++i){
                    map[hash[pre]][hash[i]] += map[hash[now]][hash[i]];
                    map[hash[i]][hash[pre]] += map[hash[now]][hash[i]];
                }
                hash[now] = hash[--n];
                break;
            }
            pre = now; nowCut = -1;
            for(i = 1; i < n; ++i){
                if(!vis[hash[i]]){
                    W[hash[i]] += map[hash[pre]][hash[i]];
                    if(W[hash[i]] > nowCut){
                        nowCut = W[hash[i]]; now = i;
                    }
                }
            }
        }
    }
    return minCut;
}

void solve(int n)
{
    printf("%d\n", Stoer_Wagner(n));
}

int main()
{
    //freopen("stdin.txt", "r", stdin);
    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        getMap(n, m);
        solve(n);
    }
    return 0;
}