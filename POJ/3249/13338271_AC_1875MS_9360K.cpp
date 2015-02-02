#include <stdio.h>
#include <string.h>
#define inf 0x7fffffff
#define maxn 100002
#define maxm 1000002

int dp[maxn], val[maxn], id;
int head[maxn];
struct Node{
    int to, next;
} E[maxm];
bool in[maxn], out[maxn];

void addEdge(int u, int v)
{
    E[id].to = v; 
    E[id].next = head[u];
    head[u] = id++;
}

void getMap(int n, int m)
{
    int i, u, v;
    for(i = 1, id = 0; i <= n; ++i){
        scanf("%d", &val[i]);
        in[i] = out[i] = 0; dp[i] = -inf;
        head[i] = -1;
    }
    for(i = 0; i < m; ++i){
        scanf("%d%d", &u, &v);
        addEdge(u, v); in[v] = out[u] = 1;
    }
}

int DFS(int k)
{
    if(dp[k] != -inf) return dp[k];
    int i, ans = -inf, tmp;
    for(i = head[k]; i != -1; i = E[i].next){
        tmp = DFS(E[i].to);
        if(tmp > ans) ans = tmp;
    }
    dp[k] = ans + val[k];
    return dp[k];
}

void solve(int n)
{
    int i, ans = -inf, tmp;
    for(i = 1; i <= n; ++i)
        if(!out[i]) dp[i] = val[i];
    for(i = 1; i <= n; ++i){
        if(!in[i]){
            tmp = DFS(i);
            if(tmp > ans) ans = tmp;
        }
    }
    printf("%d\n", ans);
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
