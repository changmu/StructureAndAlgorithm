#include <stdio.h>
#include <string.h>
#include <queue>
#define maxn 102
using std::queue;

int head[maxn], id, dist[maxn], out[maxn];
struct Node{
    int to, w, next;
} E[maxn];
bool vis[maxn];

void addEdge(int u, int v, int w)
{
    E[id].to = v; E[id].w = w;
    E[id].next = head[u]; head[u] = id++;
}

void getMap(int n, int m)
{
    int i, u, v, t; char str[5];
    memset(head, -1, sizeof(head));
    for(i = id = 0; i < m; ++i){
        scanf("%d%d%s%d", &u, &v, str, &t);
        if(str[0] == 'g') addEdge(u-1, u+v, t+1);
        else addEdge(u+v, u-1, 1-t);
    }
}

bool SPFA(int n)
{
    int i, u, v, tmp;
    queue<int> Q;
    for(i = 0; i <= n; ++i){
        out[i] = 0; vis[i] = 1;
        dist[i] = 0; Q.push(i);
    }
    while(!Q.empty()){
        u = Q.front(); Q.pop(); vis[u] = 0;
        if(++out[u] > n + 1) return false;
        for(i = head[u]; i != -1; i = E[i].next){
            tmp = dist[u] + E[i].w; v = E[i].to;
            if(tmp > dist[v]){
                dist[v] = tmp;
                if(!vis[v]){
                    vis[v] = 1; Q.push(v);
                }
            }
        }
    }
    return true;
}

int main()
{
    int n, m;
    while(scanf("%d%d", &n, &m) == 2){
        getMap(n, m);
        if(SPFA(n)) printf("lamentable kingdom\n");
        else printf("successful conspiracy\n");
    }
    return 0;
}