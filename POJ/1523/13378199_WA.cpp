#include <stdio.h>
#include <string.h>
#define maxn 1002
#define maxm maxn * maxn

int head[maxn], id, cas = 1, vertex[maxn], sec;
int dfn[maxn], low[maxn], n, sta[maxn], id2, son;
struct Node{
    int to, next;
} E[maxm];

int max(int a, int b)
{
    if(a < b) a = b;
    return a;
}

int min(int a, int b){
    return a < b ? a : b;
}

void initial()
{
    id = n = id2 = sec = son = 0;
    memset(head, -1, sizeof(head));
    memset(vertex, 0, sizeof(vertex));
    memset(dfn, 0, sizeof(dfn));
    memset(low, 0, sizeof(low));
}

void addEdge(int u, int v)
{
    E[id].to = v; E[id].next = head[u];
    head[u] = id++; E[id].to = u;
    E[id].next = head[v]; head[v] = id++;
}

void Tarjan(int pos, int father)
{
    dfn[pos] = low[pos] = ++sec;
    sta[id2++] = pos; int i;
    for(i = head[pos]; i != -1; i = E[i].next){
        if(E[i].to == father) continue;
        if(!dfn[E[i].to]){
            Tarjan(E[i].to, pos);
            low[pos] = min(low[pos], low[E[i].to]);
            if(dfn[pos] <= low[E[i].to]){
                while(sta[--id2] != E[i].to) ;
                ++vertex[pos];
            }
        }else low[pos] = min(low[pos], low[E[i].to]);
    }
}

void solve(int n)
{
    int i, u, v, ok = 0;
    Tarjan(1, 0);
    --vertex[1];
    printf("Network #%d\n", cas++);    
    for(i = 1; i <= n; ++i){
        if(vertex[i]){
            printf("  SPF node %d leaves %d subnets\n", i, vertex[i] + 1);
            ok = 1;
        }
    }
    if(ok == 0) printf("  No SPF nodes\n");
    printf("\n");
}

int main()
{
    //freopen("stdin.txt", "r", stdin);
    int u, v; initial();
    while(scanf("%d%d", &u, &v) != EOF){
        n = max(u, n);
        n = max(v, n);
        if(0 == u){
            solve(n); if(!v) break;
            initial(); scanf("%d", &u);
            n = max(u, n);
        }
        addEdge(u, v);
    }
    return 0;
}
