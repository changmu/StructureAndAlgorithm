#include <stdio.h>
#include <string.h>
#define maxn 10002
#define maxm 50002

int head[maxn], vis[maxn], id, id2, scc_num, sec;
int dfn[maxn], low[maxn], sta[maxn], count[maxn];
bool out[maxn];
struct Node{
    int to, next;
} E[maxm];

int min(int a, int b){
    return a < b ? a : b;
}

void addEdge(int u, int v)
{
    E[id].to = v; 
    E[id].next = head[u];
    head[u] = id++;
}

void getMap(int n, int m)
{
    int i, u, v; id = 0;
    memset(head, -1, sizeof(int) * (n + 1));
    memset(vis, 0, sizeof(int) * (n + 1));
    memset(out, 0, sizeof(bool) * (n + 1));
    memset(count, 0, sizeof(int) * (n + 1));
    for(i = 0; i < m; ++i){
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
}

void DFS(int pos) //å¼ºè¿žé€šåˆ†é‡å¿…å®šæ˜¯è¯¥æ ‘çš„å­æ ‘
{
    dfn[pos] = low[pos] = ++sec;
    vis[pos] = 1; sta[id2++] = pos;
    int i, u, v;
    for(i = head[pos]; i != -1; i = E[i].next){
        v = E[i].to;
        if(!vis[v]) DFS(v);
        if(vis[v] == 1)
            low[pos] = min(low[pos], low[v]);
    }
    if(dfn[pos] == low[pos]){
        ++scc_num;
        do{
            ++count[scc_num];
            u = sta[--id2];
            low[u] = scc_num;
            vis[u] = 2;
        } while(u != pos);
    }
}

void solve(int n) //Tarjan
{
    int i, j, ok = 0, ans; sec = id2 = scc_num = 0;
    for(i = 1; i <= n; ++i)
        if(!vis[i]) DFS(i);
    for(i = 1; i <= n; ++i)
        for(j = head[i]; j != -1; j = E[j].next)
            if(low[i] != low[E[j].to]){
                out[low[i]] = 1; break;
            }
    for(i = 1; i <= scc_num; ++i)
        if(!out[i]){
            if(++ok > 1) break;
            ans = count[i];
        }
    if(ok != 1) printf("0\n");
    else printf("%d\n", ans);
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