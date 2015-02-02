#include <stdio.h>
#include <string.h>

#define maxn 30

char G[maxn][maxn];
int n, m, X, Y, sum; // n rows m columns and start position
const int mov[][2] = {0, 1, 0, -1, 1, 0, -1, 0};

void getMap() {
    int i, j;
    for(i = 0; i < n; ++i) {
        scanf("%s", G[i]);
        for(j = 0; G[i][j]; ++j)
            if(G[i][j] == '@') {
                X = i; Y = j;
            }
    }
}

bool check(int x, int y) {
    if(x < 0 || y < 0 || x >= n || y >= m)
        return false;
    return G[x][y] == '.';
}

void DFS(int x, int y) {
    G[x][y] = '#'; ++sum;
    int i, j, xa, ya;
    for(i = 0; i < 4; ++i) {
        xa = x + mov[i][0];
        ya = y + mov[i][1];
        if(check(xa, ya))
            DFS(xa, ya);
    }
}

int main() {
    // freopen("stdin.txt", "r", stdin);
    while(scanf("%d%d", &m, &n), m | n) {
        getMap();
        sum = 0;
        DFS(X, Y);
        printf("%d\n", sum);
    }
    return 0;
}