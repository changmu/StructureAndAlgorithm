#include <stdio.h>
#include <string.h>
#define maxn 102
#define maxm maxn * maxn

int head[maxn], sta1[maxn], sta2[maxn], scc[maxn];
int low[maxn], id, id1, id2, sec, sccNum;
bool in[maxn], out[maxn];
struct Node{
    int to, next;
} E[maxm];

void addEdge(int u, int v)
{
    E[id].to = v;
    E[id].next = head[u];
    head[u] = id++;
}

void getMap(int n)
{
    memset(head, -1, sizeof(int) * (n + 1));
    int i, v; id = 0;
    for(i = 1; i <= n; ++i)
        while(scanf("%d", &v), v)
            addEdge(i, v);    
}

void Garbow(int pos)
{
    sta1[id1++] = sta2[id2++] = pos;
    low[pos] = ++sec;
    for(int i = head[pos]; i != -1; i = E[i].next){
        if(!low[E[i].to]) Garbow(E[i].to);
        else if(!scc[E[i].to])
            while(low[E[i].to] < low[sta2[id2-1]]) --id2;
        if(scc[E[i].to]) in[scc[E[i].to]] = 1;
    }
    if(sta2[id2-1] == pos){
        ++sccNum; --id2; int v;
        do{
            v = sta1[--id1];
            scc[v] = sccNum;
        } while(sta1[id1] != pos);
    }
}

void solve(int n)
{
    memset(low, 0, sizeof(int) * (n + 1));
    memset(scc, 0, sizeof(int) * (n + 1));
    memset(in, 0, sizeof(bool) * (n + 1));
    memset(out, 0, sizeof(bool) * (n + 1));
    int i, j, ans1 = 0, ans2 = 0; id1 = id2 = sec = sccNum = 0;
    for(i = 1; i <= n; ++i)
        if(!low[i]) Garbow(i);
    for(i = 1; i <= n; ++i)
        for(j = head[i]; j != -1; j = E[j].next)
            if(scc[i] != scc[E[j].to]){
                out[scc[i]] = 1; break;
            }
    if(sccNum != 1){
        for(i = 1; i <= sccNum; ++i){
            if(!out[i]) ++ans2;
            if(!in[i]) ++ans1;
        }
        if(ans1 > ans2) ans2 = ans1;
    }else ans1 = 1;
    printf("%d\n%d\n", ans1, ans2);
}

int main()
{
    int n;
    while(scanf("%d", &n) == 1){
        getMap(n);
        solve(n);
    }
    return 0;
}