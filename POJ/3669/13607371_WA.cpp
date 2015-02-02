/*
** Problem: POJ No.3276 
** Running time: 297MS 
** Complier: C++ 
** Author: Changmu 
*/

#include <stdio.h>
#include <string.h>
#include <queue>

#define maxn 305
#define maxT 1005

int map[maxn][maxn];
const int mov[][2] = {0, 1, 0, -1, -1, 0, 1, 0,};
int N;
struct Node {
    int x, y, t;
};

void Destory(int x, int y, int t) {
    if(!map[x][y] || t < map[x][y]) 
        map[x][y] = t;
    int xa, ya;
    for(int i = 0; i < 4; ++i) {
        xa = x + mov[i][0];
        ya = y + mov[i][1];
        if(xa < 0 || ya < 0) continue;
        if(!map[xa][ya] || t < map[xa][ya])
            map[xa][ya] = t;
    }
}

void getMap() {
    memset(map, 0, sizeof(map));
    int i, j, x, y, t;
    for(i = 0; i < N; ++i) {
        scanf("%d%d%d", &x, &y, &t);
        Destory(x, y, t);
    }
}

bool check(int x, int y, int t) {
    if(x < 0 || y < 0 || map[x][y] == -1)
        return false;
    if(map[x][y] == 0 || map[x][y] > t) return true;
    return false;
}

int BFS() {
    if(map[0][0] == 0) return 0;
    std::queue<Node> Q;
    Node u, v;
    u.x = u.y = u.t = 0;
    Q.push(u);
    while(!Q.empty()) {
        u = Q.front(); Q.pop();
        for(int i = 0; i < 4; ++i) {
            v = u; ++v.t;
            v.x += mov[i][0];
            v.y += mov[i][1];
            if(check(v.x, v.y, v.t)) {
                if(map[v.x][v.y] == 0)
                    return v.t;
                map[v.x][v.y] = -1;
                Q.push(v);
            }
        }
    }
    return -1;
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d", &N) == 1) {
        getMap();
        printf("%d\n", BFS());
    }
    return 0;
}