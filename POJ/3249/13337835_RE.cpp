#include <stdio.h>
#include <string.h>
#define inf 0x7fffffff
#define maxn 100002
#define maxm 1000002

long long dp[maxn]; int id;
struct Node2{
    int first, v;
} head[maxn];
struct Node{
    int to, next;
} E[maxm];
bool in[maxn], out[maxn];

void addEdge(int u, int v)
{
    E[id].to = v; 
    E[id].next = head[u].first;
    head[u].first = id++;
}

void getMap(int n, int m)
{
    int i, u, v;
    for(i = 1; i <= n; ++i){
        scanf("%d", &head[i].v);
        in[i] = out[i] = 0; dp[i] = -inf;
        head[i].first = -1;
    }
    for(i = 0; i < m; ++i){
        scanf("%d%d", &u, &v);
        addEdge(u, v); in[v] = 1; out[u] = 1;
    }
}

long long DFS(int k)
{
    if(dp[k] != -inf) return dp[k];
    int i; long long ans = -inf, tmp;
    for(i = head[k].first; i != -1; i = E[i].next){
        tmp = head[k].v + DFS(E[i].to);
        if(tmp > ans) ans = tmp;
    }
    return dp[k] = ans;
}

void solve(int n)
{
    int i; long long ans = -inf, tmp;
    for(i = 1; i <= n; ++i)
        if(!out[i]) dp[i] = head[i].v;
    for(i = 1; i <= n; ++i){
        if(!in[i]){
            tmp = DFS(i);
            if(tmp > ans) ans = tmp;
        }
    }
    printf("%lld\n", ans);
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