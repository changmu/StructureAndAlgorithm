#include <stdio.h>
#include <string.h>
#include <queue>

#define maxn 305
#define maxp 105
#define maxm maxn * maxp
#define inf 0x3f3f3f3f

int head[maxp], id, p, n, dis;
struct Node {
    int v, next;
} E[maxm];
int dx[maxp], dy[maxn], cx[maxp], cy[maxn];
bool visy[maxn];

void AddEdge(int u, int v) {
    E[id].v = v; 
    E[id].next = head[u];
    head[u] = id++;
}

void GetMap() {
    int k, v, i; id = 0;
    scanf("%d%d", &p, &n);
    memset(head, -1, sizeof(int) * (p + 1));
    for(i = 1; i <= p; ++i) {
        scanf("%d", &k);
        while(k--) {
            scanf("%d", &v);
            AddEdge(i, v);
        }
    }
}

bool searchPath() {
    std::queue<int> Q;
    int i, u, v; dis = inf;
    memset(dx, 0, sizeof(int) * (p + 1));
    memset(dy, 0, sizeof(int) * (n + 1));
    for(i = 1; i <= p; ++i) {
        if(!cx[i]) {
            Q.push(i);
        }
    }
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        if(dx[u] > dis) break;
        for(i = head[u]; i != -1; i = E[i].next) {
            if(!cy[v = E[i].v]) {
                dy[v] = dx[u] + 1;
                if(!cy[v]) dis = dy[v];
                else {
                    dx[cy[v]] = dy[v] + 1;
                    Q.push(cy[v]);
                }
            }
        }
    }
    return dis != inf;
}

int findPath(int u) {
    int i, v;
    for(i = head[u]; i != -1; i = E[i].next) {
        if(!visy[v = E[i].v] && dx[u] + 1 == dy[v]) {
            visy[v] = 1;
            if(dy[v] == dis && cy[v]) continue;
            if(!cy[v] || findPath(cy[v])) {
                cy[v] = u; cx[u] = v;
                return 1;
            }
        }
    }
    return 0;
}

int MaxMatch() {
    int ans = 0, i;
    memset(cx, 0, sizeof(int) * (p + 1));
    memset(cy, 0, sizeof(int) * (n + 1));
    while(searchPath()) {
        memset(visy, 0, sizeof(bool) * (n + 1));
        for(i = 1; i <= p; ++i)
            if(!cx[i]) ans += findPath(i);
    }
    return ans;
}

void Solve() {
    printf(MaxMatch() == p ? "YES\n" : "NO\n");
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        GetMap();
        Solve();
    }
    return 0;
}
