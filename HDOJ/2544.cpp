////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-27 16:17:27
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 2544
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:248KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 102

const int maxint = 1000000000;
int n, m;
int map[maxn][maxn], dist[maxn];
bool vis[maxn];

int getNextNode()
{
    int i, tmp = maxint, u = -1;
    for(i = 1; i <= n; ++i)
        if(!vis[i] && dist[i] != -1 && dist[i] < tmp){
            tmp = dist[i]; u = i;
        }
    return u;
}

void Dijkstra(int start, int end)
{
    memset(dist, -1, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    int i, tmp, u;
    u = start; dist[u] = 0;
    while(u != -1){
        for(i = 1; i <= n; ++i){
            if(map[u][i] != -1){
                tmp = dist[u] + map[u][i];
                if(dist[i] == -1 || tmp < dist[i])
                    dist[i] = tmp;
            }
        }
        vis[u] = true;
        if(vis[end]) return;
        u = getNextNode();
    }
}

int main()
{
    int i, a, b, x;
    while(scanf("%d%d", &n, &m) != EOF && (n || m)){
        memset(map, -1, sizeof(map));
        for(i = 0; i < m; ++i){
            scanf("%d%d%d", &a, &b, &x);
            if(map[a][b] != -1 && map[a][b] < x) continue;
            map[a][b] = map[b][a] = x;
        }
        Dijkstra(1, n);
        printf("%d\n", dist[n]);
    }
    return 0;
}