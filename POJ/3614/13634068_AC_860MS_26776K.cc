#include <stdio.h>
#include <string.h>

#define maxn 4010
#define maxm maxn * 2000
#define inf 0x3f3f3f3f

int head[maxn], id, N, L, source, sink;
struct Node {
    int u, v, c, next;
} E[maxm];

void addEdge(int u, int v, int c) {
    E[id].u = u; E[id].v = v;
    E[id].c = c; E[id].next = head[u];
    head[u] = id++;

    E[id].u = v; E[id].v = u;
    E[id].c = 0; E[id].next = head[v];
    head[v] = id++;
}

void getMap() {
    memset(head, -1, sizeof(head));
    int i, j, a, b; 
    source = 3502; sink = source + 1;
    for(i = 0; i < N; ++i) {
        addEdge(source, i, 1);
        scanf("%d%d", &a, &b);
        for(j = a; j <= b; ++j)
            addEdge(i, j + N, 1);
    }
    while(L--) {
        scanf("%d%d", &a, &b);
        addEdge(N + a, sink, b);
    }
}

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

int main() {
    // freopen("stdin.txt", "r", stdin);
    scanf("%d%d", &N, &L);
    getMap();
    printf("%d\n", Dinic(sink + 1, source, sink));
    return 0;
}