#include <stdio.h>
#include <string.h>
#define maxn 10

char map[maxn][maxn];
int n, m, ans, k;

bool check(int x, int y)
{
    int i;
    for(i = 1; x - i >= 0; ++i) //up
        if(map[x-i][y] == 'A') return 0;
    for(i = 1; x + i < n; ++i) //down
        if(map[x+i][y] == 'A') return 0;
    for(i = 1; y - i >= 0; ++i) //left
        if(map[x][y-i] == 'A') return 0;
    for(i = 1; y + i < n; ++i) //right
        if(map[x][y+i] == 'A') return 0;
    return 1;
}

void DFS(int x, int y)
{
    if(k == m){
        ++ans; return;
    }
    int i, j;
    for(i = x, j = y; i < n; ++i, j = 0){
        for(; j < n; ++j)
            if(map[i][j] == '#' && check(i, j)){
                ++k; map[i][j] = 'A';
                DFS(i, j + 1);
                --k; map[i][j] = '#';
            }
    }
}

int main()
{
    int i;
    while(scanf("%d%d", &n, &m) != EOF){
        if(n == -1 && m == -1) break;
        for(i = 0; i < n; ++i)
            scanf("%s", map[i]);
        ans = k = 0; DFS(0, 0);
        printf("%d\n", ans);
    }
    return 0;
}