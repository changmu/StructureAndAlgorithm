#include <stdio.h>
#include <string.h>
#define inf 0x7fffffff
#define maxn 100002
#define maxm 1000002

int in[maxn], id, cost[maxn], sta[maxn];
struct Node2{
    int v, first;
} head[maxn];
struct Node{
    int to, next;
} E[maxm];
bool vis[maxn];

void addEdge(int u, int v)
{
    E[id].to = v; E[id].next = head[u].first;
    head[u].first = id++;
}

void getMap(int n, int m)
{
    int i, u, v;
    for(i = 1; i <= n; ++i){
        scanf("%d", &head[i].v);
        head[i].v *= -1; in[i] = 0;
        head[i].first = -1; 
        vis[i] = 0; cost[i] = inf;
    }
    for(i = id = 0; i < m; ++i){
        scanf("%d%d", &u, &v);
        addEdge(v, u); ++in[u];
    }
}

void DAG(int n)
{
    int i, u, v, id2 = 0, ans = inf, tmp;
    for(i = 1; i <= n; ++i)
        if(!in[i]){
            sta[id2++] = i; vis[i] = 1;
            cost[i] = head[i].v;
            if(cost[i] < ans) ans = cost[i];
        }
    while(id2){
        u = sta[--id2]; vis[u] = 0;
        for(i = head[u].first; i != -1; i = E[i].next){
            v = E[i].to; tmp = cost[u] + head[v].v;
            if(tmp < cost[v]){
                cost[v] = tmp;
                if(!vis[v]){
                    vis[v] = 1; sta[id2++] = v;
                }
                if(tmp < ans) ans = tmp;
            }
        }
    }
    //if(ans < 0) ans = - ans;
    printf("%d\n", -ans);
}

int main()
{
    int n, m, i, u, v;
    while(scanf("%d%d", &n, &m) == 2){
        getMap(n, m);
        DAG(n);
    }
    return 0;
}