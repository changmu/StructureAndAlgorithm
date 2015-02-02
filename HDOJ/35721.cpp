////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-10-13 17:04:03
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3572
////Problem Title: 
////Run result: Accept
////Run time:62MS
////Run memory:2976KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define maxn 25000
#define maxm 750000

int head[maxn], n, m, id; // n machines
struct Node {
    int u, v, c, next;
} E[maxm];
int source, sink, tar, maxDay, nv;

const int inf = 0x3f3f3f3f;

int cur[maxn], ps[maxn], dep[maxn];

void addEdge(int u, int v, int c) {
    E[id].u = u; E[id].v = v;
    E[id].c = c; E[id].next = head[u];
    head[u] = id++;

    E[id].u = v; E[id].v = u;
    E[id].c = 0; E[id].next = head[v];
    head[v] = id++;
}

void getMap() {
    int i, j, u, v, p, s, e; 
    id = tar = maxDay = 0;
    scanf("%d%d", &m, &n);
    memset(head, -1, sizeof(head));
    source = 0;
    for(i = 1; i <= m; ++i) {
        scanf("%d%d%d", &p, &s, &e);
        tar += p;
        if(e > maxDay) maxDay = e;
        addEdge(source, i, p);
        for(j = s; j <= e; ++j)
            addEdge(i, m + j, 1);
    }
    sink = m + maxDay + 1; nv = sink + 1;
    for(i = 1; i <= maxDay; ++i)
        addEdge(m + i, sink, n);
}




int flow(int n, int s, int t) {
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
            for(j=cur[i];cur[i] != -1;j=cur[i]=E[cur[i]].next)
                if(E[j].c&&dep[i]+1==dep[E[j].v])break;
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

void solve(int cas) {
    printf("Case %d: %s\n\n", cas, tar == flow(nv, source, sink) ? "Yes" : "No");
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int t, cas;
    scanf("%d", &t);
    for(cas = 1; cas <= t; ++cas) {
        getMap();
        solve(cas);
    }
    return 0;
}
