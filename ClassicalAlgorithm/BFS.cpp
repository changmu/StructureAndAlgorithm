/************************************************************* 
 * 广搜：有M颗流星即将坠落：
 *      x, y, t
 * 表示这颗流星在时刻t落到点(x, y)上，该点及周围4个点都将毁坏，
 * 小明时刻0时在(0, 0)点，问：他能逃到安全区的最短用时，若不能
 * 则输出-1.
 * BFS模板题
 *************************************************************/ 
#include <stdio.h>
#include <string.h>

const int inf = 0x3f3f3f3f;
const int maxn = 310;
const int dir[][2] = {0, 1, 0, -1, 1, 0, -1, 0};
int G[maxn][maxn], M;
struct Node {
    int x, y, t;
    Node() {x = y = 1; t = 0; }
} que[maxn*maxn];

int min(int a, int b) { return a < b ? a : b; }

void getMap() {
    int x, y, t;

    memset(G, 0x3f, sizeof(G));

    while (M--) {
        scanf("%d%d%d", &x, &y, &t);
        ++x; ++y;
        G[x][y] = min(G[x][y], t);
        /* adjacent */
        G[x-1][y] = min(G[x-1][y], t);
        G[x+1][y] = min(G[x+1][y], t);
        G[x][y-1] = min(G[x][y-1], t);
        G[x][y+1] = min(G[x][y+1], t);
    }
}

bool check(int x, int y, int t) {
    return x > 0 && x < maxn && y > 0 && y < maxn &&
        G[x][y] > t;
}

int solve() {
    if (G[1][1] <= 0) return -1;

    int x, y, t, i, front = 0, back = 0;
    Node u, v;
    que[back++] = Node();
    
    while (front != back) {
        u = que[front++];
        for (i = 0; i < 4; ++i) {
            v = u;
            v.x += dir[i][0];
            v.y += dir[i][1];
            ++v.t;
            if (check(v.x, v.y, v.t)) {
                if (G[v.x][v.y] == inf)
                    return v.t;
                else {
                    G[v.x][v.y] = 0;
                    que[back++] = v;
                }
            }
        }
    }

    return -1;
}

int main() {
    while (~scanf("%d", &M)) {
        getMap();
        printf("%d\n", solve());
    }
    return 0;
}
