//not mine
#include <iostream>
#include <cstdlib>
#include <cstring>
#include <cstdio>
using namespace std;

#define maxn 100005
#define maxm 1000005

struct Edge
{
    int v, next;
}edge[maxm];

int n, m;
int value[maxn];
int in[maxn], out[maxn];
int head[maxn], ecount;
long long f[maxn];
bool vis[maxn];

void addedge(int a, int b)
{
    edge[ecount].next = head[a];
    edge[ecount].v = b;
    head[a] = ecount++;
}

void input()
{
    for (int i = 0; i < n; i++)
        scanf("%d", &value[i]);
    memset(in, 0, sizeof(in));
    memset(out, 0, sizeof(out));
    memset(head, -1, sizeof(head));
    ecount = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b;
        scanf("%d%d", &a, &b);
        a--;
        b--;
        in[b]++;
        out[a]++;
        addedge(a, b);
    }
}

long long cal(int a)
{
    if (vis[a])
        return f[a];
    f[a] = -20000;
    f[a] *= maxn;
    for (int i = head[a]; i != -1; i = edge[i].next)
        f[a] = max(f[a], cal(edge[i].v));
    f[a] += value[a];
    vis[a] = true;
    return f[a];
}

void work()
{
    memset(vis, 0, sizeof(vis));
    for (int i = 0; i < n; i++)
        if (out[i] == 0)
        {
            f[i] = value[i];
            vis[i] = true;
        }
    long long ans = -20000;
    ans *= maxn;
    for (int i = 0; i < n; i++)
        if (in[i] == 0)
        {
            ans = max(ans, cal(i));
        }
    printf("%lld\n", ans);
}

int main()
{
    //freopen("t.txt", "r", stdin);
    while (~scanf("%d%d", &n, &m))
    {
        input();
        work();
    }
    return 0;
}