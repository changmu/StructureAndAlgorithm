#include <stdio.h>
#include <string.h>
#include <stdlib.h>

const int maxn = 105;
const int largeNum = 210;
const int inf = 0x3f3f3f3f;
int n, m; // n rows, m columns
char str[maxn];
struct Node {
    int x, y;
} A[maxn], B[maxn];
int id1, id2;
int G[maxn][maxn];
int Lx[maxn], Ly[maxn];
int match[maxn];
bool visx[maxn], visy[maxn];
int slack[maxn];

void getMap() {
    int i, j, dis; Node e;
    id1 = id2 = 0;
    for(i = 0; i < n; ++i) {
        scanf("%s", str);
        for(j = 0; str[j] != '\0'; ++j) {
            if(str[j] == '.') continue;
            e.x = i; e.y = j;
            if(str[j] == 'm') A[id1++] = e;
            else B[id2++] = e;
        }
    }
    memset(G, 0, sizeof(G));
    for(i = 0; i < id1; ++i) {
        for(j = 0; j < id2; ++j) {
            G[i][j] = largeNum - (abs(A[i].x - B[j].x) + abs(A[i].y - B[j].y));
        }
    }
}

bool DFS(int cur) {
    int t, y;
    visx[cur] = true;
    for(y = 0; y < id2; ++y) {
        if(visy[y]) continue;
        t = Lx[cur] + Ly[y] - G[cur][y];
        if(t == 0) {
            visy[y] = true;
            if(match[y] == -1 || DFS(match[y])) {
                match[y] = cur; return true;
            }
        } else if(slack[y] > t) slack[y] = t; 
    }
    return false;
}

int KM() {
    int i, j, x, d, ret;
    memset(match, -1, sizeof(match));
    memset(Ly, 0, sizeof(Ly));
    for(i = 0; i < id1; ++i) {
        Lx[i] = -inf;
        for(j = 0; j < id2; ++j)
            if(G[i][j] > Lx[i]) Lx[i] = G[i][j];
    }
    for(x = 0; x < id1; ++x) {
        memset(slack, 0x3f, sizeof(slack));
        while(true) {
            memset(visx, 0, sizeof(visx));
            memset(visy, 0, sizeof(visy));
            if(DFS(x)) break;
            d = inf;
            for(i = 0; i < id2; ++i)
                if(!visy[i] && d > slack[i]) 
                    d = slack[i];
            for(i = 0; i < id1; ++i)
                if(visx[i]) Lx[i] -= d;
            for(i = 0; i < id2; ++i)
                if(visy[i]) Ly[i] += d;
                else slack[i] -= d;
        }
    }
    ret = 0;
    for(i = 0; i < id1; ++i)
        if(match[i] > -1) ret += G[match[i]][i];
    return ret;
}

void solve() {
    printf("%d\n", largeNum * id1 - KM());
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d%d", &n, &m), n | m) {
        getMap();
        solve();
    }
    return 0;
}
