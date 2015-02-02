#include <stdio.h>
#include <string.h>
#define inf 0x3f3f3f3f
#define maxn 102

int map[maxn][maxn], pre[maxn][maxn];
int dist[maxn][maxn], store[maxn], minCircle;

void getMap(int n, int m)
{
    int i, u, v, d;
    memset(map, 0x3f, sizeof(map));
    for(i = 0; i < m; ++i){
        scanf("%d%d%d", &u, &v, &d);
        if(d < map[u][v])
            map[u][v] = map[v][u] = d;
    }
    memcpy(dist, map, sizeof(map));
}

void solve(int n)
{
    int k, i, j, id, tmp; minCircle = inf;
    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j) pre[i][j] = j;
    for(k = 1; k <= n; ++k){
        for(i = 1; i <= n; ++i){
            for(j = 1; j <= n; ++j)
                if(i != j && dist[i][j] != inf && map[i][k] != inf && 
                    map[k][j] != inf && dist[i][j] + map[i][k] +
                    map[k][j] < minCircle){
                    minCircle = dist[i][j] + map[i][k] + map[k][j];
                    tmp = i; id = 0;
                    while(tmp != j){
                        store[id++] = tmp;
                        tmp = pre[tmp][j];
                    }
                    store[id++] = j; store[id++] = k;
                }
        }
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
                if(dist[i][k] != inf && dist[k][j] != inf && 
                    dist[i][k] + dist[k][j] < dist[i][j]){
                    dist[i][j] = dist[i][k] + dist[k][j];
                    pre[i][j] = pre[i][k];
                }
    }
    if(minCircle == inf){
        printf("No solution.\n"); return;
    }
    for(i = 0; i < id; ++i)
        if(i != id - 1) printf("%d ", store[i]);
        else printf("%d\n", store[i]);
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        getMap(n, m);
        solve(n);
    }
    return 0;
}