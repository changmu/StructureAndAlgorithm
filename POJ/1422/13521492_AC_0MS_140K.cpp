#include <stdio.h>
#include <string.h>

const int maxn = 125;
int n, m;
int cx[maxn], cy[maxn];
bool visy[maxn], G[maxn][maxn];

void getMap() {
    memset(G, 0, sizeof(G));
    int u, v;
    scanf("%d%d", &n, &m);
    while(m--) {
        scanf("%d%d", &u, &v);
        G[u][v] = true;
    }
}

int findPath(int x) {
    int i;
    for(i = 1; i <= n; ++i) {
        if(G[x][i] && !visy[i]) {
            visy[i] = 1;
            if(cy[i] == -1 || findPath(cy[i])) {
                cy[i] = x; return 1;
            }
        }
    }
    return 0;
}

int MaxMatch() {
    int ans = 0, i;
    memset(cx, -1, sizeof(cx));
    memset(cy, -1, sizeof(cy));
    for(i = 1; i <= n; ++i) {
        memset(visy, 0, sizeof(visy));
        if(cx[i] == -1) ans += findPath(i);
    }
    return ans;
}

void solve() {
    printf("%d\n", n - MaxMatch());
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int t;
    scanf("%d", &t);
    while(t--) {
        getMap();
        solve();
    }
    return 0;
}