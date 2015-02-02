#include <stdio.h>
#include <string.h>
#include <algorithm>

#define maxn 102
#define inf 0x3f3f3f3f

int map[maxn][maxn];

void getMap(int n) {
    int i, j, k, u, v, dis;
    memset(map, 0x3f, sizeof(map));
    for(u = 1; u <= n; ++u) {
        map[u][u] = 0;
        scanf("%d", &k);
        while(k--) {
            scanf("%d%d", &v, &dis);
            map[u][v] = dis;
        }
    }
}

void Floyd(int n) {
    int k, i, j;
    for(k = 1; k <= n; ++k)
        for(i = 1; i <= n; ++i)
            for(j = 1; j <= n; ++j)
                if(map[i][j] > map[i][k] + map[k][j])
                    map[i][j] = map[i][k] + map[k][j];
}

void solve(int n) {
    Floyd(n);
    int i, ans_val = inf, ans_pos = 0, *p;
    for(i = 1; i <= n; ++i) {
        p = std::max_element(map[i] + 1, map[i] + n + 1);
        if(*p != inf && *p < ans_val) {
            ans_val = *p; ans_pos = i;
        }
    }
    if(!ans_pos) printf("disjoint\n");
    else printf("%d %d\n", ans_pos, ans_val);
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    int n;
    while(scanf("%d", &n), n) {
        getMap(n);
        solve(n);
    }
    return 0;
}
