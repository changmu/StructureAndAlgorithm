#include <stdio.h>
#include <string.h>
#include <map>

int G[5][5], ans;
const int mov[][2] = {0, 1, 0, -1, 1, 0, -1, 0};
std::map<int, int> mp;

void DFS(int x, int y, int k, int sum) {
    if(k == 6) {
        if(mp[sum]++ == 0) ++ans;
        return;
    }
    for(int i = 0, a, b; i < 4; ++i) {
        a = x+mov[i][0];
        b = y+mov[i][1];
        if(a>=0&&b>=0&&a<5&&b<5)
            DFS(a, b, k+1, sum*10+G[x][y]);
    }
}

int main() {
    int i, j;
    for(i = 0; i < 5; ++i)
        for(j = 0; j < 5; ++j)
            scanf("%d", &G[i][j]);
    for(i = 0; i < 5; ++i)
        for(j = 0; j < 5; ++j)
            DFS(i, j, 0, 0);
    printf("%d\n", ans);
    return 0;
}