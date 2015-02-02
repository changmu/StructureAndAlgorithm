#include <stdio.h>
#include <string.h>

#define maxn 205

bool G[maxn][maxn], visy[maxn];
int girl[maxn], boy[maxn];
int g, b, m, cas = 1;

void getMap() {
    int u, v;
    memset(G, 0, sizeof(G));
    while(m--) {
        scanf("%d%d", &u, &v);
        G[u][v] = true;
    }
}

int findPath(int x) {
    int i;
    for(i = 1; i <= b; ++i) {
        if(!G[x][i] && !visy[i]) {
            visy[i] = 1;
            if(boy[i] == -1 || findPath(boy[i])) {
                boy[i] = x; return 1;
            }
        }
    }
    return 0;
}

int MaxMatch() {
    int i, ans = 0;
    memset(girl, -1, sizeof(girl));
    memset(boy, -1, sizeof(boy));
    for(i = 1; i <= g; ++i) {
        memset(visy, 0, sizeof(visy));
        ans += findPath(i);
    }
    return ans;
}

void solve() {
    printf("Case %d: %d\n", cas++, g + b - MaxMatch());
}

int main() {
    while(scanf("%d%d%d", &g, &b, &m), g | b | m) {
        getMap();
        solve();
    }
    return 0;
}