#include <stdio.h>
#include <string.h>

const int inf = 0x3f3f3f3f;
const int maxn = 102;
int n, m, k;
bool map[maxn][maxn], visy[maxn];
int cx[maxn], cy[maxn];

void getMap() {
    memset(map, 0, sizeof(map));
    int u, v;
    while(k--) {
        scanf("%*d%d%d", &u, &v);
        map[u][v] = true;
    }
}

int findPath(int x) {
    int i, j;
    for(i = 0; i < m; ++i) {
        if(map[x][i] && !visy[i]) {
            visy[i] = 1;
            if(cy[i] == -1 || findPath(cy[i])) {
                cx[x] = i; cy[i] = x; return 1;
            }
        }
    }
    return 0;
}

int MaxMatch() {
    memset(cy, -1, sizeof(cy));
    memset(cx, -1, sizeof(cx));
    int i, j, ans = 0;
    for(i = 0; i < n; ++i) {
        if(cx[i] == -1) {
            memset(visy, 0, sizeof(visy));
            ans += findPath(i);
        }
    }
    return ans;
}

void solve() {
    printf("%d\n", MaxMatch());
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d%d%d", &n, &m, &k) == 3) {
        getMap();
        solve();
    }
    return 0;
}