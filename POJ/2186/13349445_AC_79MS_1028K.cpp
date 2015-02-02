#include <stdio.h>
#include <string.h>
#define maxn 10002
#define maxm 50002

int head0[maxn], head1[maxn], id;
int count[maxn], num[maxn], hash[maxn];
struct Node{
    int t0, next0, t1, next1;
} E[maxm];
bool vis[maxn], out[maxn];

void addEdge(int u, int v)
{
    E[id].t0 = v; E[id].next0 = head0[u];
    head0[u] = id; E[id].t1 = u;
    E[id].next1 = head1[v]; head1[v] = id++;
}

void getMap(int n, int m)
{
    int i, u, v; id = 0;
    memset(head0, -1, sizeof(int) * (n + 1)); //save time
    memset(head1, -1, sizeof(int) * (n + 1));
    for(i = 0; i < m; ++i){
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
}

void DFS0(int pos, int& sig)
{
    vis[pos] = 1; int i;
    for(i = head0[pos]; i != -1; i = E[i].next0){
        if(!vis[E[i].t0]) DFS0(E[i].t0, sig);
    }
    num[++sig] = pos;
}

void DFS1(int pos, int sig)
{
    vis[pos] = 1; hash[pos] = sig;
    int i; ++count[sig];
    for(i = head1[pos]; i != -1; i = E[i].next1){
        if(!vis[E[i].t1]) DFS1(E[i].t1, sig);
        else if(hash[E[i].t1] != hash[pos]) out[hash[E[i].t1]] = 1;
    }
}

void solve(int n) //Kosaraju
{
    int i, sig = 0, tmp = 0, ans;
    memset(vis, 0, sizeof(bool) * (n + 1));
    for(i = 1; i <= n; ++i)
        if(!vis[i]) DFS0(i, sig);
    memset(vis, 0, sizeof(bool) * (n + 1));
    memset(count, 0, sizeof(int) * (n + 1));
    memset(out, 0, sizeof(bool) * (n + 1));
    i = sig; sig = 0;
    for(; i; --i)
        if(!vis[num[i]]) DFS1(num[i], ++sig);
    for(i = 1; i <= sig; ++i)
        if(!out[i]) ++tmp, ans = count[i];
    //printf("sig%d\n", sig);
    if(tmp == 1) printf("%d\n", ans);
    else printf("0\n");
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