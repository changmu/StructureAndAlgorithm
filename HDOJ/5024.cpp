////////////////////System Comment////////////////////
////Welcome to Hangzhou Dianzi University Online Judge
////http://acm.hdu.edu.cn
//////////////////////////////////////////////////////
////Username: changmu
////Nickname: ³¤Ä¾
////Run ID: 
////Submit time: 2014-09-23 00:12:14
////Compiler: Visual C++
//////////////////////////////////////////////////////
////Problem ID: 5024
////Problem Title: 
////Run result: Accept
////Run time:15MS
////Run memory:564KB
//////////////////System Comment End//////////////////
#include <stdio.h>
#include <string.h>
#define maxn 102

char map[maxn][maxn];
int dist[maxn][maxn][8], n;
int dir[8][2] = {0, -1, -1, -1, -1, 0, -1, 1,
                 0, 1, 1, 1, 1, 0, 1, -1};

int DFS(int x, int y, int dire) {
    if(dist[x][y][dire]) return dist[x][y][dire];
    if(x < 0 || y < 0 || x >= n || y >= n || map[x][y] == '#') 
        return 0;
    return dist[x][y][dire] = 1 + DFS(x + dir[dire][0], y + dir[dire][1], dire);
}

int main(int argc, char *argv[]) {
    int i, j, k, ans, tmp;
    while(scanf("%d", &n), n) {
        for(i = 0; i < n; ++i)
            scanf("%s", map[i]);
        memset(dist, 0, sizeof(dist));
        for(i = ans = 0; i < n; ++i)
            for(j = 0; j < n; ++j)
                if(map[i][j] == '.') {
                    tmp = DFS(i, j, 0) + DFS(i, j, 2);
                    if(tmp > ans) ans = tmp;
                    tmp = DFS(i, j, 0) + DFS(i, j, 6);
                    if(tmp > ans) ans = tmp;
                    tmp = DFS(i, j, 1) + DFS(i, j, 3);
                    if(tmp > ans) ans = tmp;
                    tmp = DFS(i, j, 1) + DFS(i, j, 7);
                    if(tmp > ans) ans = tmp;
                    tmp = DFS(i, j, 2) + DFS(i, j, 4);
                    if(tmp > ans) ans = tmp;
                    tmp = DFS(i, j, 3) + DFS(i, j, 5);
                    if(tmp > ans) ans = tmp;
                    tmp = DFS(i, j, 4) + DFS(i, j, 6);
                    if(tmp > ans) ans = tmp;
                    tmp = DFS(i, j, 5) + DFS(i, j, 7);
                    if(tmp > ans) ans = tmp;
                }
        printf("%d\n", ans - 1);
    }
    return 0;
}
