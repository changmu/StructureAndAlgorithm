/************************************************************* 
 * 编程解决“农夫、白菜、羊、狼问题”
 *************************************************************/ 
#include <stdio.h>
#include <string.h>
#include <queue>

using namespace std;

enum {
    famer = 1, vegetable = 2, sheep = 4, wolf = 8
};
struct Node {
    int x[2], step;
};
Node G[100][100];
bool vis[20];

bool check(int k) {
    if (k & 1) return true;
    for ( ; k; k >>= 1)
        if ((k&3) == 3) return false;
    return true;
}

void print(int x, int y) {
    if (x == 0 && y == 0) return;
    print(G[x][y].x[0], G[x][y].x[1]);
    printf("(%d, %d)\n", x, y);
}

int main() {
    int A[2] = {15}, i, j, flag;
    queue<Node> Q;
    Node u, v;
    u.x[0] = 15;
    u.x[1] = u.step = flag = 0;
    vis[15] = 1;
    Q.push(u);

    while (!Q.empty()) {
        u = Q.front(); Q.pop();
        if (u.x[1] == 15) break;
        if (u.x[0] & 1) flag = 0;
        else flag = 1;

        for (i = 1; i <= 8; i <<= 1) {
            j = i;
            if ((u.x[flag] & j)) {
                if (j != 1) ++j;
                if (!check(u.x[flag] - j)) continue;
                v.x[flag] = u.x[flag] - j;
                v.x[!flag] = 15 - v.x[flag];
                if (vis[v.x[0]]) continue;
                G[v.x[0]][v.x[1]].x[0] = u.x[0];
                G[v.x[0]][v.x[1]].x[1] = u.x[1];
                vis[v.x[0]] = true;
                if (v.x[0] == 0) break;
                Q.push(v);
            }
        }
        if (v.x[0] == 0) break;
    }

    print(0, 15);
    return 0;
}

