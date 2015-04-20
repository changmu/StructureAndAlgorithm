#include <stdio.h>
#include <string.h>

const int maxn = 210;
const int maxm = 210;
const int inf = 0x3f3f3f3f;
int N, M;
int head[maxn], id;
struct Node {
    int u, v, c, next;
} E[maxm<<1];

 // 参数：顶点个数(若编号0不用则传入最大编号+1)，源点，汇点
int dep[maxn], ps[maxn], cur[maxn];
int Dinic(int n, int s, int t) {
    int tr, res = 0;
    int i, j, k, f, r, top;
    while(true) {
        memset(dep, -1, n * sizeof(int));
        for(f = dep[ps[0] = s] = 0, r = 1; f != r; )
            for(i = ps[f++], j = head[i]; j != -1; j = E[j].next) {
                if(E[j].c && -1 == dep[k=E[j].v]) {
                    dep[k] = dep[i] + 1; ps[r++] = k;
                    if(k == t) {
                        f = r; break;
                    }
                }
            }
        if(-1 == dep[t]) break;

        memcpy(cur, head, n * sizeof(int));
        for(i = s, top = 0; ; ) {
            if(i == t) {
                for(k = 0, tr = inf; k < top; ++k)
                    if(E[ps[k]].c < tr) tr = E[ps[f=k]].c;
                for(k = 0; k < top; ++k)
                    E[ps[k]].c -= tr, E[ps[k]^1].c += tr;
                res += tr; i = E[ps[top = f]].u;
            }
            for(j = cur[i]; cur[i] != -1;j = cur[i] = E[cur[i]].next)
                if(E[j].c && dep[i] + 1 == dep[E[j].v]) break;
            if(cur[i] != -1) {
                ps[top++] = cur[i];
                i = E[cur[i]].v;
            } else {
                if(0 == top) break;
                dep[i] = -1; i = E[ps[--top]].u;
            }
        }
    }
    return res;
}

void init()
{
    memset(head, -1, sizeof(head));
    id = 0;
}

void addEdge(int u, int v, int c)
{
    E[id].u = u;
    E[id].v = v;
    E[id].c = c;
    E[id].next = head[u];
    head[u] = id++;

    E[id].u = v;
    E[id].v = u;
    E[id].c = 0;
    E[id].next = head[v];
    head[v] = id++;
}

void getMap()
{
    int u, v, c, i;
    while (N--) {
        scanf("%d%d%d", &u, &v, &c);
        addEdge(u, v, c);
    }
}

int solve()
{
    printf("%d\n", Dinic(M + 1, 1, M));
}

int main()
{
    while (~scanf("%d%d", &N, &M)) {
        init();
        getMap();
        solve();
    }
    return 0;
}
