////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-07-27 15:36:20
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1874
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:368KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 202

const int maxint = 100000000;
int n, m; 
int dist[maxn], map[maxn][maxn];
bool vis[maxn];

int getNextNode()
{
    int i, tmp = maxint, u = -1;
    for(i = 0; i < n; ++i){
        if(dist[i] != -1 && !vis[i] && dist[i] < tmp){
            tmp = dist[i]; u = i;
        }
    }
    return u;
}

void Dijkstra(int start, int end)
{    
    memset(dist, -1, sizeof(dist));
    memset(vis, 0, sizeof(vis));
    int i, tmp, u;
    dist[start] = 0; vis[start] = true;
    for(i = 0; i < n; ++i){
        if(map[start][i] != -1) 
            dist[i] = map[start][i];
    }
    u = getNextNode();
    while(u != -1){
        for(i = 0; i < n; ++i){
            if(map[u][i] != -1 && !vis[i]){
                tmp = dist[u] + map[u][i];
                if(dist[i] == -1 || dist[i] > tmp)
                    dist[i] = tmp;
            }                
        }
        vis[u] = true;        
        u = getNextNode();
    }
}

int main()
{
    int i, a, b, x, s, t;
    while(scanf("%d%d", &n, &m) != EOF){  
        memset(map, -1, sizeof(map));      
        for(i = 0; i < m; ++i){
            scanf("%d%d%d", &a, &b, &x);
            if(map[a][b] != -1 && x > map[a][b])
                continue;
            map[a][b] = map[b][a] = x;
        }
        scanf("%d%d", &s, &t);
        Dijkstra(s, t);
        printf("%d\n", dist[t]);
    }
    return 0;
}