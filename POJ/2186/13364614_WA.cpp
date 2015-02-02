#include <stdio.h>
#include <string.h>
#define maxn 10002
#define maxm 50002
//sta2用以维护当前连通分量的根
int head[maxn], id, sta1[maxn], id1, sta2[maxn], id2;
int low[maxn], scc[maxn], sccNum, sec, count[maxn];
struct Node{
    int to, next;
} E[maxm];
bool out[maxn];

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
    for(i = 0; i < m; ++i){
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
}

void Garbow(int pos)
{
    low[pos] = ++sec;
    sta1[id1++] = sta2[id2++] = pos;
    for(int i = head[pos]; i != -1; i = E[i].next){
        if(!low[E[i].to]) Garbow(E[i].to);
        else if(!scc[E[i].to]){
            while(sta2[id2-1] > low[E[i].to]) --id2;
        }
    }
    if(low[pos] == sta2[id2-1]){        
        int v; ++sccNum; --id2;
        do{
            v = sta1[--id1];
            scc[v] = sccNum;
            ++count[sccNum];
        } while(sta1[id1] != pos);
    }
}

void solve(int n)
{
    int i, j; id1 = id2 = 0; sec = sccNum = 0;
    memset(low, 0, sizeof(int) * (n + 1));
    memset(scc, 0, sizeof(int) * (n + 1));
    memset(count, 0, sizeof(int) * (n + 1));
    memset(out, 0, sizeof(bool) * (n + 1));
    for(i = 1; i <= n; ++i)
        if(!low[i]) Garbow(i);
    for(i = 1; i <= n; ++i)
        for(j = head[i]; j != -1; j = E[j].next)
            if(scc[i] != scc[E[j].to]){
                out[scc[i]] = 1; break;
            }
    int tmp = 0, ans;
    for(i = 1; i <= sccNum; ++i)
        if(!out[i]){
            if(++tmp > 1){
                ans = 0; break;
            }
            ans = count[i];
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