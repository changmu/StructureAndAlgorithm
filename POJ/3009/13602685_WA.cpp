#include <stdio.h>
#include <string.h>

#define maxn 30
#define inf 0x3f3f3f3f

int G[maxn][maxn];
int n, m, ans; // n rows
int sx, sy;
const int mov[][2] = {1, 0, -1, 0, 0, 1, 0, -1};

void getMap() {
    int i, j;
    for(i = 0; i < n; ++i)
        for(j = 0; j < m; ++j) {
            scanf("%d", &G[i][j]);
            if(G[i][j] == 2) {
                sx = i; sy = j;
            }
        }
}

bool check(int& x, int& y, int i) {
    while(true) {
        x += mov[i][0];
        y += mov[i][1];
        if(x < 0 || y < 0 || x >= n || y >= m)
            return false;
        if(G[x][y] == 3)
            return true;
        if(G[x][y] == 1) {
            x -= mov[i][0];
            y -= mov[i][1];
            return true;
        }
    }
}

void DFS(int x, int y, int steps) {
    if(G[x][y] == 3) {
        if(steps < ans)
            ans = steps;
        return;
    }
    if(steps == 10) return;
    int xa, ya, i, k;
    for(i = 0; i < 4; ++i) {
        xa = x; ya = y;
        if(check(xa, ya, i)) {
            if(xa == x && ya == y)
                continue;
            G[xa+mov[i][0]][ya+mov[i][1]] = 0;
            DFS(xa, ya, steps + 1);
            if(G[xa][ya] == 3) return;
            G[xa+mov[i][0]][ya+mov[i][1]] = 1; // backtrace
        }
    }
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d%d", &m, &n), m | n) {
        getMap();
        ans = inf;
        DFS(sx, sy, 0);
        if(ans > 10) ans = -1;
        printf("%d\n", ans);
    }
}
