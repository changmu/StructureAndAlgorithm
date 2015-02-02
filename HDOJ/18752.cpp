////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-08-17 13:12:39
////Compiler: GUN C++
//////////////////////////////////////////////////////
////Problem ID: 1875
////Problem Title: 
////Run result: Accept
////Run time:31MS
////Run memory:332KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#include <math.h>
#define maxn 102
#define maxm (maxn * maxn) >> 1
#define inf 0x3f3f3f3f

struct Node2{
    int x, y;
} V[maxn];
struct Node{
    int u, v;
    double d;
} E[maxm];
double ans, dist[maxn], map[maxn][maxn];
bool vis[maxn];

double calDist(int i, int j)
{
    double x = V[i].x - V[j].x;
    double y = V[i].y - V[j].y;
    return sqrt(x * x + y * y);
}

int getNext(int n)
{
    int u = -1, i;
    double tmp = inf;
    for(i = 1; i <= n; ++i)
        if(!vis[i] && dist[i] < tmp){
            tmp = dist[i]; u = i;
        }
    return u;
}

bool Prim(int n)
{
    int i, u, v, count = 0;
    double tmp; ans = 0.0;
    for(i = 1; i <= n; ++i){
        vis[i] = 0; dist[i] = inf;
        if(map[1][i] >= 10.0 && map[1][i] <= 1000.0)
            dist[i] = map[1][i];
    }
    u = 1; dist[u] = 0.0; vis[u] = 1;
    u = getNext(n);
    while(count < n - 1){
        if(u == -1) return false;
        vis[u] = 1; ans += dist[u]; ++count;
        for(i = 1; i <= n; ++i)
            if(!vis[i] && map[u][i] <= 1000.0 && map[u][i] >= 10.0 && dist[i] > map[u][i]){
                dist[i] = map[u][i];
            }        
        u = getNext(n);
    }
    return true;
}

int main()
{
    int t, n, i, j;
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(i = 1; i <= n; ++i)
            scanf("%d%d", &V[i].x, &V[i].y);
        for(i = 1; i < n; ++i)
            for(j = i + 1; j <= n; ++j)
                map[i][j] = map[j][i] = calDist(i, j);
        if(!Prim(n)) printf("oh!\n");
        else printf("%.1lf\n", ans * 100.0);
    }
}