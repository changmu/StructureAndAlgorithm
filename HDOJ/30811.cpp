////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-12-07 19:41:50
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 3081
////Problem Title: 
////Run result: Accept
////Run time:78MS
////Run memory:1200KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>

#define inf 0x3f3f3f3f
#define maxn 102
#define maxm 10002

int pre[maxn], head[maxn], id;
int B[maxn], T, N, M, F;
struct Node {
    int u, v, next;
} E[maxm];
bool vis[maxn];
bool G[maxn][maxn];

int ufind(int k) {
    int a = k, b;
    while(pre[k] != -1) k = pre[k];
    while(a != k) {
        b = pre[a];
        pre[a] = k;
        a = b;
    }
    return k;
}

void unite(int u, int v) {
    u = ufind(u);
    v = ufind(v);
    if(u != v) pre[v] = u;
}

void addEdge(int u, int v) {
    E[id].u = u;
    E[id++].v = v;
}

void getMap() {
    memset(G, 0, sizeof(G));
    memset(B, 0, sizeof(B));
    memset(head, -1, sizeof(head));
    memset(pre, -1, sizeof(pre));
    int i, j, u, v; id = 0;
    for(i = 0; i < M; ++i) {
        scanf("%d%d", &u, &v);
        addEdge(u, v);
    }
    for(i = 0; i < F; ++i) {
        scanf("%d%d", &u, &v);
        unite(u, v);
    }

    for(i = 0; i < id; ++i) {
        E[i].u = ufind(E[i].u);
        // E[i].next = head[E[i].u];
        // head[E[i].u] = i;
        G[E[i].u][E[i].v] = 1;
    }

    for(i = 1; i <= N; ++i) {
        u = ufind(i);
        if(i != u) memcpy(G[i], G[u], sizeof(bool) * (N + 1));
    }

    // for(i = 1; i <= N; ++i) {
    //     for(j = 1; j <= N; ++j)
    //         if(G[i][j]) printf("1..");
    //         else printf("0..");
    //     printf("\n");
    // }
}

int mfind(int x) {
    int i, v;
    for(i = 1; i <= N; ++i) {
        if(!vis[i] && G[x][i]) {
            vis[i] = 1;
            if(!B[i] || mfind(B[i])) {
                B[i] = x; return 1;
            }
        }
    }
    return 0;
}

void solve() {
    int ans = 0, tmp, i, j;
    do{
        tmp = 0;
        for(i = 1; i <= N; ++i)
            if(B[i]) G[B[i]][i] = 0, B[i] = 0;
        for(i = 1; i <= N; ++i) {
            memset(vis, 0, sizeof(vis));
            tmp += mfind(i);
        }
        if(tmp == N) ++ans;
        else break;
    } while(true);
    printf("%d\n", ans);
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    scanf("%d", &T);
    while(T--) {
        scanf("%d%d%d", &N, &M, &F);
        getMap();
        solve();
    }
    return 0;
}